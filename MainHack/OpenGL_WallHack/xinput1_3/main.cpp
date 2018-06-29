#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"GLu32.lib")

#include <windows.h>
#include <string>
#include <tlhelp32.h>
#include <iostream>
#include <gl\gl.h>
#include <gl\glu.h>
typedef void (APIENTRY *glBegin_t)(GLenum);
typedef void (APIENTRY *glEnd_t)(void);
typedef void (APIENTRY *glClear_t)(GLbitfield);
typedef void (APIENTRY *glVertex3fv_t)(const GLfloat *v);
typedef void (APIENTRY *glVertex3f_t)(GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRY *glEnable_t)(GLenum);
glBegin_t pglBegin = NULL;
glEnd_t pglEnd = NULL;
glClear_t pglClear = NULL;
glVertex3fv_t pglVertex3fv = NULL;
glVertex3f_t pglVertex3f = NULL;
glEnable_t pglEnable = NULL;

bool wallhack = false;

#pragma comment(linker, "/EXPORT:DllMain=_AheadLib_DllMain,@1")
#pragma comment(linker, "/EXPORT:XInputGetState=_AheadLib_XInputGetState,@2")
#pragma comment(linker, "/EXPORT:XInputSetState=_AheadLib_XInputSetState,@3")
#pragma comment(linker, "/EXPORT:XInputGetCapabilities=_AheadLib_XInputGetCapabilities,@4")
#pragma comment(linker, "/EXPORT:XInputEnable=_AheadLib_XInputEnable,@5")
#pragma comment(linker, "/EXPORT:XInputGetDSoundAudioDeviceGuids=_AheadLib_XInputGetDSoundAudioDeviceGuids,@6")
#pragma comment(linker, "/EXPORT:XInputGetBatteryInformation=_AheadLib_XInputGetBatteryInformation,@7")
#pragma comment(linker, "/EXPORT:XInputGetKeystroke=_AheadLib_XInputGetKeystroke,@8")
#pragma comment(linker, "/EXPORT:Noname9=_AheadLib_Noname9,@9,NONAME")
#pragma comment(linker, "/EXPORT:Noname10=_AheadLib_Noname10,@10,NONAME")
#pragma comment(linker, "/EXPORT:Noname11=_AheadLib_Noname11,@11,NONAME")
#pragma comment(linker, "/EXPORT:Noname12=_AheadLib_Noname12,@12,NONAME")
#pragma comment(linker, "/EXPORT:Noname13=_AheadLib_Noname13,@13,NONAME")
#pragma comment(linker, "/EXPORT:Noname14=_AheadLib_Noname14,@14,NONAME")
#pragma comment(linker, "/EXPORT:Noname15=_AheadLib_Noname15,@15,NONAME")
#pragma comment(linker, "/EXPORT:Noname16=_AheadLib_Noname16,@16,NONAME")
#pragma comment(linker, "/EXPORT:Noname17=_AheadLib_Noname17,@17,NONAME")
#pragma comment(linker, "/EXPORT:Noname18=_AheadLib_Noname18,@18,NONAME")
#pragma comment(linker, "/EXPORT:Noname19=_AheadLib_Noname19,@19,NONAME")
#pragma comment(linker, "/EXPORT:Noname20=_AheadLib_Noname20,@20,NONAME")
#pragma comment(linker, "/EXPORT:Noname21=_AheadLib_Noname21,@21,NONAME")
#pragma comment(linker, "/EXPORT:Noname22=_AheadLib_Noname22,@22,NONAME")
#pragma comment(linker, "/EXPORT:Noname23=_AheadLib_Noname23,@23,NONAME")
#pragma comment(linker, "/EXPORT:Noname24=_AheadLib_Noname24,@24,NONAME")
#pragma comment(linker, "/EXPORT:Noname25=_AheadLib_Noname25,@25,NONAME")
#pragma comment(linker, "/EXPORT:Noname26=_AheadLib_Noname26,@26,NONAME")
#pragma comment(linker, "/EXPORT:Noname27=_AheadLib_Noname27,@27,NONAME")
#pragma comment(linker, "/EXPORT:Noname28=_AheadLib_Noname28,@28,NONAME")
#pragma comment(linker, "/EXPORT:Noname29=_AheadLib_Noname29,@29,NONAME")
#pragma comment(linker, "/EXPORT:Noname30=_AheadLib_Noname30,@30,NONAME")
#pragma comment(linker, "/EXPORT:Noname31=_AheadLib_Noname31,@31,NONAME")
#pragma comment(linker, "/EXPORT:Noname32=_AheadLib_Noname32,@32,NONAME")
#pragma comment(linker, "/EXPORT:Noname33=_AheadLib_Noname33,@33,NONAME")
#pragma comment(linker, "/EXPORT:Noname34=_AheadLib_Noname34,@34,NONAME")
#pragma comment(linker, "/EXPORT:Noname35=_AheadLib_Noname35,@35,NONAME")
#pragma comment(linker, "/EXPORT:Noname36=_AheadLib_Noname36,@36,NONAME")
#pragma comment(linker, "/EXPORT:Noname37=_AheadLib_Noname37,@37,NONAME")
#pragma comment(linker, "/EXPORT:Noname38=_AheadLib_Noname38,@38,NONAME")
#pragma comment(linker, "/EXPORT:Noname39=_AheadLib_Noname39,@39,NONAME")
#pragma comment(linker, "/EXPORT:Noname40=_AheadLib_Noname40,@40,NONAME")
#pragma comment(linker, "/EXPORT:Noname41=_AheadLib_Noname41,@41,NONAME")
#pragma comment(linker, "/EXPORT:Noname42=_AheadLib_Noname42,@42,NONAME")
#pragma comment(linker, "/EXPORT:Noname43=_AheadLib_Noname43,@43,NONAME")
#pragma comment(linker, "/EXPORT:Noname44=_AheadLib_Noname44,@44,NONAME")
#pragma comment(linker, "/EXPORT:Noname45=_AheadLib_Noname45,@45,NONAME")
#pragma comment(linker, "/EXPORT:Noname46=_AheadLib_Noname46,@46,NONAME")
#pragma comment(linker, "/EXPORT:Noname47=_AheadLib_Noname47,@47,NONAME")
#pragma comment(linker, "/EXPORT:Noname48=_AheadLib_Noname48,@48,NONAME")
#pragma comment(linker, "/EXPORT:Noname49=_AheadLib_Noname49,@49,NONAME")
#pragma comment(linker, "/EXPORT:Noname50=_AheadLib_Noname50,@50,NONAME")
#pragma comment(linker, "/EXPORT:Noname51=_AheadLib_Noname51,@51,NONAME")
#pragma comment(linker, "/EXPORT:Noname52=_AheadLib_Noname52,@52,NONAME")
#pragma comment(linker, "/EXPORT:Noname53=_AheadLib_Noname53,@53,NONAME")
#pragma comment(linker, "/EXPORT:Noname54=_AheadLib_Noname54,@54,NONAME")
#pragma comment(linker, "/EXPORT:Noname55=_AheadLib_Noname55,@55,NONAME")
#pragma comment(linker, "/EXPORT:Noname56=_AheadLib_Noname56,@56,NONAME")
#pragma comment(linker, "/EXPORT:Noname57=_AheadLib_Noname57,@57,NONAME")
#pragma comment(linker, "/EXPORT:Noname58=_AheadLib_Noname58,@58,NONAME")
#pragma comment(linker, "/EXPORT:Noname59=_AheadLib_Noname59,@59,NONAME")
#pragma comment(linker, "/EXPORT:Noname60=_AheadLib_Noname60,@60,NONAME")
#pragma comment(linker, "/EXPORT:Noname61=_AheadLib_Noname61,@61,NONAME")
#pragma comment(linker, "/EXPORT:Noname62=_AheadLib_Noname62,@62,NONAME")
#pragma comment(linker, "/EXPORT:Noname63=_AheadLib_Noname63,@63,NONAME")
#pragma comment(linker, "/EXPORT:Noname64=_AheadLib_Noname64,@64,NONAME")
#pragma comment(linker, "/EXPORT:Noname65=_AheadLib_Noname65,@65,NONAME")
#pragma comment(linker, "/EXPORT:Noname66=_AheadLib_Noname66,@66,NONAME")
#pragma comment(linker, "/EXPORT:Noname67=_AheadLib_Noname67,@67,NONAME")
#pragma comment(linker, "/EXPORT:Noname68=_AheadLib_Noname68,@68,NONAME")
#pragma comment(linker, "/EXPORT:Noname69=_AheadLib_Noname69,@69,NONAME")
#pragma comment(linker, "/EXPORT:Noname70=_AheadLib_Noname70,@70,NONAME")
#pragma comment(linker, "/EXPORT:Noname71=_AheadLib_Noname71,@71,NONAME")
#pragma comment(linker, "/EXPORT:Noname72=_AheadLib_Noname72,@72,NONAME")
#pragma comment(linker, "/EXPORT:Noname73=_AheadLib_Noname73,@73,NONAME")
#pragma comment(linker, "/EXPORT:Noname74=_AheadLib_Noname74,@74,NONAME")
#pragma comment(linker, "/EXPORT:Noname75=_AheadLib_Noname75,@75,NONAME")
#pragma comment(linker, "/EXPORT:Noname76=_AheadLib_Noname76,@76,NONAME")
#pragma comment(linker, "/EXPORT:Noname77=_AheadLib_Noname77,@77,NONAME")
#pragma comment(linker, "/EXPORT:Noname78=_AheadLib_Noname78,@78,NONAME")
#pragma comment(linker, "/EXPORT:Noname79=_AheadLib_Noname79,@79,NONAME")
#pragma comment(linker, "/EXPORT:Noname80=_AheadLib_Noname80,@80,NONAME")
#pragma comment(linker, "/EXPORT:Noname81=_AheadLib_Noname81,@81,NONAME")
#pragma comment(linker, "/EXPORT:Noname82=_AheadLib_Noname82,@82,NONAME")
#pragma comment(linker, "/EXPORT:Noname83=_AheadLib_Noname83,@83,NONAME")
#pragma comment(linker, "/EXPORT:Noname84=_AheadLib_Noname84,@84,NONAME")
#pragma comment(linker, "/EXPORT:Noname85=_AheadLib_Noname85,@85,NONAME")
#pragma comment(linker, "/EXPORT:Noname86=_AheadLib_Noname86,@86,NONAME")
#pragma comment(linker, "/EXPORT:Noname87=_AheadLib_Noname87,@87,NONAME")
#pragma comment(linker, "/EXPORT:Noname88=_AheadLib_Noname88,@88,NONAME")
#pragma comment(linker, "/EXPORT:Noname89=_AheadLib_Noname89,@89,NONAME")
#pragma comment(linker, "/EXPORT:Noname90=_AheadLib_Noname90,@90,NONAME")
#pragma comment(linker, "/EXPORT:Noname91=_AheadLib_Noname91,@91,NONAME")
#pragma comment(linker, "/EXPORT:Noname92=_AheadLib_Noname92,@92,NONAME")
#pragma comment(linker, "/EXPORT:Noname93=_AheadLib_Noname93,@93,NONAME")
#pragma comment(linker, "/EXPORT:Noname94=_AheadLib_Noname94,@94,NONAME")
#pragma comment(linker, "/EXPORT:Noname95=_AheadLib_Noname95,@95,NONAME")
#pragma comment(linker, "/EXPORT:Noname96=_AheadLib_Noname96,@96,NONAME")
#pragma comment(linker, "/EXPORT:Noname97=_AheadLib_Noname97,@97,NONAME")
#pragma comment(linker, "/EXPORT:Noname98=_AheadLib_Noname98,@98,NONAME")
#pragma comment(linker, "/EXPORT:Noname99=_AheadLib_Noname99,@99,NONAME")
#pragma comment(linker, "/EXPORT:Noname100=_AheadLib_Noname100,@100,NONAME")
#pragma comment(linker, "/EXPORT:Noname101=_AheadLib_Noname101,@101,NONAME")
#pragma comment(linker, "/EXPORT:Noname102=_AheadLib_Noname102,@102,NONAME")
#pragma comment(linker, "/EXPORT:Noname103=_AheadLib_Noname103,@103,NONAME")

#define EXTERNC extern "C"
#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)

#define ALCPP EXPORT NAKED
#define ALSTD EXTERNC EXPORT NAKED void __stdcall
#define ALCFAST EXTERNC EXPORT NAKED void __fastcall
#define ALCDECL EXTERNC NAKED void __cdecl

namespace AheadLib
{
	HMODULE m_hModule = NULL;
	DWORD m_dwReturn[103] = {0};

	inline BOOL WINAPI Load()
	{
		TCHAR tzPath[MAX_PATH];
		TCHAR tzTemp[MAX_PATH * 2];

		GetSystemDirectory(tzPath, MAX_PATH);
		lstrcat(tzPath, TEXT("\\xinput1_3"));
		m_hModule = LoadLibrary(tzPath);
		if (m_hModule == NULL)
		{
			wsprintf(tzTemp, TEXT("無法加載 %s，程序無法正常運行。"), tzPath);
			MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
		}

		return (m_hModule != NULL);	
	}

	inline VOID WINAPI Free()
	{
		if (m_hModule)
		{
			FreeLibrary(m_hModule);
		}
	}

	FARPROC WINAPI GetAddress(PCSTR pszProcName)
	{
		FARPROC fpAddress;
		CHAR szProcName[16];
		TCHAR tzTemp[MAX_PATH];

		fpAddress = GetProcAddress(m_hModule, pszProcName);
		if (fpAddress == NULL)
		{
			if (HIWORD(pszProcName) == 0)
			{
				wsprintf(szProcName, "%d", pszProcName);
				pszProcName = szProcName;
			}

			wsprintf(tzTemp, TEXT("無法找到函數 %hs，程序無法正常運行。"), pszProcName);
			MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
			ExitProcess(-2);
		}

		return fpAddress;
	}
}
using namespace AheadLib;


//透視function
void DrawBox(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glVertex3f(x + width, y, z);
	glVertex3f(x + width, y + height, z);
	glVertex3f(x, y + height, z);
	glEnd();
}


void APIENTRY Hooked_glBegin(GLenum mode)
{
	if (GetAsyncKeyState(VK_F2) & 1)
		wallhack = !wallhack;

	if (wallhack)
	{
		if (mode == GL_TRIANGLES || mode == GL_TRIANGLE_STRIP || mode == GL_TRIANGLE_FAN)
			glDepthRange(0, 0.5);
		else
			glDepthRange(0.5, 1);
	}

	if (pglBegin)
		(*pglBegin)(mode);
}

void APIENTRY Hooked_glEnd(void)
{
	(*pglEnd)();
}

void APIENTRY Hooked_glVertex3fv(GLfloat *v)
{
	(*pglVertex3fv)(v);
}


void APIENTRY Hooked_glVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
	(*pglVertex3f)(x, y, z);
}

void APIENTRY Hooked_glClear(GLbitfield mask)
{
	(*pglClear)(mask);
}

void APIENTRY Hooked_glEnable(GLenum cap)
{
	DrawBox(200, 100, 0, 50, 30);
	(*pglEnable)(cap);
}

void *DetourFunc(BYTE *src, const BYTE *dst, const int len)
{
	BYTE *jmp = (BYTE*)malloc(len + 5);
	DWORD dwback;
	VirtualProtect(src, len, PAGE_READWRITE, &dwback);
	memcpy(jmp, src, len);
	jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp + 1) = (DWORD)(src + len - jmp) - 5;
	src[0] = 0xE9;
	*(DWORD*)(src + 1) = (DWORD)(dst - src) - 5;
	VirtualProtect(src, len, dwback, &dwback);
	return (jmp - len);
}

void HookGL()
{
	HMODULE hOpenGL = GetModuleHandle("opengl32.dll");
	pglVertex3fv = (glVertex3fv_t)DetourFunc((LPBYTE)GetProcAddress(hOpenGL, "glVertex3fv"), (LPBYTE)&Hooked_glVertex3fv, 6);
	pglVertex3f = (glVertex3f_t)DetourFunc((LPBYTE)GetProcAddress(hOpenGL, "glVertex3f"), (LPBYTE)&Hooked_glVertex3f, 6);
	pglBegin = (glBegin_t)DetourFunc((LPBYTE)GetProcAddress(hOpenGL, "glBegin"), (LPBYTE)&Hooked_glBegin, 6);
	pglEnd = (glEnd_t)DetourFunc((LPBYTE)GetProcAddress(hOpenGL, "glEnd"), (LPBYTE)&Hooked_glEnd, 6);
	pglClear = (glClear_t)DetourFunc((LPBYTE)GetProcAddress(hOpenGL, "glClear"), (LPBYTE)&Hooked_glClear, 7);
	pglEnable = (glEnable_t)DetourFunc((LPBYTE)GetProcAddress(hOpenGL, "glEnable"), (LPBYTE)&Hooked_glEnable, 6);
}

int _declspec(dllexport)RunDllHostCallBack(int a,int b,int c)
{
	return 0;
}

DWORD WINAPI dwMainThread(LPVOID)
{
	HookGL();

	return TRUE;
}
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
		CreateThread(0, 0, dwMainThread, 0, 0, 0);
	return TRUE;
}

ALCDECL AheadLib_DllMain(void)
{
	__asm POP m_dwReturn[0 * TYPE long];
	GetAddress("DllMain")();
	__asm JMP m_dwReturn[0 * TYPE long];
}


ALCDECL AheadLib_XInputGetState(void)
{
	__asm POP m_dwReturn[1 * TYPE long];
	GetAddress("XInputGetState")();
	__asm JMP m_dwReturn[1 * TYPE long];
}

ALCDECL AheadLib_XInputSetState(void)
{
	__asm POP m_dwReturn[2 * TYPE long];
	GetAddress("XInputSetState")();
	__asm JMP m_dwReturn[2 * TYPE long];
}

ALCDECL AheadLib_XInputGetCapabilities(void)
{
	__asm POP m_dwReturn[3 * TYPE long];
	GetAddress("XInputGetCapabilities")();
	__asm JMP m_dwReturn[3 * TYPE long];
}

ALCDECL AheadLib_XInputEnable(void)
{
	__asm POP m_dwReturn[4 * TYPE long];
	GetAddress("XInputEnable")();
	__asm JMP m_dwReturn[4 * TYPE long];
}

ALCDECL AheadLib_XInputGetDSoundAudioDeviceGuids(void)
{

	__asm POP m_dwReturn[5 * TYPE long];
	GetAddress("XInputGetDSoundAudioDeviceGuids")();
	__asm JMP m_dwReturn[5 * TYPE long];
}

ALCDECL AheadLib_XInputGetBatteryInformation(void)
{
	__asm POP m_dwReturn[6 * TYPE long];
	GetAddress("XInputGetBatteryInformation")();
	__asm JMP m_dwReturn[6 * TYPE long];
}

ALCDECL AheadLib_XInputGetKeystroke(void)
{
	
	__asm POP m_dwReturn[7 * TYPE long];

	
	GetAddress("XInputGetKeystroke")();

	
	__asm JMP m_dwReturn[7 * TYPE long];
}






ALCDECL AheadLib_Noname9(void)
{
	
	__asm POP m_dwReturn[8 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(9))();

	
	__asm JMP m_dwReturn[8 * TYPE long];
}






ALCDECL AheadLib_Noname10(void)
{
	
	__asm POP m_dwReturn[9 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(10))();

	
	__asm JMP m_dwReturn[9 * TYPE long];
}






ALCDECL AheadLib_Noname11(void)
{
	
	__asm POP m_dwReturn[10 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(11))();

	
	__asm JMP m_dwReturn[10 * TYPE long];
}






ALCDECL AheadLib_Noname12(void)
{
	
	__asm POP m_dwReturn[11 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(12))();

	
	__asm JMP m_dwReturn[11 * TYPE long];
}






ALCDECL AheadLib_Noname13(void)
{
	
	__asm POP m_dwReturn[12 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(13))();

	
	__asm JMP m_dwReturn[12 * TYPE long];
}






ALCDECL AheadLib_Noname14(void)
{
	
	__asm POP m_dwReturn[13 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(14))();

	
	__asm JMP m_dwReturn[13 * TYPE long];
}






ALCDECL AheadLib_Noname15(void)
{
	
	__asm POP m_dwReturn[14 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(15))();

	
	__asm JMP m_dwReturn[14 * TYPE long];
}






ALCDECL AheadLib_Noname16(void)
{
	
	__asm POP m_dwReturn[15 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(16))();

	
	__asm JMP m_dwReturn[15 * TYPE long];
}






ALCDECL AheadLib_Noname17(void)
{
	
	__asm POP m_dwReturn[16 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(17))();

	
	__asm JMP m_dwReturn[16 * TYPE long];
}






ALCDECL AheadLib_Noname18(void)
{
	
	__asm POP m_dwReturn[17 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(18))();

	
	__asm JMP m_dwReturn[17 * TYPE long];
}






ALCDECL AheadLib_Noname19(void)
{
	
	__asm POP m_dwReturn[18 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(19))();

	
	__asm JMP m_dwReturn[18 * TYPE long];
}






ALCDECL AheadLib_Noname20(void)
{
	
	__asm POP m_dwReturn[19 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(20))();

	
	__asm JMP m_dwReturn[19 * TYPE long];
}






ALCDECL AheadLib_Noname21(void)
{
	
	__asm POP m_dwReturn[20 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(21))();

	
	__asm JMP m_dwReturn[20 * TYPE long];
}






ALCDECL AheadLib_Noname22(void)
{
	
	__asm POP m_dwReturn[21 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(22))();

	
	__asm JMP m_dwReturn[21 * TYPE long];
}






ALCDECL AheadLib_Noname23(void)
{
	
	__asm POP m_dwReturn[22 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(23))();

	
	__asm JMP m_dwReturn[22 * TYPE long];
}






ALCDECL AheadLib_Noname24(void)
{
	
	__asm POP m_dwReturn[23 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(24))();

	
	__asm JMP m_dwReturn[23 * TYPE long];
}






ALCDECL AheadLib_Noname25(void)
{
	
	__asm POP m_dwReturn[24 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(25))();

	
	__asm JMP m_dwReturn[24 * TYPE long];
}






ALCDECL AheadLib_Noname26(void)
{
	
	__asm POP m_dwReturn[25 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(26))();

	
	__asm JMP m_dwReturn[25 * TYPE long];
}






ALCDECL AheadLib_Noname27(void)
{
	
	__asm POP m_dwReturn[26 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(27))();

	
	__asm JMP m_dwReturn[26 * TYPE long];
}






ALCDECL AheadLib_Noname28(void)
{
	
	__asm POP m_dwReturn[27 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(28))();

	
	__asm JMP m_dwReturn[27 * TYPE long];
}






ALCDECL AheadLib_Noname29(void)
{
	
	__asm POP m_dwReturn[28 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(29))();

	
	__asm JMP m_dwReturn[28 * TYPE long];
}






ALCDECL AheadLib_Noname30(void)
{
	
	__asm POP m_dwReturn[29 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(30))();

	
	__asm JMP m_dwReturn[29 * TYPE long];
}






ALCDECL AheadLib_Noname31(void)
{
	
	__asm POP m_dwReturn[30 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(31))();

	
	__asm JMP m_dwReturn[30 * TYPE long];
}






ALCDECL AheadLib_Noname32(void)
{
	
	__asm POP m_dwReturn[31 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(32))();

	
	__asm JMP m_dwReturn[31 * TYPE long];
}






ALCDECL AheadLib_Noname33(void)
{
	
	__asm POP m_dwReturn[32 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(33))();

	
	__asm JMP m_dwReturn[32 * TYPE long];
}






ALCDECL AheadLib_Noname34(void)
{
	
	__asm POP m_dwReturn[33 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(34))();

	
	__asm JMP m_dwReturn[33 * TYPE long];
}






ALCDECL AheadLib_Noname35(void)
{
	
	__asm POP m_dwReturn[34 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(35))();

	
	__asm JMP m_dwReturn[34 * TYPE long];
}






ALCDECL AheadLib_Noname36(void)
{
	
	__asm POP m_dwReturn[35 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(36))();

	
	__asm JMP m_dwReturn[35 * TYPE long];
}






ALCDECL AheadLib_Noname37(void)
{
	
	__asm POP m_dwReturn[36 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(37))();

	
	__asm JMP m_dwReturn[36 * TYPE long];
}






ALCDECL AheadLib_Noname38(void)
{
	
	__asm POP m_dwReturn[37 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(38))();

	
	__asm JMP m_dwReturn[37 * TYPE long];
}






ALCDECL AheadLib_Noname39(void)
{
	
	__asm POP m_dwReturn[38 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(39))();

	
	__asm JMP m_dwReturn[38 * TYPE long];
}






ALCDECL AheadLib_Noname40(void)
{
	
	__asm POP m_dwReturn[39 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(40))();

	
	__asm JMP m_dwReturn[39 * TYPE long];
}






ALCDECL AheadLib_Noname41(void)
{
	
	__asm POP m_dwReturn[40 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(41))();

	
	__asm JMP m_dwReturn[40 * TYPE long];
}






ALCDECL AheadLib_Noname42(void)
{
	
	__asm POP m_dwReturn[41 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(42))();

	
	__asm JMP m_dwReturn[41 * TYPE long];
}






ALCDECL AheadLib_Noname43(void)
{
	
	__asm POP m_dwReturn[42 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(43))();

	
	__asm JMP m_dwReturn[42 * TYPE long];
}






ALCDECL AheadLib_Noname44(void)
{
	
	__asm POP m_dwReturn[43 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(44))();

	
	__asm JMP m_dwReturn[43 * TYPE long];
}






ALCDECL AheadLib_Noname45(void)
{
	
	__asm POP m_dwReturn[44 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(45))();

	
	__asm JMP m_dwReturn[44 * TYPE long];
}






ALCDECL AheadLib_Noname46(void)
{
	
	__asm POP m_dwReturn[45 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(46))();

	
	__asm JMP m_dwReturn[45 * TYPE long];
}






ALCDECL AheadLib_Noname47(void)
{
	
	__asm POP m_dwReturn[46 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(47))();

	
	__asm JMP m_dwReturn[46 * TYPE long];
}






ALCDECL AheadLib_Noname48(void)
{
	
	__asm POP m_dwReturn[47 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(48))();

	
	__asm JMP m_dwReturn[47 * TYPE long];
}






ALCDECL AheadLib_Noname49(void)
{
	
	__asm POP m_dwReturn[48 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(49))();

	
	__asm JMP m_dwReturn[48 * TYPE long];
}






ALCDECL AheadLib_Noname50(void)
{
	
	__asm POP m_dwReturn[49 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(50))();

	
	__asm JMP m_dwReturn[49 * TYPE long];
}






ALCDECL AheadLib_Noname51(void)
{
	
	__asm POP m_dwReturn[50 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(51))();

	
	__asm JMP m_dwReturn[50 * TYPE long];
}






ALCDECL AheadLib_Noname52(void)
{
	
	__asm POP m_dwReturn[51 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(52))();

	
	__asm JMP m_dwReturn[51 * TYPE long];
}






ALCDECL AheadLib_Noname53(void)
{
	
	__asm POP m_dwReturn[52 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(53))();

	
	__asm JMP m_dwReturn[52 * TYPE long];
}






ALCDECL AheadLib_Noname54(void)
{
	
	__asm POP m_dwReturn[53 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(54))();

	
	__asm JMP m_dwReturn[53 * TYPE long];
}






ALCDECL AheadLib_Noname55(void)
{
	
	__asm POP m_dwReturn[54 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(55))();

	
	__asm JMP m_dwReturn[54 * TYPE long];
}






ALCDECL AheadLib_Noname56(void)
{
	
	__asm POP m_dwReturn[55 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(56))();

	
	__asm JMP m_dwReturn[55 * TYPE long];
}






ALCDECL AheadLib_Noname57(void)
{
	
	__asm POP m_dwReturn[56 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(57))();

	
	__asm JMP m_dwReturn[56 * TYPE long];
}






ALCDECL AheadLib_Noname58(void)
{
	
	__asm POP m_dwReturn[57 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(58))();

	
	__asm JMP m_dwReturn[57 * TYPE long];
}






ALCDECL AheadLib_Noname59(void)
{
	
	__asm POP m_dwReturn[58 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(59))();

	
	__asm JMP m_dwReturn[58 * TYPE long];
}






ALCDECL AheadLib_Noname60(void)
{
	
	__asm POP m_dwReturn[59 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(60))();

	
	__asm JMP m_dwReturn[59 * TYPE long];
}






ALCDECL AheadLib_Noname61(void)
{
	
	__asm POP m_dwReturn[60 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(61))();

	
	__asm JMP m_dwReturn[60 * TYPE long];
}






ALCDECL AheadLib_Noname62(void)
{
	
	__asm POP m_dwReturn[61 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(62))();

	
	__asm JMP m_dwReturn[61 * TYPE long];
}






ALCDECL AheadLib_Noname63(void)
{
	
	__asm POP m_dwReturn[62 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(63))();

	
	__asm JMP m_dwReturn[62 * TYPE long];
}






ALCDECL AheadLib_Noname64(void)
{
	
	__asm POP m_dwReturn[63 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(64))();

	
	__asm JMP m_dwReturn[63 * TYPE long];
}






ALCDECL AheadLib_Noname65(void)
{
	
	__asm POP m_dwReturn[64 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(65))();

	
	__asm JMP m_dwReturn[64 * TYPE long];
}






ALCDECL AheadLib_Noname66(void)
{
	
	__asm POP m_dwReturn[65 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(66))();

	
	__asm JMP m_dwReturn[65 * TYPE long];
}






ALCDECL AheadLib_Noname67(void)
{
	
	__asm POP m_dwReturn[66 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(67))();

	
	__asm JMP m_dwReturn[66 * TYPE long];
}






ALCDECL AheadLib_Noname68(void)
{
	
	__asm POP m_dwReturn[67 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(68))();

	
	__asm JMP m_dwReturn[67 * TYPE long];
}






ALCDECL AheadLib_Noname69(void)
{
	
	__asm POP m_dwReturn[68 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(69))();

	
	__asm JMP m_dwReturn[68 * TYPE long];
}






ALCDECL AheadLib_Noname70(void)
{
	
	__asm POP m_dwReturn[69 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(70))();

	
	__asm JMP m_dwReturn[69 * TYPE long];
}






ALCDECL AheadLib_Noname71(void)
{
	
	__asm POP m_dwReturn[70 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(71))();

	
	__asm JMP m_dwReturn[70 * TYPE long];
}






ALCDECL AheadLib_Noname72(void)
{
	
	__asm POP m_dwReturn[71 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(72))();

	
	__asm JMP m_dwReturn[71 * TYPE long];
}






ALCDECL AheadLib_Noname73(void)
{
	
	__asm POP m_dwReturn[72 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(73))();

	
	__asm JMP m_dwReturn[72 * TYPE long];
}






ALCDECL AheadLib_Noname74(void)
{
	
	__asm POP m_dwReturn[73 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(74))();

	
	__asm JMP m_dwReturn[73 * TYPE long];
}






ALCDECL AheadLib_Noname75(void)
{
	
	__asm POP m_dwReturn[74 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(75))();

	
	__asm JMP m_dwReturn[74 * TYPE long];
}






ALCDECL AheadLib_Noname76(void)
{
	
	__asm POP m_dwReturn[75 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(76))();

	
	__asm JMP m_dwReturn[75 * TYPE long];
}






ALCDECL AheadLib_Noname77(void)
{
	
	__asm POP m_dwReturn[76 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(77))();

	
	__asm JMP m_dwReturn[76 * TYPE long];
}






ALCDECL AheadLib_Noname78(void)
{
	
	__asm POP m_dwReturn[77 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(78))();

	
	__asm JMP m_dwReturn[77 * TYPE long];
}






ALCDECL AheadLib_Noname79(void)
{
	
	__asm POP m_dwReturn[78 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(79))();

	
	__asm JMP m_dwReturn[78 * TYPE long];
}






ALCDECL AheadLib_Noname80(void)
{
	
	__asm POP m_dwReturn[79 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(80))();

	
	__asm JMP m_dwReturn[79 * TYPE long];
}






ALCDECL AheadLib_Noname81(void)
{
	
	__asm POP m_dwReturn[80 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(81))();

	
	__asm JMP m_dwReturn[80 * TYPE long];
}






ALCDECL AheadLib_Noname82(void)
{
	
	__asm POP m_dwReturn[81 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(82))();

	
	__asm JMP m_dwReturn[81 * TYPE long];
}






ALCDECL AheadLib_Noname83(void)
{
	
	__asm POP m_dwReturn[82 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(83))();

	
	__asm JMP m_dwReturn[82 * TYPE long];
}






ALCDECL AheadLib_Noname84(void)
{
	
	__asm POP m_dwReturn[83 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(84))();

	
	__asm JMP m_dwReturn[83 * TYPE long];
}






ALCDECL AheadLib_Noname85(void)
{
	
	__asm POP m_dwReturn[84 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(85))();

	
	__asm JMP m_dwReturn[84 * TYPE long];
}






ALCDECL AheadLib_Noname86(void)
{
	
	__asm POP m_dwReturn[85 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(86))();

	
	__asm JMP m_dwReturn[85 * TYPE long];
}






ALCDECL AheadLib_Noname87(void)
{
	
	__asm POP m_dwReturn[86 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(87))();

	
	__asm JMP m_dwReturn[86 * TYPE long];
}






ALCDECL AheadLib_Noname88(void)
{
	
	__asm POP m_dwReturn[87 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(88))();

	
	__asm JMP m_dwReturn[87 * TYPE long];
}






ALCDECL AheadLib_Noname89(void)
{
	
	__asm POP m_dwReturn[88 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(89))();

	
	__asm JMP m_dwReturn[88 * TYPE long];
}






ALCDECL AheadLib_Noname90(void)
{
	
	__asm POP m_dwReturn[89 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(90))();

	
	__asm JMP m_dwReturn[89 * TYPE long];
}






ALCDECL AheadLib_Noname91(void)
{
	
	__asm POP m_dwReturn[90 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(91))();

	
	__asm JMP m_dwReturn[90 * TYPE long];
}






ALCDECL AheadLib_Noname92(void)
{
	
	__asm POP m_dwReturn[91 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(92))();

	
	__asm JMP m_dwReturn[91 * TYPE long];
}






ALCDECL AheadLib_Noname93(void)
{
	
	__asm POP m_dwReturn[92 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(93))();

	
	__asm JMP m_dwReturn[92 * TYPE long];
}






ALCDECL AheadLib_Noname94(void)
{
	
	__asm POP m_dwReturn[93 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(94))();

	
	__asm JMP m_dwReturn[93 * TYPE long];
}






ALCDECL AheadLib_Noname95(void)
{
	
	__asm POP m_dwReturn[94 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(95))();

	
	__asm JMP m_dwReturn[94 * TYPE long];
}






ALCDECL AheadLib_Noname96(void)
{
	
	__asm POP m_dwReturn[95 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(96))();

	
	__asm JMP m_dwReturn[95 * TYPE long];
}






ALCDECL AheadLib_Noname97(void)
{
	
	__asm POP m_dwReturn[96 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(97))();

	
	__asm JMP m_dwReturn[96 * TYPE long];
}






ALCDECL AheadLib_Noname98(void)
{
	
	__asm POP m_dwReturn[97 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(98))();

	
	__asm JMP m_dwReturn[97 * TYPE long];
}






ALCDECL AheadLib_Noname99(void)
{
	
	__asm POP m_dwReturn[98 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(99))();

	
	__asm JMP m_dwReturn[98 * TYPE long];
}






ALCDECL AheadLib_Noname100(void)
{
	
	__asm POP m_dwReturn[99 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(100))();

	
	__asm JMP m_dwReturn[99 * TYPE long];
}






ALCDECL AheadLib_Noname101(void)
{
	
	__asm POP m_dwReturn[100 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(101))();

	
	__asm JMP m_dwReturn[100 * TYPE long];
}






ALCDECL AheadLib_Noname102(void)
{
	
	__asm POP m_dwReturn[101 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(102))();

	
	__asm JMP m_dwReturn[101 * TYPE long];
}






ALCDECL AheadLib_Noname103(void)
{
	
	__asm POP m_dwReturn[102 * TYPE long];

	
	GetAddress(MAKEINTRESOURCE(103))();

	
	__asm JMP m_dwReturn[102 * TYPE long];
}


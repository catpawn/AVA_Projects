using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Security.Cryptography;
using System.IO;
using System.Runtime.InteropServices;

namespace AvAClient
{
    public partial class Form1 : Form
    {
        CRC32 crc = new CRC32();
        Encrypt enc = new Encrypt();
        Form2 f2 = new Form2();
        public String GamePath;
        public String Version;
        public Form1()
        {
            InitializeComponent();
        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult result = folderBrowserDialog1.ShowDialog();
            if (folderBrowserDialog1.SelectedPath.IndexOf(@"GarenaAVA\GameData\Apps\AVATW\Binaries") >= 0)
            {
                textBox1.Text = folderBrowserDialog1.SelectedPath;
                System.IO.File.WriteAllText(Application.StartupPath + "/config.xml", "GamePath=" + textBox1.Text);
                CheckFileExists();
            }
            else
            {
                MessageBox.Show("路徑設置錯誤!");
                System.IO.File.WriteAllText(Application.StartupPath + "/config.xml", "GamePath=");
            }
        }
        void CheckFileExists()
        {
            bool isVaild = true;
            String[] files = { "xinput1_3.dll","d3d9.dll"};
            String[] FilesCRC = { "2655169869", "2021478022" };
            for(int i = 0;i < files.Length;i++)
            {
                if(System.IO.File.Exists(textBox1.Text + "/" +  files[i]))
                {
                    String CRCOfFile = crc.CountCrc(crc.ReadFile(textBox1.Text + "/" + files[i])).ToString();
                    if (CRCOfFile == FilesCRC[i])
                    {
                        listBox1.Items.Add("檔案[" + i + "]檔案檢查完成!");
                    }
                    else
                    {
                        listBox1.Items.Add("檔案[" + i + "]版本並不正確!");
                        if (i == 0)
                        {
                            BinWrite(textBox1.Text + "/" + files[i], FileRes.xinput1_3);
                            listBox1.Items.Add("檔案[" + i + "]安裝完成!");
                        }
                        if (i == 1)
                        {
                            BinWrite(textBox1.Text + "/" + files[i], FileRes.d3d9);
                            listBox1.Items.Add("檔案[" + i + "]安裝完成!");
                        }
                    }
                }
                else
                {
                    try
                    {
                        listBox1.Items.Add("檔案[" + i + "]檔案狀態並不正常!");
                        if (i == 0) BinWrite(textBox1.Text + "/" + files[i], FileRes.xinput1_3);
                        if (i == 1) BinWrite(textBox1.Text + "/" + files[i], FileRes.d3d9); //xin_put
                        listBox1.Items.Add("檔案[" + i + "]安裝完成!");
                    }
                    catch
                    {
                        listBox1.Items.Add("發生未知錯誤!\n正在清空config.xml...");
                        System.IO.File.WriteAllText(Application.StartupPath + "/config.xml", "GamePath=");
                        MessageBox.Show("請重新打開本程式!");
                        this.Close();
                    }
                }
            }
            if(isVaild)
            {
                listBox1.Items.Add("外掛檔案全部正常，可以進入遊戲!");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "")
            {
                MessageBox.Show("路徑尚未設置!");
            }
            else
            {
                button2.Enabled = false;
                button2.Text = "驗證中...";
                String user = enc.Rot13Encode(enc.Base64Encode(textBox2.Text));
                String pass = enc.MyEnCode(enc.md5EnCode(textBox3.Text));
                String AcData = ReadAccountData(user);
                if (DownloadString("https://dl.dropboxusercontent.com/s/fe899asstmo7agj/Data.txt").IndexOf(user + "@" + pass) >= 0)
                {
                    if (AcData != "False")
                    {
                        MessageBox.Show("登入成功!");
                        f2.AccountData = AcData;
                        f2.Show();
                        f2.GamePath = GamePath;
                        this.Hide();
                    }
                }
                else
                {
                    MessageBox.Show("帳號或密碼錯誤!");
                    button2.Enabled = true;
                    button2.Text = "登入";
                }
            }
        }
        String ReadAccountData(String user)
        {
            String data = DownloadString("https://dl.dropboxusercontent.com/s/fe899asstmo7agj/Data.txt");
            String[] SaveData = data.Split(new string[] {"\n"},StringSplitOptions.RemoveEmptyEntries);
            for(int i = 0;i < SaveData.Length;i++)
            {
                if(SaveData[i].IndexOf(user) >= 0)
                {
                    return SaveData[i];
                }
            }
            return "False";
        }
        String DownloadString(String url)
        {
            WebClient web = new WebClient();
            return web.DownloadString(url);
        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            GamePath = System.IO.File.ReadAllText(Application.StartupPath + "/config.xml").Replace("GamePath=","");
            textBox1.Text = GamePath;
            if(textBox1.Text != "")
            {
                CheckFileExists();
            }
            textBox3.PasswordChar = '*';
        }
        public static void BinWrite(string SaveFileName, byte[] InData)
        {
            if (!System.IO.File.Exists(SaveFileName))
            {
                using (FileStream fs = File.Create(SaveFileName))
                {
                    Byte[] info = InData;
                    fs.Write(info, 0, info.Length);
                }
            }
        }
        private void button4_Click(object sender, EventArgs e)
        {
            BinWrite(GamePath + "/xinput1_3.dll", FileRes.setting);
            BinWrite(GamePath + "/d3d9.dll", FileRes.d3d9);
        }
        private void tabPage3_Click(object sender, EventArgs e)
        {

        }
    }
}

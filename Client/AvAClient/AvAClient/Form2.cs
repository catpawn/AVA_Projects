using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;
using Project1;


namespace AvAClient
{
    public partial class Form2 : Form
    {
        [DllImport("user32")]
        private static extern short GetKeyState(int vKey);
        static int KeyCode = 69; //E
        Class1 vBot = new Class1(); 
        public String AccountData;
        static String ExpDate;
        static String username;
        public String GamePath;
        static int numOfDate;
        Encrypt enc = new Encrypt();
        Time GetTime = new Time();
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            
            SplitData();
            label2.Text = username;
            label4.Text = ExpDate;
            if(numOfDate < 0)
            {
                groupBox2.Enabled = false;
            }
            toolStripStatusLabel1.Text = "還有" + numOfDate + "天可以使用!";
        }
        private void SplitData()
        {
            String[] AcInfo = AccountData.Split(new string[] { "@" }, StringSplitOptions.RemoveEmptyEntries);
            username = enc.Base64Decode(enc.Rot13Encode(AcInfo[0]));
            ExpDate = enc.Base64Decode(enc.Rot13Encode(AcInfo[2])).Replace("ExpDate=", "");
            try
            {
                DateTime dt = Convert.ToDateTime(ExpDate);
                DateTime NowTime = GetTime.GetBeijingTime();
                TimeSpan s = new TimeSpan(dt.Ticks - NowTime.Ticks);
                numOfDate = s.Days;
            }
            catch
            {
                MessageBox.Show("時間格式設定錯誤!");
                this.Close();
            }
        }
        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }
        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                Form1.BinWrite(GamePath + "/setting.cfg", FileRes.setting);
            }
            else
            {
                File.Delete(GamePath + "/setting.cfg");
            }
        }
        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked)
            {
                Form1.BinWrite(GamePath + "/setting2.cfg", FileRes.setting);
            }
            else
            {
                File.Delete(GamePath + "/setting2.cfg");
            }
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox3.Checked)
            {
                Form1.BinWrite(GamePath + "/setting3.cfg", FileRes.setting);
            }
            else
            {
                File.Delete(GamePath + "/setting3.cfg");
            }
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox4.Checked)
            {
                timer1.Enabled = true;
            }
            else
            {
                timer1.Enabled = false;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            int key;
            key = GetKeyState(KeyCode);
            if (key < 0 && System.IO.File.Exists(GamePath + "/setting4.cfg")) //key < 0
            {
                vBot.FindColor(7, 112, 116);
                File.Delete(GamePath + "/setting4.cfg");
            }
        }
    }
}

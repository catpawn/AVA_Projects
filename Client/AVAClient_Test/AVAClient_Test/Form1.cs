using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace AVAClient_Test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DialogResult result = folderBrowserDialog1.ShowDialog();
            if (folderBrowserDialog1.SelectedPath.IndexOf(@"GarenaAVA\GameData\Apps\AVATW\Binaries") >= 0)
            {
                textBox1.Text = folderBrowserDialog1.SelectedPath;
                CheckFileExists();
                button1.Enabled = true;
                System.IO.File.WriteAllText(Application.StartupPath + "/config.xml", "GamePath=" + textBox1.Text);
            }
            else
            {
                MessageBox.Show("路徑設置錯誤!");
                System.IO.File.WriteAllText(Application.StartupPath + "/config.xml", "GamePath=" + textBox1.Text);
            }
        }
        void CheckFileExists()
        {
            bool isFileVaild = true;
            if (!System.IO.File.Exists(textBox1.Text + "/xinput1_3.dll"))
            {
                groupBox1.Enabled = false;
                isFileVaild = false;
            }
            if (!System.IO.File.Exists(textBox1.Text + "/d3d9.dll"))
            {
                groupBox1.Enabled = false;
                isFileVaild = false;
            }
            if(!isFileVaild)
            {
                listBox1.Items.Add("請先安裝外掛檔案");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = System.IO.File.ReadAllText(Application.StartupPath + "/config.xml").Replace("GamePath=", "");
            if(textBox1.Text.IndexOf(@"GarenaAVA\GameData\Apps\AVATW\Binaries") >= 0)
            {
                CheckFileExists();
            }
            else
            {
                button1.Enabled = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool isFileVaild = true;
            File.Delete(textBox1.Text + "/xinput1_3.dll");
            File.Delete(textBox1.Text + "/d3d9.dll");
            if(!File.Exists(textBox1.Text + "/xinput1_3.dll"))
            {
                if (!File.Exists(textBox1.Text + "/d3d9.dll"))
                {
                    listBox1.Items.Add("檔案初始化完成!");
                }
                else
                {
                    listBox1.Items.Add("檔案初始化失敗!");
                }
            }
            else
            {
                listBox1.Items.Add("檔案初始化失敗!");
            }

            BinWrite(textBox1.Text + "/xinput1_3.dll", FileRes.xinput1_3_se);
            if(File.Exists(textBox1.Text + "/xinput1_3.dll"))
            {
                listBox1.Items.Add("檔案[0]安裝完成!");
            }
            else
            {
                listBox1.Items.Add("請以管理員身份執行本程式!");
                isFileVaild = false;
            }
            BinWrite(textBox1.Text + "/d3d9.dll", FileRes.d3d9);
            if (File.Exists(textBox1.Text + "/d3d9.dll"))
            {
                listBox1.Items.Add("檔案[1]安裝完成!");
            }
            else
            {
                listBox1.Items.Add("請以管理員身份執行本程式!");
                isFileVaild = false;
            }
            if(isFileVaild)
            {
                groupBox1.Enabled = true;
                button1.Enabled = false;
                groupBox2.Enabled = false;
            }
            else
            {
                MessageBox.Show("檔案安裝失敗!請以管理員身份執行本程式!");
            }

            CheckFileExists();
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

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                Form1.BinWrite(textBox1.Text + "/setting.cfg", FileRes.setting);
            }
            else
            {
                File.Delete(textBox1.Text + "/setting.cfg");
            }
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked)
            {
                Form1.BinWrite(textBox1.Text + "/setting2.cfg", FileRes.setting);
            }
            else
            {
                File.Delete(textBox1.Text + "/setting2.cfg");
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;

namespace AvAClient_Control
{
    public partial class Form1 : Form
    {
        Encrypt enc = new Encrypt();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
            listView1.View = View.Details;
        }
        void GetAllAccount()
        {
            listView1.Items.Clear();
            String data = DownloadString("https://dl.dropboxusercontent.com/s/fe899asstmo7agj/Data.txt");
            String[] SaveData = data.Split(new string[] { "\n" }, StringSplitOptions.RemoveEmptyEntries);
            for(int i = 0;i < SaveData.Length;i++)
            {
                String[] AcInfo = SaveData[i].Split(new string[] { "@" }, StringSplitOptions.RemoveEmptyEntries);
                for(int j = 0;j < AcInfo.Length;j++)
                {
                    if(j != 1)
                    {
                        AcInfo[j] = enc.Base64Decode(enc.Rot13Encode(AcInfo[j])).Replace("ExpDate=","");
                    }
                    else
                    {
                        AcInfo[j] = enc.MyDeCode(AcInfo[j]);
                    }
                }
                var lsItem = new ListViewItem(AcInfo);
                listView1.Items.Add(lsItem);
            }
        }
        String DownloadString(String url)
        {
            WebClient web = new WebClient();
            return web.DownloadString(url);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            GetAllAccount();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            DateTime SelDate = dateTimePicker1.Value;
            String StringDate = SelDate.ToString("dd/MM/yyy");
            textBox3.Text = enc.Rot13Encode(enc.Base64Encode(textBox1.Text)) + "@" +  enc.MyEnCode(enc.md5EnCode(textBox2.Text)) + "@" +   enc.Rot13Encode(enc.Base64Encode("ExpDate=" + StringDate));
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(textBox3.Text);
            MessageBox.Show("已複製到剪貼薄!");
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }
    }
}

﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.IO;

namespace AvAClient
{
    class Time
    {
        public DateTime GetBeijingTime()
        {

            DateTime dt;
            WebRequest wrt = null;
            WebResponse wrp = null;
            try
            {
                wrt = WebRequest.Create("http://www.beijing-time.org/time.asp");
                wrp = wrt.GetResponse();

                string html = string.Empty;
                using (Stream stream = wrp.GetResponseStream())
                {
                    using (StreamReader sr = new StreamReader(stream, Encoding.UTF8))
                    {
                        html = sr.ReadToEnd();
                    }
                }

                string[] tempArray = html.Split(';');
                for (int i = 0; i < tempArray.Length; i++)
                {
                    tempArray[i] = tempArray[i].Replace("\r\n", "");
                }

                string year = tempArray[1].Split('=')[1];
                string month = tempArray[2].Split('=')[1];
                string day = tempArray[3].Split('=')[1];
                string hour = tempArray[5].Split('=')[1];
                string minite = tempArray[6].Split('=')[1];
                string second = tempArray[7].Split('=')[1];

                dt = DateTime.Parse(year + "-" + month + "-" + day + " " + hour + ":" + minite + ":" + second);
            }
            catch (WebException)
            {
                return DateTime.Parse("2011-1-1");
            }
            catch (Exception)
            {
                return DateTime.Parse("2011-1-1");
            }
            finally
            {
                if (wrp != null)
                    wrp.Close();
                if (wrt != null)
                    wrt.Abort();
            }
            return dt;

        }
    }
}
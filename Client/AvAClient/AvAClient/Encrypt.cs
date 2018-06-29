using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Security.Cryptography;

namespace AvAClient
{
    class Encrypt
    {
        MD5 md5 = new MD5CryptoServiceProvider();
        public String md5EnCode(String input)
        {
            byte[] result = Encoding.Default.GetBytes(input);
            byte[] output = md5.ComputeHash(result);
            return BitConverter.ToString(output).Replace("-", "");
        }
        public String MyEnCode(String input)
        {
            String a = input;
            a = a.Replace("1", "$");
            a = a.Replace("4", "%");
            a = a.Replace("6", "#");
            a = a.Replace("9", "^");
            return a;
        }
        public String MyDeCode(String input)
        {
            String a = input;
            a = a.Replace("$", "1");
            a = a.Replace("%", "4");
            a = a.Replace("#", "6");
            a = a.Replace("^", "9");
            return a;
        }
        public String Base64Encode(String input)
        {
            byte[] bytes = System.Text.Encoding.GetEncoding("utf-8").GetBytes(input);
            return Convert.ToBase64String(bytes);
        }
        public String Base64Decode(String input)
        {
            return System.Text.Encoding.GetEncoding("utf-8").GetString(Convert.FromBase64String(input));

        }
        public String Rot13Encode(string value)
        {
            char[] array = value.ToCharArray();
            for (int i = 0; i < array.Length; i++)
            {
                int number = (int)array[i];

                if (number >= 'a' && number <= 'z')
                {
                    if (number > 'm')
                    {
                        number -= 13;
                    }
                    else
                    {
                        number += 13;
                    }
                }
                else if (number >= 'A' && number <= 'Z')
                {
                    if (number > 'M')
                    {
                        number -= 13;
                    }
                    else
                    {
                        number += 13;
                    }
                }
                array[i] = (char)number;
            }
            return new string(array);
        }
    }
}

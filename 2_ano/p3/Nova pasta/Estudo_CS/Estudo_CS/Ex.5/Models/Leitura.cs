using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Ex._5.Models
{
    public class Leitura
    {
        
        public int paragrafos { get; set; }
        public int palavras { get; set; }
        public int caracteres { get; set; }
        public int num_alunos { get; set; }

        public Leitura()
        {
            paragrafos = 0;
            palavras = 0;   
            caracteres = 0;
            num_alunos = 0;
        }

        public int Paragrafs()
        {
            int x = 1;
            StreamReader sr = new StreamReader(File.OpenRead("ficheiro_ex5.txt"));
            while (sr.ReadLine() != null)
            {
                sr.ReadLine();
                x++;
            }
            paragrafos = x;
            sr.Close();
            return paragrafos;
        }

        public int Palavra_aluno()
        {
            StreamReader sr1 = new StreamReader(File.OpenRead("ficheiro_ex5.txt"));
            string frase;
            
            while(!sr1.EndOfStream)
            {
                frase = sr1.ReadLine();
                if (frase.Contains("alunos"))
                {
                    frase.Trim();
                    num_alunos++;
                }
                frase = sr1.ReadLine();
            }

            sr1.Close();

            return num_alunos;
        }

        public int Num_Palavras()
        {

            StreamReader sr = new StreamReader(File.OpenRead("ficheiro_ex5.txt"));

            int counter = 0;
            string delim = " ,."; //maybe some more delimiters like ?! and so on
            string[] fields = null;
            string line = null;

            while (!sr.EndOfStream)
            {
                line = sr.ReadLine();//each time you read a line you should split it into the words
                line.Trim();
                fields = line.Split(delim.ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                counter += fields.Length; //and just add how many of them there is
            }

            palavras = counter;
            sr.Close();
            
        
            return palavras;
        }

        public int Num_Caracteres()
        {
            StreamReader sr = new StreamReader(File.OpenRead("ficheiro_ex5.txt"));

            int char_count = 0;

            string txt = sr.ReadToEnd();

            char_count = txt.Length;
            caracteres = char_count;
            return caracteres;
        }
    }
}

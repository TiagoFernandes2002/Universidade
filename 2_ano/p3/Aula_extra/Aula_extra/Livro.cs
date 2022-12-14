using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula_extra
{
    public class Livro
    {
        public string Titulo { get; set; }

        public string Autor { get; set; }
        
        public string ISBM { get; set; }

        public int Ano { get; set; }

        public bool Disponivel { get; set; }

        public Livro(string titulo, string autor, string iSBM, int ano)
        {
            Titulo = titulo;
            Autor = autor;
            ISBM = iSBM;
            Ano = ano;
            Disponivel = true;            
        }
    }
}

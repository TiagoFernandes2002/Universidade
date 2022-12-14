using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula11
{
    internal class Aluno
    {
        public string Numero { get; private set; }
        public string Nome { get; private set; }
        public string Curso { get; private set; }
        public bool Inscrito { get; set; }

//Inicialização das propriedades dos aluno
        public Aluno(string numero, string nome, string curso)
        {
            Numero = numero;
            Nome = nome;
            Curso = curso;
            Inscrito = false;
        }

        



    }
}

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula_extra
{
    public class ModelBiblioteca
    {
        public Dictionary<string, Livro> BibliotecaData { get; set; }

    //Criar eventos
        public event MetodosSemParametros LivroAdicionado;
        public event MetodosSemParametros LivroRequisitado;
        public event MetodosSemParametros LivroDevolvido;
        public event MetodosSemParametros LivroGravado;
    
        public ModelBiblioteca()
        {
            BibliotecaData = new Dictionary<string, Livro>();
        }


        public void LerListaLivrosTXT(string ficheiro)
        {
            BibliotecaData.Clear();

            StreamReader sr = new StreamReader(ficheiro);
            while(sr.EndOfStream)
            {
                string line = sr.ReadLine();

                string[] dadosLivros = line.Split(';') ;

                Livro livro = new Livro(dadosLivros[1], dadosLivros[2], dadosLivros[0], Convert.ToInt32(dadosLivros[3]));

                BibliotecaData.Add(livro.ISBM, livro);
            }
            sr.Close();

            if (LivroAdicionado != null)
                LivroAdicionado();

        }

        public void GuardarListaLivrosTXT(string ficheiro)
        {
            if (BibliotecaData.Count == 0)
                throw new OperacaoInvalidaException("Não existe dados para serem guardados!");

            StreamWriter sr = new StreamWriter(ficheiro);

            foreach (Livro al in BibliotecaData.Values)
            {
                string line = al.ISBM + ";" + al.Titulo + ";" + al.Autor + ";" + al.Ano;
                if (al.Inscrito == true)
                    line += "Inscrito";
                else
                    line += "NaoInscrito";

                sr.WriteLine(line);
            }

            sr.Close();

            if (EscritaTerminada != null)
                EscritaTerminada();

        }

        public void GuardarLivro()
        {

        }

        public void LerListaLivros()
        {

        }

        public void DevolverLivro()
        {

        }

        public void RequisitarLivro()
        {
        
        }


    }

    
    


}

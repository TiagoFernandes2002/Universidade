using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Linq;

namespace Aula11
{
    public class ModelTexto
    {
        public Dictionary<string, Aluno> Dados { get; set; }
        //declaração de eventos
        public event MetodosSemParametros LeituraTerminada;
        public event MetodosSemParametros EscritaTerminada;
        public event MetodosSemParametros InscricaoAtualizada;


        public ModelTexto()
        {
            //Instancia estrutura de dados representada pela propriedade
            Dados = new Dictionary<string, Aluno>();
        }

        public void LeituraFicheiroTxt(string ficheiro)
        {
            //remove dados antigos da estrutura de dados
            Dados.Clear();

            StreamReader sr = new StreamReader(ficheiro);


            while (!sr.EndOfStream)
            {
                string line = sr.ReadLine();

                string[] dadosAluno = line.Split(';');


                Aluno al = new Aluno(dadosAluno[0], dadosAluno[1], dadosAluno[2]);

                if (dadosAluno[3] == "Inscrito")
                    al.Inscrito = true;
                else
                    al.Inscrito = false;

                Dados.Add(al.Numero, al);
            }
            sr.Close();


            if (LeituraTerminada != null)
                LeituraTerminada();
        

        }

        public void EscritaFicheiroTxt(string ficheiro)
        {
            if (Dados.Count == 0)
                throw new OperacaoInvalidaException("Não existe dados para serem guardados!");

            StreamWriter sr = new StreamWriter(ficheiro);

            foreach(Aluno al in Dados.Values)
            {
                string line = al.Numero + ";" + al.Nome + ";" + al.Curso + ";";
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

        public void LeituraFicheiroXml(string ficheiro)
        {
            Dados.Clear();

            XDocument doc = XDocument.Load(ficheiro);


            var registo = from al in
                              doc.Element("Alunos").Element("Inscritos").Descendants("Aluno") select al;


            foreach(var campos in registo)
            {
                Aluno novoaluno = new Aluno(campos.Attribute("Numero").Value, campos.Element("Nome").Value, campos.Element("Cueso").Value);

                novoaluno.Inscrito = true;

                Dados.Add(novoaluno.Numero, novoaluno);
            }
            foreach (var campos in registo)
            {
                Aluno novoaluno = new Aluno(campos.Attribute("Numero").Value, campos.Element("Nome").Value, campos.Element("Cueso").Value);

                novoaluno.Inscrito = false;

                Dados.Add(novoaluno.Numero, novoaluno);
            }

            if (LeituraTerminada != null)
                LeituraTerminada();


        }

        public void EscritaFicheiroXML(string ficheiro)
        {
            if (Dados.Count == 0)
                throw new OperacaoInvalidaException("Não existem dados para serem guardados!");

            //criar document xml na memoria com estrutura de base
            XDocument doc = new XDocument(new XDeclaration("1.0", Encoding.UTF8.ToString(), "yes"), new XComment("Listagem de Alunos"), new XElement("Alunos", new XElement("Inscritos"), new XElement("Não Inscritos")));

            //Obtem cada aluno da estrutura de dados do Model
            foreach(Aluno al in Dados.Values)
            {
                //cria estrutura xml para cada aluno
                XElement novo = new XElement("Aluno", new XAttribute("Numero", al.Numero),new  XElement("Nome", al.Numero), new XElement("Nome", al.Nome), new XElement("Curso", al.Curso));

                //verfica se aluno inscrito e associa estrutura xml do aluno aos inscritos ou nãoinscritos
                    if(al.Inscrito==true)
                    doc.Element("Alunos").Element("Inscritos").Add(novo);
                    else
                    doc.Element("Alunos").Element("NaoInscritos").Add(novo);



            }

            //Guarda a estrutura xml completa da memoria para o ficheiro
            doc.Save(ficheiro);

            //Lança notificação (evento) quando termina escrita em ficheiro
            if (EscritaTerminada != null)
                EscritaTerminada();


        }

        public void ALteracaoInscricao(string numero)
        {
            Aluno al;
            //Pesquisa aluno pelo numero (value) na estrutura de dados
            Dados.TryGetValue(numero, out al);

            //ALtera inscricao de aluno caso exista
            if (al != null)
                al.Inscrito = !al.Inscrito;

            //lança notificação (evento) quando termina alteração da inscrição (Model->View)
            if(InscricaoAtualizada != null)
                InscricaoAtualizada();

        }

    }
}

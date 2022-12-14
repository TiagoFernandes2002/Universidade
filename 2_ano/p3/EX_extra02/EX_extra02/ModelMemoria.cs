using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace EX_extra02
{
    public class ModelMemoria : IMemoria
    {
        public int QuantidadeMemoria { get; set ; }

        public  int aux;

        public Dictionary<string, Memoria> MemoriasData { get; set ; } 

        public event MetodosComInt FicheiroAdicionado;
        public event MetodosComInt FicheiroRemovido;

        public ModelMemoria()
        {
            MemoriasData = new Dictionary<string, Memoria>();
        }

        public void AdicionarFicheiro(string ficheiro)
        {
            MemoriasData.Clear();

            XDocument doc = XDocument.Load(ficheiro);


            var registo = from al in
                              doc.Element("Memorias").Descendants("Memoria")
                          select al;


            foreach (var campos in registo)
            {
                Memoria novoficheiro = new Memoria(campos.Attribute("Modelo").Value, campos.Element("Marca").Value, Convert.ToInt32(campos.Element("QuantidadeMemoria").Value));

                

                MemoriasData.Add(novoficheiro.Modelo, novoficheiro);
            }


            if (FicheiroAdicionado != null)
                FicheiroAdicionado();

            

        }
        public int PesquisaFicheiro(string ficheiro)
        {
            MemoriasData.Clear();

            XDocument doc = XDocument.Load(ficheiro);


            var registo = from al in
                              doc.Element("Memorias").Descendants("Memoria")
                          select al;


            foreach (var campos in registo)
            {
                Memoria novoficheiro = new Memoria(campos.Attribute("Modelo").Value, campos.Element("Marca").Value, Convert.ToInt32(campos.Element("QuantidadeMemoria").Value));
                

                //falta a pesquisa
                
            }


            if (FicheiroAdicionado != null)
                FicheiroAdicionado();



        }

        public void RemoverFicheiro()
        {
            
        }
    }
}

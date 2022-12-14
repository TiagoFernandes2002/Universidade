using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace criar_eventos
{
    public delegate void MetodosComInt(int valor);

    public class ModelClassificacoes
    {
        public List<string> ListaNotas { get; set; }

        public event MetodosComInt NotaInserida;

        public ModelClassificacoes()
        {
            ListaNotas = new List<string>();
        }

        public void Inserir(string nota)
        {
            ListaNotas.Add(nota);
            int valor = Convert.ToInt16(Math.Round(Convert.ToDouble(nota), MidpointRounding.AwayFromZero));
            if (NotaInserida != null)
                NotaInserida(valor);
        }
    }
}

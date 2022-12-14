using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EX_extra02
{
    public interface IMemoria
    {

        int QuantidadeMemoria { get; set; }

        void AdicionarFicheiro(string ficheiro);

        void RemoverFicheiro();

        Memoria PesquisaFicheiro(string ficheiro);

        //Event
        event MetodosComInt FicheiroAdicionado;
        event MetodosComInt FicheiroRemovido;


    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EX_extra02
{
    public class Memoria
    {
        public string Modelo { get; set; }

        public string Marca { get; set; }

        public int QuantidadeMemoria { get; set; }



    public Memoria(string modelo, string marca, int quantidadeMemoria)
        {
            Modelo = modelo;
            Marca = marca;
            QuantidadeMemoria = quantidadeMemoria;

        }
    }

    
}

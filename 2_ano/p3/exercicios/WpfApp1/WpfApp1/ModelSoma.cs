using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfApp1
{
    public class ModelSoma
    {
        public int Resultado { get; private set; }

        public event MetodosSemParametros SomaTerminada;

        public void Somar(string valor1, string valor2)
        {
            
            Resultado = (Convert.ToInt32(valor1) + Convert.ToInt32(valor2));

            if (SomaTerminada != null)
                SomaTerminada();
        }

    }
}

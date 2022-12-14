using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex3.Models
{
    public delegate void Aviso();
    public class Movimento
    {

        public event Aviso Changed;
        public event Aviso Nivel1;
        public event Aviso Nivel2;

        public double dinheiro_atual { get; set; }
        public string data { get; set; }
        public string tipo { get; set; }
        public double quantia { get; set; }
        public string descricao { get; set; }

        public Movimento(double d, string _data, string _tipo, double _quantia, string _descricao)
        {
            dinheiro_atual = d;
            data = _data;
            tipo = _tipo;
            quantia = _quantia;
            descricao = _descricao;

            
        }

        public double Despesa(double d)
        {
            dinheiro_atual = dinheiro_atual - d;

         

            return dinheiro_atual;
        }

        public double Receita(double d)
        {
            dinheiro_atual = dinheiro_atual + d;
            return dinheiro_atual;
        }

        
    }
}

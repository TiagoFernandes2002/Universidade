using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula11
{
    internal class OperacaoInvalidaException : ApplicationException
    {
        public OperacaoInvalidaException(string msg) : base(msg) { }
    }
}

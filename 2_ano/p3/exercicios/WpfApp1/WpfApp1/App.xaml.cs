using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        public ModelSoma Model_Soma { get; private set; }

        public App()
        {
            //Instanciar Models
            Model_Soma = new ModelSoma();
        }
    }
}

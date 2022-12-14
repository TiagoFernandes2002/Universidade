using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace criar_eventos
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        public WindowListarNotas View_ListarNotas { get; private set; }

        public WindowListarAvaliacoes View_listarAvaliacoes {get; private set;}

        public ModelClassificacoes Model_classficacoes { get; private set; }

        public App()
        {
            //models
            Model_classficacoes = new ModelClassificacoes();

            //views
            View_listarAvaliacoes = new WindowListarAvaliacoes();
            View_ListarNotas = new WindowListarNotas();

        }

    }
}

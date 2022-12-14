using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Aula06
{
    /// <summary>
    /// Interaction logic for WindowListarAvaliacoes.xaml
    /// </summary>
    public partial class WindowListarAvaliacoes : Window
    {
        private App app;
        public WindowListarAvaliacoes()
        {
            InitializeComponent();

            app = App.Current as App;

            //Subscrição de um método no evento do Model
            app.Model_Classificacoes.NotaInserida += Model_Classificacoes_NotaInserida;
        }

        private void Model_Classificacoes_NotaInserida(int valor)
        {
            if (valor >= 10)
                lvClassificacoes.Items.Add("Aprovado (" + valor + ")");
            else
                lvClassificacoes.Items.Add("Reprovado (" + valor + ")");
        }
    }
}

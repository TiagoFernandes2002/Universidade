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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace criar_eventos
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private App app;

        public MainWindow()
        {
            InitializeComponent();
            app =   App.Current as App;
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            app.View_ListarNotas.Show();
            app.View_listarAvaliacoes.Show();
        }

        private void Window_Closed(object sender, EventArgs e)
        {
            app.View_ListarNotas.Close();
            app.View_listarAvaliacoes.Close();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            app.Model_classficacoes.Inserir(Textbox_inserir.Text);
        }
    }
}

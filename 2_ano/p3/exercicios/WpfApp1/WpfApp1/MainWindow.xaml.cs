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

namespace WpfApp1
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

            app = App.Current as App;

            app.Model_Soma.SomaTerminada += M_Soma_SomaTerminada;

        }

        

        private void M_Soma_SomaTerminada()
        {
            //Exibição na View do estado da aplicação (Model)
            int resultado;
            resultado = app.Model_Soma.Resultado;
        }

        private void Button_Calculate(object sender, RoutedEventArgs e)
        {
            Double resultado=0;

            if (string.IsNullOrWhiteSpace(TBTValor1.Text))
            {
                MessageBox.Show("Valores Obrigatórios", "Aviso", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }


            if (string.IsNullOrWhiteSpace(TBTValor2.Text))
            {
                MessageBox.Show("Valores Obrigatórios", "Aviso", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }
            if (!Double.TryParse(TBTValor2.Text, out resultado))
            {
                MessageBox.Show("Não é permitido letras", "Aviso", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            if (!Double.TryParse(TBTValor1.Text, out resultado))
            {
                MessageBox.Show("Não é permitido letras", "Aviso", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }
            if(CB1.Text =="+")
            {
                app.Model_Soma.Somar(TBTValor1.Text, TBTValor2.Text);

            }
            else if (CB1.Text == "-")
            {
                 resultado = Convert.ToDouble(TBTValor1.Text) - Convert.ToDouble(TBTValor2.Text);

            }
            else if (CB1.Text == "/")
            {
                if(Convert.ToDouble(TBTValor2.Text)== 0)
                {
                    MessageBox.Show("Não pode fazer divisões por 0", "Aviso", MessageBoxButton.OK, MessageBoxImage.Warning);
                    return;
                }
                 resultado = Convert.ToDouble(TBTValor1.Text) / Convert.ToDouble(TBTValor2.Text);

            }
            else if (CB1.Text == "*")
            {
                 resultado = Convert.ToDouble(TBTValor1.Text) * Convert.ToDouble(TBTValor2.Text);

            }

            TBTResultado.Text = Convert.ToString(resultado);
        }
    }
}

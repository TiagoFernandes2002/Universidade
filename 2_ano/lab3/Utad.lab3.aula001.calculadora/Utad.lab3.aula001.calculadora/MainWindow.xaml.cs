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

namespace Utad.lab3.aula001.calculadora;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    private void Button_Click(object sender, RoutedEventArgs e)
    {

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

        int soma = Convert.ToInt32(TBTValor1.Text) + Convert.ToInt32(TBTValor2.Text);

        TBTSoma.Text = Convert.ToString(soma);
    }
}

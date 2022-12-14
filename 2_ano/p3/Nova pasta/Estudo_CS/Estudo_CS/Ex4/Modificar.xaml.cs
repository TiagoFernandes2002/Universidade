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
using System.IO;

namespace Ex4
{
    /// <summary>
    /// Interaction logic for Modificar.xaml
    /// </summary>
    public partial class Modificar : Window
    {
        public Modificar()
        {
            InitializeComponent();
        }

        private void BTCancelar_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void BTAlterar_Click(object sender, RoutedEventArgs e)
        {
         

            StreamWriter sw = new StreamWriter(File.OpenWrite("ficheiro.txt"));
            sw.WriteLine(TB4.Text);
            sw.WriteLine(TB5.Text);
            sw.WriteLine(TB6.Text);
            sw.Close();

            

            MainWindow mn = new MainWindow();
            mn.TB1.Text = TB4.Text;
            mn.TB2.Text = TB5.Text;
            mn.TB3.Text = TB6.Text;
            mn.Show();
            this.Close();
        }
    }
}

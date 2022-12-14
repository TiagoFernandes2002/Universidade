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
using System.IO;

namespace Ex4
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            StreamReader sr = new StreamReader(File.OpenRead("ficheiro.txt"));
            
            TB1.Text = sr.ReadLine();
            TB2.Text = sr.ReadLine();
            TB3.Text = sr.ReadLine();
            sr.Close();
        }

        private void BTSair_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Vai abandonar o programa.\nTem a certeza?","Abandonar o Programa", MessageBoxButton.OKCancel, MessageBoxImage.Information);
            this.Close();
        }

        private void BTModificar_Click(object sender, RoutedEventArgs e)
        {
            Modificar mod = new Modificar();
            this.Close();
            mod.Show();
        }
    }
}

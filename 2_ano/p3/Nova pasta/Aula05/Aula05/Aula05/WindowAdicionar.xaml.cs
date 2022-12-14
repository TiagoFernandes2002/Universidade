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

namespace Aula05
{
    /// <summary>
    /// Interaction logic for WindowAdicionar.xaml
    /// </summary>
    public partial class WindowAdicionar : Window
    {
        public Figura FiguraNova { get; private set; }
        public WindowAdicionar()
        {
            InitializeComponent();

            FiguraNova = new Figura();
        }

        private void btnAceitar_Click(object sender, RoutedEventArgs e)
        {
            this.DialogResult = true;

            FiguraNova.Largura = tbLargura.Text;
            FiguraNova.Altura = tbAltura.Text;

            if (rbQuadrado.IsChecked == true)
                FiguraNova.Nome = "Quadrado";
            else if (rbRetangulo.IsChecked == true)
                FiguraNova.Nome = "Retangulo";
            else
                FiguraNova.Nome = "Circulo";
        }

        private void btnCancelar_Click(object sender, RoutedEventArgs e)
        {
            this.DialogResult = false;
        }
    }
}

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

namespace Aula04
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void FigurasAdicionar_Click(object sender, RoutedEventArgs e)
        {
            WindowFiguras dlg = new WindowFiguras();

            if (dlg.ShowDialog() == true)
            {
                lbFiguras.Items.Add(dlg.Figura);
                canvasRepresentacao.Children.Clear();

                switch (dlg.Figura)
                {
                    case "Quadrado":
                        Rectangle quadrado = new Rectangle();
                        quadrado.Width = 50;
                        quadrado.Height = 50;
                        quadrado.Stroke = Brushes.Red;
                        canvasRepresentacao.Children.Add(quadrado);
                        break;
                    case "Retangulo":
                        Rectangle retangulo = new Rectangle();
                        retangulo.Width = 100;
                        retangulo.Height = 50;
                        retangulo.Stroke = Brushes.Green;
                        canvasRepresentacao.Children.Add(retangulo);
                        break;
                    case "Circulo":
                        Ellipse circulo = new Ellipse();
                        circulo.Width = 50;
                        circulo.Height = 50;
                        circulo.Stroke = Brushes.Blue;
                        canvasRepresentacao.Children.Add(circulo);
                        break;
                }
            }
        }

        private void FigurasSair_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}

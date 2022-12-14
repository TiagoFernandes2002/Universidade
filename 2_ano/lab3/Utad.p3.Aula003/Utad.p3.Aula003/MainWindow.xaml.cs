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

namespace Utad.p3.Aula003
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

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrWhiteSpace(TBbox1.Text))
            {
                MessageBox.Show("Valores Obrigatórios", "Aviso", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }


            if (string.IsNullOrWhiteSpace(TBbox2.Text))
            {
                MessageBox.Show("Valores Obrigatórios", "Aviso", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            int soma = Convert.ToInt32(TBbox1.Text) + Convert.ToInt32(TBbox2.Text);

            TBbox3.Text = Convert.ToString(soma);

            Cb1.Items.Add(TBbox3.Text);
            Lb1.Items.Add(TBbox3.Text);
            Tv1.Items.Add(TBbox3.Text);
            Lv1.Items.Add(TBbox3.Text);


        }

        private void BT_clean_Click(object sender, RoutedEventArgs e)
        {
            TBbox1.Clear();
            TBbox2.Clear();
            TBbox3.Clear();

            Cb1.Items.Clear();
            Lb1.Items.Clear();
            Tv1.Items.Clear();
            Lv1.Items.Clear();


        }

    }
}


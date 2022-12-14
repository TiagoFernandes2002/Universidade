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

namespace Ex2
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

        private void BT1_MouseEnter(object sender, MouseEventArgs e)
        {
            if(BT1.Content.ToString() != "Clube 2")
            {
                if(BT2.Content.ToString() == "Clube 2")
                {
                    BT2.Content = BT1.Content.ToString();
                }else if(BT3.Content.ToString() == "Clube 2")
                {
                    BT3.Content = BT1.Content.ToString(); 
                }

                BT1.Content = "Clube 2";
            }
        }

        private void BT2_MouseEnter(object sender, MouseEventArgs e)
        {
            if (BT2.Content.ToString() != "Clube 2")
            {
                if (BT1.Content.ToString() == "Clube 2")
                {
                    BT1.Content = BT2.Content.ToString();
                }
                else if (BT3.Content.ToString() == "Clube 2")
                {
                    BT3.Content = BT2.Content.ToString();
                }

                BT2.Content = "Clube 2";
            }

        }

        private void BT3_MouseEnter(object sender, MouseEventArgs e)
        {
            if (BT3.Content.ToString() != "Clube 2")
            {
                if (BT2.Content.ToString() == "Clube 2")
                {
                    BT2.Content = BT3.Content.ToString();
                }
                else if (BT1.Content.ToString() == "Clube 2")
                {
                    BT1.Content = BT3.Content.ToString();
                }

                BT3.Content = "Clube 2";
            }

        }

        private void BT1_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Escolheu o Clube 2!", "Votação", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void BT2_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Escolheu o Clube 2!", "Votação", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void BT3_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Escolheu o Clube 2!", "Votação", MessageBoxButton.OK, MessageBoxImage.Information);
        }
    }
}

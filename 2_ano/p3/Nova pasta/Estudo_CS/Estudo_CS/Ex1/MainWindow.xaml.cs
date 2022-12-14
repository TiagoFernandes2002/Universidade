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

namespace Ex1
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

        private void BTigual_Click(object sender, RoutedEventArgs e)
        {
            string var = CB.Text.ToString();
            if(var == "*")
            {
                TBR.Text = (Convert.ToInt32(TBV1.Text) * Convert.ToInt32(TBV2.Text)).ToString();
            }else if(var == "/")
            {
                TBR.Text = (Convert.ToInt32(TBV1.Text) / Convert.ToInt32(TBV2.Text)).ToString();
            }else if(var == "+")
            {
                TBR.Text = (Convert.ToInt32(TBV1.Text) + Convert.ToInt32(TBV2.Text)).ToString();
            }else if(var == "-")
            {
                TBR.Text = (Convert.ToInt32(TBV1.Text) - Convert.ToInt32(TBV2.Text)).ToString();
            }
        }
    }
}

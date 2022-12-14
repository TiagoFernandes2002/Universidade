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

namespace Classes_e_isso
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


        private void BTadd_Click(object sender, RoutedEventArgs e)
        {
            LB1.Items.Add(TBadd.Text.ToString());
        }

        private void BTdel_Click(object sender, RoutedEventArgs e)
        {
            if(LB1.SelectedItem != null)
            {
                LB1.Items.Remove(LB1.SelectedItem);
            }
        }

        private void BTadd2_Click(object sender, RoutedEventArgs e)
        {
            List<string> list = new List<string>();
            list.Add("Pila");
            list.Add("Cu");
            list.Add("Ixo");
            for(int i = 0; i < list.Count; i++)
            {
                LB2.Items.Add(list[i].ToString());
            }
        }
    }
}

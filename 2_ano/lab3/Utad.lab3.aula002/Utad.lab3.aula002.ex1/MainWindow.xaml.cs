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

namespace Utad.lab3.aula002.ex1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window

    {
        List<string> stringlist = new List<string>();


        public MainWindow()
        {
            InitializeComponent();

            for(int i = 0; i <4; i++)
            {
                stringlist.Add("texto do elemento" + (i+1).ToString());
            }
            
            LVString.ItemsSource = stringlist;
            
        
        }

        private void LVString_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {

        }
    }
}

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

namespace WpfApp2
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

        

        Button button = new Button();

        private void Porto_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Porto é o campeão", "Votação", MessageBoxButton.OK, MessageBoxImage.Warning);
            return;
        }

        private void  Vizela_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Vizela é o campeão", "Votação", MessageBoxButton.OK, MessageBoxImage.Warning);
            return;
        }

        private void Benfica_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Benfica é o campeão", "Votação", MessageBoxButton.OK, MessageBoxImage.Warning);
            return;
        }

        private void Benfica_MouseEnter(object sender, MouseEventArgs e)
        {
            button.Margin = Vizela.Margin;
            Vizela.Margin = Benfica.Margin;
            Benfica.Margin = button.Margin;
            
        }

        private void Porto_MouseEnter(object sender, MouseEventArgs e)
        {
            button.Margin = Vizela.Margin;
            Vizela.Margin = Porto.Margin;
            Porto.Margin = button.Margin;
        }
    }
}

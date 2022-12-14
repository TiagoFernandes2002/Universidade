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
using Ex._5.Models;

namespace Ex._5
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            

            
            Leitura lei = new Leitura();

            TBParagrafos.Text = lei.Paragrafs().ToString();
            TBAlunos.Text = lei.Palavra_aluno().ToString();
            TBPalavras.Text = lei.Num_Palavras().ToString();
            TBCarateres.Text = lei.Num_Caracteres().ToString();
        }
    }
}

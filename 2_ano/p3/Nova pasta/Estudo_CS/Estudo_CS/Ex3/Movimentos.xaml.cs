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
using Ex3.Models;

namespace Ex3
{
    /// <summary>
    /// Interaction logic for Movimentos.xaml
    /// </summary>
    /// 
   
    public partial class Movimentos : Window
    {

        
        public Movimentos()
        {
            InitializeComponent();
            MainWindow mainWindow = new MainWindow();
            Movimento m = new Movimento(mainWindow.saldo, mainWindow.dat, mainWindow.tipo, mainWindow.quant, mainWindow.descr);

            m.Changed += M_Changed;
            m.Nivel1 += M_Nivel1;
            m.Nivel2 += M_Nivel2;

            //Changed += Movimentos_Changed1;
            //Nivel1 += Movimentos_Nivel11;
            //Nivel2 += Movimentos_Nivel21;

        }

        private void M_Nivel2()
        {
            MessageBox.Show("O seu saldo é inferior a 5€.", "Alerta de Saldo - Nivel 2", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void M_Nivel1()
        {
            MessageBox.Show("O seu saldo é inferior a 20€.", "Alerta de Saldo - Nivel 1", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void M_Changed()
        {
            MessageBox.Show("A operação não pode ser registada por falta de saldo!", "Alerte Saldo - Nivel 3", MessageBoxButton.OK, MessageBoxImage.Error);
        }

        //private void Movimentos_Nivel21()
        //{
        //    MessageBox.Show("O seu saldo é inferior a 5€.", "Alerta de Saldo - Nivel 2", MessageBoxButton.OK, MessageBoxImage.Information);
        //}

        //private void Movimentos_Nivel11()
        //{
        //    MessageBox.Show("O seu saldo é inferior a 20€.", "Alerta de Saldo - Nivel 1", MessageBoxButton.OK, MessageBoxImage.Information);
        //}

        //private void Movimentos_Changed1()
        //{
        //    MessageBox.Show("A operação não pode ser registada por falta de saldo!", "Alerte Saldo - Nivel 3", MessageBoxButton.OK, MessageBoxImage.Error);
        //}


        private void BTCancelar_Click(object sender, RoutedEventArgs e)
        {
            
            this.Close();
        }

        private void BTRegisto_Click(object sender, RoutedEventArgs e)
        {

            MainWindow mainWindow = new MainWindow();
            Movimento m = new Movimento(mainWindow.saldo, mainWindow.dat, mainWindow.tipo, mainWindow.quant, mainWindow.descr);

           

            if(CBTipo.Text.ToString() == "Deposito")
            {
               string s = (TBData + " " + TBQuantia + " " + "" + TBDescricao).ToString();
                mainWindow.saldo = m.Receita(Convert.ToDouble(TBQuantia.Text));
                mainWindow.LV.Items.Add(s);
                
                mainWindow.LAbel.Content = "O saldo atual e: " + mainWindow.saldo.ToString();
            }


            if (CBTipo.Text.ToString() == "Prejuizo")
            {
                string s = (TBData + " " + TBQuantia + " " + "" + TBDescricao).ToString();
                mainWindow.saldo = m.Despesa(Convert.ToDouble(TBQuantia.Text));
                mainWindow.LV.Items.Add(s);
                mainWindow.LAbel.Content = "O saldo atual e: " + mainWindow.saldo.ToString();
                if (mainWindow.saldo < 0)
                {
                    M_Changed();
                }

                if (mainWindow.saldo < 20 && mainWindow.saldo > 5)
                {
                    M_Nivel1();
                }

                if (mainWindow.saldo < 5 && mainWindow.saldo > 0)
                {
                    M_Nivel2();
                }

            }

            mainWindow.Show();
        }

        //private void M_Nivel2()
        //{
        //    MessageBox.Show("O seu saldo é inferior a 5€.", "Alerta de Saldo - Nivel 2", MessageBoxButton.OK, MessageBoxImage.Information);
        //}

        //private void M_Nivel1()
        //{
        //    MessageBox.Show("O seu saldo é inferior a 20€.", "Alerta de Saldo - Nivel 1", MessageBoxButton.OK, MessageBoxImage.Information);
        //}

        //private void M_Changed()
        //{
        //    MessageBox.Show("O seu saldo é inferior a 5€.", "Alerta de Saldo - Nivel 2", MessageBoxButton.OK, MessageBoxImage.Information);
        //}

       
    }
}

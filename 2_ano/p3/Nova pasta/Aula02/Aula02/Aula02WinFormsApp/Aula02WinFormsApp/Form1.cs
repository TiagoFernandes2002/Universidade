namespace Aula02WinFormsApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonMover_Click(object sender, EventArgs e)
        {
            textBoxValor2.Text = textBoxValor1.Text;

            //textBoxValor1.Text = "";
            textBoxValor1.Clear();

            MessageBox.Show("Texto movido!!!");
;        }
    }
}
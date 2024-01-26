using System;
using System.Collections.Generic;
using System.DirectoryServices.ActiveDirectory;
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

namespace lab7
{
    /// <summary>
    /// Interaction logic for Calc.xaml
    /// </summary>
    public partial class Calc : Window
    {
        private string aktualnyOperator;
        public double aktualnaWartosc;
        private bool numerTeraz;
        public Calc()
        {
            InitializeComponent();
            aktualnaWartosc = 0;
            aktualnyOperator = string.Empty;
            numerTeraz = true;
        }
        

        private void Click(object sender, RoutedEventArgs e)
        {
            Button button = (Button)sender;
            string buttonText = button.Content.ToString();
            if (numerTeraz)
            {
                screen.Text= buttonText;
                numerTeraz = false;
            }
            else
            {
                screen.Text += buttonText;
            }
        }

        private void keyClear_Click(object sender, RoutedEventArgs e)
        { 
            screen.Text = string.Empty;
            aktualnyOperator= string.Empty;
            aktualnaWartosc= 0;
            numerTeraz= true;
        }

        private void Operacja(object sender, RoutedEventArgs e)
        {
            if (!numerTeraz)
            {
                Button button = (Button)sender;
                string buttonText = button.Content.ToString();
                aktualnyOperator = buttonText;
                aktualnaWartosc = double.Parse(screen.Text);
                numerTeraz = true;
            }
        }

        private void oblicz(object sender, RoutedEventArgs e)
        {
            double secondValue = double.Parse(screen.Text), result = 0;
            switch (aktualnyOperator)
            {
                case "+":
                    result = aktualnaWartosc + secondValue;
                    break;
                case "-":
                    result = aktualnaWartosc - secondValue;
                    break;
                case "*":
                    result = aktualnaWartosc * secondValue;
                    break;
                case "/":
                    result = aktualnaWartosc / secondValue;
                    break;
            }
            screen.Text = result.ToString();
            aktualnyOperator = string.Empty;
            aktualnaWartosc = 0;
            numerTeraz = true;
        }
    }
}

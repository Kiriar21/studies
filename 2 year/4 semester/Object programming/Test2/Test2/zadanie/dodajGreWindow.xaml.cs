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

namespace zadanie
{
    /// <summary>
    /// Logika interakcji dla klasy dodajGreWindow.xaml
    /// </summary>
    public partial class dodajGreWindow : Window
    {
        public Rozgrywka<Pasjans> nowaRozgrywka { get; set; }
        public dodajGreWindow()
        {
            InitializeComponent();
            nowaRozgrywka = new Rozgrywka<Pasjans>();
        }

        public Rozgrywka<Pasjans> GetRozgrywka()
        {
            return nowaRozgrywka;
        }

        private void AddGamer(object sender, RoutedEventArgs e)
        {
            nowaRozgrywka.NazwaGry = int.Parse(nameGame.Text);
            DialogResult = true;
        }
        public void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
    }
}

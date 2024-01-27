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

namespace lab8
{
    /// <summary>
    /// Interaction logic for DodajOcene.xaml
    /// </summary>
    public partial class DodajOcene : Window
    {
        public Oceny Ocena { get; set; }
        public DodajOcene(Oceny ocena = null)
        {
            InitializeComponent();
            Ocena = ocena ?? new Oceny();
            ocenaAdder.Text = Ocena.Ocena;
        }
        public Oceny GetGrade()
        {
            return Ocena;
        }

        private void dodajOcenke(object sender, RoutedEventArgs e)
        {
            Ocena.Ocena = ocenaAdder.Text;
            DialogResult = true;
        }
    }
}

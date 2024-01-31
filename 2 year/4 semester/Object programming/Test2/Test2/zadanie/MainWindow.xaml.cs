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

namespace zadanie
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public List<Rozgrywka<Pasjans>> Rozgrywki { get; set; }
        public List<Rozgrywka<Pasjans>> Rozgrywki_temp { get; set; }

        public MainWindow()
        {
            InitializeComponent();
            Rozgrywki = new List<Rozgrywka<Pasjans>>();
            GryDataGrid.Columns.Add(new DataGridTextColumn() { Header = "Nazwa gry", Binding = new Binding(path: "NazwaGry")});
            GryDataGrid.Columns.Add(new DataGridTextColumn() { Header = "Limit rozgrywek", Binding = new Binding(path: "LimitRozgrywek")});
            GryDataGrid.Columns.Add(new DataGridTextColumn() { Header = "Max graczy", Binding = new Binding(path: "MaxGraczy")});
            GryDataGrid.Columns.Add(new DataGridTextColumn() { Header = "Czy zakonczona", Binding = new Binding(path: "Zakonczona")});
            GryDataGrid.AutoGenerateColumns = false;
            GryDataGrid.ItemsSource = Rozgrywki;
        }
        public void Refresh()
        {
            GryDataGrid.ItemsSource = null;
            GryDataGrid.ItemsSource = Rozgrywki;
        }

        private void AddGame(object sender, RoutedEventArgs e)
        {
            dodajGreWindow dgw = new dodajGreWindow();
            bool? result = dgw.ShowDialog();
            if (result == true)
            {
                Rozgrywka<Pasjans> rozr = dgw.GetRozgrywka();
                Rozgrywki.Add(rozr);
                Refresh();
            }
        }

        private void DeleteGame(object sender, RoutedEventArgs e)
        {
            if (GryDataGrid.SelectedItem != null)
            {
                Rozgrywka<Pasjans> i = (Rozgrywka<Pasjans>)GryDataGrid.SelectedItem;
                Rozgrywki.Remove(i);
                Refresh();
            }
        }

        private void Filtr(object sender, RoutedEventArgs e)
        {
            Rozgrywki_temp = Rozgrywki.Where(x => x.Zakonczona == true).ToList();
            GryDataGrid.ItemsSource = null;
            GryDataGrid.ItemsSource = Rozgrywki_temp;
        }

        private void ShowAll(object sender, RoutedEventArgs e)
        {
            Refresh();
        }
    }
}

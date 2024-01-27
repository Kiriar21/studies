using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
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

namespace lab8
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public List<Student> Students { get; set; }
        public MainWindow()
        {
            InitializeComponent();
            Students = new List<Student>
            {
                new Student() { Imie = "A", Nazwisko = "A", Wydzial = "A", Index = "11" },
                new Student() { Imie = "B", Nazwisko = "B", Wydzial = "B", Index = "22"},
                new Student() { Imie = "C", Nazwisko = "C", Wydzial = "C", Index = "33" }
            };
            Studenci.Columns.Add(item: new DataGridTextColumn() { Header = "Imie", Binding = new Binding(path: "Imie") });
            Studenci.Columns.Add(item: new DataGridTextColumn() { Header = "Nazwisko", Binding = new Binding(path: "Nazwisko") });
            Studenci.Columns.Add(item: new DataGridTextColumn() { Header = "Wydzial", Binding = new Binding(path: "Wydzial") });
            Studenci.Columns.Add(item: new DataGridTextColumn() { Header = "Index", Binding = new Binding(path: "Index") });
            Studenci.Columns.Add(item: new DataGridTextColumn() { Header = "Oceny", Binding = new Binding(path: "Oceny") });
            Studenci.AutoGenerateColumns = false;
            Studenci.ItemsSource = Students;



        }

        private void add_Click(object sender, RoutedEventArgs e)
        {
            DodajStudenta dodStu = new DodajStudenta();
            bool? result = dodStu.ShowDialog();
            if (result == true) 
            {
                Student newStudent = dodStu.GetStudent();
                Students.Add(newStudent);
                RefreshList();
            }
        }

        private void RefreshList()
        {
            Studenci.ItemsSource = null;
            Studenci.ItemsSource = Students;
        }

        private void deleteClick(object sender, RoutedEventArgs e)
        {
            if (Studenci.SelectedItems != null)
            {
                Student selStu = (Student)Studenci.SelectedItem;
                Students.Remove(selStu);
                RefreshList();
            }
        }

        private void dodajOcene(object sender, RoutedEventArgs e)
        {
            if (Studenci.SelectedItems != null)
            {
                Student selStu = (Student)Studenci.SelectedItem;

                DodajOcene dodOce = new DodajOcene();
                bool? result = dodOce.ShowDialog();

                if (result == true) 
                {
                    Oceny oce = dodOce.GetGrade();
                    selStu.Oceny.Add(oce);
                }
            }
        }
    }
}

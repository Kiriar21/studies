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

namespace pierwsze_kolos
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public List<Student<string>> Students { get; set; }
        public List<Student<string>> StudentsTemp { get; set; }
        Student<string> test = new Student<string>("a","b","100000");
        public MainWindow()
        {
            InitializeComponent();
            Students = new List<Student<string>>();
            Ocena<float,string> a= new Ocena<float,string>(DateTime.Now, "IT", 5.0f);
            Ocena<float,string> b= new Ocena<float,string>(DateTime.Now, "PN", 2.0f);
            Ocena<float,string> c= new Ocena<float,string>(DateTime.Now, "PO", 3.0f);
            test.Oceny.Add(a);
            test.Oceny.Add(b);
            test.Oceny.Add(c);
            Students.Add(test);
            StudentsDataGrid.Columns.Add(item: new DataGridTextColumn() { Header= "Numer Indeksu", Binding = new Binding(path: "NrIndeksu") });
            StudentsDataGrid.AutoGenerateColumns = false;
            StudentsDataGrid.ItemsSource = Students;
        }
        private void RefreshList()
        {
            StudentsDataGrid.ItemsSource = null;
            StudentsDataGrid.ItemsSource=Students;
        }

        private void showUser(object sender, RoutedEventArgs e)
        {
            if(StudentsDataGrid.SelectedItem != null)
            {
                Student<string> x = (Student<string>)StudentsDataGrid.SelectedItem;
                ShowUserWindow windowShow = new ShowUserWindow(x);
                bool? result = windowShow.ShowDialog();
                if (result == true)
                {
                    foreach (var y in Students)
                    {
                        if (y == x)
                        {
                            Student<string> temp = (Student<string>)windowShow.GetStudent();
                            y.NrIndeksu = temp.NrIndeksu;
                            y.Imie = temp.Imie;
                            y.Nazwisko = temp.Nazwisko;
                            break;
                        }
                    }
                    RefreshList();
                }
            }    
                
        }

        private void addUser(object sender, RoutedEventArgs e)
        {
            AddUserWindow auw = new AddUserWindow();
            bool? result = auw.ShowDialog();
            if (result == true)
            {
                Student<string> nS = auw.GetStudent();
                Students.Add(nS);
                
            }

            RefreshList();
        }

        private void deleteUser(object sender, RoutedEventArgs e)
        {
            if(StudentsDataGrid.SelectedItem != null)
            {
                Student<string> Remover = (Student<string>)StudentsDataGrid.SelectedItem;
                Students.Remove(Remover);
                RefreshList();
            }
        }
        private void SearchUser(object sender, RoutedEventArgs e)
        {
            string tempNI = idUserSearch.Text;
            if (string.IsNullOrEmpty(tempNI))
            {
                RefreshList();
            }
            else
            {
                StudentsTemp = Students.Where(x => x.NrIndeksu == tempNI).ToList();
                StudentsDataGrid.ItemsSource = null;
                StudentsDataGrid.ItemsSource = StudentsTemp;
            }
        }
    }
}

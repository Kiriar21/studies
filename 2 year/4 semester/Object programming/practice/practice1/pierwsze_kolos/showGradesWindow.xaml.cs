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

namespace pierwsze_kolos
{
    /// <summary>
    /// Interaction logic for showGradesWindow.xaml
    /// </summary>
    public partial class showGradesWindow : Window
    {
        public List<Ocena<float, string>> OcenyStudenta {get;set;}
        public Student<string> student { get;set;}
        public showGradesWindow(Student<string> stu = null)
        {
            InitializeComponent();
            OcenyStudenta = new List<Ocena<float, string>>();

            if (stu != null)
            {
                student = stu;
                foreach (Ocena<float, string> x in stu.Oceny)
                {
                    OcenyStudenta.Add(x);
                }

                GradesDataGrid.Columns.Add(item: new DataGridTextColumn() { Header = "Przedmiot", Binding = new Binding(path: "Przedmiot") });
                GradesDataGrid.Columns.Add(item: new DataGridTextColumn() { Header = "Data wystawienia", Binding = new Binding(path: "Date") });
                GradesDataGrid.Columns.Add(item: new DataGridTextColumn() { Header = "Ocena", Binding = new Binding(path: "Wartosc") });
                GradesDataGrid.AutoGenerateColumns = false;
                GradesDataGrid.ItemsSource = OcenyStudenta;
                avg();
                userID.Text = stu.NrIndeksu;
            }
        }

        public void avg()
        {
            string srednia = student.AverageGrades().ToString();
            if (string.IsNullOrEmpty(srednia))
            {
                avgGrades.Text = "Brak Ocen";
            }
            else
            {
                avgGrades.Text = srednia;
            }
        }

        private void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }

        public void RefreshGrid()
        {
            GradesDataGrid.ItemsSource = null;
            GradesDataGrid.ItemsSource = OcenyStudenta;
            avg();
        }

        private void addGrade(object sender, RoutedEventArgs e)
        {

            AddGradeWindows agw = new AddGradeWindows(student);
            bool? result = agw.ShowDialog();
            if(result==true)
            {
                Student<string> newStu = agw.GetStudent();
                OcenyStudenta = newStu.Oceny;
                RefreshGrid();

            }
        }
    }
}

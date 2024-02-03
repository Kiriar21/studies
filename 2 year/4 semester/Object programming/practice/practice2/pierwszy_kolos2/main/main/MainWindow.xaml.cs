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

namespace main
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public List<Student> students;
        public List<Student> students_temp;
        public Student studentID_Grades;
        public MainWindow()
        {
            InitializeComponent();
            students = new List<Student>();
            Student student = new Student("Kamil",12,"123123");
            Oceny ocena1 = new Oceny();
            Oceny ocena2 = new Oceny(3.0f,"kokos");
            student.oceny.Add(ocena1);
            student.oceny.Add(ocena2);
            students.Add(student);
            StudentsGrid.Columns.Add(new DataGridTextColumn() { Header = "Imie", Binding = new Binding(path: "imie") } ); 
            StudentsGrid.Columns.Add(new DataGridTextColumn() { Header = "Wiek", Binding = new Binding(path: "wiek") } ); 
            StudentsGrid.Columns.Add(new DataGridTextColumn() { Header = "Numer Indeksu", Binding = new Binding(path: "NrIndeksu") } ); 
            StudentsGrid.AutoGenerateColumns = false;
            StudentsGrid.ItemsSource= students;
            studentID_Grades = new Student();
            students_temp = new List<Student>();

        }

        public void Refresh()
        {
            StudentsGrid.ItemsSource = null;
            StudentsGrid.ItemsSource = students;
        }
        private void DelUser(object sender, RoutedEventArgs e)
        {
            if(StudentsGrid.SelectedItem != null)
            {
                Student s = (Student)StudentsGrid.SelectedItem;
                students.Remove(s);
                Refresh();
            }
        }

        private void Add(object sender, RoutedEventArgs e)
        {
            AddUserWindow auw = new AddUserWindow();
            bool? result = auw.ShowDialog();
            if(result == true)
            {
                Student s = (Student)auw.GetStudent();
                students.Add(s);
                Refresh();
            }
        }
        private void ShowGrades(object sender, RoutedEventArgs e)
        {
            if(StudentsGrid.SelectedItem != null)
            {
                studentID_Grades = (Student)StudentsGrid.SelectedItem;
                ShowGradesWindow sgw = new ShowGradesWindow(studentID_Grades);
                sgw.ShowDialog();
            }
        }

        private void SearchUser(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrEmpty(idSearch.Text))
            {
                Refresh();
            }
            else
            {
                students_temp = students.Where(x => x.NrIndeksu == idSearch.Text).ToList();
                StudentsGrid.ItemsSource = null;
                StudentsGrid.ItemsSource = students_temp;
            }
        }
    }
}

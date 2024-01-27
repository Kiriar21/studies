using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
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
    /// Interaction logic for DodajStudenta.xaml
    /// </summary>
    public partial class DodajStudenta : Window
    {
        public Student Student { get; set; }
        public DodajStudenta(Student student = null)
        {
            InitializeComponent();
            if (student != null)
            {
                imieAdder.Text = student.Imie;
                nazwiskoAdder.Text=student.Nazwisko;
                wydzialAdder.Text=student.Wydzial;
                indexAdder.Text = student.Index;
            }
            Student = student ?? new Student();
        }

        private void studentAdd_Click(object sender, RoutedEventArgs e)
        {
            if (!Regex.IsMatch(input: imieAdder.Text, pattern: @"^\p{L}{1,12}$") ||
                !Regex.IsMatch(input: nazwiskoAdder.Text, pattern: @"^\p{L}{1,12}$") ||
                !Regex.IsMatch(input: wydzialAdder.Text, pattern: @"^\p{L}{1,12}$") ||
                !Regex.IsMatch(input: indexAdder.Text, pattern: @"^[0-9]{4,10}$"))
            {
                MessageBox.Show(messageBoxText: "Invalid input data");
                return;
            }
            Student.Nazwisko = nazwiskoAdder.Text;
            Student.Imie= imieAdder.Text;
            Student.Wydzial= wydzialAdder.Text;
            Student.Index= indexAdder.Text;
            DialogResult = true;
        }
        public Student GetStudent()
        {
            return Student;
        }
        private void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
    }
}

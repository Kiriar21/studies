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

namespace main
{
    /// <summary>
    /// Interaction logic for AddUserWindow.xaml
    /// </summary>
    public partial class AddUserWindow : Window
    {
        public Student S { get; set; }
        public AddUserWindow(Student s = null)
        {
            InitializeComponent();
            S = s ?? new Student();
        }

        private void addUser(object sender, RoutedEventArgs e)
        {
            if(Regex.IsMatch(input: name.Text, pattern: @"^\p{L}{1,20}$") &&
                Regex.IsMatch(input: age.Text, pattern: @"^[0-9]{1,3}$") && 
                Regex.IsMatch(input: ID.Text, pattern: @"^[0-9]{6}$"))
            {
                S = new Student(name.Text, int.Parse(age.Text), ID.Text);
                DialogResult = true;
            }
            else
            {
                MessageBox.Show("Error.");
                DialogResult = false;
                return;
            }
        }
        public Student GetStudent()
        {
            return S;
        }
        public void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
    }
}

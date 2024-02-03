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
                S = new Student(name.Text, int.Parse(age.Text), ID.Text);
                DialogResult = true;
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

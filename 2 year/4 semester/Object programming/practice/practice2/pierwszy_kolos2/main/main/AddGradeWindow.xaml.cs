using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace main
{
    /// <summary>
    /// Interaction logic for AddGradeWindow.xaml
    /// </summary>
    public partial class AddGradeWindow : Window
    {
        public Student stu { get; set; }
        public AddGradeWindow(Student s = null)
        {
            InitializeComponent();
            stu = s ?? new Student();
        }

        private void AddGrade(object sender, RoutedEventArgs e)
        {
            if (Regex.IsMatch(input: subjectName.Text, pattern: @"^\p{L}{1,20}$")
                && Regex.IsMatch(input: gradeValue.Text, pattern: @"^[2-5]{1}.[0,5]{1}$"))
            {
                Oceny o = new Oceny(float.Parse(gradeValue.Text), subjectName.Text);
                stu.oceny.Add(o);
                DialogResult = true;
            }
            else
            {
                MessageBox.Show("Error.");
            }
        }
        public void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
    }
}

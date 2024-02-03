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
                Oceny o = new Oceny(float.Parse(gradeValue.Text), subjectName.Text);
                stu.oceny.Add(o);
                DialogResult = true;
        }
        public void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
    }
}

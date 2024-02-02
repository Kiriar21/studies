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

namespace pierwsze_kolos
{
    /// <summary>
    /// Interaction logic for AddGradeWindows.xaml
    /// </summary>
    /// 
    
    public partial class AddGradeWindows : Window
    {
        public Student<string> s { get; set; }
        public AddGradeWindows(Student<string> s = null)
        {
            InitializeComponent();
            if(s != null) this.s = s;
        }

        private void addGrade(object sender, RoutedEventArgs e)
        {
               
            if(Regex.IsMatch(input: grade.Text, pattern: @"^[2-5]{1}.[0,5]{1}$")  &&
                Regex.IsMatch(input: subject.Text, pattern: @"^\p{L}{1,12}$"))
            {
                if(grade.Text != "5.5")
                {
                    Ocena<float, string> o = new Ocena<float, string>(DateTime.Now, subject.Text, float.Parse(grade.Text));
                    s.Oceny.Add(o);
                    DialogResult = true;
                }
                else
                {
                    MessageBox.Show("Blednie podane dane. Wartosc oceny 2.0 - 5.0");
                }
            }
            else
            {
                MessageBox.Show("Blednie podane dane. Nazwa przedmiotu 1-12 znakow / Wartosc oceny 2.0 - 5.0");
                return;
            }
        }
        private void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
        public Student<string> GetStudent()
        {
            return s;
        }
    }
}

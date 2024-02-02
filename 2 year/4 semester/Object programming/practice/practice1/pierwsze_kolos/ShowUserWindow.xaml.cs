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
    /// Interaction logic for ShowUserWindow.xaml
    /// </summary>
    public partial class ShowUserWindow : Window
    {
        Student<string> stu = new Student<string>();
        public ShowUserWindow(Student<string> x = null)
        {
            InitializeComponent();
            if (x != null)
            {
                UserFirstName.Text = x.Imie;
                UserLastName.Text = x.Nazwisko;
                UserID.Text = x.NrIndeksu;
                stu = x;
            }
            else
            {
                return;
            }

        }

        private void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }

        private void ShowGrades(object sender, RoutedEventArgs e)
        {
            showGradesWindow sgw = new showGradesWindow(stu);
            sgw.ShowDialog();
        }

        private void SaveUser(object sender, RoutedEventArgs e)
        {
            stu.NrIndeksu=UserID.Text;
            stu.Nazwisko=UserLastName.Text;
            stu.Imie=UserFirstName.Text;
            DialogResult = true;

        }
        public Student<string> GetStudent()
        {
            return stu;
        }
    }
}

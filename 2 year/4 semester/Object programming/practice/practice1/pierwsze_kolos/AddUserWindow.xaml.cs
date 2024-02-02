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
    /// Interaction logic for AddUserWindow.xaml
    /// </summary>
    public partial class AddUserWindow : Window
    {
        public Student<string> User { get; set; }
        public AddUserWindow(Student<string> user =null)
        {
            InitializeComponent();
            if(user != null )
            {
                userNameAdder.Text = user.Imie;
                userLastNameAdder.Text = user.Nazwisko;
                userIDAdder.Text = user.NrIndeksu;
            }
            User = user ?? new Student<string>();
        }

        private void addUser(object sender, RoutedEventArgs e)
        {
            if(Regex.IsMatch(input: userNameAdder.Text, pattern: @"^\p{L}{1,20}$") &&
               Regex.IsMatch(input: userLastNameAdder.Text, pattern: @"^\p{L}{1,20}$") &&
               Regex.IsMatch(input: userIDAdder.Text, pattern: @"^[0-9]{6}$"))
            {
                User.Imie = userNameAdder.Text;
                User.Nazwisko = userLastNameAdder.Text;
                User.NrIndeksu = userIDAdder.Text;
                DialogResult = true;
            }
            else
            {
                MessageBox.Show("Blednie podane dane. Imie, Nazwisko 1-20 znakow, Numer Indeksu 6 cyfr");
                return;
            }
        }
        public Student<string> GetStudent()
        {
            return User;
        }

        private void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult=false;
        }
    }
}

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

namespace main
{
    /// <summary>
    /// Interaction logic for ShowGradesWindow.xaml
    /// </summary>
    public partial class ShowGradesWindow : Window
    {
        public Student S { get; set; }
        public ShowGradesWindow(Student s = null)
        {
            InitializeComponent();
            S = s ?? new Student();
            GradesGrid.Columns.Add(new DataGridTextColumn() { Header = "Przedmiot", Binding = new Binding(path: "przedmiot") });
            GradesGrid.Columns.Add(new DataGridTextColumn() { Header = "Przedmiot", Binding = new Binding(path: "ocena") });
            GradesGrid.AutoGenerateColumns = false;
            GradesGrid.ItemsSource = S.oceny;
            idStudent.Content = S.NrIndeksu;
            avgStudent.Content = S.avgGrades();
        }

        public void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
        public void Refresh()
        {
            GradesGrid.ItemsSource = null;
            GradesGrid.ItemsSource = S.oceny;
        }
        private void AddGrade(object sender, RoutedEventArgs e)
        {
                AddGradeWindow agw = new AddGradeWindow(S);
                bool? result = agw.ShowDialog();
                if(result == true)
                {
                    Refresh();
                    avgStudent.Content = S.avgGrades();
                }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace main
{
    public class Student
    {
        public string imie { get; set; }    
        public int wiek { get; set; }
        public string NrIndeksu { get; set; }
        public List<Oceny> oceny { get; set; }
        public Student(string i, int w, string n) { imie = i; wiek = w; NrIndeksu = n; oceny = new List<Oceny>(); }
        public Student() { imie = "none"; wiek = 1; NrIndeksu = "111111"; oceny = new List<Oceny>(); }
        public float avgGrades()
        {
            if (oceny.Count==0 || oceny == null)
            {
                return 0.0f;
            }
            else
            {
                return oceny.Select(x => x.ocena).Average();
            }
        }
    }
}

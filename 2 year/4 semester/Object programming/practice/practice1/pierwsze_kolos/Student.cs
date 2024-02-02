using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace pierwsze_kolos
{
    public class Student<S>: Element<S>
    {
        public string Imie { get; set; }
        public string Nazwisko { get; set; }
        public S NrIndeksu { get; set; }
        public List<Ocena<float, S>> Oceny { get; set; }

        public Student(string i, string n, S nI){
            Imie= i;
            Nazwisko = n;
            NrIndeksu = nI;
            Oceny = new List<Ocena<float, S>>();
        }
        public Student() { Oceny = new List<Ocena<float, S>>(); }

        public float AverageGrades()
        {
            if (Oceny == null || Oceny.Count == 0)
            {
                return 0.0f;
            }
            else
            {
                return Oceny.Select(o => o.Wartosc).Average();
            }
        }
    }
}

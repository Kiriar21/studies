using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    public class Student
    {
        public string Imie { get; set; }
        public string Nazwisko { get; set; }
        public string Wydzial { get; set; }
        public string Index { get; set; }
        public List<Oceny> Oceny { get; set; }

        public Student() { Oceny = new List<Oceny>(); }
    }
}

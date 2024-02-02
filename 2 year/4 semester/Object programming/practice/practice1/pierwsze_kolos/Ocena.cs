using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace pierwsze_kolos
{
    public class Ocena<T,S> : Element<S>
    {
        public DateTime Date { get; set; } 
        public string Przedmiot { get; set; }
        public T Wartosc { get; }
        public Ocena(DateTime d, string p, T w)
        {
            Date = d;
            Przedmiot = p;
            Wartosc = w;
        }
        public Ocena() { }
    }
}

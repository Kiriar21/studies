using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cwiczenie
{
    public class Ocena<T, S> : Element<S>
    {
        public DateTime Data { get; set; }
        public string Przedmiot { get; set; }
        public T Wartosc { get; set; }


        public Ocena(T wartosc, string przedmiot) // musimy zrobić konstruktor, który nam będzie tworzył te oceny
        {
            Data = DateTime.Now;
            Przedmiot = przedmiot;
            Wartosc = wartosc;
        }
        public override string ToString()
        {
            return $"Przedmiot:\t{this.Przedmiot}\tOcena:\t{this.Wartosc}\tData wystawienia:\t{this.Data}\n"; // Przeciążenie, do szybkiego wyświetlenia
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie
{
    public class MenagerGry<IZ>
    {
        public List<Rozgrywka<IZ>> Rozgrywki { get; set; }

        public MenagerGry() {
            Rozgrywki = new List<Rozgrywka<IZ>>();    
        }
        
        public void DodajRozgrywke(Rozgrywka<IZ> roz)
        {
            Rozgrywki.Add(roz);
        }
        public List<Rozgrywka<IZ>> RozgrywkiZakonczone() 
        {
            List<Rozgrywka<IZ>> l = new List<Rozgrywka<IZ>>();
            return l;
        }
        public List<Rozgrywka<IZ>> Szukaj(Func<Rozgrywka<IZ>, bool> pred)
        {
            List<Rozgrywka<IZ>> l = new List<Rozgrywka<IZ>>();
            return l ;
        }

    }
}

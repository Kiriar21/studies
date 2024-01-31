using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie
{
    public class Rozgrywka<IZ> : IRozgrywka
    {
        public int NazwaGry { get; set; }
        public bool Zakonczona { get; set; }
        public bool CzyZakonczona()
        {
            return true;
        }

        public List<string> Gracze { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

        public string KtoWygrywa => throw new NotImplementedException();

        public List<int> Wyniki { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

        bool IRozgrywka.CzyZakonczona => throw new NotImplementedException();

        public void ZakonczGre()
        {
            Zakonczona = CzyZakonczona();
        }


    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie
{
    public interface IRozgrywka
    {
        public bool CzyZakonczona { get; }
        public List<string> Gracze { get; set; }
        public string KtoWygrywa { get; }
        public List<int> Wyniki { get; set; }

        public void ZakonczGre();
    }
}

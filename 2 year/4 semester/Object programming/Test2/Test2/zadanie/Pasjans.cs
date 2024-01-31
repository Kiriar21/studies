using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie
{
    public class Pasjans : IZasady
    {
        public int LimitRozgrywek => 5;

        public int MaxGraczy => 2;

        public IRozgrywka NowaGra()
        {
            Rozgrywka<int> i = new Rozgrywka<int>();
            return i;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie
{
    public interface IZasady
    {
        public int LimitRozgrywek { get; }
        public int MaxGraczy { get; }

        public IRozgrywka NowaGra();
    }
}

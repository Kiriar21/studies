using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace cwiczenie
{
    public abstract class Element<T>
    {
        public T Id { get; set; } // zwykle zadeklarowanie czego oczekiwano
    }
}

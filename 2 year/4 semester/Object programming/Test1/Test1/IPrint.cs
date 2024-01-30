using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArturMatuszczyk
{
    public interface IPrint
    {
        public string ID { get; set; }
        public void Print() { Console.WriteLine($"Identyfikator: {ID}"); }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    public class Author:Person
    {
        public string Nationality { get; set; }
        public Author(string fn, string ln, string nat):base(fn,ln)
        {
            Nationality = nat;
        }
        public Author() : this("none", "none", "none") { }
        public override string ToString()
        {
            return "cos4";
        }
    }
}

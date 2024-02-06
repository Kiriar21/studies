using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    public class Librarian:Person
    {
        public DateTime HireDate { get; set; }
        public decimal Salary { get; set; }
        public Librarian(string fn, string ln, DateTime dat, decimal salary) : base(fn,ln) { this.Salary = salary; this.HireDate = dat; }
        public Librarian() : this("none", "none", DateTime.Now, 11110.13m) {}
        public override string ToString()
        {
            return "cos6";
        }
    }
}

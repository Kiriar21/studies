using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie3
{
    public class Librarian:Person
    {
        public DateTime HireDate { get; set; }
        public decimal Salary { get; set; }
        public Librarian(string fname, string lname, DateTime hd, decimal salary) : base(fname, lname)
        {
            this.HireDate = hd;
            this.Salary = salary;
        }
        public Librarian() : this("none","none",DateTime.Now, 3999.99m) { }
        public override string ToString()
        {
            return $"{base.ToString()} Date Hire = {HireDate} Salary = {Salary} ";
        }

    }
}

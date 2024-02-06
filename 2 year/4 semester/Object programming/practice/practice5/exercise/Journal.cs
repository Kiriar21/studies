using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    public class Journal:Item
    {
        public int Number { get; set; }
        public Journal(string title, int id, string publisher, DateTime dat, int number) : base(title, id,publisher, dat)
        {
            Number = number;
        }
        public Journal() : base("none",1,"none",DateTime.Now) { }

        public Journal(string title, int id, string publisher, DateTime dateOfIssue) : base(title, id, publisher, dateOfIssue)
        {
            Number = 1;
        }
        public override string ToString()
        {
            return "cos1";
        }
        public override string GenerateBarCode()
        {
            return $"Dziennk{Number}";
        }
    }
}

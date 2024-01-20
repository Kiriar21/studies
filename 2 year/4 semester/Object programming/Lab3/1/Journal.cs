using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace zadanie3
{
    public class Journal:Item
    {
        public int Number { get; set; }
        public Journal(string title, int id, string publisher, DateTime dateOfIssue, int number) : base(title, id, publisher, dateOfIssue)
        {
            Number = number;
        }
        public Journal() : this("none",1,"none",DateTime.Now,1) { }
        public override string ToString()
        {
            return $"{base.ToString()}\nNumber = {Number}\n";
        }
        public override string GenerateBarCode()
        {
            return $"Dziennik{base.Id}";
        }
    }
}

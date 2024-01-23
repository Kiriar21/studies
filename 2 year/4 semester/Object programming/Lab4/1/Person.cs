using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab4
{
    public class Person
    {
        public int Age { get; set; }
        public int Id { get; set; }
        public string FirstName { get; set; } 
        public string LastName { get; set; }

        static private int id_counter = 1;
        public Person(string fn, string ln, int a)
        {

            Age = a;
            FirstName = fn;
            LastName = ln;
            Id = id_counter++;
        }
        public Person() : this("none", "none", 1) { }
        public override string ToString()
        {
            return $"Id={this.Id} Name: {this.FirstName} {this.LastName} Age: {this.Age}";
        }
    }

}

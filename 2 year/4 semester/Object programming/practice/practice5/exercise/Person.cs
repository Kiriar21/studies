using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    public class Person
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public Person(string firstName, string lastName)
        {
            FirstName = firstName;
            LastName = lastName;
        }
        public Person() : this("none", "nonoe") { }
        public override string ToString()
        {
            return "cos5";
        }
        public void Details()
        {
            Console.WriteLine(ToString());
        }
    }
}

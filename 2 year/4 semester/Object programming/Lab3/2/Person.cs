using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie3
{
    public class Person
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public Person(string firstname, string lastname)
        { 
            FirstName = firstname;
            LastName = lastname;
        }
        public Person() : this("none","none"){ }
        public override string ToString()
        {
            return $"{FirstName} {LastName}";
        }
        public void Details()
        {
            Console.WriteLine(ToString());
        }
    }
}

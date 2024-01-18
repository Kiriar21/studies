using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie1
{
    public class Person
    {
        protected string _firstName;
        protected string _lastName;
        protected DateTime _dateOfBirth;

        public string FirstName { get { return _firstName; } set { _firstName = value; } }
        public string LastName { get { return _lastName; } set { _lastName = value; } }
        public DateTime DateOfBirth { get { return _dateOfBirth; } set { _dateOfBirth = value; } }
        public Person(string name, string lname, DateTime date)
        {
            _firstName = name;
            _lastName = lname;
            _dateOfBirth = date;
        }
        public Person() : this("name","name",DateTime.Now){ }
        public override string ToString()
        {
            return $"Name: {FirstName} {LastName} Birthday: {DateOfBirth}\n";
        }
        virtual public void Details()
        {
            Console.WriteLine($"{ToString()}");
        }
    }
}

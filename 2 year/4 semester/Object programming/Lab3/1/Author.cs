using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie3
{
    public class Author
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Nationality { get; set; }
        public Author(string fname, string lname, string national) 
        {
            FirstName = fname;
            LastName = lname;
            Nationality = national;
        }
        public Author() : this("none","none","none"){ }
        public override string ToString()
        {
            return $"{FirstName} {LastName} Nationality: {Nationality}";
        }
    }
}

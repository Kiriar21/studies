using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace zadanie1
{
    class Person
    {
        private string _firstName;
        private string _lastName;
        private string _address;
        private int _maxCarCount=3;

        private string[] _registerNumbers;
        private int _numCount=0;
        public string FirstName
        {
            get { return _firstName; } 
            set { _firstName = value; }  
        }
        public string LastName { get { return this._lastName;  } set { this._lastName = value; } }
        public string Address { get { return this._address; } set { this._address = value; } }
        public int MaxCarCount { get { return this._maxCarCount; } set { this._maxCarCount = value; }  }
        public string this[int index]
        { 
            get { return _registerNumbers[index]; }
            set { _registerNumbers[index] = value; }
        }
        public int numberCount 
        { 
            get { return this._numCount; } 
            set { this._numCount = value; }  
        }
        public Person(string firstName, string lastName, string address, string[] registerNumbers)
        {
            if(registerNumbers.Length < 4 )
            {
                FirstName = firstName;
                LastName = lastName;
                Address = address;
                _registerNumbers = new string[3];
                for (int i = 0; i < registerNumbers.Length; i++)
                {
                    _registerNumbers[i] = registerNumbers[i];
                }
                _numCount = registerNumbers.Length;
            }
            else
            {
                Console.WriteLine($"Max 3 Registration Numbers.\n\n");
            }
        }

        public Person(string firstName, string lastName, string address)
        {
            FirstName = firstName;
            LastName = lastName;
            Address = address;
        }
        public Person() : this("nieznajomy","nieznajomy","nieznajomy") { }
        public Person(Person person)
        {
            if (person._numCount > 0)
            {
                this._firstName = person.FirstName;
                this._lastName = person.LastName;
                this._address = person.Address;
                _registerNumbers = new string[3];
                for (int i = 0; i < person._registerNumbers.Length; i++)
                {
                    _registerNumbers[i] = person._registerNumbers[i];
                }
                this._numCount = person._numCount;
            }
        }
        public void AddCarRegistrationNumber(string number)
        {
            if(this._numCount < 3)
            {
                _registerNumbers[this._numCount] = number;
                this._numCount++;
            }
            else
            {
                Console.WriteLine($"You have limit a cars.");
            }
        }
        public void RemoveCarRegistrationNumber(string number)
        {
            if( this._numCount > 0)  
            {
                for (int i = 0; i < this._numCount; i++)
                {
                    if (_registerNumbers[i] == number)
                    {
                        this._registerNumbers[i] = null;
                        this._numCount--;
                        for (int j=i; j<this._numCount; j++)
                        {
                            _registerNumbers[j] = _registerNumbers[j+1];
                        }
                        Console.WriteLine("Registration Number was delete.");
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                Console.WriteLine($"You don't have any car.");
            }
        }

        public override string ToString()
        {
            string result = "Registration Numbers: \n";
            for(int i=0; i < this._numCount; i++)
            {
                result += $"{i+1}. {_registerNumbers[i]}\n";
            }
            return result;
        }
        public void Details()
        {
            if (this._numCount > 0)
            {
                Console.WriteLine($"\nPerson: {this._firstName} {this._lastName} \nAddress: {this.Address} \nCars: \n");
                Console.WriteLine(ToString());
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1
{
    public class Person
    {
        public string[] _registrationNumbers;

        public static int MaxCarCount { get { return MaxCarCount; } set => MaxCarCount = 3; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Address { get; set; }
        public int CarsCount { get { return CarsCount; } set => CarsCount = 0; }
        public Person(string fs, string lname, string add)
        {
            FirstName = fs;
            LastName = lname;
            Address = add;
            _registrationNumbers = new string[MaxCarCount];
        }
        public Person() : this("None","None","None"){ }
        public Person(string fs, string ln, string add, Car[] cars) : this(fs, ln, add)
        {
            CarsCount = cars.Length;
        }
        public void AddCarRegistrationNumber(string num)
        {
            if(_registrationNumbers.Length < MaxCarCount) 
            {
                _registrationNumbers[CarsCount] = num;
                CarsCount++;
                Console.WriteLine("Dodano numer.");
            }
            else
            {
                Console.WriteLine("Nie ma miejsca.");
            }
        }
        public void RemoveCarRegistrationNumber(string num)
        {
            if (CarsCount > 0)
            {
                for (int i = 0; i < _registrationNumbers.Length; i++)
                {
                    if (_registrationNumbers[i] == num)
                    {
                        _registrationNumbers[i] = null;
                        CarsCount--;
                        for (int j = i; j < CarsCount; j++)
                        {
                            _registrationNumbers[j] = _registrationNumbers[j+1];
                        }
                        break;
                    }
                }
            }
            else
            {
                Console.WriteLine("Brak aut.");
            }
        }
        public override string ToString()
        {
            string tmp = "";
            foreach(string car in _registrationNumbers)
            {
                tmp += car.ToString();
            }
            return tmp;
        }
        public void Details()
        {
            Console.WriteLine($"FN: {FirstName} LN: {LastName} Add: {Address} CarsCount: {CarsCount}\n{ToString()}");
        }

    }
}

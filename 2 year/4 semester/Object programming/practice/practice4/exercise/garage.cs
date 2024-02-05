using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1
{
    public class Garage
    {
        public Car[] _cars;
        public string _address;
        public int _carsCount=0, _capacity;

        public int Capacity { get; set; }
        public string Address { get; set; } 
        public Garage(string address, int capacity)
        {
            Address = address;
            Capacity = capacity;
            _cars = new Car[capacity];
        }
        public Garage() : this("none", 1) { }
        public override string ToString()
        {
            string result = "";
            foreach (Car car in _cars)
            {
                result += car;
            }
            return result;
        }
        public void Details()
        {
            Console.WriteLine(ToString());
        }
        public void CarIn(Car car)
        {
            if (_carsCount < Capacity)
            {
                _cars[_carsCount] = car;
                _carsCount++;
                Console.WriteLine($"Auto zostalo dodane.");
            }
            else
            {
                Console.WriteLine("Brak miejsca w garazu.\n");
            }
        }
        public Car CarOut()
        {
            if (_carsCount > 0)
            {
                var result = _cars[_cars.Length - 1];
                _cars[_cars.Length - 1] = null;
                Console.WriteLine("Auto zostalo wyciagniete.");
                return result;
            }
            else
            {
                Console.WriteLine("Brak aut w garazu.");
                return null;
            }
            
        }

    }
}

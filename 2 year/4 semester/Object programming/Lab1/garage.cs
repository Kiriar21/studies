using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie1
{
    public class Garage
    {
        private Car[] _cars;
        private string _address;
        private int _carsCount = 0;
        private int _capacity;

        public string Address { get { return _address;  } set { _address = value; }  }
        public int carsCount { get { return _carsCount;  } set { _carsCount = value; } }
        public int Capacity 
        { 
            get { return _capacity; } 
            set 
                {
                    _capacity = value; 
                    _cars = new Car[value]; 
                } 
        } 
        public Garage(string address, int capacity)
        {
            this._address = address;
            this._capacity = capacity;
            this._cars = new Car[capacity];
        }
        public Garage() : this("nieznany", 0) { }
        public void CarIn(Car car1)
        {
            if (this._carsCount < this._capacity)
            {
                this._cars[this._carsCount] = car1;
                this._carsCount+=1;
            }
            else
            {
                Console.WriteLine($"Garage is full!!");
            }
        }
        public Car CarOut()
        {
            if(this._carsCount == 0)
            {
                Console.WriteLine($"Garage is empty B( ");
                return null;
            }
            else
            {   
                Console.WriteLine($"Car will be out from Garage");
                Car car = this._cars[this._carsCount-1];
                this._cars[this._carsCount-1] = null;
                this._carsCount-=1;
                return car;
            }
        }
        public override string ToString()
        {
            string result = $"Address: {this._address} Capacity: {this._capacity} \n";
            foreach (Car item in this._cars)
            {
                result += $"\n{item}";
            }
            return result;
        }
        public void Details()
        {
            Console.WriteLine($" {ToString()}");
        }
    }
}

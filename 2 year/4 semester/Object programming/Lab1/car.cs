using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace zadanie1
{
    public class Car
    {
        private string _brand;
        private string _model;
        private int _doorCount;
        private float _engineVolume;
        private double _avgConsump;
        private string _registrationNumber;

        public string Brand { get { return _brand; } set { _brand = value; } }
        public string Model { get { return _model; } set { _model = value; } }
        public int DoorCount { get { return _doorCount; } set { _doorCount = value; } }
        public float EngineVolume { get { return _engineVolume; } set { _engineVolume = value; } }
        public double AvgConsump { get { return _avgConsump; } set { _avgConsump = value; } }
        public string RegistrationNumber { get { return _registrationNumber; } set { _registrationNumber = value; } }

        private static int _carCount = 0;

        public Car(string brand, string model, int doorCount, float engineVolume, double avgConsump, string RegistationNumber)
        {
            this._brand = brand;
            this._model = model;
            this._doorCount = doorCount;
            this._engineVolume = engineVolume;
            this._avgConsump = avgConsump;
            this._registrationNumber = RegistationNumber;
            _carCount++;
        }
        public Car() : this("nieznajomy", "nieznajomy", 0, 0, 0.00,"nieznajomy") { }
        public double CalculateConsump(double roadLength)
        {
            return (this._avgConsump * roadLength) / 100.0;
        }
        public double CalculateCost(double roadLength, double petrolCost)
        {
            return CalculateConsump(roadLength) * petrolCost;
        }
        public override string ToString()
        {
            return $"Car | Brand: {this._brand}, Model: {this._model}, Number of Doors: {this._doorCount}, Engine Volume: {this._engineVolume}, Average Consump: {this._avgConsump}, RegistrationNumber: {this._registrationNumber}\n";
        }
        public void Details()
        {
            Console.WriteLine($"h {ToString()}");
        }
        public static void DisplayCarCount()
        {
            Console.WriteLine($"{Car._carCount}");
        } 
    }
}

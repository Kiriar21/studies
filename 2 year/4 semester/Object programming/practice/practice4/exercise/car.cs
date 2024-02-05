using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net.NetworkInformation;
using System.Runtime.Versioning;
using System.Text;
using System.Threading.Tasks;

namespace lab1
{
    public class Car
    {
        public string _brand,_model,_registrationName;
        public int _doorCount;
        double _engineVolume, _avgConsume;
        public static int _carCount = 0;

        public string RegistrationNumber { get; set; }
        public string Brand { get; set; }
        public string Model  { get; set; }
        public int DoorCount { get; set; }
        public double EngineVolume { get; set; }
        public double AvgConsump { get; set; }
        public Car(string brand, string model, int doorCount, double engineVolume, double avgConsume, string registrationName)
        {
            Brand = brand;
            Model = model;
            RegistrationNumber = registrationName;
            DoorCount = doorCount;
            EngineVolume = engineVolume;
            AvgConsump = avgConsume;
            _carCount++;
        }
        public Car() : this("none", "none", 1, 1.00, 1.00, "none") { }
        public override string ToString()
        {
            return $"{Brand} {Model} {RegistrationNumber} \n{DoorCount} {EngineVolume} {AvgConsump}\n";
        }
        public double CalculateConsump(double roadLength)
        {
            return (this._avgConsume * roadLength) / 100.00;
        }
        public double CalculateCost(double roadLength, double petrolCost)
        {
            return petrolCost*CalculateConsump(roadLength);
        }
        public void Details()
        {
            Console.WriteLine(ToString());
        }
        public static void DisplayCarCount()
        {
            Console.WriteLine($"Liczba samochodow: {_carCount}");
        }
    }
}

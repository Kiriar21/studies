using System;
using System.Runtime.ConstrainedExecution;

namespace zadanie1
{
    public class main
    {
        static void Main(string[] args)
        {
            Car car1 = new Car();
            car1.Details();
            car1.Brand = "Fiat";
            car1.Model = "126p";
            car1.DoorCount = 2;
            car1.EngineVolume = 650;
            car1.AvgConsump = 6.0;
            car1.RegistrationNumber = "KR12345";
            car1.Details();
            Car car2 = new Car("Syrena", "105", 2, 0.8f, 7.6d, "WE1234");
            car2.Details();
            Console.WriteLine(car1);
            double routeConsumption = car2.CalculateConsump(500);
            Console.WriteLine($"Route consumption: {routeConsumption} l");
            double routeCost = car2.CalculateCost(500, 5);
            Console.WriteLine($"Route cost: {routeCost}");
            Car.DisplayCarCount();
            Console.WriteLine("\r\n=========================================\r\n");
            Garage garage1 = new Garage();
            garage1.Address = "ul. Garażowa 1";
            garage1.Capacity = 1;
            Garage garage2 = new Garage("ul. Garażowa 2", 2);
            garage1.CarIn(car1);
            garage1.Details();
            garage1.CarIn(car2);
            garage2.CarIn(car2);
            var movedCar = garage1.CarOut();
            garage2.CarIn(movedCar);
            Console.WriteLine($"1\n");
            garage2.Details();
            Console.WriteLine($"2\n");
            garage1.Details();
            Console.WriteLine($"3\n");
            garage2.CarOut();
            Console.WriteLine($"4\n");
            garage2.Details();
            Console.WriteLine($"5\n");
            garage2.CarOut();
            Console.WriteLine($"6\n");
            garage2.CarOut();
            Console.WriteLine($"7\n");
            garage2.Details();
            Console.WriteLine($"8\n");
            garage1.Details();
            Console.WriteLine("\r\n=========================================\r\n");
            // Mój kod testujący do klasy Person
            Person person = new();
            Person person1 = new("Jan", "Kowalski", "Czestochowa, Polska");
            string[] registrationNumbers = { "SCZ 11111", "ERA 22222", "WWA 33333" };
            string[] registrationNumbers1 = { "SCZ 11111", "ERA 22222", "WWA 33333", "SZCZECIN 4444" };
            Person person2 = new("Adam", "Małysz", "Krakow, Polska", registrationNumbers);
            Person person3 = new("Napoleon", "Gotycki", "Rome, Italy", registrationNumbers1);
            //person.Details();
            //person1.Details();
            //person2.Details();
            //person3.Details();
            Person person4 = new(person2);
            //Console.WriteLine($"Test usuwania i dodawania numer rejestracyjnych.");
            //person4.Details();
            //person2.Details();
            //powinno byc ograniczenie w dodaniu
            person4.AddCarRegistrationNumber("TEST 5555");
            //person4.Details();
            //person2.Details();
            // usuniecie powinno napisac jako null
            person4.RemoveCarRegistrationNumber("WWA 33333");
            //person4.Details();
            //person2.Details();
            //Console.WriteLine($"{person2.numberCount}");
            //Console.WriteLine($"{person4.numberCount}");
            //person4.Details();
            person4.AddCarRegistrationNumber("TEST 5555");
            //person4.Details();
            person4.RemoveCarRegistrationNumber("ERA 22222");
            person4.Details();
            person2.Details();

        }
    }
}

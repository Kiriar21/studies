using System;

namespace ArturMatuszczyk
{
    public class Program
    {
        static void Main(string[] args)
        {
            Client klient1 = new("adres", "name", "01");
            Client klient2 = new("adres2", "name2", "02");
            System system = new System();
            system.Add(klient2);
            system.Add(klient1);
            var x = system.Find("name");

        }
    }
}

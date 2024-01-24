using System;
using System.Collections.Generic;
using System.Linq;

namespace lab4
{
    public class Program
    {
        static void Main(string[] args)
        {
            var list = new Klasa1generic<Person>
            {
                new Person ("Anna","B",15),
                new Person ("Cezary", "D", 18),
                new Person ("Ewelina", "F", 21),  
                new Person ("Grażyna", "H", 30),
            };
            Console.WriteLine("\nOsoby:");
            int i = 0;
            foreach (var item in list)
            {
                Console.WriteLine($"\t{++i}. {item}");
            }
            
            Console.WriteLine("\nKobiety:");
            var sublist = list.Where(e => e.FirstName.EndsWith("a"));
            sublist.ToList().ForEach(e => Console.WriteLine(e) );
            Console.WriteLine("\nOsoby pełnoletnie:");
            var sublist2 = list.Where(e => e.Age >= 18);
            sublist2.ToList().ForEach(e => Console.WriteLine(e));

            Console.ReadKey();
        }
    }
}

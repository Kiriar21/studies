using System;

namespace cwiczenie
{
    public class Glowna
    {
        static void Main(string[] args)
        {
            Console.WriteLine("---Start---");
            Console.WriteLine("---Na ocene 3---");
            Console.WriteLine("1. Utworzenie studenta. Wyswietlenie podstawowych danych:");
            Student<string> student1= new("Jan", "Kowalski", "100000"); // Odwołanie się do Element, i nadaje string jako Id, ja sobie ID ustalilem jako NumerIndeksu
            student1.Wyswietl();
            Console.WriteLine("\n\n2. Dodanie nowych ocen do studenta. Wyswietlenie podstawowych danych po dodaniu:");
            Ocena<float, string> ocena1 = new(5.0f,"JA");
            Ocena<float, string> ocena2 = new(4.0f,"PO");
            Ocena<float, string> ocena3 = new(3.0f,"PP");
            Ocena<float, string> ocena4 = new(2.0f,"PN");
            Ocena<float, string> ocena5 = new(2.0f,"SO");
            student1.Dodaj(ocena1);
            student1.Dodaj(ocena2);
            student1.Dodaj(ocena3);
            student1.Dodaj(ocena4);
            student1.Dodaj(ocena5);
            student1.Wyswietl();
            Console.WriteLine("---Na ocene 4---");
            Console.WriteLine("\n\n3. Wyswietlenie sredniej studenta:");
            student1.Srednia();
            Console.WriteLine("\n\n4. Usuwanie ocen. Wyswietlenie danych:");
            student1.Usun(ocena4);
            student1.Usun(ocena5);
            student1.Wyswietl();
            Console.WriteLine("---Na ocene 5---");
            Console.WriteLine("\n\n5. Wyszukiwanie wyników w nauce. Po nazwie: ");
            student1.Wyszukaj("JA");
            student1.Wyszukaj("SO");
            Console.WriteLine("\n\n6. Wyszukiwanie wyników w nauce. Po ocenie:");
            student1.Wyszukaj(5.0f);
            student1.Wyszukaj(1.0f);
            Console.WriteLine("\n\n7. Edytowanie ocen. Wyswietlenie danych.");
            student1.Edytuj("PP", 5.0f);
            student1.Edytuj("SO", 5.0f);
            student1.Edytuj("PP", 6.0f);
            student1.Wyswietl();
            student1.Srednia();
            Console.WriteLine("\n\n8. Walidacja dodawanych przedmiotow. Wyswietlenie danych.");
            student1.Dodaj(new Ocena<float, string>(5.0f, "PP"));
            student1.Dodaj(new Ocena<float, string>(6.0f, "PPO"));
            student1.Wyswietl();
            Console.WriteLine("\n\n9. Test pozostalych opcji.");
            Student<string> student2 = new Student<string>("Ktos","nie","200000");
            student2.Wyswietl();
            student2.Srednia();
            Console.WriteLine("---Koniec---");
        }
    }
}

using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace lab7
{
    //zadanie 1
    // Klasa Para w wersji generycznej
    public class Pair<T1, T2>
    {
        public T1 First { get; set; }
        public T2 Second { get; set; }

        public Pair(T1 first, T2 second)
        {
            First = first;
            Second = second;
        }
    }

    // Klasa Para w wersji zwykłej
    public class Pair
    {
        public object First { get; set; }
        public object Second { get; set; }

        public Pair(object first, object second)
        {
            First = first;
            Second = second;
        }
    }


    //zadanie 2
    public class GenerycznaKlasa<T> where T : class, new() // wymusza zeby bylo generyczne i mialo konstruktor domyslny 
    {
        private readonly T wartosc;

        public GenerycznaKlasa(T wartosc)
        {
            this.wartosc = wartosc;
        }

        public T Wartosc
        {
            get { return wartosc; }
        }

        public T NowaWartosc()
        {
            return new T();
        }
    }

    //zadanie 4

    public class Osoba : IComparable<Osoba>
    {
        public string Imie { get; set; }
        public string Nazwisko { get; set; }
        public int Wiek { get; set; }

        public int CompareTo(Osoba other)
        {
            return Wiek.CompareTo(other.Wiek);
        }
    }

    //zadanie 6

    public class KolekcjaTypow
    {
        private Dictionary<string, object> _kolekcja = new Dictionary<string, object>();

        public void Dodaj<T>(string nazwa, T obiekt)
        {
            _kolekcja.Add(nazwa, obiekt);
        }

        public T Pobierz<T>(string nazwa)
        {
            object obiekt;
            if (_kolekcja.TryGetValue(nazwa, out obiekt))
            {
                if (obiekt is T)
                {
                    return (T)obiekt;
                }
                else
                {
                    throw new ArgumentException($"Obiekt o nazwie {nazwa} nie jest typu {typeof(T)}");
                }
            }
            else
            {
                throw new ArgumentException($"Nie znaleziono obiektu o nazwie {nazwa}");
            }
        }
    }


    public class Program
    {
        static void Main(string[] args)
        {
            //zadanie 1
            Console.WriteLine("Zadanie1\n");
            // Utworzenie instancji klas Para
            Pair<int, int> genericPair = new Pair<int, int>(1, 2);
            Pair nonGenericPair = new Pair(1, 2);

            // Pomiar czasu wykonania pętli dla klasy generycznej
            Stopwatch genericWatch = new Stopwatch();
            genericWatch.Start();
            for (int i = 0; i < 100000000; i++)
            {
                int result = genericPair.First + genericPair.Second;
            }
            genericWatch.Stop();
            Console.WriteLine("Czas wykonania dla klasy generycznej: " + genericWatch.ElapsedMilliseconds + "ms");

            // Pomiar czasu wykonania pętli dla klasy zwykłej
            Stopwatch nonGenericWatch = new Stopwatch();
            nonGenericWatch.Start();
            for (int i = 0; i < 100000000; i++)
            {
                int result = (int)nonGenericPair.First + (int)nonGenericPair.Second;
            }
            nonGenericWatch.Stop();
            Console.WriteLine("Czas wykonania dla klasy zwykłej: " + nonGenericWatch.ElapsedMilliseconds + "ms");
            Console.WriteLine("\nCzas wykonania dla klasy generycznej jest dużo szybszy niż dla zwykłej klasy.\n");

            //zadanie 2
            Console.WriteLine("Zadanie2\nStworzona klasa.\n");
            //zadanie 4
            Console.WriteLine("Zadanie4\n");
            // Utworzenie kilku obiektów Osoba z różnymi wiekami
            Osoba osoba1 = new Osoba { Imie = "Jan", Nazwisko = "Kowalski", Wiek = 30 };
            Osoba osoba2 = new Osoba { Imie = "Anna", Nazwisko = "Nowak", Wiek = 25 };
            Osoba osoba3 = new Osoba { Imie = "Tomasz", Nazwisko = "Szymański", Wiek = 40 };
            Osoba osoba4 = new Osoba { Imie = "Maria", Nazwisko = "Kowalczyk", Wiek = 20 };

            // Dodanie obiektów do listy
            List<Osoba> lista = new List<Osoba> { osoba1, osoba2, osoba3, osoba4 };

            // Sortowanie listy wg. wieku
            lista.Sort();

            // Wyświetlenie posortowanej listy
            foreach (Osoba x in lista)
            {
                Console.WriteLine("{0} {1}, wiek: {2}", x.Imie, x.Nazwisko, x.Wiek);
            }

            //zadanie 6

            Console.WriteLine("\nZadanie6\n");

            // Utworzenie kolekcji
            KolekcjaTypow kolekcja = new KolekcjaTypow();

            // Dodanie obiektów różnych typów
            kolekcja.Dodaj("liczba", 2115);
            kolekcja.Dodaj("tekst", "Randomowy tekst");
            kolekcja.Dodaj("osoba", new Osoba { Imie = "Jan", Nazwisko = "Kowalski", Wiek = 30 });

            // Pobranie wartości z kolekcji
            int liczba = kolekcja.Pobierz<int>("liczba");
            string tekst = kolekcja.Pobierz<string>("tekst");
            Osoba osoba = kolekcja.Pobierz<Osoba>("osoba");

            Console.WriteLine(liczba); // wyświetli "2115"
            Console.WriteLine(tekst); // wyświetli "Hello, World!"
            Console.WriteLine($"{osoba.Imie} {osoba.Nazwisko}, wiek: {osoba.Wiek}"); // wyświetli "Jan Kowalski, wiek: 30"

        }
    }
}

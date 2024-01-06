using System;
using System.Collections.Generic;

namespace lab10
{
    public class Program
    {
        // 4.1
        static IEnumerable<int> PobierzLiczby()
        {
            while (true)
            {
                if (int.TryParse(Console.ReadLine(), out int liczba))
                {
                    yield return liczba;
                }
                else
                {
                    yield break;
                }
            }
        }
        //4.2
        static IEnumerable<int> TylkoParzyste(IEnumerable<int> kolekcja)
        {
            foreach (var liczba in kolekcja)
            {
                if (liczba % 2 == 0)
                {
                    yield return liczba;
                }
            }
        }
        //4.5
        static IEnumerable<int> DoKwadratu(IEnumerable<int> kolekcja)
        {
            foreach (var liczba in kolekcja)
            {
                yield return liczba * liczba;
            }
        }
        //4.6
        static IEnumerable<TResult> ModyfikujLiczby<TSource, TResult>(
        IEnumerable<TSource> kolekcja, Func<TSource, TResult> modyfikacja)
        {
            foreach (var liczba in kolekcja)
            {
                yield return modyfikacja(liczba);
            }
        }
        //4.7
        static IEnumerable<TResult> ModyfikujElementy<TSource, TResult>(
        IEnumerable<TSource> kolekcja, Func<TSource, TResult> modyfikacja)
        {
            foreach (var element in kolekcja)
            {
                yield return modyfikacja(element);
            }
        }
        //4.10
        static IEnumerable<int> StopJesliUjemna(IEnumerable<int> liczby)
        {
            foreach (var x in liczby)
            {
                if (x < 0)
                {
                    yield break;
                }
                yield return x;
            }
        }
        static void Wyswietl(IEnumerable<int> liczby)
        {
            foreach (var x in liczby)
            {
                Console.WriteLine(x);
            }
        }
        //4.11
        //Jak dobrze rozumiem mamy zliczać ile liczb przed ujemną się wpisało, bo przecież program ma przestać działać jak ktoś poda ujemną liczbę........
        static int LiczbaLiczb(IEnumerable<int> kolekcja)
        {
            return kolekcja.TakeWhile(x => x >= 0).Count();
        }
        //4.12
        static int Sumuj(IEnumerable<int> liczby)
        {
            int suma = 0;
            foreach (var x in liczby)
            {
                if (x >= 0)
                {
                    suma += x;
                }
            }
            return suma;
        }
        //4.13
        static IEnumerable<int> Buforuj(IEnumerable<int> liczby)
        {
            var lista = liczby.ToList();
            foreach (var x in lista)
            {
                yield return x;
                if (x < 0)
                {
                    break;
                }
            }
        }
        //4.14
        static void WyswietlOdwrotnie(IEnumerable<int> liczby)
        {
            var lista = new List<int>();
            foreach (var x in liczby)
            {
                lista.Add(x);
            }
            for (int i = lista.Count - 1; i >= 0; i--)
            {
                Console.WriteLine(lista[i]);
            }
        }


        static void Main(string[] args)
        {
            //1
            Console.WriteLine("zad1:");
            foreach (var x in PobierzLiczby())
            {
                Console.WriteLine(x);
            }
            //2
            Console.WriteLine("zad2:");
            foreach (var x in TylkoParzyste(PobierzLiczby()))
            {
                Console.WriteLine(x);
            }
            //5
            Console.WriteLine("zad5:");
            foreach (var x in DoKwadratu(PobierzLiczby()))
            {
                Console.WriteLine(x);
            }
            //6
            Console.WriteLine("zad6:");
            foreach (var x in ModyfikujLiczby(PobierzLiczby(), l => l * l + 1))
            {
                Console.WriteLine(x);
            }
            //7
            Console.WriteLine("zad7:");
            var listaLiczb = new List<int> { 1, 2, 3, 4, 5 };
            var listaKwadratow = ModyfikujElementy(listaLiczb, l => l * l);
            foreach (var kwadrat in listaKwadratow)
            {
                Console.WriteLine(kwadrat);
            }
            //10
            Console.WriteLine("zad10:");
            Wyswietl(StopJesliUjemna(PobierzLiczby()));
            //11
            Console.WriteLine("zad11:");
            Console.WriteLine(LiczbaLiczb(StopJesliUjemna(PobierzLiczby())));
            //12
            Console.WriteLine("zad12:");
            Console.WriteLine(Sumuj(StopJesliUjemna(PobierzLiczby())));
            //13
            Console.WriteLine("zad13:");
            Wyswietl(Buforuj(StopJesliUjemna(PobierzLiczby())));
            //14
            Console.WriteLine("zad14:");
            WyswietlOdwrotnie(PobierzLiczby());
        }

    }
}

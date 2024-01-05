using System;
using System.Collections.Generic;
using System.Security.Principal;

namespace lab9
{
    //zad6
    interface IWyswietlaczListy
    {
        void WyswietlListe(List<string> lista);
    }

    class WyswietlaczListyGwiazdki : IWyswietlaczListy
    {
        public void WyswietlListe(List<string> lista)
        {
            foreach (var element in lista)
            {
                Console.WriteLine($"* {element}");
            }
        }
    }
    class WyswietlaczListyHTML : IWyswietlaczListy
    {
        public void WyswietlListe(List<string> lista)
        {
            Console.WriteLine("<ul>");
            foreach (var element in lista)
            {
                Console.WriteLine($"<li>{element}</li>");
            }
            Console.WriteLine("</ul>");
        }
    }
    class WyswietlaczListyMarkdown : IWyswietlaczListy
    {
        public void WyswietlListe(List<string> lista)
        {
            foreach (var element in lista)
            {
                Console.WriteLine($"- {element}");
            }
        }
    }

    //main
    public class Program
    {
        static void Main(string[] args)
        {
            //zad1
            Func<T2, T1, TResult> Odwroc<T1, T2, TResult>(Func<T1, T2, TResult> funkcja)
            {
                return (arg2, arg1) => funkcja(arg1, arg2);
            }
            Func<double, double, double> funkcja1 = (a, b) => a / b;
            var x1 = 10;
            var x2 = 2;
            var wynik1=funkcja1(x1, x2);
            var funkcja2 = Odwroc(funkcja1);
            var wynik2=funkcja2(x2, x1);
            if (wynik1==wynik2) { Console.WriteLine("Zad1. OK"); }
            else { Console.WriteLine("Zad1. Blad"); }


            //zad2
            Func<T1, TResult> Zloz<T1, T2, TResult>(Func<T1, T2> funkcja1, Func<T2, TResult> funkcja2)
            {
                return arg1 => funkcja2(funkcja1(arg1));
            }
            Func<double, double> funkcja21 = a => a * a;
            Func<double, double> funkcja22 = b => b * 2;

            var funkcja3 = Zloz(funkcja21, funkcja22);
            var wynik = funkcja3(10);
            if (wynik == 200) { Console.WriteLine("Zad2. OK"); }
            else { Console.WriteLine("Zad2. Blad"); }

            //zad4
            Console.WriteLine("Zad4. Wykonanie hello world x razy");
            void PowtorzAkcje(Action akcja, int iloscRazy)
            {
                for (int i = 0; i < iloscRazy; i++)
                {
                    akcja.Invoke();
                }
            }
            PowtorzAkcje(() => Console.WriteLine("Paradygmaty Programowania zad4"), 5);

            //zad5
            Action<T> Powtorz<T>(int iloscPowtorzen, Action<T> akcja)
            {
                return (arg) =>
                {
                    for (int i = 0; i < iloscPowtorzen; i++)
                    {
                        akcja.Invoke(arg);
                    }
                };
            }
            Console.WriteLine("Zad5. Ala ma kota 10x");
            var akcja = Powtorz<string>(10, Console.WriteLine);
            akcja("Ala ma kota");
            ////zad6
            List<string> lista = new List<string>()
            {
                "Paradygmaty Programowania",
                "Programowanie Niskopoziomowe",
                "Systemy Operacyjne",
                "Programowanie obiektowe",
                "Grafika Komputerowa",
                "Inzynieria oprogramowania",
                "Jezyk Angielski"
            };

            Console.WriteLine("Jak chcesz wyświetlić listę elementów?");
            Console.WriteLine("1 - Każdy element w osobnej linii rozpoczynający się od *");
            Console.WriteLine("2 - Lista HTML");
            Console.WriteLine("3 - Lista Markdown");
            string wybor = Console.ReadLine();
            IWyswietlaczListy wyswietlacz;
            switch (wybor)
            {
                case "1":
                    wyswietlacz = new WyswietlaczListyGwiazdki();
                    break;
                case "2":
                    wyswietlacz = new WyswietlaczListyHTML();
                    break;
                case "3":
                    wyswietlacz = new WyswietlaczListyMarkdown();
                    break;
                default:
                    Console.WriteLine("Niepoprawny wybór.");
                    return;
            }

            wyswietlacz.WyswietlListe(lista);
            //zad11
            Func<T, TResult> Memoryzacja<T, TResult>(Func<T, TResult> func)
            {
                var cache = new Dictionary<T, TResult>();

                return arg =>
                {
                    if (cache.ContainsKey(arg))
                    {
                        return cache[arg];
                    }
                    else
                    {
                        var result = func(arg);
                        cache[arg] = result;
                        return result;
                    }
                };
            }

            Console.WriteLine("Zad11. Memoryzacja");
            Func<int, int> funkcja111 = x => x + 1;
            var funkcja112 = Memoryzacja(funkcja111);
            Console.WriteLine(funkcja112(1));
            Console.WriteLine(funkcja112(1));
        }

    }
}

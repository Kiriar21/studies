using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace cwiczenie
{
    public class Student<S> : Element<S>
    {
        public string Imie { get; set; }
        public string Nazwisko { get; set; }
        public S NrIndeksu { get; set; }
        public List<Ocena<float, S>> Oceny = new(); //pamietac trzeba o przypisaniu tego new(), albo new List<Ocena<float,S>>()

        public void Dodaj(Ocena<float,S> ocena)
        {
            if (Walidacja(ocena.Przedmiot))
            {
                Console.WriteLine("Nie mozna dodac drugi raz tego samego przedmiotu.");
            }
            else if (Walidacja(ocena.Wartosc))
            {
                Console.WriteLine("Nie mozna dodac przedmiotu z taka ocena, bo jest ona niezgodna z dostępnymi ocenami.");
            }
            else 
            {
                //Do zadania na 3 - cala reszta to otoczka do zadania na 5
                Oceny.Add(ocena);
            }
        }
        public Student(string imie, string nazwisko, S id)
        {
            base.Id = NrIndeksu = id; //przypisuje id do id z Elementu
            Imie = imie; 
            Nazwisko = nazwisko;
        }
        public override string ToString() // proste nadpisanie ToStringa
        {
            string result = "";
            string basic = $"Student: {this.Imie} {this.Nazwisko} Indeks: {this.NrIndeksu}\nOceny tego studenta:\n";
            foreach (var x in Oceny)
            {
                result += x.ToString();
            }
            if (Oceny.Count() > 0)
            {
               return result;
            }
            else
            {
                return $"{basic}Niestety, ale ten student nie posiada ŻADNYCH ocen.";
            }
        }
        public void Wyswietl() // służy do szybkiego wyświetlenia info o studencie
        {
            Console.WriteLine(ToString());
        }
        //Na ocene 4
        public void Usun(Ocena<float,S> o) // usuwa ocene
        {
            if (Oceny.Remove(o))
            {
                Console.WriteLine("Przedmiot wraz z ocena został usuniety.");
            }
            else
            {
                Console.WriteLine("Brak przedmiotu o podanych wartosciach.");
            }
        }
        public void Srednia() // wyswietla srednia studenta, o ile on ma jakies oceny
        {
            float wartosc=0.00f;
            foreach(var ele in Oceny)
            {
                wartosc += ele.Wartosc;
            }
            if (Oceny.Count > 0)
            {
                Console.WriteLine($"Średnia studenta wynosi: {wartosc / Oceny.Count:F2}"); //:F2  - ograniczenie do 2 miejsc po przecinku
            }
            else
            {
                Console.WriteLine("Niestety, ale ten student nie ma żadnych ocen więc obliczenie średniej jest NIEMOŻLIWE.");
            }
        }
        
        // Na ocene 5
        public void Wyszukaj(string przedmiot) // wyszukiwanie przedmiotu po nazwie przedmiotu
        {
            string result = "";

            foreach(var x in Oceny)
            {
                if(x.Przedmiot.Trim() == przedmiot)
                {
                    result += x.ToString();
                    break; // bedzie tylko jeden przedmiot z ocena wiec mozemy zakonczyc
                }
            }
            if (result == "")
            {
                Console.WriteLine($"Brak oceny z przedmiotu o podanej nazwie => {przedmiot}");
            }
            else
            {
                Console.WriteLine($"Wynik dla => {przedmiot}\n{result}");
            }
        }
        public void Wyszukaj(float ocena) // wyszukiwanie przedmiotów po ocenie z przedmiotów
        {
            string result = "";
            foreach(var x in Oceny)
            {
                if(x.Wartosc== ocena)
                {
                    result += x.ToString(); // moze byc duzo przedmiotow z jakas ocena
                }
            }
            if(ocena!=2.0f && ocena!=3.0f && ocena!=3.5f && ocena!=4.0f && ocena!=4.5f && ocena != 5.0f)  // ocena nie moze byc rozna niz te ktore mozemy dostac
            {
                Console.WriteLine($"Podana wartosc => {ocena} nie odpowiada zadnej ocenie.");
            }
            else if (result == "")
            {
                Console.WriteLine($"Brak ocen o podanej wartosci => {ocena}");
            }
            else
            {
                Console.WriteLine($"Lista ocen o wartosci => {ocena}\n{result}");
            }
        }
        public void Edytuj(string przedmiot, float ocena)
        {
            if (ocena != 2.0f && ocena != 3.0f && ocena != 3.5f && ocena != 4.0f && ocena != 4.5f && ocena != 5.0f)
            {
                Console.WriteLine("Nie mozna zmienic oceny na podaną. Wprowadz poprawna wartosc");
            }
            else
            {
                bool check = false;
                foreach (var x in Oceny)
                {
                    if (x.Przedmiot.Trim() == przedmiot)
                    {
                        x.Wartosc = ocena;
                        check = true;
                        break;
                    }
                }
                if (check)
                {
                    Console.WriteLine("Ocena została zmieniona.");
                }
                else
                {
                    Console.WriteLine("Nie znaleziono przedmiotu o podanej nazwie.");
                }
            }
        }
        public bool Walidacja(string przedmiot) // sprawdza czy przedmiot istnieje juz dla danego studenta
        {
            bool result = false;
            foreach(var x in Oceny) 
            {
                if (x.Przedmiot.Trim() == przedmiot) result = true;
            }
            return result;
        } 
        public bool Walidacja(float ocena) // sprawdza czy ocena jest poprawna
        {
            bool result = true;
            if (ocena == 2.0f || ocena == 3.0f || ocena == 3.5f || ocena == 4.0f || ocena == 4.5f || ocena == 5.0f)
            {
                result = false;
            }
            return result;
        }



    }
}

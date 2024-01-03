//zad 1
using System;
using System.Collections.Generic;
using System.Security.Principal;

public class Ksiazka
{
    private readonly string _id;
    private readonly List<string> _authors;
    private readonly string _title;
    private readonly int _publicationYear;
    private readonly Price _price;

    public Ksiazka(string id, List<string> authors, string title, int publicationYear, Price price)
    {
        if (authors == null || authors.Count == 0)
        {
            throw new ArgumentException("At least one author is required.");
        }

        if (string.IsNullOrWhiteSpace(title) || title.Length > 50)
        {
            throw new ArgumentException("Invalid title.");
        }

        if (publicationYear < 2015 || publicationYear > DateTime.Now.Year + 1)
        {
            throw new ArgumentException("Invalid publication year.");
        }

        _id = id;
        _authors = authors;
        _title = title;
        _publicationYear = publicationYear;
        _price = price;
    }

    public string Id { get { return _id; } }
    public IReadOnlyList<string> Authors { get { return _authors.AsReadOnly(); } }
    public string Title { get { return _title; } }
    public int PublicationYear { get { return _publicationYear; } }
    public Price Price { get { return _price; } }
}

public class Price
{
    private readonly decimal _amount;
    private readonly string _currency;

    public Price(decimal amount, string currency)
    {
        if (string.IsNullOrWhiteSpace(currency))
        {
            throw new ArgumentException("Currency cannot be null or empty.");
        }

        _amount = amount;
        _currency = currency;
    }

    public decimal Amount { get { return _amount; } }
    public string Currency { get { return _currency; } }
}

//zad 2
public class Ksiazka1
{
    private readonly string id;
    private readonly IReadOnlyList<string> authors; // lista tylko do odczytu
    private readonly string title;
    private readonly int publicationYear;
    private readonly Price price;

    public Ksiazka1(string id, IReadOnlyList<string> authors, string title, int publicationYear, Price price)
    {
        if (!IsValidId(id))
        {
            throw new ArgumentException("Invalid ID format");
        }

        if (authors.Count == 0)
        {
            throw new ArgumentException("There must be at least one author");
        }

        if (string.IsNullOrWhiteSpace(title) || title.Length > 50)
        {
            throw new ArgumentException("Title must be between 1 and 50 characters long");
        }

        if (publicationYear < 2015 || publicationYear > DateTime.Now.Year + 1)
        {
            throw new ArgumentException("Invalid publication year");
        }

        this.id = id;
        this.authors = authors;
        this.title = title;
        this.publicationYear = publicationYear;
        this.price = price;
    }

    public string Id => id;

    public IReadOnlyList<string> Authors => authors;

    public string Title => title;

    public int PublicationYear => publicationYear;

    public Price Price => price;

    private bool IsValidId(string id)
    {
        if (string.IsNullOrEmpty(id) || id.Length != 9)
        {
            return false;
        }

        if (id[0] != 'B' || id[1] != '-')
        {
            return false;
        }

        int year;
        if (!int.TryParse(id.Substring(2, 2), out year) || year < 0 || year > 99)
        {
            return false;
        }

        int number;
        if (!int.TryParse(id.Substring(5, 3), out number) || number < 1 || number > 999)
        {
            return false;
        }

        return true;
    }
}

//zad 3
public record Ksiazka2
{
    public string Id { get; init; }
    public IReadOnlyList<string> Authors { get; init; }
    public string Title { get; init; }
    public int PublicationYear { get; init; }
    public Price Price { get; init; }

    public Ksiazka2(string id, IReadOnlyList<string> authors, string title, int publicationYear, Price price)
    {
        if (!IsValidId(id))
        {
            throw new ArgumentException("Invalid ID format");
        }

        if (authors.Count == 0)
        {
            throw new ArgumentException("There must be at least one author");
        }

        if (string.IsNullOrWhiteSpace(title) || title.Length > 50)
        {
            throw new ArgumentException("Title must be between 1 and 50 characters long");
        }

        if (publicationYear < 2015 || publicationYear > DateTime.Now.Year + 1)
        {
            throw new ArgumentException("Invalid publication year");
        }

        Id = id;
        Authors = authors;
        Title = title;
        PublicationYear = publicationYear;
        Price = price;
    }

    private static bool IsValidId(string id)
    {
        if (string.IsNullOrEmpty(id) || id.Length != 9)
        {
            return false;
        }

        if (id[0] != 'B' || id[1] != '-')
        {
            return false;
        }

        int year;
        if (!int.TryParse(id.Substring(2, 2), out year) || year < 0 || year > 99)
        {
            return false;
        }

        int number;
        if (!int.TryParse(id.Substring(5, 3), out number) || number < 1 || number > 999)
        {
            return false;
        }

        return true;
    }
}

//zad 4
public class Blog
{
    private int _id;
    private string _nazwa;
    private Autor _autor;
    private List<Artykul> _artykuly;
    public string Nazwa { get; set; }
    public Autor autor { get; set; }
    public Blog(string nazwa, Autor a)
    {
        Nazwa = nazwa;
        autor = a;
        _artykuly = new List<Artykul>();
    }
    public void dodajArtykul(Artykul a)
    {
        _artykuly.Add(a);
    }
    public List<string> pobierzTytulyArtykulow()
    {
        List<string> result = new List<string>();
        foreach(var x in  _artykuly)
        {
            result.Add(x.Tytul);
        }
        return result;
    }
    public Artykul pobierzArtykul(string tytul)
    {
        Artykul xxxx=new Artykul();
        foreach(var x in _artykuly)
        {
            if (x.Tytul == tytul)
            {
                xxxx = x;
                break;
            }
        }
        return xxxx;
    }

}
public class Artykul
{
    private int _id;
    private string _tytul;
    private string _tresc;
    private DateTime _dataUtworzenia;
    private List<Komentarz> _komentarze;
    public string Tytul { get; set; }
    public string Tresc { get; set; }

    public Artykul(string tytul, string tresc)
    {
        Tytul= tytul;
        Tresc= tresc;
        _komentarze = new List<Komentarz>();
    }
    public Artykul() : this("none","none") {} 
    public void dodajKomentarz(Komentarz komentarz)
    {
        _komentarze.Add(komentarz);
    }
    public List<Komentarz> pobierzKomentarze()
    {
        return _komentarze;
    }

}
public class Komentarz
{
    private string _tresc;
    private DateTime _data;
    private List<Komentarz> _odpowiedzi;
    private string _nick;
    public string Tresc { get; set; }
    public DateTime Data { get; set; }
    public string Nick { get; set; }

    public Komentarz(string tresc, string nick)
    {
        Tresc=tresc;
        Nick=nick;
        _odpowiedzi = new List<Komentarz>();
    }
    public Komentarz() : this("none","none") { }
    public void dodajOdpowiedz (Komentarz komentarz)
    {
        _odpowiedzi.Add(komentarz);
    }
    public List<Komentarz> pobierzOdpowiedzi()
    {
        return _odpowiedzi;
    }

}
public class Autor
{
    private static int _id=0;
    private string _imie;
    private string _nazwisko;
    private string _email;
    public string  Imie { get; set; }
    public string  Nazwisko { get; set; }
    public string Email { get; set; }

    public Autor(string imie, string nazwisko)
    {
        Imie=imie;
        Nazwisko=nazwisko;
        _id = ++_id;
    }
}
//main 

class Program
{
    static void Main(string[] args)
    {
        var price = new Price(39.99m, "PLN");

        var book = new Ksiazka("B-00-001", new List<string> { "J.K. Rowling" }, "Harry Potter and the Philosopher's Stone", 2016, price);

        Console.WriteLine("ID: {0}", book.Id);
        Console.WriteLine("Author(s): {0}", string.Join(", ", book.Authors));
        Console.WriteLine("Title: {0}", book.Title);
        Console.WriteLine("Publication year: {0}", book.PublicationYear);
        Console.WriteLine("Price: {0} {1}", book.Price.Amount, book.Price.Currency);

        //pusta lista autorów
        try
        {
            var book3 = new Ksiazka("B-00-002", new List<string>(), "The Great Gatsby", 1925, price);
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine(ex.Message);
        }

        //tytul
        try
        {
            var book4 = new Ksiazka("B-00-003", new List<string> { "Ernest Hemingway" }, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 1926, price);
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine(ex.Message);
        }

        //rok zly
        try
        {
            var book5 = new Ksiazka("B-00-004", new List<string> { "George Orwell" }, "1984", 1949, price);
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine(ex.Message);
        }


        //zad7
        var stack = new Stack<double>();
        string input;

        do
        {   
            Console.WriteLine("Podaj wartość");
            input = Console.ReadLine();

            if (double.TryParse(input, out double number))
            {
                stack.Push(number);
            }
            else if (input == "+" && stack.Count >= 2)
            {
                double b = stack.Pop();
                double a = stack.Pop();
                stack.Push(a + b);
            }
            else if (input == "-" && stack.Count >= 2)
            {
                double b = stack.Pop();
                double a = stack.Pop();
                stack.Push(a - b);
            }
            else if (input == "*" && stack.Count >= 2)
            {
                double b = stack.Pop();
                double a = stack.Pop();
                stack.Push(a * b);
            }
            else if (input == "/" && stack.Count >= 2)
            {
                double b = stack.Pop();
                double a = stack.Pop();
                stack.Push(a / b);
            }
            else if (input == "=" && stack.Count == 1)
            {
                Console.WriteLine(stack.Pop());
            }
            else
            {
                Console.WriteLine("Invalid input");
            }
        } while (input != "=");
    }
}
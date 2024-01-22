using System;
using System.Collections.Generic;

namespace zadanie3
{
    public class main
    {
        static void Main(string[] args)
        {
            Item item1 = new Journal("JAISCR", 1, "Springer", new DateTime(2000, 1, 1), 1);
            Author author = new Author("Robert", "Cook", "Polish");
            Item item2 = new Book("Agile C#", 2, "SPRINGER", new DateTime(2015, 1, 1), 500, new List<Author>() { author });
            ((Book)item2).AddAuthor(author);
            var bookBarCode = ((Book)item2).GenerateBarCode(); 
            var journalBarCode = ((Journal)item1).GenerateBarCode();
            Console.WriteLine($"{item1} \r\n Barcode {journalBarCode}"); 
            Console.WriteLine($"{item2} \r\n Barcode {bookBarCode}");
            List<Item> items = new List<Item>();
            items.Add(item1); 
            items.Add(item2); 
            Catalog catalog = new Catalog("IT C# development", items);
            catalog.AddItem(new Journal("Neurocomputing", 1, "IEEE", new DateTime(2020, 1, 1), 1));
            Console.WriteLine(catalog);
            catalog.ShowAllItems();
            //--- find position
            Console.WriteLine("\n\n\n1. Początkowe drugiego kodu.\n\n\n");
            string searchedValue = "Agile C#";
            Item foundedItemById = catalog.FindItem(item => item.Id == 1);
            Item foundedItemByTitle = catalog.FindItem(item => item.Title == searchedValue);
            Item foundedItemByDateRange = catalog.FindItem(item => item.DateOfIssue >= new DateTime(2014, 12, 31) && item.DateOfIssue <= new DateTime(2015, 12, 31));
            Console.WriteLine("++++++++++++++++++++++++++++++++++");
            Console.WriteLine("1.1 Szukanie po id (id = 1) \n");
            Console.WriteLine(foundedItemById);
            Console.WriteLine("1.2 Szukanie po tytule (tytul = Agile C#) \n");
            Console.WriteLine(foundedItemByTitle); 
            Console.WriteLine("1.3 Szukanie po zakresie dat (zakres daty 2014.12.31 - 2015.12.31 )\n");
            Console.WriteLine(foundedItemByDateRange);
            Console.WriteLine("\n\n\n2. Druga czesc - szukanie po jakims old\n\n\n");
            Item foundedItemByIdOld = catalog.FindItemBy(1);
            Item foundedItemByTitleOld = catalog.FindItemBy(searchedValue);
            Console.WriteLine("Found old way");
            Console.WriteLine("2.1 Szukanie old po id (id=1)\n");
            Console.WriteLine(foundedItemByIdOld); 
            Console.WriteLine("2.2 Szukanie old po tytule (tytul = Agile C# )\n");
            Console.WriteLine(foundedItemByTitleOld); 
            Console.WriteLine("++++++++++++++++++++++++++++++++++"); 
            Person librarian = new Librarian("John", "Kowalsky", DateTime.Now.Date, 2000);
            Library library = new Library("Czestochowa, Armii Krajowej 36", new List<Librarian>(), new List<Catalog>());
            library.AddLibrarian((Librarian)librarian);
            Console.WriteLine("\n\n\n3. Bibliotekarze - wszyscy: \n\n\n");
            library.ShowAllLibrarians();
            Catalog catalog2 = new Catalog("Novels", new List<Item>());
            library.AddCatalog(catalog2);
            library.AddCatalog(catalog);
            Item newItem = new Book("Song of Ice and Fire", 4, "Publisher", new DateTime(2011, 1, 1), 800, new List<Author>() { author });
            library.AddItem(newItem, "Novels");
            Console.WriteLine("3.1 Wyswietlenie bilbioteki \n");
            Console.WriteLine(library);
            Console.WriteLine("===========================All Items=======================\r\n");
            Console.WriteLine("\n\n\n4. Biblioteka\n\n\n4.1 Wyswietlenie wszystkich itemow\n");
            library.ShowAllItems();
            Console.WriteLine("===========================FIND BY=======================\r\n");
            var foundedById = library.FindItemBy(4);
            var foundedByTitle = library.FindItemBy(searchedValue);
            var foundedByLambda = library.FindItem(x => x.Publisher == "Springer");
            Console.WriteLine("4.1 Szukanie old po id (id=4)\n");
            Console.WriteLine(foundedById);
            Console.WriteLine("4.2 Szukanie old po tytule (tytul=Agile C#)\n");
            Console.WriteLine(foundedByTitle);
            Console.WriteLine("4.3 Szukanie old po lamdzie (Publisher=Springer) \n");
            Console.WriteLine(foundedByLambda);
        }
    }
}

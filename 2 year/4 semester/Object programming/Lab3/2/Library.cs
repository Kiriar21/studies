using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace zadanie3
{
    public class Library : IItemManagment
    {
        public string Address { get; set; }
        public List<Librarian> Librarians { get; set; }
        public List<Catalog> Catalog { get; set; }
        public Library(string address, List<Librarian> librarians, List<Catalog> catalogs)
        {
            Address = address;
            Librarians = new List<Librarian>();
            foreach (Librarian lib in librarians)
            {
                Librarians.Add(lib);
            }
            Catalog = new List<Catalog>();
            foreach (Catalog catalog in catalogs)
            {
                Catalog.Add(catalog);
            }
        }
        public void AddLibrarian(Librarian librarian)
        {
            Librarians.Add((Librarian)librarian);
        }
        public void ShowAllLibrarians()
        {
            foreach (Librarian librarian in Librarians)
            {
                Console.WriteLine($"{librarian}\n");
            }
        }
        public void AddCatalog(Catalog catalog)
        {
            Catalog.Add((Catalog)catalog);
        }
        public void AddItem(Item item, string thematic)
        {
            foreach (var cat in Catalog)
            {
                if (cat.ThematicDepartment == thematic) cat.AddItem(item);
            }
        }
        public void ShowAllItems()
        {
            foreach (var cat in Catalog)
            {
                foreach (var item in cat.Items)
                {
                    Console.WriteLine($"{item}\n");
                }
            }
        }



        public Item FindItem(Expression<Func<Item, bool>> precidate)
        {
            //??            
            return null;
        }
        public Item FindItemBy(string title)
        {
            Item item1 = null;
            foreach (var cat in Catalog)
            {
                foreach (var item in cat.Items)
                {
                    if (item.Title == title) item1 = item;
                }
            }
            return item1;
        }
        public Item FindItemBy(int id)
        {
            Item item1 = null;
            foreach (var cat in Catalog)
            {
                foreach (var item in cat.Items)
                {
                    if (item.Id == id ) item1 = item;
                }
            }
            return item1;
        }
        public override string ToString()
        {
            return $"Address library = {Address}";
        }
    }
}

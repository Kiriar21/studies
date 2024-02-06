using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    public class Library : IItemManagement
    {
        public string Address { get; set; }
        public List<Librarian> Librarians { get; set; }
        public List<Catalog> Catalogs { get; set; }
        public Library(string address, List<Librarian> librarianList, List<Catalog> catalogList)
        {
            Address = address;
            Librarians = new List<Librarian>();
            Catalogs = new List<Catalog>();
            foreach (Catalog catalog in catalogList)
            {
                Catalogs.Add(catalog);
            }
            foreach (Librarian librarian in librarianList)
            {
                Librarians.Add(librarian);
            }
        }
        public void AddLibrarian(Librarian librarian)
        {
            Librarians.Add(librarian);
        }
        public void ShowAllLibrarians()
        {
            foreach(Librarian library in Librarians)
            {
                Console.WriteLine(library);
            }
        }
        public void AddCatalog(Catalog catalog)
        {
            Catalogs.Add((Catalog)catalog);
        }
        public void AddItem(Item item, string td)
        {
            foreach(Catalog cat in Catalogs)
            {
                if (cat.ThematicDepartment == td) cat.AddItem(item);
            }
        }
        public void ShowAllItems()
        {
            foreach(Catalog catalog in Catalogs)
            {
                foreach(Item item in catalog.Items)
                {
                    Console.WriteLine(item);
                }
            }
        }
        public Item FindItem(Expression<Func<Item, bool>> predicate)
        {
            return null;
        }
        public Item FindItemBy(string title)
        {
            Item result = null;
            foreach (Catalog catalog in Catalogs)
            {
                foreach (Item item in catalog.Items)
                {
                    if(item.Title == title)
                    {
                        result = item;
                    }
                }
            }
            return result;
        }
        public Item FindItemBy(int id)
        {
            Item result = null;
            foreach (Catalog catalog in Catalogs)
            {
                foreach (Item item in catalog.Items)
                {
                    if (item.Id == id)
                    {
                        result = item;
                    }
                }
            }
            return result;
        }
        public override string ToString()
        {
            return "cos8";
        }
    }

}

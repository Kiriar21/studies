using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    public class Book:Item
    {
        public int PageCount { get; set; }
        public List<Author> Authors { get; set; }
        public Book(string title, int id, string pub, DateTime dat, int pageCount, List <Author> authors) : base(title, id, pub, dat)
        {
            PageCount = pageCount;
            Authors = new List<Author>();
            foreach(var x in authors)
            {
                Authors.Add(x);
            }
        }
        public override string ToString()
        {
            return "cos2";
        }
        public override string GenerateBarCode()
        {
            return $"Book{PageCount}";
        }
        public void AddAuthor(Author aut)
        {
            Authors.Add(aut);
        }
    }
}

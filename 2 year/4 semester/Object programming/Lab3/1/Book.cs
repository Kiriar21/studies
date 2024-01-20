using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie3
{
    public class Book:Item
    {
        public int PageCount { get; set; }
        public List<Author> Authors { get; set; }
        public Book(string title,int id,string publisher, DateTime dateOfIssue, int pageCount, List<Author> authors) : base(title, id, publisher, DateTime.Now)
        {
            PageCount = pageCount;
            Authors = new List<Author>();
            foreach (Author author in authors)
            {
                Authors.Add(author);
            }
        }
        public override string ToString()
        {
            return $"{base.ToString()}\n{Title}\n";
        }
        public override string GenerateBarCode()
        {
            return $"Book{base.Id}";
        }
        public void AddAuthor(Author author)
        {
            Authors.Add(author);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArturMatuszczyk
{
    public class Invoice : Document
    {
        public DateTime Date { get; set; }
        public List<InvoiceItem> Items { get; set; }

        public Invoice(List<InvoiceItem> items, string id)
        {
            base.ID = id;
            Date = DateTime.Now;
            Items = new();
            foreach(InvoiceItem item in items)
            {
                Items.Add(item);
            }
        }


        public float Value { get
            {
                float res=0.0f;
                foreach (var item in Items)
                {
                    res += item.Value;
                }
                return res; 
            }
        }
        
        public new void Print() 
        {
            Console.WriteLine($"Invoice, ID: {base.ID}  Date: {Date} Value: {Value}\nItems:");
            foreach( var item in Items)
            {
                Console.WriteLine(item.ToString());
            }
        }

    }
}

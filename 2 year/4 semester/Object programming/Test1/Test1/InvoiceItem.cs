using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArturMatuszczyk
{
    public class InvoiceItem
    {
        public float Amount { get; set; }
        public string Name { get; set; }
        public float Price { get; set; }
        public float Value { get
            {
               return (Amount * Price);
            }
        } 
        public InvoiceItem(float a, string n, float p)
        {
            Amount = a;
            Name = n;
            Price = p;
        }

    }
}

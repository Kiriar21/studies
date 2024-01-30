using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArturMatuszczyk
{
    public class System
    {
        public List<Client> Clients { get; set; }
        public List<Invoice> Invoices { get; set; }

        public System()
        {
            Clients = new List<Client>();
            Invoices = new List<Invoice>();
        }

        public void Add(Client c)
        {
            Clients.Add(c);
        }
        public void Add(Invoice c)
        {
            Invoices.Add(c);
        }
        public void Remove(Client c)
        {
            if (Clients.Remove(c))
            {
                Console.WriteLine("Usunieto kllienta.");
            }
            else
            {
                Console.WriteLine("Nie znaleziono klienta.");
            }
        } 
        public void Remove(Invoice c)
        {
            if (Invoices.Remove(c))
            {
                Console.WriteLine("Usunieto fakture.");
            }
            else
            {
                Console.WriteLine("Nie znaleziono faktury.");
            }
        }

        public Client Find(string name)
        {
            return Clients.FirstOrDefault(x => x.Name == name);
        }
        public Invoice FindById(string id)
        {
            Invoice res = null;
            foreach( var x in Invoices)
            {
                if(x.ID == id)
                {
                    res = x;
                }
            }
            return res;
        }
        public void AllInfo()
        {
            Console.WriteLine("Wszyscy klienci:");
            foreach( var x in Clients)
            {
                x.Print();
            }
        }
        public void InvoicesClient(Client c)
        {
            foreach(var x in Clients)
            {
                if(c.ID == x.ID)
                {
                    foreach( var y in Invoices)
                    {
                        y.Print();
                    }
                }
            }
        }
    }
}

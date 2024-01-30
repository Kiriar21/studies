using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArturMatuszczyk
{
    public class Client : User<string>
    {
        private string v1;
        private string v2;
        private string v3;

        public string Address { get; set; }
        public Client(string add, User<string> name, string id)
        {
            base.ID = id;
            base.Name = name.Name;
            Address = add;
        }

        public Client(string v1, string v2, string v3)
        {
            this.v1 = v1;
            this.v2 = v2;
            this.v3 = v3;
        }

        public new void Print()
        {
            Console.WriteLine($"{base.ID} {base.Name}\nAddress: {Address}");
        }
    }
}

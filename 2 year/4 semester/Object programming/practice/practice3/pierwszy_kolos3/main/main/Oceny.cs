using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace main
{
    public class Oceny
    {
        public float ocena { get; set; }
        public string przedmiot { get; set; }
        public Oceny() { ocena = 2.0f; przedmiot = string.Empty; }
        public Oceny(float ocena, string przedmiot)
        {
            this.ocena = ocena;
            this.przedmiot = przedmiot;
        }
 
    }
}

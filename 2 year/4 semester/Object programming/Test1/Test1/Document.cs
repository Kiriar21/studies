using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArturMatuszczyk
{
    public abstract class Document
    {
        public string ID { get; set; }
        public virtual void Print() { }
    }
}

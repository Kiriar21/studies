using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArturMatuszczyk
{
    public abstract class User<T>
    {
        public string ID { get; set; }
        public T Name { get; set; }
        public void Print(){}
    }
}

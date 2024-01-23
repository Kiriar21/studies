using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab4
{
    public partial class klasa1generic<Person> 
    {
        private class Node
        {
            public Person value { get; set; }
            public Node next;
        }
        private Node first = null;
        private Node last = null;

        public void Add(Person e)
        {
            if(first == null)
            {
                first = last = new Node() { value = e };
            }
            else
            {
                last = last.next = new Node() { value = e };
            }
        }
        private Node Get(int i)
        {
            var e = first;
            while(i-->0 && e!= null)
            {
                e = e.next;
            }
            if (e == null)
            {
                throw new IndexOutOfRangeException();
            }
            return e;
        }
        public Person this[int i]
        {
            get => Get(i).value; set=>Get(i).value = value;
        }


    }
}

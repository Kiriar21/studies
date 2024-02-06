using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    public class Catalog: IItemManagement
    {
        public List<Item> Items { get; set; }
        public string ThematicDepartment { get; set; }
        public Catalog(string td, List <Item> items)
        {
            ThematicDepartment = td;
            Items = new List<Item>();
            foreach (Item item in items)
            {
                Items.Add(item);
            }
        }
        public Catalog(List <Item> items)
        {
            Items = new List<Item>();
            foreach (Item item in items)
                Items.Add(item);
        }
        public void AddItem(Item item)
        {
            Items.Add(item);
        }
        public Item FindItem(Expression<Func<Item,bool>> predicate)
        {
            return null;
        }
        public Item FindItemBy(string title)
        {
            Item result = null;
            foreach (Item item in Items)
            {
                if (item.Title == title)
                {
                    result = item;
                    break;
                }
            }
            return result;
        }
        public Item FindItemBy(int id)
        {
            Item result = null;
            foreach(Item item in Items)
            {
                if(item.Id == id)
                {
                    result = item;
                }
            }
            return result;
        }
        public override string ToString()
        {
            return "cos7";
        }
        public void ShowAllItems()
        {
            Console.WriteLine(ToString());
        }

    }
}

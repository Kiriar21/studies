using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie3
{
    public class Catalog
    {
        public List<Item> Items { get ; set; }
        public string ThematicDepartment { get; set; }
        public Catalog(List<Item> items) 
        {
            Items = new List<Item>();
            foreach (Item item in items)
            {
                Items.Add(item);
            }
        }
        public Catalog(string thematicDepartment, List<Item> items)
        {
            Items = new List<Item>();
            foreach (Item item in items)
            {
                Items.Add(item);
            }
            ThematicDepartment = thematicDepartment;
        }
        public void AddItem(Item item)
        {
            Items.Add(item);
        }
        public override string ToString() // ?
        {
            string result= $"Thematic = {ThematicDepartment}\n";
            foreach (Item item in Items)
            {
                result += item.ToString() ;
            }
            return result;
        }
        public void ShowAllItems()
        {
            foreach (var item in Items)
            {
                Console.WriteLine(item.ToString());
            }
        }
    }
}

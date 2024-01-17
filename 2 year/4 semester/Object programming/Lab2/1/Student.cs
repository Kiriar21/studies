using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie1
{
    public class Student:Person
    {
        private int _year;
        private int _group;
        private int _indexId;
        public int Year { get { return _year; } set { _year = value; } }
        public int Group { get { return _group; } set { _group = value; } }
        public int IndexId { get { return _indexId; } set { _indexId = value; } }
        public Student(string name, string lname, DateTime date, int year, int group, int index)
        {
            base.FirstName = name;
            base.LastName = lname;
            base.DateOfBirth = date;
            Year = year;
            Group = group;
            IndexId = index;
        }
        public Student() : this("name","name",DateTime.Now, 2000, 1, 100000) { }
        public override string ToString()
        {
            return $"{base.ToString()}\nYear: {Year}, Group: {Group}, Index: {IndexId}";
        }
    }
}

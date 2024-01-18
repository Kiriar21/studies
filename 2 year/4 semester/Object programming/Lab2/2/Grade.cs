using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie1
{
    public class Grade
    {
        private string _subjectName;
        private DateTime _date;
        private double _value;
        public string SubjectName { get { return _subjectName; } set { _subjectName = value; } }
        public DateTime Date { get { return _date; } set { _date = value; } }
        public double Value { get { return _value; } set { _value = value; } }
        public Grade(string subName, double val, DateTime date) 
        {
            _subjectName = subName;
            _date = date;
            _value = val;
        }  
        public Grade() : this("none",5,DateTime.Now) { }
        public override string ToString()
        {
            return $"Subject name: {SubjectName} Grade: {Value} Date: {Date} \n ";
        }
    }
}

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace zadanie1
{
    public class Student : Person
    {
        private int _year;
        private int _group;
        private int _indexId;
        private List<Grade> _grades = new List<Grade>();

        public int Year { get { return _year; } set { _year = value; } }
        public int Group { get { return _group; } set { _group = value; } }
        public int IndexId { get { return _indexId; } set { _indexId = value; } }
        //>????
        public List<Grade> Grades { get { return _grades; } }
        public Student(string name, string lname, DateTime date, int year, int group, int index) : base(name, lname, date)
        {
            Year = year;
            Group = group;
            IndexId = index;
        }
        public Student() : this("name", "name", DateTime.Now, 2000, 1, 100000) { }
        public override string ToString()
        {
            string result = $"{base.ToString()}\nYear: {Year}, Group: {Group}, Index: {IndexId} \n";
            foreach (Grade grade in Grades) 
            { 
                result += grade.ToString();
            }
            return result;
        }

        //zadanie 2
        public void AddGrade(string subjectName, double value, DateTime date)
        {
            Grade grade = new Grade(subjectName, value, date);
            this._grades.Add(grade);
        }
        //>????
        public void AddGrade(Grade grade)
        {
            this._grades.Add((Grade)grade);
        }
        public void DisplayGrades()
        {
            foreach (Grade i in _grades)
            {
                Console.WriteLine(i.ToString());
            }
        }
        public void DisplayGrades(string subjectName)
        {
            foreach (Grade i in Grades)
            {
                if (i.SubjectName == subjectName)
                {
                    Console.WriteLine(i.ToString());
                }
            }
        }
        public void DeleteGrade(string subjectName, double value, DateTime date)
        {
            foreach (Grade grade in Grades)
            {
                if(grade.SubjectName == subjectName && grade.Value == value && grade.Date == date)
                {
                    _grades.Remove(grade);
                    break;
                }
            }
        }
        //??????
        public void DeleteGrade(Grade grade)
        {
            foreach (Grade grade1 in _grades)
            {
                if(grade1 == grade)
                {
                    _grades.Remove(grade1);
                    break;
                }
            }
        }
        public void DeleteGrades(string subjectName)
        {
            //foreach (Grade grade1 in _grades)
            //{
            //    if (grade1.SubjectName == subjectName)
            //    {
            //        _grades.Remove(grade1);
            //    }
            //}
            for(int i=0;i<_grades.Count;i++)
            {
                if (_grades[i].SubjectName == subjectName)
                {
                    _grades.Remove(_grades[i]);
                }
            }
        }
        public void DeleteGrades()
        {
            _grades.Clear();
        }
    }
}

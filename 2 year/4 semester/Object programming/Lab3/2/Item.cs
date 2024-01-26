﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie3
{
    public abstract class Item
    {
        protected int _id;
        protected string _title,_publisher;
        protected DateTime _dateOfIssue;

        public int Id { get { return _id; } set { _id = value; } }
        public string Title { get { return _title; } set { _title = value; } }
        public string Publisher { get { return _publisher; } set { _publisher = value; } }
        public DateTime DateOfIssue { get { return _dateOfIssue; } set { _dateOfIssue = value; } }
        public Item(string title,int id, string publisher, DateTime dateOfIssue)
        {
            _title = title;
            _id = id;
            _publisher = publisher;
            _dateOfIssue = dateOfIssue;
        }
        public Item() : this("none", 1, "none", DateTime.Now) { }
        public override string ToString()
        {
            return ($"IDKey = {Id} Title = '{Title}' Publisher = {Publisher} \nDate = {DateOfIssue}");
        }
        public void Details()
        {
            Console.WriteLine(ToString());
        }
        public abstract string GenerateBarCode();
    }
}
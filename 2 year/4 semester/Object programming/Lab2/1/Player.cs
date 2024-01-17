using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie1
{
    public class Player:Person
    {
        private string _position;
        private string _club;
        private int _scoredGoals;

        public string Position { get { return _position; } set { _position = value; }  }
        public string Club{ get { return _club; } set { _club = value; } }
        public int ScoredGoals { get { return _scoredGoals;  } set { _scoredGoals = value; } }
        public Player(string name, string lname, DateTime date, string position, string club, int scoredGoals) 
        {
            base.FirstName = name;
            base.LastName = lname;
            base.DateOfBirth = date;
            Position = position;
            Club = club;
            ScoredGoals = scoredGoals;
        }
        public Player() : this("name", "name", DateTime.Now,"N","None",0) { }
        public override string ToString()
        {
            return $"{base.ToString()}\nPosition: {Position} Club: {Club} Score Goals: {ScoredGoals}";
        }
        public void ScoreGoal()
        {
            Console.WriteLine($"{ScoredGoals}");
            ScoredGoals++;
        }
    }
}

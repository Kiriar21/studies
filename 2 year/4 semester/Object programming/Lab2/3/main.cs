﻿using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace zadanie1
{
    public class main
    {
        static void Main(string[] args)
        {
            Person person1 = new Person("Adam", "Miś", new DateTime(1990, 3, 20, 12, 30, 10));
            Person person2 = new Student("Michał", "Kot", new DateTime(1990, 4, 13), 3, 5, 12345);
            Person person3 = new Player("Robert", "Lewandowski", new DateTime(1988, 10, 3), "Striker", "Bayern", 41);
            //person1.Details();
            //person2.Details();
            //person3.Details();
            Student student = new Student("Krzysztof", "Jeż", new DateTime(1990, 12, 29), 2, 5, 54321);
            //student.Details();
            //((Player)person3).ScoreGoal();
            //person3.Details();

            //Kod testujacy do tego zadania 
            ((Student)person2).AddGrade("PO", 5.0D, new DateTime(2011, 2, 20));
            ((Student)person2).AddGrade("Bazy Danych", 5.0D, new DateTime(2011, 2, 13));
            //person2.Details();
            Grade grade = new Grade("Bazy Danych", 5.0D, new DateTime(2011, 5, 1));
            student.AddGrade(grade);
            student.AddGrade("AWWW", 5.0D, new DateTime(2011, 5, 11));
            student.AddGrade("AWWW", 4.5D, new DateTime(2011, 4, 2));
            //student.Details();
            student.DeleteGrade("AWWW", 4.5D, new DateTime(2011, 4, 2));
            //student.Details();
            student.DeleteGrades("AWWW");
            student.AddGrade("AWWW", 5.0D, new DateTime(2011, 6, 11));
            student.AddGrade("AWWW", 4.0D, new DateTime(2011, 7, 11));
            student.AddGrade("XDD", 5.0D, new DateTime(2011, 5, 11));
            //student.Details();
            student.AddGrade("AWWW", 5.0D, new DateTime(2011, 4, 3));
            //student.Details();
            student.DeleteGrades("AWWW");
            //student.Details();
            student.DeleteGrades();
            //student.Details();

            Person footballPlayer = new FootballPlayer("Mateusz", "Żbik", new DateTime(1986, 8, 10), "striker", "FC Barcelona", 10);
            Person handballPlayer = new HandballPlayer("Piotr", "Kos", new DateTime(1984, 9, 14), "striker", "FC Bayern", 10);
            footballPlayer.Details();
            handballPlayer.Details();
            ((Player)handballPlayer).ScoreGoal(); // rzutowanie bezpośrednie
            (footballPlayer as Player).ScoreGoal(); // rzutowanie referencyjne
            footballPlayer.Details();
            handballPlayer.Details();
        }
    }
}

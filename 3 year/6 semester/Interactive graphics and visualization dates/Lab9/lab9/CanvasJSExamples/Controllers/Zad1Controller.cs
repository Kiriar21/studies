using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using CanvasJSExamples.Models;
using Newtonsoft.Json;  //Do serializacji danych 

namespace CanvasJSExamples.Controllers
{
    public class Zad1Controller : Controller
    {
        //Generator liczb losowych
        public Random random;
        
        public Zad1Controller()
        {
            random = new Random();
        }


        // Defalut plot for ploting linear chart using Canvasjs library 
        // GET: Canvasjs
        public ActionResult Index()
        {
            //double N = 500; //liczba punktów
            //double y = 10; //wartość dla osi OY
            //Dane do rysowania wykresu liniowego (losowe)

            List<DataPoint> dataPoints = new List<DataPoint>();

            for (double i = -5; i < 5; i += 0.02)
            {
                double pom = Math.Sin(5 * i) + Math.Cos(3 * i);
                dataPoints.Add(new DataPoint(i, pom));
            }

            //Zwrócenie danych do widoku Indeks w celu narysowania przy użyciu Canvasjs
            ViewBag.DataPoints = JsonConvert.SerializeObject(dataPoints);

            //Zwrócenie widoku
            return View();
        }
    }
}
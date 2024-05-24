using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using CanvasJSExamples.Models;
using Newtonsoft.Json;  //Do serializacji danych 

namespace CanvasJSExamples.Controllers
{
    public class Zad2Controller : Controller
    {
        //Generator liczb losowych
        public Random random;
        
        public Zad2Controller()
        {
            random = new Random();
        }


        // Defalut plot for ploting linear chart using Canvasjs library 
        // GET: Canvasjs
        public ActionResult Index()
        {
            List<DataPoint> dataPoints = new List<DataPoint>();

            for (double x = -5; x <= 5; x += 0.02)
            {
                double sum = 0;

                for (int i = 1; i <= 1; i++) // D=1, więc pętla wykonuje się tylko raz
                {
                    sum += Math.Pow(x * i, 2) - 10 * Math.Cos(2 * Math.PI * x * i) + 10;
                }

                dataPoints.Add(new DataPoint(x, sum));
            }

            ViewBag.DataPoints = JsonConvert.SerializeObject(dataPoints);

            return View();
        }
    }
}
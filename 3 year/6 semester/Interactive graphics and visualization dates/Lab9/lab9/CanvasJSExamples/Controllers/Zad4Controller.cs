using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using CanvasJSExamples.Models;
using Newtonsoft.Json;  //Do serializacji danych 

namespace CanvasJSExamples.Controllers
{
    public class Zad4Controller : Controller
    {
        //Generator liczb losowych
        public Random random;
        
        public Zad4Controller()
        {
            random = new Random();
        }

        public class PieChartData
        {
            public string label { get; set; }
            public double y { get; set; }
        }
        // Defalut plot for ploting linear chart using Canvasjs library 
        // GET: Canvasjs
        public ActionResult Index()
        {
            
            List<PieChartData> dataPoints = new List<PieChartData>();

            for (int i = 0; i < 5; i++)
            {
                double y = random.NextDouble() * 100; 
                dataPoints.Add(new PieChartData { label = $"Category {i + 1}", y = y });
            }

            
            ViewBag.DataPoints = JsonConvert.SerializeObject(dataPoints);

            return View();
        }
    }
}
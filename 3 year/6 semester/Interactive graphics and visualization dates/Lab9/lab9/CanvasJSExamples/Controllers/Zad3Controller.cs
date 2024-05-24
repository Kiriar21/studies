using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using CanvasJSExamples.Models;
using Newtonsoft.Json;  //Do serializacji danych 

namespace CanvasJSExamples.Controllers
{
    public class Zad3Controller : Controller
    {
        //Generator liczb losowych
        public Random random;
        
        public Zad3Controller()
        {
            random = new Random();
        }


        // Defalut plot for ploting linear chart using Canvasjs library 
        // GET: Canvasjs
        public class BarChartSeries
        {
            public string name { get; set; }
            public List<DataPoint> dataPoints { get; set; }
        }
        public ActionResult Index()
        {
            List<BarChartSeries> series = new List<BarChartSeries>();

            for (int i = 0; i < 3; i++)
            {
                List<DataPoint> dataPoints = new List<DataPoint>();

                for (int j = 0; j < 10; j++) 
                {
                    double y = random.NextDouble() * 100; 
                    dataPoints.Add(new DataPoint(j, y));
                }

                series.Add(new BarChartSeries { name = $"Series {i + 1}", dataPoints = dataPoints });
            }

            
            ViewBag.Series = JsonConvert.SerializeObject(series);

            return View();
        }
    }
}
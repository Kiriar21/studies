using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using CanvasJSExamples.Models;
using Newtonsoft.Json;  //Do serializacji danych 

namespace CanvasJSExamples.Controllers
{
    public class Zad5Controller : Controller
    {
        //Generator liczb losowych
        public Random random;
        
        public Zad5Controller()
        {
            random = new Random();
        }

        public class LineChartSeries
        {
            public string name { get; set; }
            public List<DataPoint> dataPoints { get; set; }
        }

        public class BarChartSeries
        {
            public string name { get; set; }
            public List<DataPoint> dataPoints { get; set; }
        }
        // Defalut plot for ploting linear chart using Canvasjs library 
        // GET: Canvasjs
        public ActionResult Index()
        {
            
            List<LineChartSeries> lineSeries = new List<LineChartSeries>();
            List<BarChartSeries> columnSeries = new List<BarChartSeries>();

            for (int i = 0; i < 2; i++)
            {
                List<DataPoint> dataPoints = new List<DataPoint>();

                for (int j = 0; j < 10; j++) 
                {
                    double y = random.NextDouble() * 100; 
                    dataPoints.Add(new DataPoint(j, y));
                }

                lineSeries.Add(new LineChartSeries { name = $"Line Series {i + 1}", dataPoints = dataPoints });
            }

            for (int i = 0; i < 1; i++)
            {
                List<DataPoint> dataPoints = new List<DataPoint>();

                for (int j = 0; j < 10; j++) 
                {
                    double y = random.NextDouble() * 100; 
                    dataPoints.Add(new DataPoint(j, y));
                }

                columnSeries.Add(new BarChartSeries { name = $"Column Series {i + 1}", dataPoints = dataPoints });
            }

            
            ViewBag.LineSeries = JsonConvert.SerializeObject(lineSeries);
            ViewBag.ColumnSeries = JsonConvert.SerializeObject(columnSeries);

            return View();
        }
    }
}
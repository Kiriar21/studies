using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using CanvasJSExamples.Models;
using Newtonsoft.Json;  //Do serializacji danych 

namespace CanvasJSExamples.Controllers
{
    public class CanvasjsController : Controller
    {
        //Generator liczb losowych
        public Random random;
        
        public CanvasjsController()
        {
            random = new Random();
        }


        // Defalut plot for ploting linear chart using Canvasjs library 
        // GET: Canvasjs
        public ActionResult Index()
        {
            double N = 10000; //liczba punktów
            double y = 100; //wartość dla osi OY
            //Dane do rysowania wykresu liniowego (losowe)

            List<DataPoint> dataPoints = new List<DataPoint>();

            for(int i=0;i<N;i++)
            {
                y += random.Next(-20, 20);
                dataPoints.Add(new DataPoint(i, y));
            }

            //Zwrócenie danych do widoku Indeks w celu narysowania przy użyciu Canvasjs
            ViewBag.DataPoints = JsonConvert.SerializeObject(dataPoints);

            //Zwrócenie widoku
            return View();
        }
    }
}
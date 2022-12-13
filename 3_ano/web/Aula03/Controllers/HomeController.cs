using Aula03.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.StaticFiles;
using System.Diagnostics;
using System.Xml.Linq;

namespace Aula03.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly IHostEnvironment _he;

        public HomeController(ILogger<HomeController> logger, IHostEnvironment he)
        {
            _logger = logger;
            _he = he;
        }

        public IActionResult Upload(IFormFile Name)
        {
            if (ModelState.IsValid)
            {
                string destination = Path.Combine(_he.ContentRootPath, "wwwroot/Documents/", Path.GetFileName(Name.FileName));

                FileStream Fs = new FileStream(destination, FileMode.Create);

                Name.CopyTo(Fs);
                Fs.Close();

                return (RedirectToAction("Index"));

            }

            else {
                return View(); }
        }


        public IActionResult Index()
        {
            DocFiles files = new DocFiles();

            return View(files.GetFiles(_he));
            
        }

        public IActionResult Download(string id)
        {

            string pathFile = Path.Combine(_he.ContentRootPath, "wwwroot/Documents/", id);

            byte[] fileBytes = System.IO.File.ReadAllBytes(pathFile);

            string mimeType;

            new FileExtensionContentTypeProvider().TryGetContentType(id, out mimeType);

            return File(fileBytes, mimeType);
        }

        public IActionResult Delete(string id)
        {
            string pathFile = Path.Combine(_he.ContentRootPath, "wwwroot/Documents/", id);

            System.IO.File.Delete(pathFile);

            return RedirectToAction("Index");
        }




        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
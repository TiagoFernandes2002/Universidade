using Microsoft.AspNetCore.Mvc;

namespace teste.Controllers
{
    public class ExpController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}

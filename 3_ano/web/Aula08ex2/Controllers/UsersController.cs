using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Aula08ex2.Data;
using Aula08ex2.Models;

namespace Aula08ex2.Controllers
{
    public class UsersController : Controller
    {
        private readonly Aula08ex2Context _context;

        public UsersController(Aula08ex2Context context)
        {
            _context = context;
        }

        public IActionResult Login()
        {
            return View();
        }


        [HttpPost]
        public IActionResult Login(string username, string password)
        {
            if( ModelState.IsValid)
            {
                User u = _context.User.SingleOrDefault(u => u.username == username && u.Password == password);
                if (u == null)
                    ModelState.AddModelError("username", "username or password is invalid");
                else
                {
                    //the user is authenticated
                    //the session variable "user" is created to recover the user idetify at each request
                    HttpContext.Session.SetString("user", username);

                    return RedirectToAction("Index", "Home");
                }
            }


            return View();
        }

    }
}

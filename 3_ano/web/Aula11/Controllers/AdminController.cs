using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Aula11.Data;
using Aula11.Models;

namespace Aula11.Controllers
{
    public class AdminController : Controller
    {
        private readonly Aula11Context _context;

        public AdminController(Aula11Context context)
        {
            _context = context;
        }

        public IActionResult Create(string NewName)
        {
            Person newP = new Person();
            newP.Name = NewName;
            _context.Person.Add(newP);
            _context.SaveChanges();

            return PartialView("Listing", _context.Person);
        }
    }
}

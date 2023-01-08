using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Teste_2022.Data;
using Teste_2022.Models;


namespace Teste_2022.Controllers
{
    
    [Authorize]
    public class HomeController : Controller
    {
        private readonly ApplicationDbContext _context;

        public HomeController(ApplicationDbContext context)
        {
            _context = context;
        }

        [AllowAnonymous]
        public async Task<IActionResult> Index()
        {
              return View(await _context.Filmes.OrderByDescending(f =>f.Duracao).Where(f=>f.estado == true).ToListAsync());
        }

        

        // GET: Home/Create
        public IActionResult AddFilme()
        {
            return View();
        }

        
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> AddFilme([Bind("Id,Titulo,Duracao,estado")] Filme filme)
        {
            if (ModelState.IsValid)
            {
                _context.Add(filme);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(filme);
        }

       

       

        // GET: Home/Delete/5
        public IActionResult Delete(int? id)
        {
            if (id == null || _context.Filmes == null)
            {
                return NotFound();
            }

            Filme f = _context.Filmes.FirstOrDefault(x => x.Id == id);
            f.estado = false;
            _context.Filmes.Update(f);
            _context.SaveChanges();


            HttpContext.Response.Cookies.Append("alreadyDeleted", User.Identity.Name, new CookieOptions() { Expires = DateTime.Now.AddMinutes(5) });
            

            return PartialView();
        }

        public int Adicionar(int id)
        {
            

            Filme f = _context.Filmes.FirstOrDefault(x => x.Id == id);
            f.Duracao++;
            _context.Filmes.Update(f);
            _context.SaveChanges();
            return f.Duracao;
           // return PartialView("Adicionar",_context.Filmes.Where(x => x.Id == id));
        }

        public IActionResult Edit(int Id)
        {
            Filme f = _context.Filmes.SingleOrDefault(x => x.Id == Id);
            return PartialView("Edit", f);
        }

        public string Edit(int id, Filme f)
        {
            _context.Update(f);
            _context.SaveChanges();
            return f.Titulo;
        }

        


        private bool FilmeExists(int id)
        {
          return _context.Filmes.Any(e => e.Id == id);
        }


       

    }
}

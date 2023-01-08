using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Teste_2.Data;
using Teste_2.Models;

namespace Teste_2.Controllers
{
    [Authorize]
    public class BolsasController : Controller
    {
        private readonly ApplicationDbContext _context;

        public BolsasController(ApplicationDbContext context)
        {
            _context = context;
        }


        [AllowAnonymous]
        public async Task<IActionResult> Lista()
        {
              return View(await _context.bolsas.ToListAsync());
        }

        // GET: Bolsas/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null || _context.bolsas == null)
            {
                return NotFound();
            }

            var bolsaInvestigacao = await _context.bolsas
                .FirstOrDefaultAsync(m => m.Id == id);
            if (bolsaInvestigacao == null)
            {
                return NotFound();
            }

            return View(bolsaInvestigacao);
        }

        // GET: Bolsas/Create
        public IActionResult Adiciona()
        {
            return View();
        }

        // POST: Bolsas/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Adiciona([Bind("Id,Titulo,Area,Duracao,Remuneracao")] BolsaInvestigacao bolsaInvestigacao)
        {
            if (ModelState.IsValid)
            {
                _context.Add(bolsaInvestigacao);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Lista));
            }
            return View(bolsaInvestigacao);
        }

            

        
       

        private bool BolsaInvestigacaoExists(int id)
        {
          return _context.bolsas.Any(e => e.Id == id);
        }

        public IActionResult Detalhes(int id)
        {


            BolsaInvestigacao b = _context.bolsas.FirstOrDefault(x => x.Id == id);
            
            
            
            return PartialView("Detalhes",_context.bolsas.Where(x => x.Id == id));
        }

        public IActionResult Filtro(int id)
        {


            BolsaInvestigacao b = _context.bolsas.FirstOrDefault(x => x.Id == id);
            string a;
            a = b.Area;



           // return RedirectToAction(nameof(Lista,_context.where)
            return View("Lista", _context.bolsas.Where(x => x.Area == a));
        }


    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using EW_2021_PAP1_DB_al73701;
using Teste1.Models;

namespace Teste1.Controllers
{
    public class LivrariaController : Controller
    {
        private readonly Teste1Context _context;

        public LivrariaController(Teste1Context context)
        {
            _context = context;
        }

        // GET: Livraria
        public async Task<IActionResult> Lista()
        {
              return View(await _context.Livro.ToListAsync());
        }

        // GET: Livraria/Details/5
        public async Task<IActionResult> Details(string id)
        {
            if (id == null || _context.Livro == null)
            {
                return NotFound();
            }

            var livro = await _context.Livro
                .FirstOrDefaultAsync(m => m.ISBN == id);
            if (livro == null)
            {
                return NotFound();
            }

            return View(livro);
        }

        // GET: Livraria/Inserir
        public IActionResult Inserir()
        {
           

            return View();
        }

        // POST: Livraria/Inserir
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Inserir([Bind("Titulo,Autores,Editora,ISBN,Capa,Contracapa")] Livro livro)
        {
            if (ModelState.IsValid)
            {
                _context.Add(livro);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Lista));
            }
            return View(livro);
        }

        // GET: Livraria/Edit/5
        public async Task<IActionResult> Edit(string id)
        {
            if (id == null || _context.Livro == null)
            {
                return NotFound();
            }

            var livro = await _context.Livro.FindAsync(id);
            if (livro == null)
            {
                return NotFound();
            }
            return View(livro);
        }

        // POST: Livraria/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(string id, [Bind("Titulo,Autores,Editora,ISBN,Capa,Contracapa")] Livro livro)
        {
            if (id != livro.ISBN)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(livro);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!LivroExists(livro.ISBN))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Lista));
            }
            return View(livro);
        }

        // GET: Livraria/Delete/5
        public async Task<IActionResult> Remover(string id)
        {
            if (id == null || _context.Livro == null)
            {
                return NotFound();
            }

            var livro = await _context.Livro
                .FirstOrDefaultAsync(m => m.ISBN == id);
            if (livro == null)
            {
                return NotFound();
            }

            return View(livro);
        }

        // POST: Livraria/Delete/5
        [HttpPost, ActionName("Remover")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> RemoverConfirmed(string id)
        {
            if (_context.Livro == null)
            {
                return Problem("Entity set 'Teste1Context.Livro'  is null.");
            }
            var livro = await _context.Livro.FindAsync(id);
            if (livro != null)
            {
                _context.Livro.Remove(livro);
            }
            
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Lista));
        }

        private bool LivroExists(string id)
        {
          return _context.Livro.Any(e => e.ISBN == id);
        }
    }
}

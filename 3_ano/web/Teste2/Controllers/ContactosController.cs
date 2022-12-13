using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using DB_al73701;
using Teste2.Models;

namespace Teste2.Controllers
{
    public class ContactosController : Controller
    {
        private readonly Teste2Context _context;

        public ContactosController(Teste2Context context)
        {
            _context = context;
        }

        // GET: Contactos
        public async Task<IActionResult> Lista()
        {
              return View(await _context.Contacto.ToListAsync());
        }


        public async Task<IActionResult> Lista1()
        {
            return View(await _context.Contacto.Where(X=>X.Amigo==true).ToListAsync());
        }


        // GET: Contactos/Details/5
        public async Task<IActionResult> Details(string id)
        {
            if (id == null || _context.Contacto == null)
            {
                return NotFound();
            }

            var contacto = await _context.Contacto
                .FirstOrDefaultAsync(m => m.Email == id);
            if (contacto == null)
            {
                return NotFound();
            }

            return View(contacto);
        }

        // GET: Contactos/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: Contactos/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Email,NicKname,Nome,Amigo")] Contacto contacto)
        {
            if (ModelState.IsValid)
            {
                _context.Add(contacto);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Lista));
            }
            return View(contacto);
        }

        // GET: Contactos/Edit/5
        public async Task<IActionResult> Alterar(string id)
        {
            if (id == null || _context.Contacto == null)
            {
                return NotFound();
            }

            var contacto = await _context.Contacto.FindAsync(id);
            if (contacto == null)
            {
                return NotFound();
            }
            return View(contacto);
        }

        // POST: Contactos/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Alterar(string id, [Bind("Email,NicKname,Nome,Amigo")] Contacto contacto)
        {
            if (id != contacto.Email)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(contacto);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!ContactoExists(contacto.Email))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                TempData["Mensagem"] ="Contacto "+ contacto.NicKname + "Alterado com Sucesso";

                return RedirectToAction(nameof(Lista));
            }
            return View(contacto);
        }

        // GET: Contactos/Delete/5
        public async Task<IActionResult> Delete(string id)
        {
            if (id == null || _context.Contacto == null)
            {
                return NotFound();
            }

            var contacto = await _context.Contacto
                .FirstOrDefaultAsync(m => m.Email == id);
            if (contacto == null)
            {
                return NotFound();
            }

            return View(contacto);
        }

        // POST: Contactos/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(string id)
        {
            if (_context.Contacto == null)
            {
                return Problem("Entity set 'Teste2Context.Contacto'  is null.");
            }
            var contacto = await _context.Contacto.FindAsync(id);
            if (contacto != null)
            {
                _context.Contacto.Remove(contacto);
            }
            
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Lista));
        }

        private bool ContactoExists(string id)
        {
          return _context.Contacto.Any(e => e.Email == id);
        }
    }
}

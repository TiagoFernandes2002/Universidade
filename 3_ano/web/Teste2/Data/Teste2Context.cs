using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Teste2.Models;

namespace DB_al73701
{
    public class Teste2Context : DbContext
    {
        public Teste2Context (DbContextOptions<Teste2Context> options)
            : base(options)
        {
        }

        public DbSet<Teste2.Models.Contacto> Contacto { get; set; } = default!;
    }
}

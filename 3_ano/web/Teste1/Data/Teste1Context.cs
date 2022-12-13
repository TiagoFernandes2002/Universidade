using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Teste1.Models;

namespace EW_2021_PAP1_DB_al73701
{
    public class Teste1Context : DbContext
    {
        public Teste1Context (DbContextOptions<Teste1Context> options)
            : base(options)
        {
        }

        public DbSet<Teste1.Models.Livro> Livro { get; set; } = default!;
    }
}

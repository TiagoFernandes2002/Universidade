using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Aula08ex2.Models;

namespace Aula08ex2.Data
{
    public class Aula08ex2Context : DbContext
    {
        public Aula08ex2Context (DbContextOptions<Aula08ex2Context> options)
            : base(options)
        {
        }

        public DbSet<Aula08ex2.Models.User> User { get; set; } = default!;
    }
}

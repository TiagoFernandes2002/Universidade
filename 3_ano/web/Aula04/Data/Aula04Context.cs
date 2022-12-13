using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Aula04.Models;

namespace Aula04.Data
{
    public class Aula04Context : DbContext
    {
        public Aula04Context (DbContextOptions<Aula04Context> options)
            : base(options)
        {
        }

        public DbSet<Aula04.Models.Category> Category { get; set; }
        public DbSet<Aula04.Models.Courses> Courses { get; set; }
    }
}

using Aula04.Models;

namespace Aula04.Data
{
    public class DbInitializer
    {
        private readonly Aula04Context _context;
        public DbInitializer(Aula04Context context) { _context = context; }


        public void Run()
        {
            _context.Database.EnsureCreated();

            if(_context.Category.Any())
            {
                return;
            }

            var categories = new Category[]
            {
                new Category{Name="Programming", Description="Algoritms and Programming are course", State= true},
                 new Category{Name="Administratio", Description="Public administration and business management courses", State= true},
                  new Category{Name="Comunication", Description="Business and institucianonal communication course", State= true},
            };

            foreach (var c in categories) { _context.Category.Add(c); };

            _context.SaveChanges();


            var courses = new Courses[]
            {
                new Courses
                {
                    Name = "Web Engineering",
                    Description = "Creating new sites using ASP.NET",
                    Cost= 100, Credits =6,
                    CategoryId= categories.Single(categories=> categories.Name == "Proggramming").Id
                },
                new Courses
                {
                    Name = "Strategic Leadership and Management",
                    Description = "Leadership and Business Skill",
                    Cost= 50, Credits =6,
                    CategoryId= categories.Single(categories=> categories.Name == "Administration").Id
                },
                new Courses
                {
                    Name = "Master in Corporate Communication",
                    Description = "daihdasu dhaudhsihas dhaiudhs",
                    Cost= 80, Credits =10,
                    CategoryId= categories.Single(categories=> categories.Name == "Communication").Id
                },

            };

            _context.Courses.AddRange(courses);
            _context.SaveChanges();
        }

    }
}
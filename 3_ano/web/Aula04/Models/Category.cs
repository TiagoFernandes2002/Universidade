﻿using System.ComponentModel.DataAnnotations;

namespace Aula04.Models
{
    public class Category
    {
        [Key]

        public int Id { get; set; }

        [Required(ErrorMessage = "Required Filed")]
        [StringLength(50, MinimumLength = 3, ErrorMessage = "{0}length must be between {2} and {1}")]


        public string Name { get; set; }


        [Required(ErrorMessage = "Required Filed")]
        [StringLength(256, ErrorMessage = "{0}length can not exceed {1} characters")]


        public string Description { get; set; }

        public Boolean State { get; set; }

        [Display(Name ="Creation Date")]

        public DateTime Date { get; set; } = DateTime.Now;

        public ICollection<Courses> Courses { get; set; }

    }
}

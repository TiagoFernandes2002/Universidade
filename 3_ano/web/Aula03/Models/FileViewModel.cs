using System.ComponentModel.DataAnnotations;

namespace Aula03.Models
{
    public class FileViewModel
    {
        [Required]
        [RegularExpression(@"^.+\.([pP][dD][fF])$", ErrorMessage = "Only PDFs files")]


        public string Name { get; set; }

        [Display(Name="Size in bytes")]


        public double Size { get; set; }

    }
}

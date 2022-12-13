using System.ComponentModel.DataAnnotations;

namespace Aula08ex2.Models
{
    public class User
    {

        [Key]
        [Required]
        public string username { get; set; }

        [Required]
        [DataType(DataType.Password)]
        public string Password { get; set; }

    }
}

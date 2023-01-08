using System.ComponentModel.DataAnnotations;

namespace Teste_2022.Models
{
    public class Filme
    {
        [Key]
        [Required]
        public int Id { get; set; }

        [Required]
        public string Titulo { get; set; }

        [Required]
        public int Duracao { get; set; }


        public bool? estado { get; set; } = true;
    }
}

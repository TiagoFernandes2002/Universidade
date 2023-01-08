using System.ComponentModel.DataAnnotations;

namespace Teste_2.Models
{
    public class BolsaInvestigacao
    {

        [Key]
        public int Id { get; set; }

        [Required]
        public string Titulo { get; set; }

        [Required]
        public string Area { get; set; }

        [Required]
        public int Duracao { get; set; }

        [Required]
        public int Remuneracao { get; set; }


    }
}

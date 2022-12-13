using System.ComponentModel.DataAnnotations;

namespace Teste2.Models
{
    public class Contacto
    {
        [Key]
        [Required(ErrorMessage = "Campo obrigatório")]
        [EmailAddress]
        public string Email { get; set; }

        [Required(ErrorMessage = "Campo Obrigatório")]
        [MinLength(3, ErrorMessage = "O Nickname tem de ter mais de 3 letras")]
        [RegularExpression("^[^\\s]+$", ErrorMessage = "Formato Errado")]
        public string NicKname { get; set; }

        [Required(ErrorMessage = "Campo obrgatório")]
        public string Nome { get; set; }

        [Required(ErrorMessage = "Campo obrgatório")]
        public Boolean Amigo { get; set; }
    }
}

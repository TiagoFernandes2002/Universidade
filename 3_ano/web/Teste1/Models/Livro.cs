using System.ComponentModel.DataAnnotations;

namespace Teste1.Models
{
    public class Livro
    {
        [Required(ErrorMessage = "Campo Obrigatório")]
        public string Titulo { get; set; }

        [Required(ErrorMessage = "Campo Obrigatório")]
        public string Autores { get; set; }

        [Required(ErrorMessage = "Campo Obrigatório")]
        public string Editora { get; set; }

        [Key]
        [Required(ErrorMessage = "Campo Obrigatório")]
        [RegularExpression("(97(?:8|9)([ -]?)(?=\\d{1,5}\\2?\\d{1,7}\\2?\\d{1,6}\\2?\\d)(?:\\d\\2*){9}\\d)$", ErrorMessage = "Campo Mal Preenchido ")]
        public string ISBN { get; set; }


        [RegularExpression("[^\\s]+(.*?)\\.(jpg|JPG)$", ErrorMessage = "Ficherio tem de ser no formato .jpg")]
        public string? Capa { get; set; }


        [RegularExpression("[^\\s]+(.*?)\\.(jpg|JPG)$", ErrorMessage = "Ficherio tem de ser no formato .jpg")]
        public string? Contracapa { get; set; }


    }
}

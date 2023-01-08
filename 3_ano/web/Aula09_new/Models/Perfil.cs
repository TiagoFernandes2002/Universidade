using System.ComponentModel.DataAnnotations;

namespace Aula09_new.Models
{
    public class Perfil
    {
        public int Id { get; set; }

        [DataType(DataType.Date)]
        public DateTime Birthday { get; set; }

        public string UserName { get; set; } //UserName pf the User in aspnetUsers
    }
}

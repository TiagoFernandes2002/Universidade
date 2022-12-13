using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Teste1.Migrations
{
    public partial class FirstStep : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Livro",
                columns: table => new
                {
                    ISBN = table.Column<string>(type: "nvarchar(450)", nullable: false),
                    Titulo = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Autores = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Editora = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Capa = table.Column<string>(type: "nvarchar(max)", nullable: true),
                    Contracapa = table.Column<string>(type: "nvarchar(max)", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Livro", x => x.ISBN);
                });
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Livro");
        }
    }
}

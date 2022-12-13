using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;
using DB_al73701;
using Microsoft.AspNetCore.Mvc;

var builder = WebApplication.CreateBuilder(args);
builder.Services.AddDbContext<Teste2Context>(options =>
    options.UseSqlServer(builder.Configuration.GetConnectionString("Teste2Context") ?? throw new InvalidOperationException("Connection string 'Teste2Context' not found.")));

// Add services to the container.
builder.Services.AddControllersWithViews();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "amigos",
    defaults: new {Controller = "Contactos", Action = "Lista1"}) ;

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Contactos}/{action=Lista}/{id?}");

app.Run();

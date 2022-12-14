using ReactiveUI;
using ReactiveUI.Validation.Abstractions;
using ReactiveUI.Validation.Contexts;
using ReactiveUI.Validation.Extensions;
using System;
using System.Collections.Generic;
using System.Reactive;
using System.Text;
using System.IO;
using System.Windows.Input;
using Utad.Lab.G04.Domain.Models;
using System.Xml;
using System.Xml.Linq;
using System.Linq;

namespace Utad.Lab.G04.Domain.ViewModels
{

    public class ViewModel : ReactiveObject, IValidatableViewModel
    {

        public ReactiveCommand<Unit, bool> CmdLogin { get; }
        public ReactiveCommand<Unit, bool> CmdLogout { get; }
        public ReactiveCommand<Unit, bool> CmdRegister { get; }
        public ReactiveCommand<Unit, bool> CmdCloseDlg { get; }
        public ReactiveCommand<Unit, bool> CmdOpenRegisto { get; }
        public ReactiveCommand<Unit, bool> CmdOpenEditarPerfil { get; }
        public ReactiveCommand<Unit, bool> CmdOpenAddLista { get; }
        public ReactiveCommand<Unit, bool> CmdOpenAddItem { get; set; }
        public ReactiveCommand<Unit, bool> CmdShowConta { get; }
        public ReactiveCommand<Unit, bool> CmdShowCats { get; }
        public ReactiveCommand<Unit, bool> CmdShowListasDash { get; }
        public ReactiveCommand<Unit, bool> CmdIsLogged { get; }
        public ReactiveCommand<Unit, string> CmdAddFoto { get; set; }
        public ReactiveCommand<Unit, bool> CmdAddLista { get; set; }
        public ReactiveCommand<Unit, bool> CmdAddItem { get; set; }
        public ReactiveCommand<Unit, bool> CmdMostraItems { get; }
        public ReactiveCommand<Unit, bool> CmdMostraListas { get; set; }
        public ValidationContext ValidationContext { get; } = new ValidationContext();

        private User Utilizador;
        public Categorias Cat;
        public Dictionary<string, Lista> Listas { get; private set; }
        public Dictionary<string, Produto> Produtos { get; private set; }

        public ViewModel()
        {

            Utilizador = new User();
            Cat = new Categorias();
            Listas = new Dictionary<string, Lista>();
            Produtos = new Dictionary<string, Produto>();
            // Creates the validation for the Name property.
            //this.ValidationRule(
            //    vm => vm.Email,
            //    ErroCredencias => !string.IsNullOrWhiteSpace(ErroCredencias),
            //    "Email Inválido");      

            //this.ValidationRule(
            //    vm => vm.Password,
            //    ErroCredencias => !string.IsNullOrWhiteSpace(ErroCredencias),
            //    "Password Incorreta");

            CmdLogin = ReactiveCommand.Create(Login);
            CmdLogout = ReactiveCommand.Create(Logout);
            CmdRegister = ReactiveCommand.Create(Register);
            CmdCloseDlg = ReactiveCommand.Create(CloseDialogWindow);
            CmdOpenRegisto = ReactiveCommand.Create(ShowDialogWindow);
            CmdOpenEditarPerfil = ReactiveCommand.Create(ShowDialogWindow);
            CmdOpenAddItem = ReactiveCommand.Create(ShowDialogWindow);
            CmdAddItem = ReactiveCommand.Create(AddItem);
            CmdOpenAddLista = ReactiveCommand.Create(ShowDialogWindow);
            CmdShowConta = ReactiveCommand.Create(ShowDialogWindow);
            CmdShowCats = ReactiveCommand.Create(MostraCats);
            CmdShowListasDash = ReactiveCommand.Create(ShowDialogWindow);
            CmdIsLogged = ReactiveCommand.Create(isLogged);
            CmdAddFoto = ReactiveCommand.Create(AddFoto);
            CmdAddLista = ReactiveCommand.Create(AddLista);
            CmdMostraItems = ReactiveCommand.Create(MostraItems);
            CmdMostraListas = ReactiveCommand.Create(MostraListas);


        }



        private string nome;
        public string Nome
        {
            get => nome;
            set => this.RaiseAndSetIfChanged(ref nome, value);
        }

        private string pais;
        public string Pais
        {
            get => pais;
            set => this.RaiseAndSetIfChanged(ref pais, value);
        }

        private string email;
        public string Email
        {
            get => email;
            set => this.RaiseAndSetIfChanged(ref email, value);
        }

        private string password;
        public string Password
        {
            get => password;
            set => this.RaiseAndSetIfChanged(ref password, value);
        }

        private string passwordconfirm;
        public string PasswordConfirm
        {
            get => passwordconfirm;
            set => this.RaiseAndSetIfChanged(ref passwordconfirm, value);
        }

        private string erro_credenciais;
        public string ErroCredenciais
        {
            get => erro_credenciais;
            set => this.RaiseAndSetIfChanged(ref erro_credenciais, value);
        }

        private bool is_logged;
        public bool IsLogged
        {
            get => is_logged;

            set => this.RaiseAndSetIfChanged(ref is_logged, value);
        }

        //Listas
        private string listadescricao;
        public string ListaDescricao
        {
            get => listadescricao;
            set => this.RaiseAndSetIfChanged(ref listadescricao, value);
        }

        //Produtos / Items
        private string itemdescricao;
        public string ItemDescricao
        {
            get => itemdescricao;
            set => this.RaiseAndSetIfChanged(ref itemdescricao, value);
        }

        private int itemquantidade;
        public int ItemQuantidade
        {
            get => itemquantidade;
            set => this.RaiseAndSetIfChanged(ref itemquantidade, value);
        }

        private string itemcat;
        public string ItemCat
        {
            get => itemcat;
            set => this.RaiseAndSetIfChanged(ref itemcat, value);
        }




        //Implementação de Comandos
        //---------------------------------------------------

        private bool isLogged()
        {

            if (File.Exists("users.xml"))
            {
                XDocument doc = XDocument.Load("users.xml");

                var registo = from user in doc.Element("Users").Descendants("User") select user;

                foreach (var campos in registo)
                {
                    if (campos.Element("IsLogged") != null && (string)campos.Element("IsLogged") == "true")
                    {
                        Nome = (string)campos.Element("Nome");
                        Email = (string)campos.Element("Email");
                        IsLogged = true;
                        return true;
                    }
                    else
                    {
                        return false;
                    }

                }
                return false;
            }
            return false;

        }

        private bool Login()
        {

            if (File.Exists("users.xml"))
            {
                XDocument doc = XDocument.Load("users.xml");

                var registo = from user in doc.Element("Users").Descendants("User") select user;

                foreach (var campos in registo)
                {
                    if (campos.Element("Email") != null && campos.Element("Password") != null && (string)campos.Element("Email") == Email && (string)campos.Element("Password") == Password && !string.IsNullOrEmpty(Email) && !string.IsNullOrEmpty(Password))
                    {

                        campos.SetElementValue("IsLogged", "true");
                        doc.Save("users.xml");
                        ErroCredenciais = " ";
                        IsLogged = true;
                        return true;
                    }
                    else
                    {
                        Email = "";
                        Password = "";
                        ErroCredenciais = "Credenciais Erradas";
                        return false;
                    }

                }

                Email = "";
                Password = "";
                ErroCredenciais = "Credenciais Erradas";
                return false;
            }
            else
            {
                Email = "";
                Password = "";
                ErroCredenciais = "Credenciais Erradas";
                return false;
            }


        }

        private bool Logout()
        {

            if (File.Exists("users.xml"))
            {
                XDocument doc = XDocument.Load("users.xml");

                var registo = from user in doc.Element("Users").Descendants("User") select user;

                foreach (var campos in registo)
                {
                    campos.SetElementValue("IsLogged", "false");
                    doc.Save("users.xml");
                    IsLogged = false;
                    return true;

                };
                return false;
            }
            else
            {
                return false;
            }

        }

        private string AddFoto()
        {
            return "file";
        }


        private bool ShowDialogWindow()
        {
            return true;
        }

        private bool CloseDialogWindow()
        {
            return false;
        }

        private bool Register()
        {

            if (!string.IsNullOrEmpty(Email) && !string.IsNullOrEmpty(Nome) && !string.IsNullOrEmpty(Password) && !string.IsNullOrEmpty(PasswordConfirm))
            {
                if (Password == PasswordConfirm)
                {
                    ErroCredenciais = " ";

                    Utilizador.Nome = Nome;
                    Utilizador.Pais = Pais;
                    Utilizador.Email = Email;
                    Utilizador.Password = Password;

                    XDocument doc = new XDocument(
                                        new XElement("Users",
                                            new XElement("User",
                                                new XElement("Nome", Nome),
                                                new XElement("Pais", Pais),
                                                new XElement("Email", Email),
                                                new XElement("Password", Password),
                                                new XElement("IsLogged", "false")

                                            )
                                        )
                    );

                    doc.Save("users.xml");

                    return true;
                }
                else
                {
                    Password = "";
                    PasswordConfirm = "";
                    ErroCredenciais = "Passwords não coincidem";
                    return false;
                }

            }
            else
            {
                Email = "";
                Password = "";
                ErroCredenciais = "Credenciais Inválidas";
                return false;
            }

        }

        private bool AddLista()
        {

            if (!string.IsNullOrEmpty(ListaDescricao))
            {
                if (!File.Exists("listas.xml"))
                {

                    XDocument doc = new XDocument(
                                        new XElement("Listas",
                                            new XElement("Lista",
                                                new XAttribute("Descricao", ListaDescricao)
                                            )
                                        )
                    );

                    doc.Save("listas.xml");
                    juntaListas();
                    return true;
                }
                else
                {
                    XDocument doc = XDocument.Load("listas.xml");


                    XElement XnovaLista;

                    XnovaLista = new XElement("Lista",
                                    new XAttribute("Descricao", ListaDescricao)
                                );

                    if (!Listas.ContainsKey(XnovaLista.Attribute("Descricao").Value))
                    {
                        doc.Element("Listas").Add(XnovaLista);
                    }
                    doc.Save("listas.xml");
                    juntaListas();

                    return true;
                }

            }
            return false;

        }


        private bool AddItem()
        {

            if (!string.IsNullOrEmpty(ItemDescricao) && ItemQuantidade > 0 && !string.IsNullOrEmpty(ItemCat))
            {
                if (File.Exists("listas.xml"))
                {
                    XDocument doc = XDocument.Load("listas.xml");


                    XElement XnovoItem;

                    XnovoItem = new XElement("Item",
                                    new XElement("Descricao", ItemDescricao),
                                    new XElement("Quatidade", ItemQuantidade),
                                    new XElement("Categoria", ItemCat)
                                );

                    var listas = from lista in doc.Element("Listas").Descendants("Lista")
                                 where lista.Attribute("Descricao").Value == ListaDescricao
                                 select lista;

                    foreach (var l in listas)
                    {
                        l.Add(XnovoItem);
                        doc.Save("listas.xml");
                        return true;
                    }
                    //se existir o ficheiro, mas a lista não existir
                    XElement XnovaLista;

                    XnovaLista = new XElement("Lista",
                                    new XAttribute("Descricao", ListaDescricao)
                                );

                    doc.Element("Listas").Add(XnovaLista);
                    doc.Save("listas.xml");
                    juntaListas();

                    listas = from lista in doc.Element("Listas").Descendants("Lista")
                             where lista.Attribute("Descricao").Value == ListaDescricao
                             select lista;

                    foreach (var l in listas)
                    {
                        l.Add(XnovoItem);
                        doc.Save("listas.xml");
                        return true;
                    }


                }
                else
                {
                    XDocument doc = new XDocument(
                                      new XElement("Listas",
                                          new XElement("Lista",
                                              new XAttribute("Descricao", ListaDescricao)
                                          )
                                      )
                    );

                    doc.Save("listas.xml");
                    juntaListas();

                    XElement XnovoItem;

                    XnovoItem = new XElement("Item",
                                    new XElement("Descricao", ItemDescricao),
                                    new XElement("Quatidade", ItemQuantidade),
                                    new XElement("Categoria", ItemCat)
                                );

                    var listas = from lista in doc.Element("Listas").Descendants("Lista") where lista.Attribute("Descricao").Value == ListaDescricao select lista;

                    foreach (var l in listas)
                    {
                        l.Add(XnovoItem);
                        doc.Save("listas.xml");
                        return true;

                    }
                }

            }
            return false;

        }

        private bool MostraListas()
        {

            if (File.Exists("listas.xml"))
            {

                juntaListas();

                return true;
            }
            else
            {
                return false;
            }

        }

        private bool MostraItems()
        {

            if (File.Exists("listas.xml"))
            {

                juntaItems();

                return true;
            }
            else
            {
                return false;
            }

        }


        private bool juntaListas()
        {

            XDocument doc = XDocument.Load("listas.xml");
            var registo = from lista in doc.Element("Listas").Descendants("Lista") select lista;


            foreach (var campos in registo)
            {
                if (!Listas.ContainsKey(campos.Attribute("Descricao").Value))
                {
                    Lista novaLista = new Lista();
                    novaLista.Descricao = campos.Attribute("Descricao").Value;
                    Listas.Add(novaLista.Descricao, novaLista);

                }
            };
            return true;
        }

        private bool juntaItems()
        {

            XDocument doc = XDocument.Load("listas.xml");
            var items = from lista in doc.Element("Listas").Descendants("Lista") where lista.Attribute("Descricao").Value == ListaDescricao select lista;

            foreach (var i in items)
            {
                if (!Produtos.ContainsKey(i.Element("Descricao").Value))
                {
                    Produto novoItem = new Produto();
                    novoItem.Descricao = i.Element("Descricao").Value;
                    Produtos.Add(novoItem.Descricao, novoItem);

                }
            }
            return true;
        }

        private bool MostraCats()
        {
            return true;

        }
    }
}
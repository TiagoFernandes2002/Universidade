using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ReactiveUI;
using System.Reactive.Disposables;
using System.Reactive.Linq;

using Xamarin.Forms;
using Xamarin.Forms.Internals;
using Xamarin.Forms.Xaml;


namespace Utad.Lab.G04.MobileDroid.Views
{
    /// <summary>
    /// Page to sign in with user details.
    /// </summary>
    [Preserve(AllMembers = true)]
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class RegisterPage : IViewFor<ViewModels>
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="RegisterPage" /> class.
        /// </summary>
        public RegisterPage()
        {
            this.InitializeComponent();
        }

        
        private async void BtRegister_Clicked(object sender, System.EventArgs e)
        {
            await Navigation.PushModalAsync(new NavigationPage(new MainPage()));

        }

        private async void BtX_Clicked(object sender, System.EventArgs e)
        {
            await Navigation.PushModalAsync(new NavigationPage(new LoginPage()));
        }
    }
}
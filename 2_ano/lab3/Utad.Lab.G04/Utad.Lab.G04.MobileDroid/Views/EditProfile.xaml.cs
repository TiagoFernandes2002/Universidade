using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Internals;
using Xamarin.Forms.Xaml;

namespace Utad.Lab.G04.MobileDroid.Views
{
    /// <summary>
    /// Page to reset old password
    /// </summary>
    [Preserve(AllMembers = true)]
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class EditProfile
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="EditProfile" /> class.
        /// </summary>
        public EditProfile()
        {
            this.InitializeComponent();
        }

        private async void BtX_Clicked(object sender, System.EventArgs e)
        {
            await Navigation.PushModalAsync(new NavigationPage(new ProfilePage()));
        }

        private async void BtEdit_clicked(object sender, System.EventArgs e)
        {
            await Navigation.PushModalAsync(new NavigationPage(new LoginPage()));
        }
    }
}
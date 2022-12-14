﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace Aula07
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        //Camada de Interligação

        //Models
        public ModelFicheiro Model_Ficheiro { get; private set; }

        public App()
        {
            //Instanciar Models
            Model_Ficheiro = new ModelFicheiro();
        }
    }
}

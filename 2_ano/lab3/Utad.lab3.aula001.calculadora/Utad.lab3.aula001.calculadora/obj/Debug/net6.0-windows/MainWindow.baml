   M S B A M L   `   `   `  ????X  TUtad.lab3.aula001.calculadora, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullM+clr-namespace:Utad.lab3.aula001.calculadoraUtad.lab3.aula001.calculadora  5   	   .    (Utad.lab3.aula001.calculadora.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   =local+clr-namespace:Utad.lab3.aula001.calculadora     5   	     ? Title$  Calculadora??5   	   $	??400??6   $	??400??6*   .??5	      ?  ? RowDefinitions 5
   
   ?? 5      $??* ?6   6+   ?? 5      $??* ?6   6-   ?? 5      $??70 ?6   6,    ? ColumnDefinitions 5   
   ?? 5      $	??120 ?6   6.   ?? 5      $??* ?6   6,   .+?5   
   ?? $??0??6   $??0??6   $??Valor 1??6-   $??Right=?6?   $??Center=?6[   $
??Bold"?6v   ?? 5   
   $??1??6   $??0??6   $??Valor 2??6-   $??Right=?6?   $??Center=?6[   $
??Bold"?6v   ?? 5   
   -   5        $??2??5      $??0??6   $??Calcular Soma??6.   $??Right=?6F   $??Center=?6b   6?   ?? 5   
   -   5         ??Name$ 	TBTValor1??5      $??0??6%   $??1??62   $??60q?6C   ?? 5   
   -   5        $ 	TBTValor2??5      $??1??6%   $??1??62   $??60q?6B   6Q   ?? 5   
   -   5        $ TBTSoma??5      $??2??6#   $??1??60   $??20q?6@   6O   5      5      
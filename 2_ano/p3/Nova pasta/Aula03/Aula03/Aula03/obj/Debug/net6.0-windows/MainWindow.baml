   M S B A M L   `   `   `  ????A  =Aula03, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:Aula03Aula03  5   	       Aula03.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   &localclr-namespace:Aula03     5   	     ? Title$  Adiciona Números??5   	   $	??277??6"   $	??636??6/   .??5	      ? .+?5
   
   ?? $
??Left=?6   $??	10,10,0,0q?6/   $
??Wrap=?6B   $??Introduza o valor 1:??6V   $	??Top=?6r   ?? 5   
   $
??Left=?6   $??	10,31,0,0q?6/   $
??Wrap=?6B   $??Introduza o valor 2:??6V   $	??Top=?6r   ?? 5   
   $
??Left=?6   $??	10,67,0,0q?6/   $
??Wrap=?6B   $??O resultado da soma é:??6V   $	??Top=?6t   ?? 5   
   -   5         ??Name$ tbValor1??5      $
??Left=?6$   $??
126,10,0,0q?6?    ?? TextWrapping$
 Wrap=?6S   $	??Top=?6g   $	??120??6   ?? 5   
   -   5        $ tbValor2??5      $
??Left=?6$   $??
126,33,0,0q?6?   $
 Wrap=?6S   $	??Top=?6g   $	??120??6   ?? 5   
   -   5        $ tbResultado??5      $
??Left=?6'   $??
137,67,0,0q?6B   $
 Wrap=?6V   $	??Top=?6j   $	??120??6?   ${?False??6?   ?? 5   
   -   5         ??Name$ btnAdicionar??5      $??	Adicionar??6'   $
??Left=?6;   $??203,111,0,0q?6V   $	??Top=?6k   6?   ?? 5   
   -   5        $ 	btnLimpar??5      $??Limpar??6$   $
??Left=?65   $??132,111,0,0q?6P   $	??Top=?6e   6}   ?? 5   
   $
??Left=?6   $??
333,18,0,0q?6/   $
??Wrap=?6C   $??ComboBox??6W   $	??Top=?6g   ?? 5   
   -   5         ??Name$ cbResultados??5      $
??Left=?6)   $??
302,42,0,0q?6D   $	??Top=?6X   $	??120??6p   ?? 5   
   $
??Left=?6   $??
343,87,0,0q?6/   $
??Wrap=?6C   $??ListBox??6W   $	??Top=?6f   ?? 5   
   -   5         ??Name$ lbResultados??5      $??314,109,226,47q?6(   ?? 5   
   $
??Left=?6   $??
512,26,0,0q?6/   $
??Wrap=?6C   $??ListView??6W   $	??Top=?6g   ?? 5   
   -   5         ??Name$ 	lvValores??5      $??487,44,29,146q?6&    ?? View 5      ?? 5      .P?5      ?? 5      5      ?? 5   
   $
??Left=?6   $??520,135,0,0q?6/   $
??Wrap=?6D   $??TreeView??6X   $	??Top=?6h   R? 5   
   -	   5         R?Name$ tvResultados??5      $??504,156,46,19q?6)   5!      5"      
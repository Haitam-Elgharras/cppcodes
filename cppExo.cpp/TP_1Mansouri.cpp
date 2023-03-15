
// // ex4
// #include <iostream>
// using namespace std;
// int puissance(int x, int n)
// {
//     int p = x;
//     for (int i = 0; i < n / 2; i++)
//     {
//         x = x * x;
//     }
//     if (n % 2 != 0)
//     {
//         x = x * p;
//     }
//     return x;
// }
// int main()
// {
//     int x, n;
//     cout << "donner la valeur de x";
//     cin >> x;
//     cout << "donner lordre ";
//     cin >> n;
//     x = puissance(x, n);
//     cout << x;
//     return 0;
// }

// // // ex3
// #include <iostream>
// #include <conio.h>
// using namespace std;
// int main()
// {
//     int n;
//     char tc[30], c;
//     float x;
//     cout << "Saisir un entier:";
//     cin >> n;
//     cout << "Saisir un réel:";
//     cin >> x;
//     // lorsque j'ai ecrit une phrase , cin considère l'espace comme une fin de saiser
//     // alors il passe directement a lire le premier caractère de la deuxième mot et stocker dans c
//     cout << "Saisir une phrase:";
//     cin >> tc;
//     cout << "Saisir une lettre:";
//     cin >> c;
//     cout << "Affichage : " << n << " " << x << " " << tc << " " << c << "\n";
//     getch();
//     return 0;
// }

// // ex2
// #include <stdio.h>
// #include <iostream>
// #include <conio.h>
// using namespace std;

// int main()
// {
//     int i, n = 25, *p;
//     // la chaîne de caractères qu'il(p) pointe ne peut pas être modifiée.
//     //  C'est parce que la chaîne de caractères est définie comme une chaîne constante en mémoire.
//     // il faut donc ajouter   const char *CH ou char const *CH
//     const char *CH = "On est à l’IGA !";
//     float x = 25.359;
//     cout << "BONJOUR\n";
//     cout << CH << "\n";
//     cout << "BONJOUR\n"
//          << CH << "\n";
//     cout << "n= " << n << " x= " << x << " p= " << p << "\n";
//     getch();
//     return 0;
// }

// // ex1
// int n;
// float x;
// cout << "donnez un entier et un flottant" << endl;
// cin >> n >> x;
// cout << " le produit de " << n << " par " << x << " est " << endl
//      << n * x;

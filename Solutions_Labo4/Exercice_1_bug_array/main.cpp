
#include <iostream>
#include <array>
using namespace std;

/*
 *
 */
int main()
{

    //  1) array<int, 4> a {1, 2, , 4};
    //manque un chiffre entre 2 et 4
    array<int, 4> a{1, 2, 3, 4};




    // 2) Présumez :
    array<int, 10> b{};
    for (size_t i{0}; i <= 10; ++i)
    {
        b[i] = 1;
    }

    //dépassement du tableau donc i<10;
    for (size_t i{0}; i < 10; ++i)
    {
        b[i] = 1;
    }



    // 3) Présumez :
    array<array<int, 2>, 2> c{
        {
            {1, 2},
            {3, 4}
        }};
    // c[1, 1] = 5 ;
    //le bon écriture est :
    c[1][1] = 5;



    //       4) Considérer le programme qui affiche le contenu d’un tableau suivant :
    array<int, 10> tab{1, 2, 3, 4, 5, 6, 7, 8, 9};
//        for (size_t i{0}; i < 10; ++i)
//        {
//            cout << tab + i << "\n";
//        }

    //la solution est :

    for (size_t i{0}; i < 10; ++i)
    {
        cout << tab[i] << "\n";
    }





    //    5) On veut afficher les éléments de la matrice 5x3 définie par
    array<array<int, 3>, 5> matrice{
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12},
            {13, 14, 15}
        }};
    for (size_t i{0}; i < 3; ++i)
    {
        for (size_t j{0}; j < 5; ++j)
        {
            cout << matrice[i][j] << " ";
        }
        cout << "\n";
    }

    //    les lignes et colonnes sont confondu, il y a 5 lignes et 3 colonnes. Donc :

    for (size_t i{0}; i < 5; ++i)
    {
        for (size_t j{0}; j < 3; ++j)
        {
            cout << matrice[i][j] << " ";
        }
        cout << "\n";
    }






    //    6) array<array<int, 2>, 2> d {
    //        {1, 2},
    //        {2, 3}
    //    };


    //    manque des crochets, pour iniatialiser :

    array<array<int, 2>, 2> d{
        {
            {1, 2},
            {2, 3}
        }};

    //    7) Considérer le programme qui affiche le contenu d’un tableau suivant :
    array<int, 10> tab2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (size_t i{0}; i < 10; i += 2)
    {
        cout << tab2[i] << "\n";
    }

    //    Dans la boucle for nous avons i + 2, donc l'affichage ne sera pas compléte 
    //            car seules les indices paires sont affichées.






    return 0;
}


/**
 * \file fonctions.cpp
 *
 * \version v2
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "fonctions.h"

using namespace std;

/**
 * \brief Fonction qui charge en mémoire des informations qui se trouvent dans un fichier
 * \param[in] p_nomFichier une chaîne de caractères qui représente le nom du fichier
 * \param[out] p_liste un tableau de chaînes de caractères qui va contenir les mots qui sont dans le fichier
 * \return nbMots un entier qui représente le nombre de mots présents dans le fichier
 */
int lireListe(const std::string& p_nomFichier, std::array<std::string, NOMBRE_MAX_MOTS>& p_liste)
{
    int nbMots{0};


    ifstream fichier(p_nomFichier, ios::in); //ouverture pour lecture en mode texte;
    if (!fichier)
    {
        cout << "Erreur d'ouverture du fichier\n";
        exit(ERREUR);
    }
    cout << "\n";

    char buffer[256];
    while (fichier.getline(buffer, 255))
    {
        p_liste[nbMots] = buffer;
        ++nbMots;
    }

    fichier.close();

    return nbMots;
}

/**
 * \brief Fonction qui affiche les mots contenus dans un tableau
 * \param[in] p_liste un tableau de NOMBRE_MAX_MOTS chaînes de caractères
 * \param[in] p_n un entier qui représente le nombre de mots contenus dans le tableau
 */
void afficheListe(const std::array<std::string, NOMBRE_MAX_MOTS>& p_liste, int p_nombreMot)
{
    for (size_t i {0}; i < p_nombreMot; ++i)
    {
        cout << p_liste[i] << "\n";
    }
}

/**
 * \brief Fonction qui compte le nombre de redondances d'un mot contenu dans un tableau de mots
 * \param[in] p_liste un tableau de NOMBRE_MAX_MOTS mots
 * \param[in] p_nombreMots un entier qui représente le nombre de mots contenus dans le tableau
 * \return le nombre de redondances de mots
 */
int compteRedondances(const std::array<std::string, NOMBRE_MAX_MOTS>& p_liste, int p_nombreMots)
{
    size_t i;
    size_t j;
    int redondances{0};
    string reference;

    for (i = 0; i < p_nombreMots; i++)
    {
        bool dejaTraite{false};
        reference = p_liste[i];
        // On cherche si le mot liste [i] a déjà été traité
        for (j = 0; j < i; j++)
        {
            if (p_liste[j].compare(reference) == 0)
            {
                dejaTraite = true;
            }
        }

        // Si le mot liste [i] a déjà été traité alors
        //on ne compte pas le nombre de redondances.
        if (!dejaTraite)
        {
            for (j = i + 1; j < p_nombreMots; ++j)
            {
                if (p_liste[j].compare(reference) == 0)
                {
                    ++redondances; //on a trouvé deux mots identiques
                }
            }
        }
    }

    return redondances;
}

/**
 * \brief Fonction qui ajoute à chaque mot sa longueur
 *	on utilise un flux ostringstream et l'opérateur << pour convertir un entier
 *	en chaine de caractères que l'on concatène (toujours en utilisant l'opérateur <<)
 *	avec les mots dans la liste des mots
 *	le contenu du flux ainsi constitué est ensuite converti en string par la méthode str()
 *	avant d'être assignée dans le tableau p_liste de mots (p_liste étant un tableau de
 *	string et non de ostringstream, d'où la nécessaire conversion)
 * \param[in] p_liste[NOMBRE_MAX_MOTS] un tableau de mots
 * \param[in] p_nombreMots un entier qui représente le nombre de mots contenus dans le tableau
 */
void ajouterNombreCaracteres(std::array<std::string, NOMBRE_MAX_MOTS>& p_liste, int p_nombreMots)
{
    for (size_t i{0}; i < p_nombreMots; ++i)
    {
        ostringstream os;
        int longueur = p_liste[i].length();
        os << p_liste[i] << ", " << longueur;
        p_liste[i] = os.str();
    }
}

/**
 * \brief Fonction qui sauvegarde le contenu d'un tableau dans un fichier
 * \param[in] p_nomFichier une chaîne de caractères qui représente le nom du fichier de sauvegarde
 * \param[in] p_liste[NOMBRE_MAX_MOTS] un tableau de chaînes de caractères
 * \param[in] p_n un entier qui représente le nombre de mots contenus dans le tableau
 */
void sauveListe(const std::string& p_nomFichier, const std::array<std::string, NOMBRE_MAX_MOTS>& p_liste, int p_nombreMot)
{
    ofstream sortie(p_nomFichier, ios::out); //ouverture pour l'écriture en mode texte
    // A: sortie est un pointeur non NULL
    if (!sortie)
    {
        cout << "Erreur d'ouverture du fichier\n";
        exit(ERREUR);
    }
    //sauvegarde -> écriture fichier
    for (size_t i {0}; i < p_nombreMot; ++i)
    {
        sortie << p_liste[i] << "\n"; // écriture dans le fichier
    }
}



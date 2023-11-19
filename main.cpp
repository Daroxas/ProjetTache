#include "central.h"
#include "Projet.h"
#include "Membre.h"
#include "Tache.h"
#include "TachePrio.h"
#include "TacheLongue.h"

void NewPage()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main()
{
    int choix;

    int priorite;
    int delai;

    str nom;
    str description;
    str role;
    str avancement;
    str deadline;

    NewPage();
    
    cout << CYN "Bienvenue dans le système de gestion de projet" << endl;
    cout << "Que voulez vous faire ?" NC << endl << endl;
    cout << YLW "1) Créer/Modifier l'équipe projet" << endl;
    cout << "2) Créer un nouveau projet" << endl;
    cout << "3) Manage un projet" << endl;
    cout << "4) Fermer le système de gestion" NC << endl << endl;
    cout << GRN "Votre choix : " NC;

    cin >> choix;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    
}
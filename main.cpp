#include "central.h"
#include <exception>
#include "Projet.h"
#include "Membre.h"
#include "Tache.h"
#include "TachePrio.h"
#include "TacheLongue.h"

void NewPage()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int Choix(int &choix)
{
    try
    {
        cin >> choix;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    int choix = 0;
    int end = 0;

    int priorite;
    int delai;

    str nom;
    str nomTache;
    str nomProjet;
    str description;
    str role;
    str avancement;
    str deadline;

    NewPage();
    
    cout << CYN "Bienvenue dans le système de gestion de projet" << endl;
    cout << "Que voulez vous faire ?" NC << endl << endl;
    cout << YLW "1) Créer un nouveau projet" << endl;
    cout << "2) Manage un projet" << endl;
    cout << "3) Manage l'équipe projet (seulement lorsqu'un projet est déjà existant)" << endl;
    cout << "4) Fermer le système de gestion" NC << endl << endl;
    cout << GRN "Votre choix : " NC;

    Choix(choix);

    
    switch (choix)
    {
    case 1:


        break;

    case 2:

        break;

    case 3:
        if (Projet :: ListeProjetVide())
        {
            cout << RED "Vous ne pouvez pas gérer une équipe projet sans avoir de projet défini au préalable." << endl << endl;
            break;
        }
            while(end == 0)
            {
                NewPage();

                cout << YLW "1) Ajouter un membre à l'équipe" << endl;
                cout << "2) Supprimer un membre de l'équipe" << endl;
                cout << "3) Assigner un tâche" << endl;
                cout << "4) Supprimer une tâche assignée" << endl;
                cout << "5) Obtenir la charge de travail d'un membre" << endl;
                cout << "6) Obtenir les informations d'une tâche assigner à un membre" << endl;
                cout << "7) Valider l'équipe projet et l'attribution des tâches" NC << endl << endl;

                Choix(choix);

                switch (choix)
                {
                case 1:
                    NewPage();

                    cout << "Nom : ";
                    getline(cin, nom);
                    cout << endl <<  "Role : ";
                    getline(cin, role);
                    cout << endl;
                    
                    if(!nom.empty() && !role.empty())
                    {
                        Membre* membre = new Membre(nom, role);
                        break;
                    }
                    
                    cout << RED "Erreur vous avez oublié le nom ou le role de votre membre" NC << endl << endl;
                    break;

                case 2:
                    NewPage();

                    cout << "Nom de la personne à retirer : ";
                    getline(cin, nom);

                    if(!nom.empty())
                    {
                        Membre :: SupprimerMembre(nom);
                        break;
                    }

                    cout << RED "Erreur vous avez oublié de préciser le nom du membre à retirer" NC << endl << endl;
                    break;

                case 3:
                    NewPage();
                    
                    cout << "Nom du membre à qui attribuer la tâche : ";
                    getline(cin, nom);
                    if (nom.empty())
                    {
                        cout << RED "Erreur vous n'avez pas préciser le membre qui devait se voir assigner la tâche" NC << endl << endl;
                        break;
                    }
                    Membre* membre = Membre :: SelectionnerMembre(nom);

                    cout << "Nom du projet d'où proviens la tâche : ";
                    getline(cin, nomProjet);
                    cout << "Nom de la tâche à assigner (la tâche dois se trouver dans la collection de tâche du projet précisé précédemment) : ";
                    getline(cin, nomTache);

                    if(!nomProjet.empty() && !nomTache.empty())
                    {
                        Projet* projet = Projet :: SelectionnerProjet(nomProjet);
                        membre->AssignerTache(*projet, nomTache);
                        break;
                    }

                    cout << RED "Erreur vous n'avez pas précisé le nom du projet où de la tâche" NC << endl << endl;
                    break;

                case 4:
                    NewPage();

                    cout << "Nom du membre pour qui il faut supprimer la tâche : ";
                    getline(cin, nom);
                    if (nom.empty())
                    {
                        cout << RED "Erreur vous n'avez pas préciser le membre dont il fallait supprimer la tâche" NC << endl << endl;
                        break;
                    }
                    Membre* membre = Membre :: SelectionnerMembre(nom);

                    cout << "Nom de la tâche à supprimer : ";
                    getline(cin, nomTache);

                    if (!nomTache.empty())
                    {
                        membre->SupprimerTache(nomTache);
                    }

                    cout << RED "Erreur vous n'avez pas précisé le nom de la tâche à supprimer" NC << endl << endl;
                    break;
                
                case 5:
                    NewPage();

                    cout << "Nom du membre pour qui il récupérer la charge de travail : ";
                    getline(cin, nom);
                    if (nom.empty())
                    {
                        cout << RED "Erreur vous n'avez pas préciser le membre dont vous vouliez appercevoir la charge de travail" NC << endl << endl;
                        break;
                    }
                    Membre* membre = Membre :: SelectionnerMembre(nom);
                    
                    membre->ChargeDeTravail();
                    break;

                case 6:
                    break;

                default:
                    break;
                }
            }  
        break;

    default:
        break;
    }
    

}
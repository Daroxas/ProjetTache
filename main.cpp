#include "central.h"
#include <exception>
#include <unistd.h>
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
    int retour = 0;

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
    cout << "3) Supprimer un projet" << endl;
    cout << "4) Manage l'équipe projet (seulement lorsqu'un projet est déjà existant et que des tâches on été attribué à ce dernier)" << endl;
    cout << "5) Fermer le système de gestion" NC << endl << endl;
    cout << GRN "Votre choix : " NC;

    Choix(choix);

    
    switch (choix)
    {
    case 1:
        NewPage();

        cout << GRN "Nom du projet : " NC;
        getline(cin, nomProjet);
        cout << GRN "Description du projet : " NC;
        getline(cin, description);

        if(!nomProjet.empty() && !description.empty())
        {
            Projet* projet = new Projet(nomProjet, description);
            break;
        }

        cout << RED "Erreur vous n'avez pas précisé le nom ou la description du projet" NC << endl << endl;
        break;

    case 2:
        while(end == 0)
        {
            NewPage();

            cout << GRN "Entrez le nom du projet à gérer : " NC;
            getline(cin, nomProjet);

            if(nomProjet.empty())
            {
                NewPage();

                cout << RED "Erreur vous n'avez précisé le projet que je vous souhaiter gérer" NC << endl << endl;
            
                sleep(3);
                break;
            }

            Projet* projet = Projet :: SelectionnerProjet(nomProjet);

            while(projet != nullptr)
            {
                NewPage();


            }
        }

        break;
    case 3:

        break;
    case 4:
        if (Projet :: ListeProjetVide())
        {
            cout << RED "Vous ne pouvez pas gérer une équipe projet sans avoir de projet défini au préalable." NC << endl << endl;
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

                    cout << GRN "Nom : " NC;
                    getline(cin, nom);
                    cout << endl << GRN "Role : " NC;
                    getline(cin, role);
                    cout << endl;
                    
                    if(!nom.empty() && !role.empty())
                    {
                        NewPage();
                        
                        Membre* membre = new Membre(nom, role);
                        
                        sleep(3);
                        break;
                    }

                    NewPage(); 
                    
                    cout << RED "Erreur vous n'avez pas précisé le nom ou le role de votre membre" NC << endl << endl;
                    
                    sleep(3);
                    break;

                case 2:
                    NewPage();

                    cout << GRN "Nom de la personne à retirer : " NC;
                    getline(cin, nom);

                    if(!nom.empty())
                    {
                        NewPage();

                        Membre :: SupprimerMembre(nom);
                       
                        sleep(3);
                        break;
                    }

                    NewPage();

                    cout << RED "Erreur vous n'avez pas précisé le nom du membre à retirer" NC << endl << endl;
                    
                    sleep(3);
                    break;

                case 3:
                    NewPage();
                    
                    cout << GRN "Nom du membre à qui attribuer la tâche : " NC;
                    getline(cin, nom);
                    if (nom.empty())
                    {
                        NewPage();

                        cout << RED "Erreur vous n'avez pas préciser le membre qui devait se voir assigner la tâche" NC << endl << endl;
                       
                        sleep(3);
                        break;
                    }
                    Membre* membre = Membre :: SelectionnerMembre(nom);

                    cout << GRN "Nom du projet d'où proviens la tâche : " NC;
                    getline(cin, nomProjet);
                    cout << GRN "Nom de la tâche à assigner (la tâche dois se trouver dans la collection de tâche du projet précisé précédemment) : " NC;
                    getline(cin, nomTache);

                    if(!nomProjet.empty() && !nomTache.empty())
                    {
                        NewPage();

                        Projet* projet = Projet :: SelectionnerProjet(nomProjet);
                        membre->AssignerTache(*projet, nomTache);

                        sleep(3);
                        break;
                    }

                    NewPage();

                    cout << RED "Erreur vous n'avez pas précisé le nom du projet où de la tâche" NC << endl << endl;
                    
                    sleep(3);
                    break;

                case 4:
                    NewPage();

                    cout << GRN "Nom du membre pour qui il faut supprimer la tâche : " NC;
                    getline(cin, nom);
                    if (nom.empty())
                    {
                        NewPage();

                        cout << RED "Erreur vous n'avez pas préciser le membre dont il fallait supprimer la tâche" NC << endl << endl;
                        
                        sleep(3);
                        break;
                    }
                    Membre* membre = Membre :: SelectionnerMembre(nom);

                    cout << GRN "Nom de la tâche à supprimer : " NC;
                    getline(cin, nomTache);

                    if (!nomTache.empty())
                    {
                        NewPage();

                        membre->SupprimerTache(nomTache);

                        sleep(3);
                    }

                    NewPage();

                    cout << RED "Erreur vous n'avez pas précisé le nom de la tâche à supprimer" NC << endl << endl;
                    
                    sleep(3);
                    break;
                
                case 5:
                    NewPage();

                    cout << GRN "Nom du membre pour qui il récupérer la charge de travail : " NC;
                    getline(cin, nom);
                    if (nom.empty())
                    {
                        NewPage();

                        cout << RED "Erreur vous n'avez pas préciser le membre dont vous vouliez appercevoir la charge de travail" NC << endl << endl;
                        
                        sleep(3);
                        break;
                    }
                    Membre* membre = Membre :: SelectionnerMembre(nom);
                    
                    NewPage();

                    membre->ChargeDeTravail();
                    
                    sleep(3);
                    break;

                case 6:
                    NewPage();

                    cout << GRN "Nom du membre pour qui il récupérer les informations de la tâche : " NC;
                    getline(cin, nom);
                    if (nom.empty())
                    {
                        NewPage();

                        cout << RED "Erreur vous n'avez pas préciser le membre dont vous vouliez récupérer les informations de la tâche" NC << endl << endl;
                        
                        sleep(3);
                        break;
                    }
                    Membre* membre = Membre :: SelectionnerMembre(nom);

                    cout << GRN "Nom de la tâche dont vous voulez appercevoir les informations : " NC;
                    getline(cin, nomTache);

                    if(!nomTache.empty())
                    {
                        NewPage();

                        Tache* tache = membre->SelectionnerTache(nomTache);
                        tache->GetInfo();
                    
                        sleep(3);
                        break;
                    }
                    NewPage();

                    cout << RED "Erreur vous n'avez pas précisé la tâche dont vous vouliez voir les informations" NC << endl << endl;

                    sleep(3);
                    break;

                case 7:
                    NewPage();

                    cout << CYN "Equipe projet et attribution des tâches enregistré avec succés" NC << endl << endl;
                    end = 1;

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
#include "central.h"
#include "Projet.h"
#include "Tache.h"
#include "TachePrio.h"
#include "TacheLongue.h"


bool Projet :: ProjetExists(str projet)
{
    return listeProjet.find(projet) != listeProjet.end();
}

bool Projet :: TacheExists(str tache)
{
    return listeTache.find(tache) != listeTache.end();
}

Projet :: Projet(str nom, str description)
{
    if (!ProjetExists(nom))
    {
        cout << GRN "Projet " << nom << "créer avec succés" << endl << endl;
        this->nom = nom;
        this->description = description;
        listeProjet[this->nom] = this;
    }

    cout << RED "Erreur lors de la création du projet, ce projet existe déjà" << endl << endl;
}

str Projet :: GetNom()
{
    return nom;
}

str Projet :: GetDescription()
{
    return description;
}

void Projet :: AddTache(str nom, str description, int priorite, str avancement)
{
    if (!TacheExists(nom))
    {
        if (priorite == 0)
        {
            str deadline;
            cout << GRN "Veuillez entrer une deadline pour votre tâche urgente (date limite)" << endl;
            cout << NC "Deadline : ";
            getline(cin, deadline);

            Tache* tache = new TachePrio(nom, description, priorite, avancement, deadline);
            listeTache[tache->nom] = tache;
        }   

        if (priorite == 4)
        {
            int delai;
            cout << GRN "Veuillez entrer un délai pour votre tâche longue durée (Nombre de jours)" << endl;
            cout << NC "Délai : ";
            cin >> delai;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            Tache* tache = new TacheLongue(nom, description, priorite, avancement, delai);
            listeTache[tache->nom] = tache;
        }
        Tache* tache = new Tache(nom, description, priorite, avancement);
        listeTache[tache->nom] = tache;
    }

    cout << RED "Erreur lors de la création de la tâche, cette tâche existe déjà" << endl << endl;
}

void Projet :: RemoveTache(str nom)
{
    if (TacheExists(nom))
    {
        cout << GRN "Tâche '" << nom << "' supprimée avec succés" << endl << endl;
        listeTache.erase(nom);
    }
}

Projet* Projet :: SelectionnerProjet(str projet)
{
    auto it = listeProjet.find(projet);

    if(it != listeProjet.end())
    {
        return it->second;
    }
}

Tache* Projet :: SelectionnerTache(str nom, const Projet& projet)
{
    auto it = projet.listeTache.find(nom);
    
    if(it != projet.listeTache.end())
    {
        return it->second;
    }

    cout << RED "Erreur, la tâche spécifié n'existe pas" << endl << endl;
}

void Projet :: AfficherCollectionTache()
{
    auto it = listeTache.begin();

    while (it != listeTache.end())
    {
        Tache* tache = it->second;
        if (tache->GetPriorite() == 0)
        {
            cout << RED << tache->GetNom() << endl;
        }
        if (tache->GetPriorite() == 4)
        {
            cout << YLW << tache->GetNom() << endl;
        }
        cout << NC << tache->GetNom() << endl;

        it++;
    }

    cout << endl;
}

void Projet :: AfficherListeProjets()
{
    auto it = listeProjet.begin();

    while (it != listeProjet.end())
    {
        Projet* projet = it->second;
        cout << NC << projet->GetNom() << endl;
    }

    cout << endl;
}

void Projet :: GetInfo()
{
    cout << NC "Nom du projet : " << GetNom() << endl;
    cout << "Description : " << GetDescription() << endl << endl;
}
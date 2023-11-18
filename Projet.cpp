#include "central.h"
#include "Projet.h"
#include "Tache.h"


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

void Projet :: AddTache(str nom, str description, int priorité, str avancement, int delai)
{
    if (!TacheExists(nom))
    {
        cout << GRN "Tâche '" << nom << "' créée avec succés" << endl << endl;
        Tache* tache = new Tache(nom, description, priorité, avancement, delai);
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
#include "central.h"
#include "Membre.h"
#include "Projet.h"

bool Membre :: MembreExists(str nom)
{
    return equipe.find(nom) != equipe.end();
}

bool Membre :: TacheExists(str nom)
{
    return tachesMembre.find(nom) != tachesMembre.end();
}


Membre :: Membre(str nom, str role)
{
    if(!MembreExists(nom))
    {
        cout << GRN "Membre " << nom << "ajouté à l'équipe avec succés" << endl << endl;

        this->nom = nom;
        this->role = role;
        equipe[this->nom] = this;   
    }
}

Membre* Membre :: SelectionnerMembre(str nom)
{
    auto it = equipe.find(nom);
    
    if(it != equipe.end())
    {
        return it->second;
    }

    cout << RED "Erreur, le membre recherché ne fait pas partie de l'équipe" << endl << endl;
}

Tache* Membre :: SelectionnerTache(str nom)
{
    auto it = tachesMembre.find(nom);
    
    if(it != tachesMembre.end())
    {
        return it->second;
    }

    cout << RED "Erreur la tâche recherché n'as pas été assignée à ce membre" << endl << endl;
}

void Membre :: AssignerTache(const Projet& projet, str tache)
{
    Tache* task = Projet :: SelectionnerTache(tache, projet);

    tachesMembre[task->nom] = task;
}

int Membre :: ChargeDeTravail()
{
    return tachesMembre.size();
}

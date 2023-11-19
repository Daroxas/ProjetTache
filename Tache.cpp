#include "central.h"
#include "Tache.h"

Tache :: Tache(str nom, str description, int priorite, str avancement)
{
    cout << GRN "Tâche " << nom << " créée avec succés" << endl << endl;
    this->nom = nom;
    this->descritpion = description;
    this->priorite = priorite;
    this->avancement = avancement;
}

void Tache :: UpdatePriorité(int newPriorite)
{
    cout << GRN "Nouvelle priorité appliqué avec succés" << endl << endl;

    this->priorite = newPriorite;
}

void Tache :: UpdateAvancement(str newAvancement)
{
    cout << GRN "Status d'avancement mis à jour avec succés" << endl << endl;

    this->avancement = newAvancement;
}

str Tache :: GetNom()
{
    return nom;
}

str Tache :: GetDescription()
{
    return descritpion;
}

int Tache :: GetPriorite()
{
    return priorite;
}

str Tache :: GetAvancement()
{
    return avancement;
}

void Tache :: GetInfo()
{
    cout << GRN "Information sur la tâche : " << endl << endl;
    cout << NC "Nom : " << GetNom() << endl;
    cout << "Description : " << GetDescription() << endl;
    cout << "Priorité : " << GetPriorite() << endl;
    cout << "Avancement : " << GetAvancement() << endl << endl;
}
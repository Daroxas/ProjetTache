#include "central.h"
#include "Tache.h"

Tache :: Tache(str nom, str description, int priorite, str avancement, int delai)
{
    this->nom = nom;
    this->descritpion = description;
    this->priorite = priorite;
    this->avancement = avancement;
    this->delai = delai;
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

int Tache :: GetDelai()
{
    return delai;
}

void Tache :: GetInfo()
{
    cout << NC "Nom : " << GetNom() << endl;
    cout << "Description : " << GetDescription() << endl;
    cout << "Priorité : " << GetPriorite() << endl;
    cout << "Délai de complétion (jours) : " << GetDelai() << endl << endl;
}
#include "central.h"
#include "Tache.h"

Tache :: Tache(str nom, str description, int priorité, str avancement, int delai)
{
    this->nom = nom;
    this->descritpion = description;
    this->priorité = priorité;
    this->avancement = avancement;
    this->delai = delai;
}

void Tache :: UpdatePriorité(int newPriorité)
{
    cout << GRN "Nouvelle priorité appliqué avec succés" << endl << endl;

    this->priorité = newPriorité;
}

void Tache :: UpdateAvancement(str newAvancement)
{
    cout << GRN "Status d'avancement mis à jour avec succés" << endl << endl;

    this->avancement = newAvancement;
}
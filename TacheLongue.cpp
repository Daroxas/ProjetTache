#include "central.h"
#include "TacheLongue.h"

TacheLongue :: TacheLongue(str nom, str description, int priorite, str avancement, int delai)
{
    cout << GRN "Tâche longue " << YLW << nom << NC " créée avec succés" << endl << endl;
    this->nom = nom;
    this->descritpion = description;
    this->priorite = priorite;
    this->avancement = avancement;
    this->delai = delai;
}

int TacheLongue :: GetDelai()
{
    return delai;
}

void TacheLongue :: GetInfo()
{
    cout << GRN "Information sur la tâche : " << endl << endl;
    cout << NC "Nom : " << YLW << GetNom() << NC << endl;
    cout << "Description : " << GetDescription() << endl;
    cout << "Priorité : " << GetPriorite() << endl;
    cout << "Avancement : " << GetAvancement() << endl;
    cout << "Délai : " << GetDelai() << endl << endl;
}
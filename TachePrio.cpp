#include "central.h"
#include "TachePrio.h"

TachePrio :: TachePrio(str nom, str description, int priorite, str avancement, str deadline)
{
    cout << GRN "Tâche urgente" << RED << nom << GRN " créée avec succés" << endl << endl;
    this->nom = nom;
    this->descritpion = description;
    this->priorite = priorite;
    this->avancement = avancement;
    this->deadline = deadline;
}

str TachePrio :: GetDeadline()
{
    return deadline;
}

void TachePrio :: GetInfo()
{
    cout << GRN "Information sur la tâche : " << endl << endl;
    cout << NC "Nom : " << RED << GetNom() << NC << endl;
    cout << "Description : " << GetDescription() << endl;
    cout << "Priorité : " << GetPriorite() << endl;
    cout << "Avancement : " << GetAvancement() << endl;
}
#include "central.h"
#include "TachePrio.h"
#include "Tache.h"

TachePrio :: TachePrio(str nom, str description, int priorite, str avancement, int delai, str deadline)
{
    cout << GRN "Tâche urgente" << RED << nom << GRN " créée avec succés" << endl << endl;
    this->nom = nom;
    this->descritpion = description;
    this->priorite = priorite;
    this->avancement = avancement;
    this->delai = delai;
    this->deadline = deadline;
}

str TachePrio :: GetDeadline()
{
    return deadline;
}
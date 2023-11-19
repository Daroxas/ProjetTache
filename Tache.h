#include "central.h"

class Tache
{
public :

    str nom;
    str descritpion;
    int priorite;
    str avancement;

    Tache() = default;
    Tache(str nom, str description, int priorite, str avancement);

    void UpdatePriorité(int newPriorite);
    void UpdateAvancement(str newAvancement);

    str GetNom();
    str GetDescription();
    int GetPriorite();
    str GetAvancement();

    void GetInfo();

};
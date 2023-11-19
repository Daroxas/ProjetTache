#include "central.h"

class Tache
{
public :

    str nom;
    str descritpion;
    int priorite;
    str avancement;
    int delai;

    Tache(str nom, str description, int priorite, str avancement, int delai);

    void UpdatePriorité(int newPriorite);
    void UpdateAvancement(str newAvancement);

    str GetNom();
    str GetDescription();
    int GetPriorite();
    str GetAvancement();
    int GetDelai();

    void GetInfo();

};
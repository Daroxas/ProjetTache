#include "central.h"

class Tache
{
public :

    str nom;
    str descritpion;
    int priorité;
    str avancement;
    int delai;

    Tache(str nom, str description, int priorité, str avancement, int delai);

    void UpdatePriorité(int newPriorité);
    void UpdateAvancement(str newAvancement);

};
#include "central.h"
#include "Tache.h"

class TacheLongue : public Tache
{
public :

    int delai;

    TacheLongue(str nom, str description, int priorite, str avancement, int delai);

    int GetDelai();
    void GetInfo();
};
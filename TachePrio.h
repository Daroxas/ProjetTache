#include "central.h"
#include "Tache.h"

class TachePrio : protected Tache
{
public :
    str deadline;

    TachePrio(str nom, str description, int priorite, str avancement, int delai, str deadline);

    str GetDeadline();
};
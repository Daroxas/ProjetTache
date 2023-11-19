#include "central.h"
#include "Tache.h"

class TachePrio : public Tache
{
public :
    str deadline;

    TachePrio(str nom, str description, int priorite, str avancement, str deadline);

    str GetDeadline();
    void GetInfo();
};
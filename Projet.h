#include "central.h"
#include "Tache.h"

class Projet
{
protected :

    str nom;
    str description;
    static unordered_map<str, Projet*> listeProjet;
    unordered_map<str, Tache*> listeTache;

public :

    Projet();
    Projet(str);
    Projet(str nom, str description);

    static Projet* SelectionnerProjet(str projet);
    static Tache* SelectionnerTache(str nom, const Projet& projet);

    void AddTache(str nom, str description, int priorité, str avancement, int delai);
    void RemoveTache(str nom);

    str GetNom();
    str GetDescription();

    bool ProjetExists(str projet);
    bool TacheExists(str tache);
};
#include "central.h"
#include "Tache.h"

class Membre
{
protected :

    str nom;
    str role;
    static unordered_map<str, Membre*> equipe;
    unordered_map<str, Tache*> tachesMembre;

public :

    Membre(str nom, str role);

    str GetNom();
    str GetRole();
    void GetInfo();

    void AfficherEquipe();
    void AfficherTacheAffecter();


    Membre* SelectionnerMembre(str nom);
    Tache* SelectionnerTache(str nom);

    bool MembreExists(str nom);
    bool TacheExists(str nom);

    void AssignerTache(const Projet& projet, str tache);
    int ChargeDeTravail();

};
#pragma once
#include "central.h"
#include "Projet.h"
#include "Tache.h"

class Membre
{
protected :

    str nom;
    str role;
    

public :

    unordered_map<str, Tache*> tachesMembre;
    static unordered_map<str, Membre*> equipe;

    Membre(str nom, str role);
    static void SupprimerMembre(str nom);

    str GetNom();
    str GetRole();
    void GetInfo();

    void AfficherEquipe();
    void AfficherTacheAffecter();

    static Membre* SelectionnerMembre(str nom);
    Tache* SelectionnerTache(str nom);

    static bool MembreExists(str nom);
    bool TacheExists(str nom);

    void AssignerTache(const Projet& projet, str tache);
    void SupprimerTache(str tache);
    int ChargeDeTravail();

};
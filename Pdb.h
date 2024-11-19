#ifndef PDB_H
#define PDB_H

#include <iostream>
#include <string>

using namespace std;

// Déclaration de la classe de base Pdb
class Pdb
{
protected:
    int pv;         // Points de vie
    int attaque;    // Puissance d'attaque
    int defense;    // Niveau de défense
    int vitesse;    // Vitesse
    int energie;    // Énergie (potentiellement utilisée pour certaines attaques)
    string nom;     // Nom du personnage

public:
    // Constructeur par défaut qui initialise les attributs avec des valeurs par défaut
    Pdb();

    // Constructeur avec paramètres pour initialiser les attributs spécifiques
    Pdb(int pv, int attaque, int defense, int vitesse, int energie, const string& nom);

    // Méthode pour effectuer une attaque "Frappe préventive"
    int Frappe_preventive();

    // Méthode pour effectuer une attaque spéciale "Blast"
    int Blast();

    // Méthode pour réaliser une attaque spéciale "Attaque Delta"
    bool Attaque_Delta();

    // Méthode pour appliquer des dégâts reçus par le personnage
    void Degat_recus(int degats);

    // Méthode pour afficher les statistiques actuelles du personnage dans la console
    void AfficherStatistiques() const;

    // Méthodes pour obtenir les statistiques
    int getvitesse() const { return vitesse; }
    int getpv() const { return pv; }
    string getNom() const { return nom; }

    // Méthodes pour définir les équipements du personnage
    void setEquipement(const string& heaume, const string& gilet, const string& gants, const string& bottes);
    void setEquipementArme(const string& arme);  // Pour l'arme spécifique

    // Méthodes pour obtenir des informations sur les attributs
    int getAttaque() const { return attaque; }
    int getDefense() const { return defense; }
    int getVitesse() const { return vitesse; }
    int getPv() const { return pv; }

    // Appliquer des bonus aux caractéristiques du personnage
    void appliquerBonus(int bonusVie, int bonusAttaque, int bonusDefense, int bonusVitesse);
};

#endif // PDB_H

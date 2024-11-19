#include "Pdb.h"
#include <iostream>
using namespace std;

// Définition de la constante pour l'énergie maximale
const int energie_max = 100; 

// Constructeur par défaut de la classe Pdb
// Initialise les attributs avec des valeurs par défaut
Pdb::Pdb() 
    : pv(2000), attaque(150), defense(100), vitesse(60), energie(0), nom("Pdb") {} // Valeur par défaut

// Constructeur avec paramètres
// Initialise les attributs de Pdb avec les valeurs fournies en argument
Pdb::Pdb(int pv, int attaque, int defense, int vitesse, int energie, const string& nom)
    : pv(pv), attaque(attaque), defense(defense), vitesse(vitesse), energie(energie), nom(nom) {}

// Méthode Frappe_preventive
// Simule une attaque nommée "Frappe préventive"
// Augmente l'énergie du personnage et affiche les dégâts infligés
int Pdb::Frappe_preventive() { 
    cout << "L'attaque utilisee est Frappe preventive." << endl;  
    int degats = attaque;
    cout << "La Frappe preventive fait " << degats << " degâts." << endl;  
    
    // Vérifie si l'énergie est déjà au maximum
    if (energie >= energie_max) {
        cout << "Votre energie est dejà au max." << endl;  
        cout << "Votre attaque speciale est chargee." << endl; 
    } else {
        // Augmente l'énergie de 10 unités, sans dépasser l'énergie maximale
        energie += 10;
        if (energie > energie_max) {
            energie = energie_max; 
        }
        cout << "Vous avez " << energie << " d'energie.\n\n" << endl;
    }
    return degats;
}

// Méthode Blast
// Simule une attaque spéciale "Blast" 
// Augmente l'énergie et affiche les dégâts infligés
int Pdb::Blast() {
    cout << "L'attaque utilisee est Blast." << endl;  
    int degats = attaque * 1.5; // Multiplie l'attaque par 1.5 pour plus de dégâts
    cout << "L'attaque Blast fait " << degats << " degâts." << endl;  
    
    // Vérifie si l'énergie est déjà au maximum
    if (energie >= energie_max) {
        cout << "Votre energie est dejà au max." << endl;  
        cout << "Votre attaque speciale est chargee." << endl; 
    } else {
        // Augmente l'énergie de 15 unités, sans dépasser l'énergie maximale
        energie += 15;
        if (energie > energie_max) {
            energie = energie_max; 
        }
        cout << "Vous avez " << energie << " d'energie.\n\n" << endl;    
    }
    return degats;
}

// Méthode Attaque_Delta
// Effectue une attaque spéciale puissante si l'énergie est au maximum
// Réinitialise l'énergie après l'attaque
bool Pdb::Attaque_Delta() {
    // Vérifie si l'énergie est au maximum
    if (energie >= energie_max) {
        cout << "Votre energie est au max." << endl;  
        int degats = attaque * 1.5; // Inflige des dégâts multipliés
        cout << "L'attaque utilisee est l'attaque speciale Delta. Elle fait " << degats << " degâts.\n" << endl;    
        
        // Réinitialise l'énergie après utilisation de l'attaque spéciale
        energie = 0;
        return degats; // Retourne les dégâts infligés
    } else {
        cout << "Energie insuffisante pour Attaque Delta, choisissez une autre attaque.\n" << endl; 
    }  
    return false;  
}

// Méthode Degat_recus
// Réduit les points de vie du personnage en fonction des dégâts reçus
// Prend en compte la défense pour réduire les dégâts subis
void Pdb::Degat_recus(int degats) {
    int degats_infliges = degats - defense; // Réduit les dégâts par la défense
    if (degats_infliges < 0) {
        degats_infliges = 0;  // Assure que les dégâts ne soient pas négatifs
    }
    pv -= degats_infliges; // Réduit les points de vie
    if (pv < 0) {
        pv = 0; // Assure que les points de vie ne soient pas négatifs
    }
}

// Méthode AfficherStatistiques
// Affiche les statistiques actuelles du personnage
void Pdb::AfficherStatistiques() const {
    cout << "Statistiques de " << getNom() << ": \n"; // Affiche le nom
    cout << "PV: " << pv << endl;
    cout << "Attaque: " << attaque << endl;
    cout << "Defense: " << defense << endl;
    cout << "Vitesse: " << vitesse << endl;
    cout << "Energie: " << energie << "\n" << endl;
}

// Méthode pour définir les équipements
void Pdb::setEquipement(const string& heaume, const string& gilet, const string& gants, const string& bottes) {
    cout << "Équipements pour " << nom << " : " << endl;
    cout << "Heaume: " << heaume << endl;
    cout << "Gilet: " << gilet << endl;
    cout << "Gants: " << gants << endl;
    cout << "Bottes: " << bottes << endl;
}
void Pdb::setEquipementArme(const string& arme) {
    cout << "Arme équipée: " << arme << endl;
}
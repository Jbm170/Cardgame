#include "Berserker.h"
#include <iostream>

const int energie_max = 100; // Définit la limite maximale de l'énergie

// Constructeur par défaut pour la classe Berserker avec des valeurs initiales spécifiques
Berserker::Berserker() 
    : Pdb(4000, 500, 200, 70, 0, "Berserker") {} // Initialise les attributs avec des valeurs par défaut

// Constructeur avec paramètres pour initialiser les attributs avec des valeurs fournies
Berserker::Berserker(int pv, int attaque, int defense, int vitesse, int energie, const std::string& nom)
    : Pdb(pv, attaque, defense, vitesse, energie, nom) {}

// Méthode Frappe_punitive : attaque spéciale qui inflige des dégâts en fonction des PV et consomme des PV
int Berserker::Frappe_punitive() { 
    cout << "L'attaque utilisee est Frappe punitive." << endl;  
    int degats = pv * 0.30; // Inflige 30% des PV comme dégâts
    pv -= pv * 0.10; // Consomme 10% des PV
    energie += 20; // Gagne 20 points d'énergie

    // Limite l'énergie à la valeur maximale
    if (energie > energie_max) {
        energie = energie_max;
    }

    cout << "La Frappe punitive fait " << degats << " degâts." << endl;  
    cout << "Vous avez " << energie << " d'energie et " << pv << " PV restants.\n\n" << endl;

    return degats; // Retourne les dégâts infligés
}

// Méthode Coup_dechaine : attaque spéciale qui inflige plus de dégâts mais consomme plus de PV
int Berserker::Coup_dechaine() {
    cout << "L'attaque utilisee est coup dechaine." << endl;  
    int degats = pv * 0.50; // Inflige 50% des PV comme dégâts
    pv -= pv * 0.15; // Consomme 15% des PV
    energie += 30; // Gagne 30 points d'énergie

    // Limite l'énergie à la valeur maximale
    if (energie > energie_max) {
        energie = energie_max;
    }

    cout << "L'attaque coup dechaine fait " << degats << " degâts." << endl;  
    cout << "Vous avez " << energie << " d'energie et " << pv << " PV restants.\n\n" << endl;

    return degats; // Retourne les dégâts infligés
}

// Méthode Movement_Alpha : attaque ultime qui consomme toute l'énergie pour infliger des dégâts et régénérer des PV
bool Berserker::Movement_Alpha() {
    if (energie >= energie_max) {
        cout << "Votre energie est au max." << endl;  
        int degats = pv * 0.75; // Inflige 75% des PV comme dégâts
        pv += pv * 0.50; // Régénère 50% des PV
        if (pv > 2000) { // Limite les PV à 2000
            pv = 2000;
        }
        energie = 0; // Consomme toute l'énergie

        cout << "L'attaque utilisee est l'attaque speciale Movement Alpha. Elle fait " 
             << degats << " degâts et vous regenerez à " << pv << " PV.\n" << endl;

        return true; // Indique que l'attaque a réussi
    } else {
        cout << "Energie insuffisante pour Movement Alpha, choisissez une autre attaque.\n" << endl;     
        return false; // Indique que l'attaque a échoué
    }    
}

// Méthode AfficherStatistiques : affiche les statistiques actuelles du Berserker
void Berserker::AfficherStatistiques() const {
    cout << "Statistiques de " << getNom() << ": \n"; // Affiche le nom du personnage
    cout << "PV: " << pv << endl;
    cout << "Attaque: " << attaque << endl;
    cout << "Defense: " << defense << endl;
    cout << "Vitesse: " << vitesse << endl;
    cout << "Energie: " << energie << "\n" << endl;
}

#include "Snowqueen.h"
#include <iostream>

const int energie_max = 100;

Snowqueen::Snowqueen() 
    : Pdb(4000, 650, 350, 90, 0, "Snowqueen") {} // Nom par défaut

Snowqueen::Snowqueen(int pv, int attaque, int defense, int vitesse, int energie, const string& nom)
    : Pdb(pv, attaque, defense, vitesse, energie, nom) {} // Passe le nom au constructeur de Pdb

int Snowqueen::Javelot_de_glace() { 
    cout << "L'attaque utilisée est Javelot de glace." << endl;  
    int degats = attaque * 1.25; // 125% de l'attaque
    energie += 20; // Génere 20 points d'énergie

    // Limite l'énergie à energie_max
    if (energie > energie_max) {
        energie = energie_max;
    }

    cout << "Javelot de glace inflige " << degats << " dégâts." << endl;  
    cout << "Vous avez " << energie << " d'énergie restants.\n\n" << endl;

    return degats; // Retourne les dégâts
}

int Snowqueen::Vent_glaciale() {
    cout << "L'attaque utilisée est Vent glaciale." << endl;  
    int degats = attaque * 1.5; // 150% de l'attaque
    energie += 30; // Génere 30 points d'énergie

    // Limite l'énergie à energie_max
    if (energie > energie_max) {
        energie = energie_max;
    }

    cout << "Vent glaciale inflige " << degats << " dégâts." << endl;  
    cout << "Vous avez " << energie << " d'énergie restants.\n\n" << endl;

    return degats; // Retourne les dégâts
}

bool Snowqueen::LetItGo() {
    if (energie == energie_max) { // Vérifie que l'énergie est au max
        cout << "L'attaque utilisée est l'attaque spéciale LetItGo." << endl;  
        int degats = attaque * 1.75; // 175% de l'attaque
        energie = 0; // Consomme toute l'énergie (100 points)

        cout << "LetItGo inflige " << degats << " dégâts et consomme toute votre énergie.\n" << endl;
        return true; // Indique que l'attaque a réussi
    } else {
        cout << "Energie insuffisante pour LetItGo, choisissez une autre attaque.\n" << endl;     
        return false; // Indique que l'attaque a échoué
    }    
}

void Snowqueen::AfficherStatistiques() const {
    cout << "Statistiques de " << getNom() << ": \n"; // Affiche le nom
    cout << "PV: " << pv << endl;
    cout << "Attaque: " << attaque << endl;
    cout << "Defense: " << defense << endl;
    cout << "Vitesse: " << vitesse << endl;
    cout << "Energie: " << energie << "\n" << endl;
}

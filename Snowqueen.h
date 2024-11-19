#include "Pdb.h"

// Déclaration de la classe Snowqueen qui hérite de la classe Pdb
class Snowqueen : public Pdb
{
public:
    // Constructeur par défaut de la classe Snowqueen
    Snowqueen();

    // Constructeur avec paramètres pour initialiser les attributs de la Snowqueen
    Snowqueen(int pv, int attaque, int defense, int vitesse, int energie, const string& nom);

    // Méthode pour effectuer une attaque spéciale "Javelot de glace"
    int Javelot_de_glace();

    // Méthode pour effectuer une attaque spéciale "Vent glaciale"
    int Vent_glaciale();

    // Méthode pour déclencher une compétence spéciale "Let It Go"
    // Retourne un booléen indiquant si la compétence a été utilisée avec succès
    bool LetItGo();

    // Méthode pour afficher les statistiques actuelles de la Snowqueen
    void AfficherStatistiques() const;
};

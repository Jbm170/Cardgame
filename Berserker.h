#include "Pdb.h"

// Déclaration de la classe Berserker qui hérite de la classe Pdb
class Berserker : public Pdb
{
public:
    // Constructeur par défaut de la classe Berserker
    Berserker();
    // Constructeur avec paramètres pour initialiser les attributs du Berserker
    Berserker(int pv, int attaque, int defense, int vitesse, int energie, const string& nom);

    // Méthode pour effectuer une attaque spéciale "Frappe punitive"  
        int Frappe_punitive();
        
        // Méthode pour effectuer une attaque spéciale "Coup déchaîné"
        int Coup_dechaine();

        // Méthode pour effectuer une compétence "Movement Alpha"
        // Retourne vrai si le mouvement réussit, faux sinon
        bool Movement_Alpha();

        // Méthode pour afficher les statistiques actuelles du Berserker
        // Affiche toutes les informations importantes sur l'état du personnage
    void AfficherStatistiques() const;
    
};

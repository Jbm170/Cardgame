#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <mysql/mysql.h>

#include "Pdb.h"
#include "Berserker.h"  // Vous devez implémenter ou déclarer les classes Berserker et Snowqueen
#include "Snowqueen.h"

using namespace std;
using namespace sql; 

sql::mysql::MySQL_Driver *driver;
sql::Connection *con;

// Fonction pour récupérer un équipement par son ID depuis la base de données
string getEquipement(int id) {
    string equipement = "";
    int bonus_vie = 0, bonus_attaque = 0, bonus_defense = 0, bonus_vitesse = 0;

    sql::PreparedStatement *stmt = con->prepareStatement("SELECT type, bonus_vie, bonus_attaque, bonus_defense, bonus_vitesse FROM equipement WHERE id = ?");
    stmt->setInt(1, id);
    sql::ResultSet *res = stmt->executeQuery();

    if (res->next()) {
        equipement = res->getString("type");
        bonus_vie = res->getInt("bonus_vie");
        bonus_attaque = res->getInt("bonus_attaque");
        bonus_defense = res->getInt("bonus_defense");
        bonus_vitesse = res->getInt("bonus_vitesse");

        cout << "Equipement: " << equipement << endl;
        cout << "Bonus Vie: " << bonus_vie << ", Bonus Attaque: " << bonus_attaque
             << ", Bonus Defense: " << bonus_defense << ", Bonus Vitesse: " << bonus_vitesse << endl;
    } else {
        cout << "Aucun équipement trouvé pour l'ID: " << id << endl;
    }

    delete res;
    delete stmt;

    return equipement;
}

int main() {
    string host = "localhost";
    string login = "etudiant";
    string pwd = "Passciel2";
    string nombase = "cardgame"; 

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://localhost:3306", login, pwd);
    con->setSchema(nombase);

    cout << "Connexion à la base de données réussie." << endl;

    // Initialisation des personnages
    Pdb Pdb1;
    Berserker Berserker1;
    Snowqueen Snowqueen1;
    Pdb* j1;
    Pdb* j2;
    
    int choix1, choix2;
    int n = 1; 

    cout << "Choisissez deux personnages pour combattre:\n";
    cout << "1. Pdb\n";
    cout << "2. Berserker\n";
    cout << "3. Snowqueen\n";
    cout << "Entrez le numero du premier personnage: ";
    cin >> choix1;
    cout << "Entrez le numero du second personnage: ";
    cin >> choix2;

    // Assignation des personnages choisis
    Pdb* perso1;
    Pdb* perso2;
    if (choix1 == 1) perso1 = &Pdb1;
    else if (choix1 == 2) perso1 = &Berserker1;
    else perso1 = &Snowqueen1;

    if (choix2 == 1) perso2 = &Pdb1;
    else if (choix2 == 2) perso2 = &Berserker1;
    else perso2 = &Snowqueen1;

    // Détermination du personnage ayant la vitesse la plus élevée pour commencer
    if (perso1->getvitesse() > perso2->getvitesse()) {
        j1 = perso1;
        j2 = perso2;
    } else {
        j1 = perso2;
        j2 = perso1;
    }

    cout << "Le joueur " << (j1 == perso1 ? 1 : 2) << " commence." << endl;

    // Attribution des équipements de base
    string equipHeaume = getEquipement(4);  
    string equipGilet = getEquipement(5);   
    string equipGants = getEquipement(6);   
    string equipBottes = getEquipement(7); 

    // Choix de l'arme
    int choixArme;
    cout << "Choisissez une arme:" << endl;
    cout << "1. Epee" << endl;
    cout << "2. Dagues" << endl;
    cout << "3. Baton" << endl;
    cout << "Entrez votre choix: ";
    cin >> choixArme;

    string equipArme = getEquipement(choixArme);  // ID correspondant à l'arme choisie

    // Affecter les équipements aux personnages
    if (j1 == perso1) j1->setEquipement(equipHeaume, equipGilet, equipGants, equipBottes);
    if (j2 == perso2) j2->setEquipement(equipHeaume, equipGilet, equipGants, equipBottes);

    // Afficher les équipements
    cout << "Votre équipement: " << equipHeaume << ", " << equipGilet << ", " << equipGants << ", " << equipBottes << " et " << equipArme << endl;

    j1->AfficherStatistiques();
    j2->AfficherStatistiques();
    
    // Boucle de combat principale
    while (j1->getpv() > 0 && j2->getpv() > 0) {
        int choix; // Choix d'attaque
        int degats = 0; // Points de dégâts infligés

        cout << "\nTour: " << n << "\n\n";  // Affichage du numéro du tour
        n = n + 1;  // Incrémentation du compteur de tour

        // Tour de j1 (premier joueur)
        bool attaqueValide = false;
        while (!attaqueValide) {
            cout << "Joueur 1: " << j1->getNom() << " (PV: " << j1->getpv() << ") à votre tour:" << endl;
            if (j1 == &Berserker1) {
                cout << "1. Frappe preventive\n2. Blast\n3. Frappe punitive\n4. Coup dechaine\n5. Movement Alpha\nEntrez votre choix: ";
                cin >> choix;
                if (choix == 1) {
                    degats = Berserker1.Frappe_preventive();
                    attaqueValide = true;
                } else if (choix == 2) {
                    degats = Berserker1.Blast();
                    attaqueValide = true;
                } else if (choix == 3) {
                    degats = Berserker1.Frappe_punitive();
                    attaqueValide = true;
                } else if (choix == 4) {
                    degats = Berserker1.Coup_dechaine();
                    attaqueValide = true;
                } else if (choix == 5) {
                    if (Berserker1.Movement_Alpha()) {
                        attaqueValide = true;
                    }
                } else {
                    cout << "Choix non valide.\n";
                }
            } else if (j1 == &Snowqueen1) {
                cout << "1. Frappe preventive\n2. Blast\n3. Javelot de glace\n4. Vent glaciale\n5. LetItGo\nEntrez votre choix: ";
                cin >> choix;
                if (choix == 1) {
                    degats = Snowqueen1.Frappe_preventive();
                    attaqueValide = true;
                } else if (choix == 2) {
                    degats = Snowqueen1.Blast();
                    attaqueValide = true;
                } else if (choix == 3) {
                    degats = Snowqueen1.Javelot_de_glace();
                    attaqueValide = true;
                } else if (choix == 4) {
                    degats = Snowqueen1.Vent_glaciale();
                    attaqueValide = true;
                } else if (choix == 5) {
                    if (Snowqueen1.LetItGo()) {
                        attaqueValide = true;
                    }
                } else {
                    cout << "Choix non valide.\n";
                }

            } else {
                cout << "1. Frappe preventive\n2. Blast\n3. Attaque Delta\nEntrez votre choix: ";
                cin >> choix;
                if (choix == 1) {
                    degats = j1->Frappe_preventive();
                    attaqueValide = true;
                } else if (choix == 2) {
                    degats = j1->Blast();
                    attaqueValide = true;
                } else if (choix == 3) {
                    if (j1->Attaque_Delta()) {
                        attaqueValide = true;
                    }
                } else {
                    cout << "Choix non valide.\n";
                }
            }
        }

        // Appliquer les dégâts au joueur 2
        j2->Degat_recus(degats);
        if (j2->getpv() <= 0) {
            cout << j2->getNom() << " est KO. " << j1->getNom() << " gagne!" << endl;
            break;
        }

        // Tour de j2 (deuxième joueur)
        attaqueValide = false;
        while (!attaqueValide) {
            cout << "Joueur 2: " << j2->getNom() << " (PV: " << j2->getpv() << ") à votre tour:" << endl;
            if (j2 == &Berserker1) {
                cout << "1. Frappe preventive\n2. Blast\n3. Frappe punitive\n4. Coup dechaine\n5. Movement Alpha\nEntrez votre choix: ";
                cin >> choix;
                if (choix == 1) {
                    degats = Berserker1.Frappe_preventive();
                    attaqueValide = true;
                } else if (choix == 2) {
                    degats = Berserker1.Blast();
                    attaqueValide = true;
                } else if (choix == 3) {
                    degats = Berserker1.Frappe_punitive();
                    attaqueValide = true;
                } else if (choix == 4) {
                    degats = Berserker1.Coup_dechaine();
                    attaqueValide = true;
                } else if (choix == 5) {
                    if (Berserker1.Movement_Alpha()) {
                        attaqueValide = true;
                    }
                } else {
                    cout << "Choix non valide.\n";
                }

            } else if (j2 == &Snowqueen1) {
                cout << "1. Frappe preventive\n2. Blast\n3. Javelot de glace\n4. Vent glaciale\n5. LetItGo\nEntrez votre choix: ";
                cin >> choix;
                if (choix == 1) {
                    degats = Snowqueen1.Frappe_preventive();
                    attaqueValide = true;
                } else if (choix == 2) {
                    degats = Snowqueen1.Blast();
                    attaqueValide = true;
                } else if (choix == 3) {
                    degats = Snowqueen1.Javelot_de_glace();
                    attaqueValide = true;
                } else if (choix == 4) {
                    degats = Snowqueen1.Vent_glaciale();
                    attaqueValide = true;
                } else if (choix == 5) {
                    if (Snowqueen1.LetItGo()) {
                        attaqueValide = true;
                    }
                } else {
                    cout << "Choix non valide.\n";
                }

            } else {
                cout << "1. Frappe preventive\n2. Blast\n3. Attaque Delta\nEntrez votre choix: ";
                cin >> choix;
                if (choix == 1) {
                    degats = j2->Frappe_preventive();
                    attaqueValide = true;
                } else if (choix == 2) {
                    degats = j2->Blast();
                    attaqueValide = true;
                } else if (choix == 3) {
                    if (j2->Attaque_Delta()) {
                        attaqueValide = true;
                    }
                } else {
                    cout << "Choix non valide.\n";
                }
            }
        }

        // Appliquer les dégâts au joueur 1
        j1->Degat_recus(degats);
        if (j1->getpv() <= 0) { // Vérifier si le joueur 1 est KO
            cout << j1->getNom() << " est KO. " << j2->getNom() << " gagne!" << endl;
            break; // Sortir de la boucle si un joueur est KO
        }
    }

    // Fermer la connexion MySQL après utilisation
     // Fermeture de la connexion MySQL
    delete con;  // La fermeture de la connexion est gérée automatiquement
    return 0;
}

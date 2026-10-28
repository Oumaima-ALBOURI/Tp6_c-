
#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Compte {
protected:
    string numero;
    double solde;

public:
    // Constructeur
    Compte(string num, double s) {
        numero = num;
        solde = s;
    }

    // Deposer de l'argent
    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Depot effectue avec succes." << endl;
        } else {
            cout << "Montant invalide !" << endl;
        }
    }

    // Retirer de l'argent
    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            cout << "Retrait effectue avec succes." << endl;
        } else {
            cout << "Retrait impossible !" << endl;
        }
    }

    // Afficher les informations
    void afficher() {
        cout << "Numero du compte : " << numero << endl;
        cout << "Solde : " << solde << " DH" << endl;
    }
};

// Classe derivee
class CompteEpargne : public Compte {
private:
    double tauxInteret;

public:
    // Constructeur de la classe derivee
    CompteEpargne(string num, double s, double taux)
        : Compte(num, s) {
        tauxInteret = taux;
    }

    // Calculer les interets
    double calculerInteret() {
        return solde * tauxInteret / 100;
    }

    // Ajouter les interets au solde
    void ajouterInteret() {
        solde += calculerInteret();
        cout << "Interets ajoutes au compte." << endl;
    }
};

// Fonction principale
int main() {
    CompteEpargne c1("C001", 1000, 5);

    cout << "Informations initiales :" << endl;
    c1.afficher();

    cout << "\nDepot de 500 DH :" << endl;
    c1.deposer(500);
    c1.afficher();

    cout << "\nRetrait de 200 DH :" << endl;
    c1.retirer(200);
    c1.afficher();

    cout << "\nInterets calcules : "
         << c1.calculerInteret() << " DH" << endl;

    c1.ajouterInteret();

    cout << "\nSolde final :" << endl;
    c1.afficher();

    return 0;
}

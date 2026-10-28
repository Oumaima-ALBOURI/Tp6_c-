
#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    // Constructeur
    Employe(string n, int i, float s) {
        nom = n;
        id = i;
        salaireDeBase = s;
    }

    // Methode virtuelle
    virtual void afficherInfos() {
        cout << "Nom : " << nom << endl;
        cout << "ID : " << id << endl;
        cout << "Salaire de base : "
             << salaireDeBase << " DH" << endl;
    }

    // Destructeur virtuel
    virtual ~Employe() {
        cout << "Destruction de l'employe : "
             << nom << endl;
    }
};

// Classe derivee : Permanent
class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(string n, int i, float s, float prime)
        : Employe(n, i, s) {
        primeAnnuelle = prime;
    }

    void afficherInfos() override {
        cout << "--- Employe permanent ---" << endl;
        Employe::afficherInfos();
        cout << "Prime annuelle : "
             << primeAnnuelle << " DH" << endl;
    }
};

// Classe derivee : Contractuel
class Contractuel : public Employe {
private:
    int dureeContrat;
    float tauxHoraire;

public:
    Contractuel(string n, int i, float s,
                int duree, float taux)
        : Employe(n, i, s) {
        dureeContrat = duree;
        tauxHoraire = taux;
    }

    // Calculer le salaire mensuel selon les heures travaillees
    float calculerSalaireMensuel(int heures) {
        return heures * tauxHoraire;
    }

    void afficherInfos() override {
        cout << "--- Employe contractuel ---" << endl;
        Employe::afficherInfos();
        cout << "Duree du contrat : "
             << dureeContrat << " mois" << endl;
        cout << "Taux horaire : "
             << tauxHoraire << " DH/heure" << endl;
    }
};

// Programme principal
int main() {
    // Tableau dynamique de pointeurs
    Employe** employes = new Employe*[3];

    // Creation de trois employes
    employes[0] = new Permanent(
        "Oumaima", 101, 6000, 12000
    );

    employes[1] = new Contractuel(
        "Sara", 102, 0, 6, 80
    );

    employes[2] = new Permanent(
        "Amine", 103, 7500, 15000
    );

    // Affichage polymorphique
    for (int i = 0; i < 3; i++) {
        employes[i]->afficherInfos();
        cout << endl;
    }

    // Calcul du salaire du contractuel
    Contractuel* c =
        dynamic_cast<Contractuel*>(employes[1]);

    if (c != nullptr) {
        cout << "Salaire mensuel de Sara pour 160 heures : "
             << c->calculerSalaireMensuel(160)
             << " DH" << endl;
    }

    cout << endl;

    // Liberation de la memoire
    for (int i = 0; i < 3; i++) {
        delete employes[i];
    }

    delete[] employes;

    return 0;
}

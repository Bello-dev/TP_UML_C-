#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> // Inclusion ajoutée
#include "GestionnaireCommandes.h"
#include "GestionnaireProduits.h"

using namespace std;

void sauvegarderProduits(const GestionnaireProduits &gestionnaireProduits) {
    ofstream fichier("produits.txt");
    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier produits.txt" << endl;
        return;
    }

    for (const auto &produit : gestionnaireProduits.getproduits()) {
        fichier << produit.getid() << ";"
                << produit.getnom() << ";"
                << produit.getprix() << ";"
                << produit.getquantite() << ";"
                << produit.getcategorie() << ";"
                << produit.getfournisseur().getnom() << ";"
                << produit.getfournisseur().getcontact() << ";"
                << produit.getfournisseur().gettypeProduit() << endl;
    }

    fichier.close();
}

void sauvegarderCommandes(const GestionnaireCommandes &gestionnaireCommandes) {
    ofstream fichier("commandes.txt");
    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier commandes.txt" << endl;
        return;
    }

    for (const auto &commande : gestionnaireCommandes.getcommandes()) {
        fichier << commande.getid() << ";"
                << commande.getclient().getnom() << ";"
                << commande.getclient().getadresse() << ";"
                << commande.getstatut() << endl;

        for (const auto &ligne : commande.getproduits()) {
            fichier << ligne.first.getid() << ";"
                << ligne.first.getnom() << ";"
                << ligne.second << endl;
        }


        fichier << "---" << endl;
    }

    fichier.close();
}

// Les autres fonctions restent inchangées.


void chargerProduits(GestionnaireProduits &gestionnaireProduits) {
    ifstream fichier("produits.txt");
    if (!fichier) {
        cerr << "Erreur lors de la lecture du fichier produits.txt" << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        string id, nom, prix, quantite, categorie, fournisseurNom, fournisseurContact, fournisseurType;

        getline(ss, id, ';');
        getline(ss, nom, ';');
        getline(ss, prix, ';');
        getline(ss, quantite, ';');
        getline(ss, categorie, ';');
        getline(ss, fournisseurNom, ';');
        getline(ss, fournisseurContact, ';');
        getline(ss, fournisseurType, ';');

        Fournisseur fournisseur(stoi(id), fournisseurNom, fournisseurContact, fournisseurType);
        Produit produit(stoi(id), nom, stod(prix), stoi(quantite), categorie, fournisseur);
        gestionnaireProduits.ajouterProduit(produit);
    }

    fichier.close();
}

void chargerCommandes(GestionnaireCommandes &gestionnaireCommandes, const GestionnaireProduits &gestionnaireProduits) {
    ifstream fichier("commandes.txt");
    if (!fichier) {
        cerr << "Erreur lors de la lecture du fichier commandes.txt" << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        if (ligne == "---") continue;

        stringstream ss(ligne);
        string idCommande, nomClient, adresseClient, statut;

        getline(ss, idCommande, ';');
        getline(ss, nomClient, ';');
        getline(ss, adresseClient, ';');
        getline(ss, statut, ';');

        Client client(stoi(idCommande), nomClient, adresseClient);
        Commande commande(stoi(idCommande), client, statut);

        while (getline(fichier, ligne) && ligne != "---") {
            stringstream ssProduit(ligne);
            string idProduit, nomProduit, quantite;

            getline(ssProduit, idProduit, ';');
            getline(ssProduit, nomProduit, ';');
            getline(ssProduit, quantite, ';');

            Produit produit = gestionnaireProduits.rechercherProduitParNom(nomProduit);
            commande.ajouterProduit(produit, stoi(quantite));
        }

        gestionnaireCommandes.ajouterCommande(commande);
    }

    fichier.close();
}


void afficherMenuPrincipal() {
    cout << "\n==== MENU PRINCIPAL ====\n";
    cout << "1. Gestion du quantite des produits\n";
    cout << "2. Gestion des commandes\n";
    cout << "0. Quitter\n";
    cout << "========================\n";
    cout << "Choix : ";
}

void afficherMenuProduits() {
    cout << "\n==== GESTION DU quantite DES PRODUITS ====\n";
    cout << "1. Ajouter un produit\n";
    cout << "2. Modifier le prix et le quantite d'un produit\n";
    cout << "3. Rechercher un produit par nom\n";
    cout << "4. Rechercher un produit par catégorie\n";
    cout << "5. Rechercher un produit par fournisseur\n";
    cout << "6. Afficher tous les produits\n";
    cout << "0. Retour\n";
    cout << "======================================\n";
    cout << "Choix : ";
}

void afficherMenuCommandes() {
    cout << "\n==== GESTION DES COMMANDES ====\n";
    cout << "1. Créer une commande\n";
    cout << "2. Modifier le statut d'une commande\n";
    cout << "3. Annuler une commande\n";
    cout << "4. Afficher toutes les commandes\n";
    cout << "5. Afficher les détails d'une commande\n";
    cout << "0. Retour\n";
    cout << "================================\n";
    cout << "Choix : ";
}

int main() {
    GestionnaireProduits gestionnaireProduits;
    GestionnaireCommandes gestionnaireCommandes;

    system("clear");
    // Charger les données existantes
    chargerProduits(gestionnaireProduits);
    chargerCommandes(gestionnaireCommandes, gestionnaireProduits);

    int choixPrincipal;
    do {
        afficherMenuPrincipal();
        cin >> choixPrincipal;

        switch (choixPrincipal) {
            case 1: {
                system("clear");
                int choixProduits;
                do {
                    afficherMenuProduits();
                    cin >> choixProduits;
                    switch (choixProduits) {
                        case 1: {
                            system("clear");
                            string nom, categorie, fournisseurNom, fournisseurContact, fournisseurType;
                            double prix;
                            int quantite;

                            cout << "Nom du produit : ";
                            cin >> nom;
                            cout << "Prix du produit : ";
                            cin >> prix;
                            cout << "quantite du produit : ";
                            cin >> quantite;
                            cout << "Catégorie du produit : ";
                            cin >> categorie;
                            cout << "Nom du fournisseur : ";
                            cin >> fournisseurNom;
                            cout << "Contact du fournisseur : ";
                            cin >> fournisseurContact;
                            cout << "Type de produit du fournisseur : ";
                            cin >> fournisseurType;

                            Fournisseur fournisseur(0, fournisseurNom, fournisseurContact, fournisseurType);
                            Produit produit(0, nom, prix, quantite, categorie, fournisseur);
                            gestionnaireProduits.ajouterProduit(produit);

                            sauvegarderProduits(gestionnaireProduits); // Sauvegarde automatique
                            cout << "Produit ajouté avec succès.\n";
                            break;
                        }
                         case 2: {
                            system("clear");
                            // Modifier le prix et la quantite
                            int id, quantite;
                            double prix;
                            cout << "ID du produit à modifier : ";
                            cin >> id;
                            cout << "Nouveau prix : ";
                            cin >> prix;
                            cout << "Nouvelle quantite : ";
                            cin >> quantite;
                            gestionnaireProduits.modifierProduit(id, prix, quantite);
                            sauvegarderProduits(gestionnaireProduits);
                            cout << "Produit modifié avec succès.\n";
                            break;
                        }
                        case 3: {
                            system("clear");
                            // Rechercher par nom
                            string nom;
                            cout << "Nom du produit à rechercher : ";
                            cin >> nom;
                            Produit produit = gestionnaireProduits.rechercherProduitParNom(nom);
                            cout << "Produit trouvé : " << produit.getnom() << "\n";
                            produit.afficherDetails();
                            break;
                        }
                        case 4: {
                            system("clear");
                            // Rechercher par catégorie
                            string categorie;
                            cout << "Catégorie à rechercher : ";
                            cin >> categorie;
                            gestionnaireProduits.rechercherParCategorie(categorie);
                            break;
                        }
                        case 5: {
                            system("clear");
                            // Rechercher par fournisseur
                            string fournisseur;
                            cout << "Nom du fournisseur à rechercher : ";
                            cin >> fournisseur;
                            gestionnaireProduits.rechercherParFournisseur(fournisseur);
                            break;
                        }
                        case 6: {
                            system("clear");
                            gestionnaireProduits.afficherProduits();
                            break;
                        }
                        case 0:
                            system("clear");
                            cout << "Retour au menu principal...\n";
                            break;
                        default:
                            system("clear");
                            cout << "Choix invalide.\n";
                            break;
                    }
                } while (choixProduits != 0);
                break;
            }
           
            case 2: {
                system("clear");
                // Gestion des commandes
                int choixCommandes;
                do {
                    afficherMenuCommandes();
                    cin >> choixCommandes;
                    switch (choixCommandes) {
                        case 1: {
                            system("clear");
                            // Créer une commande
                            string nomClient, adresseClient;
                            cout << "Nom du client : ";
                            cin >> nomClient;
                            cout << "Adresse du client : ";
                            cin >> adresseClient;

                            Client client(0, nomClient, adresseClient);
                            Commande commande(0, client);

                            int ajouterProduit;
                            int qt;
                            do {
                                string produitNom;
                                cout << "Nom du produit à ajouter : ";
                                cin >> produitNom;
                                Produit produit = gestionnaireProduits.rechercherProduitParNom(produitNom);
                                cout << "Quantité désirée : ";
                                cin >> qt;
                                commande.ajouterProduit(produit, qt);
                                cout << "Produit ajouté à la commande.\n";
                                cout << "Ajouter un autre produit ? (1: Oui, 0: Non) : ";
                                cin >> ajouterProduit;
                            } while (ajouterProduit != 0);

                            gestionnaireCommandes.ajouterCommande(commande);
                            sauvegarderCommandes(gestionnaireCommandes); // Sauvegarde automatique
                            cout << "Commande ajoutée avec succès !"<< endl;
                            break;
                        }
                        case 2: {
                            system("clear");
                            // Modifier le statut d'une commande
                            int idCommande;
                            string statut;
                            cout << "ID de la commande à modifier : ";
                            cin >> idCommande;
                            cout << "Nouveau statut (en cours/terminée/annulée) : ";
                            cin >> statut;
                            gestionnaireCommandes.modifierStatut(idCommande, statut);
                            cout << "Statut modifié avec succès.\n";
                            break;
                        }
                        case 3: {
                            system("clear");
                            // Annuler une commande
                            int idCommande;
                            cout << "ID de la commande à annuler : ";
                            cin >> idCommande;
                            gestionnaireCommandes.annulerCommande(idCommande);
                            cout << "Commande annulée avec succès.\n";
                            break;
                        }
                        case 4: {
                            system("clear");
                            // Afficher toutes les commandes
                            gestionnaireCommandes.afficherCommandes();
                            break;
                        }
                        case 5: {
                            system("clear");
                            // Afficher les détails d'une commande
                            int idCommande;
                            cout << "ID de la commande à afficher : ";
                            cin >> idCommande;
                            gestionnaireCommandes.afficherDetailsCommande(idCommande);
                            break;
                        }
                    }
                } while (choixCommandes != 0);
                break;
            }
            case 0:
                system("clear");
                sauvegarderProduits(gestionnaireProduits);
                sauvegarderCommandes(gestionnaireCommandes);
                cout << "Au revoir !\n";
                break;
            default:
                system("clear");
                cout << "Choix invalide.\n";
                break;
        }
    } while (choixPrincipal != 0);

    return 0;
}
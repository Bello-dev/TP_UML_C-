
#ifndef GESTIONNAIREPRODUITS_H
#define GESTIONNAIREPRODUITS_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


#include "Produit.h"
using namespace std;


/**
  * class GestionnaireProduits
  * 
  */

class GestionnaireProduits
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	GestionnaireProduits();

	/**
	 * Empty Destructor
	 */
	virtual ~GestionnaireProduits();

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 * @param  produit
	 */
	void ajouterProduit(const Produit& produit)
	{
		produits.push_back(produit);
	}


	/**
	 * @param  id
	 */
	void supprimerProduit(int id)
	{
		 produits.erase(remove_if(produits.begin(), produits.end(),
		        [id](Produit& produit) { return produit.getid() == id; }), produits.end());
	}


	/**
	 * @return Produit
	 * @param  nom
	 */
	Produit rechercherProduitParNom(string nom) const
	{
		for (const auto& produit : produits) {
		        if (produit.getnom() == nom)
		            return produit;
		    }
		    throw runtime_error("Produit non trouvé.");
	}


	/**
	 */
	void afficherProduits() const
	{
		for (const auto& produit : produits) {
		        produit.afficherDetails();
		    }
	}

	void modifierProduit(int id, double nouveauPrix, int nouveauquantite) {
    for (auto& produit : produits) {
        if (produit.getid() == id) {
            produit.setprix(nouveauPrix);
            produit.setquantite(nouveauquantite);
            cout << "Produit mis à jour avec succès.\n";
            return;
        }
    }
    cout << "Produit non trouvé.\n";
}

void rechercherParCategorie(const string& categorie) const {
    for (const auto& produit : produits) {
        if (produit.getcategorie() == categorie) {
            produit.afficherDetails();
        }
    }
}

void rechercherParFournisseur(const string& fournisseur) const {
    for (const auto& produit : produits) {
        if (produit.getfournisseur().getnom() == fournisseur) {
            produit.afficherDetails();
        }
    }
}


protected:
	// Static Protected attributes
	//  

	// Protected attributes
	//  


	// Protected attribute accessor methods
	//  


	// Protected attribute accessor methods
	//

private:
	// Static Private attributes
	//  

	// Private attributes
	//  

	vector< Produit > produits;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  
public:


	/**
	 * Set the value of produits
	 * @param value the new value of produits
	 */
	void setproduits(vector< Produit > value)
	{
		produits = value;
	}

	/**
	 * Get the value of produits
	 * @return the value of produits
	 */
	vector< Produit > getproduits() const
	{
		return produits;
	}

	void initAttributes();

};

#endif // GESTIONNAIREPRODUITS_H

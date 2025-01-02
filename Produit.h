
#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <vector>
#include <iostream>

#include "Fournisseur.h"

using namespace std;


/**
  * class Produit
  * 
  */

class Produit
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Produit();

	/**
	 * Empty Destructor
	 */
	virtual ~Produit();

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 * @param  id
	 * @param  nom
	 * @param  prix
	 * @param  quantite
	 * @param  categorie
	 * @param  fournisseur
	 */
	 Produit(int id, string nom, double prix, int quantite, string categorie, Fournisseur fournisseur)
		    : id(id), nom(nom), prix(prix), quantite(quantite), categorie(categorie), fournisseur(fournisseur) {}


	/**
	 * @param  nouveauPrix
	 * @param  nouvelleQuantite
	 */
	void mettreAJourProduit(double nouveauPrix, int nouvelleQuantite)
	{
		prix = nouveauPrix;
		    quantite = nouvelleQuantite;
	}


	/**
	 */
	void afficherDetails() const
	{
		    cout << "Produit - Nom: " << nom
		         << ", Prix: " << prix
		         << ", Quantité: " << quantite
		         << ", Catégorie: " << categorie
		         << endl;
		
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

	int id;
	string nom;
	double prix;
	int quantite;
	string categorie;
	Fournisseur fournisseur;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  

public:

	/**
	 * Set the value of id
	 * @param value the new value of id
	 */
	void setid(int value)
	{
		id = value;
	}

	/**
	 * Get the value of id
	 * @return the value of id
	 */
	int getid() const
	{
		return id;
	}

	/**
	 * Set the value of nom
	 * @param value the new value of nom
	 */
	void setnom(string value)
	{
		nom = value;
	}

	/**
	 * Get the value of nom
	 * @return the value of nom
	 */
	string getnom() const
	{
		return nom;
	}

	/**
	 * Set the value of prix
	 * @param value the new value of prix
	 */
	void setprix(double value)
	{
		prix = value;
	}

	/**
	 * Get the value of prix
	 * @return the value of prix
	 */
	double getprix() const
	{
		return prix;
	}

	/**
	 * Set the value of quantite
	 * @param value the new value of quantite
	 */
	void setquantite(int value)
	{
		quantite = value;
	}

	/**
	 * Get the value of quantite
	 * @return the value of quantite
	 */
	int getquantite() const
	{
		return quantite;
	}

	/**
	 * Set the value of categorie
	 * @param value the new value of categorie
	 */
	void setcategorie(string value)
	{
		categorie = value;
	}

	/**
	 * Get the value of categorie
	 * @return the value of categorie
	 */
	string getcategorie() const
	{
		return categorie;
	}

	/**
	 * Set the value of fournisseur
	 * @param value the new value of fournisseur
	 */
	void setfournisseur(Fournisseur value)
	{
		fournisseur = value;
	}

	/**
	 * Get the value of fournisseur
	 * @return the value of fournisseur
	 */
	Fournisseur getfournisseur() const
	{
		return fournisseur;
	}

	void initAttributes();

};

#endif // PRODUIT_H
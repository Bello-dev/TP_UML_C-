
#ifndef COMMANDE_H
#define COMMANDE_H

#include <string>
#include <vector>
#include <iostream>

#include "Client.h"
#include "Produit.h"

using namespace std;



/**
  * class Commande
  * 
  */

class Commande
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Commande();

	/**
	 * Empty Destructor
	 */
	virtual ~Commande();

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
	 * @param  client
	 */
	 Commande(int id, Client client, string statut = "En cours")
		   : id(id), client(client), statut(statut) {}


	/**
	 * @param  produit
	 * @param  quantite
	 */
	void ajouterProduit(const Produit& produit, int quantite)
	{
		 produits.emplace_back(produit, quantite);
	}


	/**
	 * @param  nouveauStatut
	 */
	void modifierStatut(string nouveauStatut)
	{
		statut = nouveauStatut;
		    cout << "Statut modifié : " << statut << endl;
	}


	/**
	 */
	void afficherDetails() const
	{
		 cout << "Commande ID: " << id
		         << ", Statut: " << statut << endl;
		
		    cout << "Client associé : ";
		    client.afficherDetails();
		
		    cout << "Produits dans la commande :" << endl;
		    for (const auto& pair : produits) {
		        const Produit& produit = pair.first;
		        int quantite = pair.second;
		
		        produit.afficherDetails();
		        cout << "Quantité : " << quantite << endl;
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

	int id;
	Client client;
	string statut;
	vector< pair < Produit , int > > produits;

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
	 * Set the value of client
	 * @param value the new value of client
	 */
	void setclient(Client value)
	{
		client = value;
	}

	/**
	 * Get the value of client
	 * @return the value of client
	 */
	Client getclient() const
	{
		return client;
	}

	/**
	 * Set the value of statut
	 * @param value the new value of statut
	 */
	void setstatut(string value)
	{
		statut = value;
	}

	/**
	 * Get the value of statut
	 * @return the value of statut
	 */
	string getstatut() const
	{
		return statut;
	}

	/**
	 * Set the value of produits
	 * @param value the new value of produits
	 */
	void setproduits(vector< pair < Produit , int > > value)
	{
		produits = value;
	}

	/**
	 * Get the value of produits
	 * @return the value of produits
	 */
	vector< pair < Produit , int > > getproduits() const
	{
		return produits;
	}

	void initAttributes();

};

#endif // COMMANDE_H

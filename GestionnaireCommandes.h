
#ifndef GESTIONNAIRECOMMANDES_H
#define GESTIONNAIRECOMMANDES_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


#include "Commande.h"

using namespace std;


/**
  * class GestionnaireCommandes
  * 
  */

class GestionnaireCommandes
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	GestionnaireCommandes();

	/**
	 * Empty Destructor
	 */
	virtual ~GestionnaireCommandes();

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 * @param  commande
	 */
	void ajouterCommande(const Commande& commande)
	{
		commandes.push_back(commande);
	}


	/**
	 * @param  id
	 */
	void annulerCommande(int id)
	{
		 commandes.erase(remove_if(commandes.begin(), commandes.end(),
		        [id](Commande& commande) { return commande.getid() == id; }), commandes.end());
	}


	/**
	 */
	void afficherCommandes() const
	{
		for (const auto& commande : commandes) {
		        commande.afficherDetails();
		    }
	}

	void modifierStatut(int idCommande, const string& nouveauStatut) {
    for (auto& commande : commandes) {
        if (commande.getid() == idCommande) {
            commande.setstatut(nouveauStatut);
            cout << "Statut de la commande mis à jour avec succès.\n";
            return;
        }
    }
    cout << "Commande non trouvée.\n";
}

void afficherDetailsCommande(int idCommande) const {
    for (const auto& commande : commandes) {
        if (commande.getid() == idCommande) {
            commande.afficherDetails();
            return;
        }
    }
    cout << "Commande non trouvée.\n";
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

	vector< Commande > commandes;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  
public:


	/**
	 * Set the value of commandes
	 * @param value the new value of commandes
	 */
	void setcommandes(vector< Commande > value)
	{
		commandes = value;
	}

	/**
	 * Get the value of commandes
	 * @return the value of commandes
	 */
	vector< Commande > getcommandes() const
	{
		return commandes;
	}

	void initAttributes();

};

#endif // GESTIONNAIRECOMMANDES_H


#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <iostream>

using namespace std;


/**
  * class Fournisseur
  * 
  */

class Fournisseur
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Fournisseur();

	/**
	 * Empty Destructor
	 */
	virtual ~Fournisseur();

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
	 * @param  contact
	 * @param  typeProduit
	 */
	 Fournisseur(int id, string nom, string contact, string typeProduit)
		: id(id), nom(nom), contact(contact), typeProduit(typeProduit) {}


	/**
	 */
	void afficherDetails() const
	{
		  cout << "Fournisseur - Nom: " << nom
		         << ", Contact: " << contact
		         << ", Type de produit fourni: " << typeProduit
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
	string contact;
	string typeProduit;

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
	int getid()
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
	string getnom()
	{
		return nom;
	}

	/**
	 * Set the value of contact
	 * @param value the new value of contact
	 */
	void setcontact(string value)
	{
		contact = value;
	}

	/**
	 * Get the value of contact
	 * @return the value of contact
	 */
	string getcontact()
	{
		return contact;
	}

	/**
	 * Set the value of typeProduit
	 * @param value the new value of typeProduit
	 */
	void settypeProduit(string value)
	{
		typeProduit = value;
	}

	/**
	 * Get the value of typeProduit
	 * @return the value of typeProduit
	 */
	string gettypeProduit()
	{
		return typeProduit;
	}

	void initAttributes();

};

#endif // FOURNISSEUR_H

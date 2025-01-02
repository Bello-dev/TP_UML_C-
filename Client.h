
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>

using namespace std;


/**
  * class Client
  * 
  */

class Client
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Client();

	/**
	 * Empty Destructor
	 */
	virtual ~Client();

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
	 * @param  adresse
	 */
	 Client(int id, string nom, string adresse)
		: id(id), nom(nom), adresse(adresse) {}


	/**
	 */
	void afficherDetails() const
	{
		 cout << "Client - Nom: " << nom
		         << ", Adresse: " << adresse
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
	string adresse;

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
	 * Set the value of adresse
	 * @param value the new value of adresse
	 */
	void setadresse(string value)
	{
		adresse = value;
	}

	/**
	 * Get the value of adresse
	 * @return the value of adresse
	 */
	string getadresse()
	{
		return adresse;
	}

	void initAttributes();

};

#endif // CLIENT_H

#include "mappTablePersonnel.h"
namespace NS_Composants
{
	mappTablePersonnel::mappTablePersonnel(void)
	{
		this->ID = -1;
		this->Nom = "RIEN";
		this->Prenom = "RIEN";
		this->Date_naissance = DateTime::Now;
		this->Date_embauche = DateTime::Now;
		this->ID_SupH = -1;
		this->ID_adresse = -1;
	}
	String^ mappTablePersonnel::SELECT(void)
	{
		return mappPersonnes::SELECT("Personnel");
	}

	String^ mappTablePersonnel::INSERT(void)
	{
		return "INSERT INTO Personnel " +
			"(Nom_perso, Prenom_perso, Date_naissance_perso, Date_embauche, ID_SupH, ID_adresse) " +
			"VALUES('" + this->getNom() + "', '" + this->getPrenom() + "', '" + this->getDateNaissance() + "', '" + this->getDateEmbauche() + "', '" + this->getID_SupH() + "', '" + this->getID_Adresse() + "');SELECT @@IDENTITY; ";
	}

	String^ mappTablePersonnel::UPDATE(void)
	{
		return "UPDATE Personnel " +
			"SET Nom_perso = '" + this->getNom() + "', Prenom_perso = '" + this->getPrenom() + "', Date_naissance_perso = '" + this->getDateNaissance() + "', Date_embauche = '" + this->getDateEmbauche() + "', ID_SupH = '" + this->getID_SupH() + "', ID_adresse = '" + this->getID_Adresse() + "' " +
			"WHERE(ID_perso = " + this->getId() + ");";
	}

	String^ mappTablePersonnel::DELETE(void)
	{
		return mappPersonnes::DELETE("Personnel", "ID_perso", this->getId());
		//return "DELETE FROM " + table + " WHERE(" + id_name +" = " + this->getId() + ");";
	}

	void mappTablePersonnel::setID(int ID_perso)
	{
		if (ID_perso > 0)
		{
			this->ID = ID_perso;
		}
	}

	void mappTablePersonnel::setPrenom(String^ Prenom_perso)
	{
		if (Prenom_perso != "")
		{
			this->Prenom = Prenom_perso;
		}
	}

	void mappTablePersonnel::setNom(String^ Nom_perso)
	{
		if (Nom_perso != "")
		{
			this->Nom = Nom_perso;
		}
	}

	void mappTablePersonnel::setDateNaissance(DateTime Date_naissance_perso)
	{
		this->Date_naissance = Date_naissance_perso;
	}

	void mappTablePersonnel::setDateEmbauche(DateTime Date_embauche)
	{
		this->Date_embauche = Date_embauche;
	}

	void mappTablePersonnel::setID_SupH(int ID_SupH)
	{
		if (ID_SupH > 0)
		{
			this->ID_SupH = ID_SupH;
		}
	}

	void mappTablePersonnel::setID_Adresse(int ID_adresse)
	{
		if (ID_adresse > 0)
		{
			this->ID_adresse = ID_adresse;
		}
	}

	int mappTablePersonnel::getId(void)
	{
		return this->ID;
	}

	String^ mappTablePersonnel::getNom(void)
	{
		return this->Nom;
	}

	String^ mappTablePersonnel::getPrenom(void)
	{
		return this->Prenom;
	}

	DateTime mappTablePersonnel::getDateNaissance(void)
	{
		return this->Date_naissance;
	}

	DateTime mappTablePersonnel::getDateEmbauche(void)
	{
		return this->Date_embauche;
	}

	int mappTablePersonnel::getID_SupH(void)
	{
		return this->ID_SupH;
	}

	int mappTablePersonnel::getID_Adresse(void)
	{
		return this->ID_adresse;
	}

}
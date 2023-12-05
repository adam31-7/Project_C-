#include "mappTableAdresse.h"
namespace NS_Composants
{
	mappTableAdresse::mappTableAdresse(void)
	{
		this->ID_adresse = -1;
		this->Num_rue = -1;
		this->Nom_rue = "RIEN";
		this->Ville = "RIEN";
		this->Code_postal = "RIEN";
		this->Pays = "RIEN";
		this->InfoSup = "RIEN";
		this->ID_client = -1;
	}
	String^ mappTableAdresse::SELECTByIdClient(void)
	{
		return "SELECT * FROM Adresse WHERE(ID_client = " + this->getIDClient() + ");";
	}
	String^ mappTableAdresse::INSERT(void)
	{
		return "INSERT INTO Adresse " +
			"(Num_rue, Nom_rue, Ville, Code_postal, Pays, InfoSup, ID_client) " +
			"VALUES('" + this->getNumRue() + "', '" + this->getNomRue() + "', '" + this->getVille() + "', '" + this->getCodePostal() + "', '" + this->getPays() + "', '" + this->getInfoSup() + "', '" + this->getId() + "');SELECT @@IDENTITY; ";
	}
	String^ mappTableAdresse::UPDATE(void)
	{
		return "UPDATE Adresse " +
			"SET Num_rue = '" + this->getNumRue() + "', Nom_rue = '" + this->getNomRue() + "', Ville = '" + this->getVille() + "', Code_postal = '" + this->getCodePostal() + "', Pays = '" + this->getPays() + "', InfoSup = '" + this->getInfoSup() + "' " +
			"WHERE(ID_adresse = " + this->getId() + ");";
	}
	String^ mappTableAdresse::DELETE(void)
	{
		return "DELETE FROM Adresse WHERE(ID_adresse = " + this->getId() + ");";
	}
	void mappTableAdresse::setID(int ID_adresse)
	{
		if (ID_adresse > 0)
		{
			this->ID_adresse = ID_adresse;
		}
	}
	void mappTableAdresse::setIDClient(int ID_client)
	{
		if (ID_client > 0)
		{
			this->ID_client = ID_client;
		}
	}
	void mappTableAdresse::setNumRue(int Num_rue)
	{
		if (Num_rue > 0)
		{
			this->Num_rue = Num_rue;
		}
	}
	void mappTableAdresse::setNomRue(String^ Nom_rue)
	{
		if (Nom_rue != "")
		{
			this->Nom_rue = Nom_rue;
		}
	}
	void mappTableAdresse::setVille(String^ Ville)
	{
		if (Ville != "")
		{
			this->Ville = Ville;
		}
	}
	void mappTableAdresse::setCodePostal(String^ Code_postal)
	{
		if (Code_postal != "")
		{
			this->Code_postal = Code_postal;
		}
	}
	void mappTableAdresse::setPays(String^ Pays)
	{
		if (Pays != "")
		{
			this->Pays = Pays;
		}
	}
	void mappTableAdresse::setInfoSup(String^ InfoSup)
	{
		if (InfoSup != "")
		{
			this->InfoSup = InfoSup;
		}
	}
	int mappTableAdresse::getId(void)
	{
		return this->ID_adresse;
	}
	int mappTableAdresse::getIDClient(void)
	{
		return this->ID_client;
	}
	int mappTableAdresse::getNumRue(void)
	{
		return this->Num_rue;
	}
	String^ mappTableAdresse::getNomRue(void)
	{
		return this->Nom_rue;
	}
	String^ mappTableAdresse::getVille(void)
	{
		return this->Ville;
	}
	String^ mappTableAdresse::getCodePostal(void)
	{
		return this->Code_postal;
	}
	String^ mappTableAdresse::getPays(void)
	{
		return this->Pays;
	}
	String^ mappTableAdresse::getInfoSup(void)
	{
		return this->InfoSup;
	}
}
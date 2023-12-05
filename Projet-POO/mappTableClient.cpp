#include "mappTableClient.h"
namespace NS_Composants

{
	mappTableClient::mappTableClient(void)
	{
		this->ID = -1;
		this->Nom = "RIEN";
		this->Prenom = "RIEN";
		this->Date_naissance= "RIEN";
		this->DatePR_Achat = "RIEN";
	}
	String^ mappTableClient::SELECT(void)
	{
		return mappPersonnes::SELECT("Client");
	}
	String^ mappTableClient::INSERT(void)
	{
		return "INSERT INTO Client " +
			"(Nom_client, Prenom_client) " +
			"VALUES('" + this->getNom() + "', '" + this->getPrenom() + "');SELECT @@IDENTITY; ";
	}
	String^ mappTableClient::UPDATE(void)
	{
		return "UPDATE Client " +
			"SET Nom_client = '" + this->getNom() + "', Prenom_client = '" + this->getPrenom() + "' " +
			"WHERE(ID_client = " + this->getId() + ");";
	}
	String^ mappTableClient::DELETE(void)
	{
		return "DELETE FROM Adresse WHERE (ID_client = " + this->getId() + ");" + mappPersonnes::DELETE("Client", "ID_client");
		//return "DELETE FROM " + table + " WHERE(" + id_name +" = " + this->getId() + ");";
	}
	void mappTableClient::setID(int ID_client)
	{
		if (ID_client > 0)
		{
			this->ID = ID_client;
		}
	}
	void mappTableClient::setPrenom(String^ Prenom_client)
	{
		if (Prenom_client != "")
		{
			this->Prenom = Prenom_client;
		}
	}
	void mappTableClient::setNom(String^ Nom_client)
	{
		if (Nom_client != "")
		{
			this->Nom = Nom_client;
		}
	}
	void mappTableClient::setDateNaissance(String^ Date_naissance_client)
	{
		if (Date_naissance_client != "")
		{
			this->Date_naissance = Date_naissance_client;
		}
	}
	void mappTableClient::setDatePr(String^ DatePR_Achat)
	{
		if (DatePR_Achat != "")
		{
			this->DatePR_Achat = DatePR_Achat;
		}
	}
	int mappTableClient::getId(void)
	{
		return this->ID;
	}
	String^ mappTableClient::getNom(void)
	{
		return this->Nom;
	}
	String^ mappTableClient::getPrenom(void)
	{
		return this->Prenom;
	}
	String^ mappTableClient::getDateNaissance(void)
	{
		return this->Date_naissance;
	}
	String^ mappTableClient::getDatePr(void)
	{
		return this->DatePR_Achat;
	}
}
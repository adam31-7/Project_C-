#include "mappTableClient.h"
namespace NS_Composants

{
	mappTableClient::mappTableClient(void)
	{
		this->ID_client = -1;
		this->Nom_client = "RIEN";
		this->Prenom_client = "RIEN";
		this->Date_naissance_client= "RIEN";
		this->DatePR_Achat = "RIEN";
	}
	String^ mappTableClient::SELECT(void)
	{
		return "SELECT ID_client, Nom_client, Prenom_client, Date_naissance_client, DatePR_Achat " +
			"FROM Client;";
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
		return "DELETE FROM Client " +
			"WHERE(ID_client = " + this->getId() + ");";
	}
	void mappTableClient::setID(int ID_client)
	{
		if (ID_client > 0)
		{
			this->ID_client = ID_client;
		}
	}
	void mappTableClient::setPrenom(String^ Prenom_client)
	{
		if (Prenom_client != "")
		{
			this->Prenom_client = Prenom_client;
		}
	}
	void mappTableClient::setNom(String^ Nom_client)
	{
		if (Nom_client != "")
		{
			this->Nom_client = Nom_client;
		}
	}
	void mappTableClient::setDateNaissance(String^ Date_naissance_client)
	{
		if (Date_naissance_client != "")
		{
			this->Date_naissance_client = Date_naissance_client;
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
		return this->ID_client;
	}
	String^ mappTableClient::getNom(void)
	{
		return this->Nom_client;
	}
	String^ mappTableClient::getPrenom(void)
	{
		return this->Prenom_client;
	}
	String^ mappTableClient::getDateNaissance(void)
	{
		return this->Date_naissance_client;
	}
	String^ mappTableClient::getDatePr(void)
	{
		return this->DatePR_Achat;
	}
}
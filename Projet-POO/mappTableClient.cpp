#include "mappTableClient.h"
namespace NS_Composants

{
	mappTableClient::mappTableClient(void)
	{
		this->ID = -1;
		this->Nom = "RIEN";
		this->Prenom = "RIEN";
		this->Date_naissance= DateTime::Now;
		this->DatePR_Achat = DateTime::Now;
	}
	String^ mappTableClient::SELECT(void)
	{
		return mappPersonnes::SELECT("Client");
	}
	String^ mappTableClient::SELECTByID(void)
	{
		return mappPersonnes::SELECTbyID("Client", "ID_client");
	}
	String^ mappTableClient::INSERT(void)
	{
		return "INSERT INTO Client " +
			"(Nom_client, Prenom_client, Date_naissance_client, DatePR_Achat) " +
			"VALUES('" + this->getNom() + "', '" + this->getPrenom() + "', '" + this->getDateNaissance() + "', '" + this->getDatePr() +
			"');SELECT @@IDENTITY; ";
	}
	String^ mappTableClient::UPDATE(void)
	{
		return "UPDATE Client " +
			"SET Nom_client = '" + this->getNom() + "', Prenom_client = '" + this->getPrenom() + "' " + ", Date_naissance_client = '" + this->getDateNaissance() + "' " + ", DatePR_Achat = '" + this->getDatePr() + "' " +
			"WHERE(ID_client = " + this->getId() + ");";
	}
	String^ mappTableClient::DELETE(void)
	{
		return mappPersonnes::DELETE("Client", "ID_client", this->getId());
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
	void mappTableClient::setDateNaissance(DateTime Date_naissance_client)
	{
			this->Date_naissance = Date_naissance_client;
	}
	void mappTableClient::setDatePr(DateTime DatePR_Achat)
	{
			this->DatePR_Achat = DatePR_Achat;
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
	DateTime mappTableClient::getDateNaissance(void)
	{
		return this->Date_naissance;
	}
	DateTime mappTableClient::getDatePr(void)
	{
		return this->DatePR_Achat;
	}
}
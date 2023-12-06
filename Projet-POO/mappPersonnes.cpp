#include "mappPersonnes.h"

namespace NS_Composants

{
	mappPersonnes::mappPersonnes(void)
	{
		this->ID = -1;
		this->Nom = "RIEN";
		this->Prenom = "RIEN";
		this->Date_naissance = DateTime::Now;
	}
	String^ mappPersonnes::SELECT(String^ table)
	{
		return "SELECT * FROM " + table + ";";
	}
	String^ mappPersonnes::DELETE(String^ table, String^ id_name)
	{
		return "DELETE FROM " + table + " WHERE(" + id_name + " = " + this->getId() + ");";
	}
}
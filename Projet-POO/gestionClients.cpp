#include "gestionClients.h"
namespace NS_SVC
{
	gestionClients::gestionClients(void)
	{
		this->cad = gcnew NS_Composants::CAD();
		this->client = gcnew NS_Composants::mappTableClient();
	}
	DataSet^ gestionClients::listeClients(String^ dataTableName)
	{
		this->ds = gcnew DataSet();
		this->ds = this->cad->getRows(this->client->SELECT(), dataTableName);
		return this->ds;
	}
	void gestionClients::ajouter(String^ nom, String^ prenom, array<String^>^
		lesAdresses)
	{
		int id;
		this->client->setNom(nom);
		this->client->setPrenom(prenom);
		id = this->cad->actionRowsID(this->client->INSERT());
	}
	void gestionClients::gestionClients::modifier(int id_client, String^ nom,
		String^ prenom, array<String^>^ lesAdresses)
	{
		this->client->setID(id_client);
		this->client->setNom(nom);
		this->client->setPrenom(prenom);
		this->cad->actionRows(this->client->UPDATE());
	}
	void gestionClients::supprimer(int idclient)
	{
		this->client->setID(idclient);
		this->cad->actionRows(this->client->DELETE());
	}
}
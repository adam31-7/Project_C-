#include "gestionClients.h"
namespace NS_SVC
{
	gestionClients::gestionClients(void)
	{
		this->cad = gcnew NS_Composants::CAD();
		this->client = gcnew NS_Composants::mappTableClient();
		this->adresse = gcnew NS_Composants::mappTableAdresse();
	}
	DataSet^ gestionClients::listeClients(String^ dataTableName)
	{
		this->ds = gcnew DataSet();
		this->ds = this->cad->getRows(this->client->SELECT(), dataTableName);
		return this->ds;
	}
	DataSet^ gestionClients::adressesClient(int id_client, String^ dataTableName)
	{
		this->adresse->setIDClient(id_client);
		this->ds = gcnew DataSet();
		this->ds = this->cad->getRows(this->adresse->SELECTByIdClient(), dataTableName);
		return this->ds;
	}
	void gestionClients::ajouter(String^ nom, String^ prenom, array<String^>^
		lesAdresses)
	{
		int id;
		this->client->setNom(nom);
		this->client->setPrenom(prenom);
		id = this->cad->actionRowsID(this->client->INSERT());
		for (int i = 0; i < lesAdresses->Length - 1; i++)
		{
			this->adresse->setIDClient(id);
			this->adresse->setNumRue(Convert::ToInt32(lesAdresses[i]));
			this->adresse->setNomRue(lesAdresses[i + 1]);
			this->adresse->setVille(lesAdresses[i + 2]);
			this->adresse->setCodePostal(lesAdresses[i + 3]);
			this->adresse->setPays(lesAdresses[i + 4]);
			this->adresse->setInfoSup(lesAdresses[i + 5]);
			this->cad->actionRows(this->adresse->INSERT());
			i = i + 5;
		}
	}
	void gestionClients::gestionClients::modifier(int id_client, String^ nom,
		String^ prenom, array<String^>^ lesAdresses)
	{
		this->client->setID(id_client);
		this->client->setNom(nom);
		this->client->setPrenom(prenom);
		this->cad->actionRows(this->client->UPDATE());
		for (int i = 0; i < lesAdresses->Length - 1; i++)
		{
			this->adresse->setIDClient(id_client);
			this->adresse->setNumRue(Convert::ToInt32(lesAdresses[i]));
			this->adresse->setNomRue(lesAdresses[i + 1]);
			this->adresse->setVille(lesAdresses[i + 2]);
			this->adresse->setCodePostal(lesAdresses[i + 3]);
			this->adresse->setPays(lesAdresses[i + 4]);
			this->adresse->setInfoSup(lesAdresses[i + 5]);
			this->cad->actionRows(this->adresse->UPDATE());
			i = i + 5;
		}

	}
	void gestionClients::supprimer(int idclient)
	{
		this->client->setID(idclient);
		this->cad->actionRows(this->client->DELETE());
	}
}
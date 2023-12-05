#include "gestionCommandes.h"

namespace NS_SVC
{
	gestionCommandes::gestionCommandes(void)
	{
		this->cad = gcnew NS_Composants::CAD();
		this->commande = gcnew NS_Composants::mappTableCommande();
		this->article = gcnew NS_Composants::mappTableArticle();
		this->client = gcnew NS_Composants::mappTableClient();
		this->adresse = gcnew NS_Composants::mappTableAdresse();
		this->ds = gcnew DataSet();
	}

	DataSet^ gestionCommandes::listeCommandes(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->commande->SELECT(), dataTableName);
		return this->ds;
	}

	DataSet^ gestionCommandes::listeArticles(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->article->SELECT(), dataTableName);
		return this->ds;
	}

	DataSet^ gestionCommandes::listeArticlesCommande(String^ Ref_Commande, String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->articleCommande->SELECTArticlesFromCommande(Ref_Commande), dataTableName);
		return this->ds;
	}

	DataSet^ gestionCommandes::listeClients(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->client->SELECT(), dataTableName);
		return this->ds;
	}

	DataSet^ gestionCommandes::listeAdresses(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->adresse->SELECT(), dataTableName);
		return this->ds;
	}
}
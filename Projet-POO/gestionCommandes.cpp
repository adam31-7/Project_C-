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

void gestionCommandes::ajouter(int Id_Adresse_livraison, int Id_Adresse_facturation, DateTime Date_emission, DateTime Date_livraison, DateTime Date_paiement, DateTime Date_reglement, String^ Moyen_reglement, int Id_Client)
	{
		this->commande->setIdAdresseLivraison(Id_Adresse_livraison);
		this->commande->setIdAdresseFacturation(Id_Adresse_facturation);
		this->commande->setDateEmission(Date_emission);
		this->commande->setDateLivraison(Date_livraison);
		this->commande->setDatePaiement(Date_paiement);
		this->commande->setDateReglement(Date_reglement);
		this->commande->setMoyenReglement(Moyen_reglement);
		this->commande->setIdClient(Id_Client);

		this->client->setID(Id_Client);

		DataRow^ dr_client = this->cad->getRows(this->client->SELECTByID(), "client")->Tables["client"]->Rows[0];

		this->client->setNom(dr_client->ItemArray[1]->ToString());
		this->client->setPrenom(dr_client->ItemArray[2]->ToString());
		this->client->setDateNaissance(Convert::ToDateTime(dr_client->ItemArray[3]->ToString()));
		this->client->setDatePr(Convert::ToDateTime(dr_client->ItemArray[4]->ToString()));

		this->adresse->setID(Id_Adresse_livraison);

		DataRow^ dr_adresse = this->cad->getRows(this->adresse->SELECTById(), "adresse")->Tables["adresse"]->Rows[0];

		this->adresse->setNumRue(Convert::ToInt32(dr_adresse->ItemArray[1]->ToString()));
		this->adresse->setNomRue(dr_adresse->ItemArray[2]->ToString());
		this->adresse->setVille(dr_adresse->ItemArray[3]->ToString());
		this->adresse->setCodePostal(dr_adresse->ItemArray[4]->ToString());
		this->adresse->setInfoSup(dr_adresse->ItemArray[5]->ToString());
		this->adresse->setPays(dr_adresse->ItemArray[6]->ToString());

		String^ reference = this->client->getPrenom()->Substring(0,2)->ToUpper() + this->client->getNom()->Substring(0, 2)->ToUpper() + this->commande->getDateEmission().Year + this->adresse->getVille()->Substring(0,3)->ToUpper();

		int numIncr = this->cad->actionRowsID("SELECT COUNT(*) AS NombreDeCommandes FROM Commande WHERE Ref_com LIKE '" + reference +"%'; ");

		if (numIncr < 10)
		{
			reference += "00" + numIncr;
		}
		else if (numIncr < 100)
		{
			reference += "0" + numIncr;
		}
		else
		{
			reference += numIncr;
		}

		this->commande->setReference(reference);

		this->cad->actionRows(this->commande->INSERT());
	}
void gestionCommandes::modifier(String^ Reference, int Id_Adresse_livraison, int Id_Adresse_facturation, DateTime Date_emission, DateTime Date_livraison, DateTime Date_paiement, DateTime Date_reglement, String^ Moyen_reglement, int Id_Client)
{
		this->commande->setReference(Reference);
		this->commande->setIdAdresseLivraison(Id_Adresse_livraison);
		this->commande->setIdAdresseFacturation(Id_Adresse_facturation);
		this->commande->setDateEmission(Date_emission);
		this->commande->setDateLivraison(Date_livraison);
		this->commande->setDatePaiement(Date_paiement);
		this->commande->setDateReglement(Date_reglement);
		this->commande->setMoyenReglement(Moyen_reglement);
		this->commande->setIdClient(Id_Client);

		this->cad->actionRows(this->commande->UPDATE());
	}
void gestionCommandes::supprimer(String^ Reference) {
		this->commande->setReference(Reference);
		this->cad->actionRows(this->commande->DELETE());
}
}
#pragma once
#include "mappTableClient.h"
#include "mappTableArticle.h"
#include "mappTableAdresse.h"

using namespace System;
namespace NS_Composants
{
	ref class mappTableCommande
	{
	private:
			String^ Reference;
			int Id_Adresse_livraison;
			int Id_Adresse_facturation;
			DateTime Date_emission;
			DateTime Date_livraison;
			DateTime Date_paiement;
			DateTime Date_reglement;
			String^ Moyen_reglement;
			int Id_Client;
	public:
			mappTableCommande(void);
			String^ SELECT(void);
			String^ INSERT(void);
			String^ UPDATE(void);
			String^ DELETE(void);
			void setReference(String^);
			void setIdAdresseLivraison(int);
			void setIdAdresseFacturation(int);
			void setDateEmission(DateTime);
			void setDateLivraison(DateTime);
			void setDatePaiement(DateTime);
			void setDateReglement(DateTime);
			void setMoyenReglement(String^);
			void setIdClient(int);
			String^ getReference(void);
			int getIdAdresseLivraison(void);
			int getIdAdresseFacturation(void);
			DateTime getDateEmission(void);
			DateTime getDateLivraison(void);
			DateTime getDatePaiement(void);
			DateTime getDateReglement(void);
			String^ getMoyenReglement(void);
			int getIdClient(void);
	};
}


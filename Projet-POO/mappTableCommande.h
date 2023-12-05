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
			String^ Date_emission;
			String^ Date_livraison;
			String^ Date_paiement;
			String^ Date_reglement;
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
			void setDateEmission(String^);
			void setDateLivraison(String^);
			void setDatePaiement(String^);
			void setDateReglement(String^);
			void setMoyenReglement(String^);
			void setIdClient(int);
			String^ getReference(void);
			int getIdAdresseLivraison(void);
			int getIdAdresseFacturation(void);
			String^ getDateEmission(void);
			String^ getDateLivraison(void);
			String^ getDatePaiement(void);
			String^ getDateReglement(void);
			String^ getMoyenReglement(void);
			int getIdClient(void);
	};
}


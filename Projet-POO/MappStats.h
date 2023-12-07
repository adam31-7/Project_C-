#pragma once
using namespace System;
namespace NS_Composants
{	ref class mappStats
	{
	private:
		String^ Ref_Art;
		String^ Couleur_Art;
		String^ Nature_Art;
		String^ Nom_Art;
		String^ QuantiteS_Art;
		String^ Prix_HT_Art;
		String^ Taux_TVA;
		int SeuilRea;
		String^ Quanti_CA;
		int ID_client;
	public:
		mappStats(void);
		String^ getArticlePlusVendu(void);
		String^ getArticleMoinsVendu(void);
		String^ ProduitSousSeuil(void);
		String^ getMontantTotalClient(void);
		String^ CalculerValCommerciale(void);
		String^ CalculerValeurStock(void);
		String^ getChiffreAffaire(void);
		String^ getPanierMoyen(void);
		String^ getRef_Art(void);
		String^ getCouleur_Art(void);
		String^ getNature_Art(void);
		String^ getNom_Art(void);
		String^ getQuantiteS_Art(void);
		String^ getPrix_HT_Art(void);
		String^ getTaux_TVA(void);
		int getSeuilRea(void);
		String^ getQuanti_CA(void);
		int getIDClient(void);
		void setID(int);
	};
}
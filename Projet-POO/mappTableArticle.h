#pragma once
using namespace System;
namespace NS_Composants
{
	ref class mappTableArticle
	{
	private:
		String^ ref;
		String^ Couleur;
		String^ Nature;
		String^ Nom;
		int Quantite_Stock;
		float TauxTVA;
		float PrixHT;
	public:
		mappTableArticle(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setRef(String^);
		void setCouleur(String^);
		void setNature(String^);
		void setTauxTVA(float);
		void setPrixHT(float);
		void setNom(String^);
		void setQuantite_Stock(int);
		String^ getRef(void);
		String^ getCouleur(void);
		String^ getNature(void);
		float getTauxTVA(void);
		float getPrixHT(void);
		String^ getNom(void);
		int getQuantite_Stock(void);
	};
}


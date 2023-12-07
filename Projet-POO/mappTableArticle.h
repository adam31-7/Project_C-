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
		Decimal TauxTVA;
		Decimal PrixHT;
		int SeuilRea;
	public:
		mappTableArticle(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setRef(String^);
		void setCouleur(String^);
		void setNature(String^);
		void setTauxTVA(Decimal);
		void setPrixHT(Decimal);
		void setNom(String^);
		void setQuantite_Stock(int);
		void setSeuilRea(int);
		String^ getRef(void);
		String^ getCouleur(void);
		String^ getNature(void);
		Decimal getTauxTVA(void);
		Decimal getPrixHT(void);
		String^ getNom(void);
		int getQuantite_Stock(void);
		int getSeuilRea(void);
	};
}


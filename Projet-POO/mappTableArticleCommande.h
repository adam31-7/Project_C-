#pragma once
#include "mappTableArticle.h"
#include "mappTableCommande.h"
namespace NS_Composants
{
	ref class mappTableArticleCommande
	{
	private:
		int ID_Article;
		int ID_Commande;
		int Quantite;
	public:
		mappTableArticleCommande(void);
		String^ SELECT(void);
		String^ SELECTArticlesFromCommande(String^);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setID_Article(int);
		void setID_Commande(int);
		void setQuantite(int);
		int getID_Article(void);
		int getID_Commande(void);
		int getQuantite(void);
	};
}

#include "mappTableArticleCommande.h"

namespace NS_Composants
{
	
	mappTableArticleCommande::mappTableArticleCommande(void) {
		this->ID_Article = -1;
		this->ID_Commande = -1;
		this->Quantite = -1;
	}
	String^ mappTableArticleCommande::SELECT(void) {
		return "SELECT * FROM Article_Commande";
	}
	String^ mappTableArticleCommande::SELECTArticlesFromCommande(String^ Ref_Commande) {
		return "SELECT * FROM Article_Commande WHERE Ref_com = '" + Ref_Commande + "'";
	}
	String^ mappTableArticleCommande::INSERT(void) {
		return "INSERT INTO Article_Commande (ID_Article, ID_Commande, Quantite) VALUES('" + this->ID_Article + "', '" + this->ID_Commande + "', '" + this->Quantite + "')";
	}
	String^ mappTableArticleCommande::UPDATE(void) {
		return "UPDATE Article_Commande SET ID_Article = '" + this->ID_Article + "', ID_Commande = '" + this->ID_Commande + "', Quantite = '" + this->Quantite + "' WHERE ID_Article = '" + this->ID_Article + "' AND ID_Commande = '" + this->ID_Commande + "'";
	}
	String^ mappTableArticleCommande::DELETE(void) {
		return "DELETE FROM Article_Commande WHERE ID_Article = '" + this->ID_Article + "' AND ID_Commande = '" + this->ID_Commande + "'";
	}
	void mappTableArticleCommande::setID_Article(int ID_Article) {
		if (ID_Article > 0) {
			this->ID_Article = ID_Article;
		}
	}
	void mappTableArticleCommande::setID_Commande(int ID_Commande) {
		if (ID_Commande > 0) {
			this->ID_Commande = ID_Commande;
		}
	}
	void mappTableArticleCommande::setQuantite(int Quantite) {
		if (Quantite > 0) {
			this->Quantite = Quantite;
		}
	}
	int mappTableArticleCommande::getID_Article(void) {
		return this->ID_Article;
	}
	int mappTableArticleCommande::getID_Commande(void) {
		return this->ID_Commande;
	}
	int mappTableArticleCommande::getQuantite(void) {
		return this->Quantite;
	}
}
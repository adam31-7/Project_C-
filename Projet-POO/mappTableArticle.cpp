#include "mappTableArticle.h"
namespace NS_Composants
{
	mappTableArticle::mappTableArticle(void)
	{
		this->ref = "RIEN";
		this->Couleur = "RIEN";
		this->Nature = "RIEN";
		this->Nom = "RIEN";
		this->Quantite_Stock = -1;
		this->TauxTVA = -1;
		this->PrixHT = -1;
	}
	String^ mappTableArticle::SELECT(void)
	{
		return "SELECT * FROM Article";
	}
	String^ mappTableArticle::INSERT(void)
	{
		return "INSERT INTO Article " +
			"(Ref_Art, Couleur_Art, Nature_Art, Nom_Art, QuantiteS_Art, Prix_HT_Art, Taux_TVA, SeuilRea) " +
			"VALUES('" + this->getRef() + "', '" + this->getCouleur() + "', '" + this->getNature() + "', '" + this->getNom() + "', '" + this->getQuantite_Stock() + "', '" + this->getPrixHT() + "', '" + this->getTauxTVA() + "', '" + this->getPrixHT() + "');SELECT @@IDENTITY; ";
	}
	String^ mappTableArticle::UPDATE(void)
	{
		return "UPDATE Article " +
			"SET Couleur_Art = '" + this->getCouleur() + "', Nature_Art = '" + this->getNature() + "', Nom_Art = '" + this->getNom() + "', QuantiteS_Art = '" + this->getQuantite_Stock() + "', Taux_TVA = '" + this->getTauxTVA() + "', Prix_HT_Art = '" + this->getPrixHT() + "' " +
			"WHERE (Ref_Art = '" + this->getRef() + "');";
	}
	String^ mappTableArticle::DELETE(void)
	{
		return "DELETE FROM Article WHERE (Ref_Art = '" + this->getRef() + ");";
	}
	void mappTableArticle::setRef(String^ Ref_article)
	{
		if (Ref_article != "")
		{
			this->ref = Ref_article;
		}
	}
	void mappTableArticle::setCouleur(String^ Couleur_article)
	{
		if (Couleur_article != "")
		{
			this->Couleur = Couleur_article;
		}
	}
	void mappTableArticle::setNature(String^ Nature_article)
	{
		if (Nature_article != "")
		{
			this->Nature = Nature_article;
		}
	}
	void mappTableArticle::setNom(String^ Nom_article)
	{
		if (Nom_article != "")
		{
			this->Nom = Nom_article;
		}
	}
	void mappTableArticle::setQuantite_Stock(int Quantite_stock)
	{
		if (Quantite_stock > 0)
		{
			this->Quantite_Stock = Quantite_stock;
		}
	}

	void mappTableArticle::setSeuilRea(int SeuilRea)
	{
		if (SeuilRea > 0)
		{
			this->SeuilRea = SeuilRea;
		}
	}

	void mappTableArticle::setTauxTVA(Decimal Taux_TVA)
	{
		if (Taux_TVA > 0)
		{
			this->TauxTVA = Taux_TVA;
		}
	}
	void mappTableArticle::setPrixHT(Decimal Prix_HT)
	{
		if (Prix_HT > 0)
		{
			this->PrixHT = Prix_HT;
		}
	}
	String^ mappTableArticle::getRef(void)
	{
		return this->ref;
	}
	String^ mappTableArticle::getCouleur(void)
	{
		return this->Couleur;
	}
	String^ mappTableArticle::getNature(void)
	{
		return this->Nature;
	}
	String^ mappTableArticle::getNom(void)
	{
		return this->Nom;
	}
	int mappTableArticle::getQuantite_Stock(void)
	{
		return this->Quantite_Stock;
	}
	Decimal mappTableArticle::getTauxTVA(void)
	{
		return this->TauxTVA;
	}
	Decimal mappTableArticle::getPrixHT(void)
	{
		return this->PrixHT;
	}
	int mappTableArticle::getSeuilRea(void)
	{
		return this->SeuilRea;
	}
}
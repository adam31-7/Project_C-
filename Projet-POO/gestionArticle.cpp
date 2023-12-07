#include "gestionArticle.h"

namespace NS_SVC
{
	gestionArticle::gestionArticle(void)
	{
		this->cad = gcnew NS_Composants::CAD();
		this->article = gcnew NS_Composants::mappTableArticle();
	}

	DataSet^ gestionArticle::listeArticles(String^ dataTableName)
	{
		this->ds = gcnew DataSet();
		this->ds = this->cad->getRows(this->article->SELECT(), dataTableName);
		return this->ds;
	}

	void gestionArticle::ajouter(array<String^>^ infoArticle)
	{
		this->article->setRef(infoArticle[0]);
		this->article->setCouleur(infoArticle[1]);
		this->article->setNature(infoArticle[2]);
		this->article->setNom(infoArticle[3]);
		this->article->setQuantite_Stock(Convert::ToInt32(infoArticle[4]));
		this->article->setTauxTVA(Convert::ToInt32(infoArticle[5]));
		this->article->setPrixHT(Convert::ToInt32(infoArticle[6]));
		this->cad->actionRows(this->article->INSERT());
	}

	void gestionArticle::modifier(array<String^>^ infoArticle)
	{
		this->article->setRef(infoArticle[0]);
		this->article->setCouleur(infoArticle[1]);
		this->article->setNature(infoArticle[2]);
		this->article->setNom(infoArticle[3]);
		this->article->setQuantite_Stock(Convert::ToInt32(infoArticle[4]));
		this->article->setTauxTVA(Convert::ToInt32(infoArticle[5]));
		this->article->setPrixHT(Convert::ToInt32(infoArticle[6]));
		this->cad->actionRows(this->article->UPDATE());
	}
}
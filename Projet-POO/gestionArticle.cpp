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
		this->article->setTauxTVA(Convert::ToDecimal(infoArticle[5]->Replace(".", ",")));
		this->article->setPrixHT(Convert::ToDecimal(infoArticle[6]->Replace(".", ",")));
		this->article->setSeuilRea(Convert::ToInt32(infoArticle[7]));
		this->cad->actionRows(this->article->INSERT());
	}

	void gestionArticle::modifier(array<String^>^ infoArticle)
	{
		this->article->setRef(infoArticle[0]);
		this->article->setCouleur(infoArticle[1]);
		this->article->setNature(infoArticle[2]);
		this->article->setNom(infoArticle[3]);

		int quantiteStock = 0, seuil = 0;
		Decimal tauxTVA = 0, prixHT = 0;

		if (!String::IsNullOrEmpty(infoArticle[4])) {
			quantiteStock = Convert::ToInt32(infoArticle[4]);
		}

		if (!String::IsNullOrEmpty(infoArticle[5])) {
			prixHT = Convert::ToDecimal(infoArticle[5]->Replace(".", ","));
		}

		if (!String::IsNullOrEmpty(infoArticle[6])) {
			tauxTVA = Convert::ToDecimal(infoArticle[6]->Replace(".", ","));
		}

		if (!String::IsNullOrEmpty(infoArticle[7])) {
			seuil = Convert::ToInt32(infoArticle[7]);
		}

		this->article->setQuantite_Stock(quantiteStock);
		this->article->setTauxTVA(tauxTVA);
		this->article->setPrixHT(prixHT);
		this->article->setSeuilRea(seuil);

		this->cad->actionRows(this->article->UPDATE());

	}

	void gestionArticle::supprimer(String^ refArticle)
	{
		// Construction de la requête SQL pour supprimer l'article avec la référence spécifiée
		String^ query = "DELETE FROM Article WHERE Ref_Art = '" + refArticle + "'";

		try
		{
			// Exécution de la requête de suppression
			this->cad->actionRows(query);
		}
		catch (Exception^ ex)
		{
			// Gestion des erreurs (par exemple, enregistrer le message d'erreur dans un fichier de journal)
			Console::WriteLine("Erreur lors de la suppression de l'article: " + ex->Message);
		}
	}

}
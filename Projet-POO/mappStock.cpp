#include "mappStock.h"

NS_Composants::mappStock::mappStock(void)
{

}

String^ NS_Composants::mappStock::getArticlePlusVendu(void)
{
	return "SELECT AC.Ref_Art,A.Nom_Art,SUM(CAST(AC.Quanti_CA AS DECIMAL)) AS TotalQuantitySold"
		+ "FROM Article_Commande AS AC JOIN Article AS A ON AC.Ref_Art = A.Ref_Art GROUP BY AC.Ref_Art, A.Nom_Art"
		+ "ORDER BY TotalQuantitySold DESC LIMIT 10;";
}

String^ NS_Composants::mappStock::getArticleMoinsVendu(void)
{
	return "SELECT AC.Ref_Art, A.Nom_Art, SUM(CAST(AC.Quanti_CA AS DECIMAL)) AS TotalQuantitySold"
		+ "FROM Article_Commande AS AC JOIN Article AS A ON AC.Ref_Art = A.Ref_Art GROUP BY AC.Ref_Art, A.Nom_Art"
		+ "ORDER BY TotalQuantitySold ASC LIMIT 10;";
}


String^ NS_Composants::mappStock::getMontantTotalClient(void)
{
	return "SELECT Client.ID_client, Client.Nom_Client, Client.Prenom_Client,"
		+ "SUM(CAST(Article.Prix_HT_Art AS DECIMAL) * CAST(Article_Commande.Quanti_CA AS DECIMAL)) AS TotalAmountSpent"
		+ "FROM Client AS C"
		+ "JOIN Commande AS Co ON C.ID_client = Co.ID_client"
		+ "JOIN Article_Commande AS AC ON Co.Ref_com = AC.Ref_com"
		+ "JOIN Article AS A ON AC.Ref_Art = A.Ref_Art"
		+ "GROUP BY C.ID_client, C.Nom_client, C.Prenom_client"
		+ "HAVING C.ID_client = " + this->getIDClient()+ ";";
}


String^ NS_Composants::mappStock::CalculerValCommerciale(void)
{
	return "SELECT Article.Ref_Art,Article.Nom_Art,SUM(CAST(Article.QuantiteS_Art AS DECIMAL) * CAST(Article.Prix_HT_Art AS DECIMAL)) AS CommercialValue"
		+"FROM Article AS A GROUP BY A.Ref_Art, A.Nom_Art;";
}


String^ NS_Composants::mappStock::CalculerValeurStock(void)
{
	return "SELECT SUM(CAST(Article.QuantiteS_Art AS DECIMAL) * CAST(Article.Prix_HT_Art AS DECIMAL)) AS TotalStockValue"
		+ "FROM Article AS A;";
}


String^ NS_Composants::mappStock::getChiffreAffaire(void)
{
	return "SELECT SUM(CAST(A.Prix_HT_Art() AS DECIMAL)* CAST(AC.Quanti_CA AS DECIMAL)) AS TotalRevenue"
		+ "FROM Article_Commande AS AC JOIN Article AS A ON AC.Ref_Art = A.Ref_Art;";
}

String^ NS_Composants::mappStock::getPanierMoyen(void)
{
	return "SELECT C.ID_client, C.Nom_client, C.Prenom_client, AVG(CAST((A.Prix_HT_Art * AC.Quanti_CA * (1 - R.pourcentage_remise / 100)) AS DECIMAL)) AS AverageBasketValueAfterDiscount"
		+"FROM Client AS C JOIN Commande AS Co ON C.ID_client = Co.ID_client"
		+"JOIN Article_Commande AC ON Co.Ref_com = AC.Ref_com JOIN Article A ON AC.Ref_Art = A.Ref_Art"
		+"LEFT JOIN Remise R ON Co.ID_remise = R.ID_remise"
		+"WHERE C.ID_client =" + this->getIDClient();
	+"GROUP BY C.ID_client, C.Nom_client, C.Prenom_client;";
}

String^ NS_Composants::mappStock::getRef_Art(void)
{
	return this->Ref_Art;
}

String^ NS_Composants::mappStock::getCouleur_Art(void)
{
	return this->Couleur_Art;
}

String^ NS_Composants::mappStock::getNature_Art(void)
{
	return this->Nature_Art;
}

String^ NS_Composants::mappStock::getNom_Art(void)
{
	return this->Nom_Art;
}

String^ NS_Composants::mappStock::getQuantiteS_Art(void)
{
	return this->QuantiteS_Art;
}

String^ NS_Composants::mappStock::getPrix_HT_Art(void)
{
	return this->Prix_HT_Art;
}

String^ NS_Composants::mappStock::getTaux_TVA(void)
{
	return this->Taux_TVA;
}

String^ NS_Composants::mappStock::ProduitSousSeuil(void)
{
	return "SELECT Ref_Art, Nom_Art, QuantiteS_Art, SeuilRea"
		+ "FROM Article WHERE QuantiteS_Art < SeuilRea;";
}

int NS_Composants::mappStock::getSeuilRea(void)
{
	return this->SeuilRea;
}

String^ NS_Composants::mappStock::getQuanti_CA(void)
{
	return this->Quanti_CA;
}

int NS_Composants::mappStock::getIDClient(void)
{
	return this->ID_client;
}

void NS_Composants::mappStock::setID(int client)
{
	if (ID_client > 0)
	{
		this->ID_client = client;
	}
}
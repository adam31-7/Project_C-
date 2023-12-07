#pragma once
#include "CAD.h"
#include "mappTableCommande.h"
#include "mappTableArticle.h"
#include "mappTableClient.h"
#include "mappTableAdresse.h"
#include "mappTableArticleCommande.h"

using namespace System::Data;

using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;
namespace NS_SVC
{
	ref class gestionCommandes
	{
	private:
		NS_Composants::CAD^ cad;
		DataSet^ ds;
		NS_Composants::mappTableCommande^ commande;
		NS_Composants::mappTableArticle^ article;
		NS_Composants::mappTableClient^ client;
		NS_Composants::mappTableAdresse^ adresse;
		NS_Composants::mappTableArticleCommande^ articleCommande;
	public:
		gestionCommandes(void);
		DataSet^ listeCommandes(String^);
		DataSet^ listeArticles(String^);
		DataSet^ listeArticlesCommande(String^, String^);
		DataSet^ listeClients(String^);
		DataSet^ listeAdresses(String^);
		void ajouter(int, int, DateTime, DateTime, DateTime, DateTime, String^, int);
		void modifier(String^, int, int, DateTime, DateTime, DateTime, DateTime, String^, int);
		void supprimer(String^);
	};
}


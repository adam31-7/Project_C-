#pragma once
#include "CAD.h"
#include "mappTableArticle.h"
namespace NS_SVC
{
	ref class gestionArticle
	{
		private:
		NS_Composants::CAD^ cad;
		DataSet^ ds;
		NS_Composants::mappTableArticle^ article;

		public:
			gestionArticle(void);
			DataSet^ listeArticles(String^);
			void ajouter(array<String^>^);
			void modifier(array<String^>^);
	};
}


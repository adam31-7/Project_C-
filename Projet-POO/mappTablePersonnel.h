#pragma once
#include "mappPersonnes.h"
using namespace System;
namespace NS_Composants
{
	ref class mappTablePersonnel : public NS_Composants::mappPersonnes
	{
	private:
		DateTime Date_embauche;
		int ID_SupH;
		int ID_adresse;
	public:
		mappTablePersonnel(void);
		virtual String^ SELECT(void) override;
		virtual String^ INSERT(void) override;
		virtual String^ UPDATE(void) override;
		virtual String^ DELETE(void) override;
		void setID(int) override;
		void setPrenom(String^) override;
		void setNom(String^) override;
		void setDateNaissance(DateTime) override;
		void setDateEmbauche(DateTime);
		void setID_SupH(int);
		void setID_Adresse(int);
		int getId(void) override;
		String^ getNom(void) override;
		String^ getPrenom(void) override;
		DateTime getDateNaissance(void) override;
		DateTime getDateEmbauche(void);
		int getID_SupH(void);
		int getID_Adresse(void);
	};
}
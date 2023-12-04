#pragma once
using namespace System;
namespace NS_Composants
{
	ref class mappTableClient
	{
	private:
		int ID_client;
		String^ Nom_client;
		String^ Prenom_client;
		String^ Date_naissance_client;
		String^ DatePR_Achat;
	public:
		mappTableClient(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setID(int);
		void setPrenom(String^);
		void setNom(String^);
		void setDateNaissance(String^);
		void setDatePr(String^);
		int getId(void);
		String^ getNom(void);
		String^ getPrenom(void);
		String^ getDateNaissance(void);
		String^ getDatePr(void);
	};
}
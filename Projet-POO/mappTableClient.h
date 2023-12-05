#pragma once
#include "mappPersonnes.h"
using namespace System;
namespace NS_Composants
{
	ref class mappTableClient : public NS_Composants::mappPersonnes
	{
	private:
		String^ DatePR_Achat;
	public:
		mappTableClient(void);
		virtual String^ SELECT(void) override;
		virtual String^ INSERT(void) override;
		virtual String^ UPDATE(void) override;
		virtual String^ DELETE(void) override;
		void setID(int) override;
		void setPrenom(String^) override;
		void setNom(String^) override;
		void setDateNaissance(String^) override;
		void setDatePr(String^);
		int getId(void) override;
		String^ getNom(void) override;
		String^ getPrenom(void) override;
		String^ getDateNaissance(void) override;
		String^ getDatePr(void);
	};
}
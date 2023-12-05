#pragma once
using namespace System;
namespace NS_Composants
{
	ref class mappTableAdresse
	{
	private:
		int ID_adresse;
		int Num_rue;
		String^ Nom_rue;
		String^ Ville;
		String^ Code_postal;
		String^ Pays;
		String^ InfoSup;
		int ID_client;
	public:
		mappTableAdresse(void);
		String^ SELECTByIdClient(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setID(int);
		void setNumRue(int);
		void setNomRue(String^);
		void setVille(String^);
		void setCodePostal(String^);
		void setPays(String^);
		void setInfoSup(String^);
		void setIDClient(int);
		int getId(void);
		int getNumRue(void);
		String^ getNomRue(void);
		String^ getVille(void);
		String^ getCodePostal(void);
		String^ getPays(void);
		String^ getInfoSup(void);
		int getIDClient(void);
	};
}
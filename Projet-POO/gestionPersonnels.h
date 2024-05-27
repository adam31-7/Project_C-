#pragma once
#include "CAD.h"
#include "mappTablePersonnel.h"

using namespace System::Data;

using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;
namespace NS_SVC
{
	public ref class gestionPersonnels
	{
	private:
		NS_Composants::CAD^ cad;
		DataSet^ ds;
		NS_Composants::mappTablePersonnel^ perso;
	public:
		gestionPersonnels(void);
		DataSet^ listePersonnels(String^);
		void ajouter(String^, String^, DateTime, DateTime, int, int);
		void modifier(int, String^, String^, DateTime, DateTime, int, int);
		void supprimer(int);
	};
}
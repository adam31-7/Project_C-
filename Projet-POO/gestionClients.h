#pragma once
#include "CAD.h"
#include "mappTableClient.h"

using namespace System::Data;

using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;
namespace NS_SVC
{
	ref class gestionClients
	{
	private:
		NS_Composants::CAD^ cad;
		DataSet^ ds;
		NS_Composants::mappTableClient^ client;
	public:
		gestionClients(void);
		DataSet^ listeClients(String^);
		void ajouter(String^, String^, array<String^>^);
		void modifier(int, String^, String^, array<String^>^);
		void supprimer(int);
	};
}
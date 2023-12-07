#pragma once

#include "CAD.h"
#include "mappStats.h"

using namespace System::Data;

using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_SVC
{
	ref class gestionStats
	{
	private:
		NS_Composants::CAD^ cad;
		DataSet^ ds;
		NS_Composants::mappStats^ Stats;
	public:
		gestionStats(void);
		DataSet^ listeArticle(String^);
	};
}
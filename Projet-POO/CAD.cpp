#include "CAD.h"
namespace NS_Composants
{
	//Si tout ça n'est pas clair, on en reparle à mon retour. Bon courage à vous.
	CAD::CAD(void)
	{
		this->rq_sql = ""; //ou ""
		this->cnx = "Data Source=ADRI-LAPTOP;Initial Catalog=ProjetPOO;User ID=adrien;Password=azerty";
		this->CNX = gcnew SqlConnection(this->cnx);
		this->CMD = gcnew SqlCommand(this->rq_sql, this->CNX);
		this->CMD->CommandType = CommandType::Text;
	}


	// Méthode pour exécuter une requête SQL et retourner une valeur (typiquement un ID)
	int CAD::actionRowsID(String^ rq_sql)
	{
		// Déclaration d'une variable pour stocker l'ID
		int id;

		// Appel de la méthode setSQL pour définir la requête SQL à exécuter
		this->setSQL(rq_sql);

		// Attribution de la requête SQL à la propriété CommandText de l'objet SqlCommand
		this->CMD->CommandText = this->rq_sql;

		// Ouverture de la connexion à la base de données
		this->CNX->Open();

		// Exécution de la requête SQL et récupération du résultat sous forme scalaire (une valeur unique)
		// Cette valeur est généralement utilisée pour récupérer un identifiant (ID) après une insertion
		id = Convert::ToInt32(this->CMD->ExecuteScalar());

		// Fermeture de la connexion à la base de données
		this->CNX->Close();

		// Retour de l'ID obtenu après l'exécution de la requête SQL
		return id;
	}

	Decimal CAD::actionRowsCalcul(String^ rq_sql)
	{
		// Déclaration d'une variable pour stocker le résultat
		Decimal result;

		// Appel de la méthode setSQL pour définir la requête SQL à exécuter
		this->setSQL(rq_sql);

		// Attribution de la requête SQL à la propriété CommandText de l'objet SqlCommand
		this->CMD->CommandText = this->rq_sql;

		// Ouverture de la connexion à la base de données
		this->CNX->Open();

		// Exécution de la requête SQL et récupération du résultat sous forme scalaire (une valeur unique)
		// Cette valeur est généralement utilisée pour récupérer un identifiant (ID) après une insertion
		result = Convert::ToDecimal(this->CMD->ExecuteScalar());

		// Fermeture de la connexion à la base de données
		this->CNX->Close();

		// Retour du résultat obtenu après l'exécution de la requête SQL
		return result;
	}


	// Méthode pour exécuter une requête SQL qui ne retourne pas de résultat (INSERT, UPDATE, DELETE, etc.)
	void CAD::actionRows(String^ rq_sql)
	{
		// Appel de la méthode setSQL pour définir la requête SQL à exécuter
		this->setSQL(rq_sql);

		// Attribution de la requête SQL à la propriété CommandText de l'objet SqlCommand
		this->CMD->CommandText = this->rq_sql;

		// Ouverture de la connexion à la base de données
		this->CNX->Open();

		// Exécution de la requête SQL sans récupération de résultat (INSERT, UPDATE, DELETE, etc.)
		this->CMD->ExecuteNonQuery();

		// Fermeture de la connexion à la base de données
		this->CNX->Close();
	}

	// Méthode pour récupérer des données à partir de la base de données dans un DataSet
	DataSet^ CAD::getRows(String^ rq_sql, String^ dataTableName)
	{
		// Appel de la méthode setSQL pour définir la requête SQL à exécuter
		this->setSQL(rq_sql);

		// Création d'un nouvel adaptateur de données SqlDataAdapter associé à l'objet SqlCommand (CMD)
		this->DA = gcnew SqlDataAdapter(this->CMD);

		// Attribution de la requête SQL à la propriété CommandText de l'objet SqlCommand
		this->CMD->CommandText = this->rq_sql;

		// Création d'un nouvel objet DataSet pour stocker les données récupérées
		this->DS = gcnew DataSet();

		// Remplissage du DataSet avec les données de la base de données en utilisant l'adaptateur de données (DataAdapter)
		// La table dans le DataSet sera nommée d'après la valeur de dataTableName
		this->DA->Fill(this->DS, dataTableName);

		// Retour du DataSet contenant les données récupérées
		return this->DS;
	}

	void CAD::setSQL(String^ rq_sql)
	{
		if (rq_sql == "" || rq_sql == "RIEN")
		{
			this->rq_sql = "RIEN";
		}
		else
		{
			this->rq_sql = rq_sql;
		}
	}
}
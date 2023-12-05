#include "gestionPersonnels.h"
namespace NS_SVC
{
	gestionPersonnels::gestionPersonnels(void)
	{
		this->cad = gcnew NS_Composants::CAD();
		this->perso = gcnew NS_Composants::mappTablePersonnel();
	}
	DataSet^ gestionPersonnels::listePersonnels(String^ dataTableName)
	{
		this->ds = gcnew DataSet();
		this->ds = this->cad->getRows(this->perso->SELECT(), dataTableName);
		return this->ds;
	}

	void gestionPersonnels::ajouter(String^ nom, String^ prenom, String^ dateEmbauche, int idSupH, int idAdresse)
	{
		int id;
		this->perso->setNom(nom);
		this->perso->setPrenom(prenom);
		this->perso->setDateEmbauche(dateEmbauche);
		this->perso->setID_SupH(idSupH);
		this->perso->setID_Adresse(idAdresse);
		id = this->cad->actionRowsID(this->perso->INSERT());
	}

	void gestionPersonnels::modifier(int id, String^ nom, String^ prenom, String^ dateEmbauche, int idSupH, int idAdresse)
	{
		this->perso->setID(id);
		this->perso->setNom(nom);
		this->perso->setPrenom(prenom);
		this->perso->setDateEmbauche(dateEmbauche);
		this->perso->setID_SupH(idSupH);
		this->perso->setID_Adresse(idAdresse);
		this->cad->actionRows(this->perso->UPDATE());
	}

	void gestionPersonnels::supprimer(int id)
	{
		this->perso->setID(id);
		this->cad->actionRows(this->perso->DELETE());
	}

}

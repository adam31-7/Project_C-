#include "gestionStats.h"

namespace NS_SVC
{
    gestionStats::gestionStats(void)
    {
        this->cad = gcnew NS_Composants::CAD();
        this->Stats = gcnew NS_Composants::mappStats();
    }
    DataSet^ gestionStats::listeArticlePV(String^ dataTableName)
    {
        this->ds = gcnew DataSet();
        this->ds = this->cad->getRows(this->Stats->getArticlePlusVendu(),dataTableName);
        return this->ds;
    }

    DataSet^ gestionStats::listeArticleMV(String^ dataTableName)
    {
        this->ds = gcnew DataSet();
        this->ds = this->cad->getRows(this->Stats->getArticleMoinsVendu(), dataTableName);
        return this->ds;
    }
    DataSet^ gestionStats::Montant(int id, String^ dataTableName)
    {
        this->ds = gcnew DataSet();
        this->ds = this->cad->getRows(this->Stats->getMontantTotalClient(id), dataTableName);
        //System::Windows::Forms::MessageBox::Show(this->Stats->getMontantTotalClient(id));
        return this->ds;
    }

    Decimal gestionStats::CA(void)
    {
        return this->cad->actionRowsCalcul(this->Stats->getChiffreAffaire());
    }

}
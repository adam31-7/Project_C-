#include "gestionStats.h"

namespace NS_SVC
{
    gestionStats::gestionStats(void)
{
    this->cad = gcnew NS_Composants::CAD();
    this->Stats = gcnew NS_Composants::mappStats();
}
    DataSet^ gestionStats::listeArticle(String^ dataTableName)
{
    this->ds = gcnew DataSet();
    this->ds = this->cad->getRows(this->Stats->SELECT(), dataTableName);
    return this->ds;
}

}
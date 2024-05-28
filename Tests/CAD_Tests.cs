using NUnit.Framework;
using NS_Composants;
using System.Data;

namespace Tests
{
    public class CADTests
    {
        private CAD cad;

        [SetUp]
        public void Setup()
        {
            cad = new CAD();
        }

        [Test]
        public void TestActionRowsID()
        {
            string sqlInsert = "INSERT INTO Adresse (Num_rue, Nom_rue, Ville, Code_postal, InfoSup, Pays, ID_client) OUTPUT INSERTED.ID_adresse VALUES (16, 'Rue Magellan','Labège','31670','Bâtiment Alpha', 'FRANCE', null)";
            int id = cad.actionRowsID(sqlInsert);

            Assert.Greater(id, 0);
        }

        [Test]
        public void TestActionRowsCalcul()
        {
            string sqlCalcul = "SELECT SUM(Num_rue) FROM Adresse";
            decimal result = cad.actionRowsCalcul(sqlCalcul);

            Assert.GreaterOrEqual(result, 0);
        }

        [Test]
        public void TestActionRows()
        {
            string sqlUpdate = "UPDATE Adresse SET Nom_rue = 'Rue Colomb' WHERE Ville = 'Labège'";
            Assert.DoesNotThrow(() => cad.actionRows(sqlUpdate));

        }

        [Test]
        public void TestGetRows()
        {
            string sqlSelect = "SELECT * FROM Adresse";
            string tableName = "Adresse";
            DataSet ds = cad.getRows(sqlSelect, tableName);

            Assert.IsNotNull(ds);
            Assert.IsTrue(ds.Tables.Contains(tableName));
            Assert.Greater(ds.Tables[tableName].Rows.Count, 0);
        }

        [Test]
        public void TestDeleteInsertedRow()
        {
            string sqlDelete = "DELETE FROM Adresse WHERE Num_rue = 16 AND Nom_rue = 'Rue Magellan' AND Ville = 'Labège' AND Code_postal = '31670' AND InfoSup = 'Bâtiment Alpha' AND Pays = 'FRANCE' AND ID_client IS NULL";
            Assert.DoesNotThrow(() => cad.actionRows(sqlDelete));
        }
    }
}

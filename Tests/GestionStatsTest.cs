using NUnit.Framework;
using NS_Composants;
using System.Data;
using System.Data.SQLite;

namespace Tests
{
    public class mappStatsTests
    {
        private SQLiteConnection connection;
        private mappStats stats;

        [SetUp]
        public void Setup()
        {
            stats = new mappStats();

            connection = new SQLiteConnection("Data Source=:memory:;Version=3;");
            connection.Open();

            CreateTestDatabase();
        }

        [TearDown]
        public void Teardown()
        {
            connection.Close();
        }

        private void CreateTestDatabase()
        {
            using (var cmd = new SQLiteCommand(connection))
            {
                cmd.CommandText = @"
                CREATE TABLE Article (
                    Ref_Art INTEGER PRIMARY KEY AUTOINCREMENT,
                    Nom_Art TEXT,
                    QuantiteS_Art INTEGER,
                    Prix_HT_Art DECIMAL,
                    SeuilRea INTEGER
                );
                CREATE TABLE Client (
                    ID_client INTEGER PRIMARY KEY AUTOINCREMENT,
                    Nom_Client TEXT,
                    Prenom_Client TEXT
                );
                CREATE TABLE Commande (
                    Ref_com INTEGER PRIMARY KEY AUTOINCREMENT,
                    ID_client INTEGER,
                    FOREIGN KEY (ID_client) REFERENCES Client(ID_client)
                );
                CREATE TABLE Article_Commande (
                    Ref_com INTEGER,
                    Ref_Art INTEGER,
                    Quanti_CA INTEGER,
                    FOREIGN KEY (Ref_com) REFERENCES Commande(Ref_com),
                    FOREIGN KEY (Ref_Art) REFERENCES Article(Ref_Art)
                );
                ";
                cmd.ExecuteNonQuery();

                cmd.CommandText = @"
                INSERT INTO Article (Nom_Art, QuantiteS_Art, Prix_HT_Art, SeuilRea) VALUES 
                ('Article1', 100, 10.0, 50),
                ('Article2', 200, 20.0, 150),
                ('Article3', 50, 30.0, 10);

                INSERT INTO Client (Nom_Client, Prenom_Client) VALUES 
                ('Doe', 'John'),
                ('Smith', 'Anna');

                INSERT INTO Commande (ID_client) VALUES 
                (1), (2);

                INSERT INTO Article_Commande (Ref_com, Ref_Art, Quanti_CA) VALUES 
                (1, 1, 10),
                (1, 2, 5),
                (2, 1, 15),
                (2, 3, 20);
                ";
                cmd.ExecuteNonQuery();
            }
        }

        private DataSet ExecuteQuery(string query)
        {
            using (var adapter = new SQLiteDataAdapter(query, connection))
            {
                var ds = new DataSet();
                adapter.Fill(ds);
                return ds;
            }
        }

        [Test]
        public void TestGetArticlePlusVendu()
        {
            string query = stats.getArticlePlusVendu(2);
            DataSet ds = ExecuteQuery(query);

            Assert.IsNotNull(ds);
            Assert.AreEqual(2, ds.Tables[0].Rows.Count);
        }

        [Test]
        public void TestGetArticleMoinsVendu()
        {
            string query = stats.getArticleMoinsVendu(2);
            DataSet ds = ExecuteQuery(query);

            Assert.IsNotNull(ds);
            Assert.AreEqual(2, ds.Tables[0].Rows.Count);
        }

        [Test]
        public void TestGetMontantTotalClient()
        {
            string query = stats.getMontantTotalClient(1);
            DataSet ds = ExecuteQuery(query);

            Assert.IsNotNull(ds);
            Assert.AreEqual(1, ds.Tables[0].Rows.Count);
        }

        [Test]
        public void TestCalculerValeurStock()
        {
            string query = stats.CalculerValeurStock();
            DataSet ds = ExecuteQuery(query);

            Assert.IsNotNull(ds);
            Assert.AreEqual(1, ds.Tables[0].Rows.Count);
        }

        [Test]
        public void TestGetChiffreAffaire()
        {
            string query = stats.getChiffreAffaire();
            DataSet ds = ExecuteQuery(query);

            Assert.IsNotNull(ds);
            Assert.AreEqual(1, ds.Tables[0].Rows.Count);
        }


    }
}

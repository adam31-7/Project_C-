using NUnit.Framework;
using System.Data;
using NS_SVC;

namespace Tests
{
    public class GestionClientTest
    {
        private gestionClients gestionClient;

        [SetUp]
        public void Setup()
        {
            this.gestionClient = new gestionClients();
        }

        [Test]
        public void AjouterClient()
        {
            Console.WriteLine("Test Start: AjouterClient");

            var lesAdresses = new string[] {
                "123", "Rue de Test", "Ville Test", "12345", "Pays Test", "Infos supplémentaires"
            };

            gestionClient.ajouter("Nom Test", "Prénom Test", DateTime.Now, DateTime.Now, lesAdresses);

            DataSet result = gestionClient.listeClients("Client");
            Assert.IsNotNull(result, "DataSet should not be null");
            Assert.IsTrue(result.Tables.Contains("Client"), "DataTable 'Client' should exist");

            bool isAdded = false;
            foreach (DataRow row in result.Tables["Client"].Rows)
            {
                if (row["Nom_client"].ToString() == "Nom Test" && row["Prenom_client"].ToString() == "Prénom Test")
                {
                    isAdded = true;
                    break;
                }
            }

            Assert.IsTrue(isAdded, "The client should be added to the DataTable");
        }

        [Test]
        public void ModifierClient()
        {
            Console.WriteLine("Test Start: ModifierClient");

            var lesAdresses = new string[] {
                "123", "Rue de Test", "Ville Test", "12345", "Pays Test", "Infos supplémentaires"
            };

            gestionClient.ajouter("Nom Test", "Prénom Test", DateTime.Now, DateTime.Now, lesAdresses);

            DataSet result = gestionClient.listeClients("Client");
            int idClient = -1;
            foreach (DataRow row in result.Tables["Client"].Rows)
            {
                if (row["Nom_client"].ToString() == "Nom Test" && row["Prenom_client"].ToString() == "Prénom Test")
                {
                    idClient = Convert.ToInt32(row["ID_client"]);
                    break;
                }
            }

            var updatedLesAdresses = new string[] {
                "456", "Nouvelle Rue", "Nouvelle Ville", "54321", "Nouveau Pays", "Nouvelles infos supplémentaires"
            };

            gestionClient.modifier(idClient, "Nouveau Nom", "Nouveau Prénom", DateTime.Now, DateTime.Now, updatedLesAdresses);

            result = gestionClient.listeClients("Client");

            bool isUpdated = false;
            foreach (DataRow row in result.Tables["Client"].Rows)
            {
                if (row["Nom_client"].ToString() == "Nouveau Nom" && row["Prenom_client"].ToString() == "Nouveau Prénom")
                {
                    isUpdated = true;
                    break;
                }
            }

            Assert.IsTrue(isUpdated, "The client should be updated in the DataTable");
        }

        [Test]
        public void SupprimerClient()
        {
            Console.WriteLine("Test Start: SupprimerClient");

            var lesAdresses = new string[] {
                "123", "Rue de Test", "Ville Test", "12345", "Pays Test", "Infos supplémentaires"
            };

            gestionClient.ajouter("Nom Test", "Prénom Test", DateTime.Now, DateTime.Now, lesAdresses);

            DataSet result = gestionClient.listeClients("Client");
            int idClient = -1;
            foreach (DataRow row in result.Tables["Client"].Rows)
            {
                if (row["Nom_client"].ToString() == "Nom Test" && row["Prenom_client"].ToString() == "Prénom Test")
                {
                    idClient = Convert.ToInt32(row["ID_client"]);
                    break;
                }
            }

            gestionClient.supprimer(idClient);

            result = gestionClient.listeClients("Client");

            bool isDeleted = true;
            foreach (DataRow row in result.Tables["Client"].Rows)
            {
                if (Convert.ToInt32(row["ID_client"]) == idClient)
                {
                    isDeleted = false;
                    break;
                }
            }

            Assert.IsTrue(isDeleted, "The client should be deleted from the DataTable");
        }
    }
}

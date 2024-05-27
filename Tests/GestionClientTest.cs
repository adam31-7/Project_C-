using NUnit.Framework;
using System;
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

            // Assign
            var lesAdresses = new string[] {
                "123", "Rue de Test", "Ville Test", "12345", "Pays Test", "Infos supplémentaires"
            };

            // Act
            gestionClient.ajouter("Nom Test", "Prénom Test", DateTime.Now, DateTime.Now, lesAdresses);

            // Retrieve the list of clients
            DataSet result = gestionClient.listeClients("Client");
            Assert.IsNotNull(result, "DataSet should not be null");
            Assert.IsTrue(result.Tables.Contains("Client"), "DataTable 'Client' should exist");

            // Check if the new client is in the DataTable
            bool isAdded = false;
            foreach (DataRow row in result.Tables["Client"].Rows)
            {
                if (row["Nom_client"].ToString() == "Nom Test" && row["Prenom_client"].ToString() == "Prénom Test")
                {
                    isAdded = true;
                    break;
                }
            }

            // Assert
            Assert.IsTrue(isAdded, "The client should be added to the DataTable");
        }

        [Test]
        public void ModifierClient()
        {
            Console.WriteLine("Test Start: ModifierClient");

            // Assign
            var lesAdresses = new string[] {
                "123", "Rue de Test", "Ville Test", "12345", "Pays Test", "Infos supplémentaires"
            };

            // Add client first
            gestionClient.ajouter("Nom Test", "Prénom Test", DateTime.Now, DateTime.Now, lesAdresses);

            // Retrieve the ID of the added client
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

            // Update client info
            var updatedLesAdresses = new string[] {
                "456", "Nouvelle Rue", "Nouvelle Ville", "54321", "Nouveau Pays", "Nouvelles infos supplémentaires"
            };

            // Act
            gestionClient.modifier(idClient, "Nouveau Nom", "Nouveau Prénom", DateTime.Now, DateTime.Now, updatedLesAdresses);

            // Retrieve the list of clients
            result = gestionClient.listeClients("Client");

            // Check if the client is updated in the DataTable
            bool isUpdated = false;
            foreach (DataRow row in result.Tables["Client"].Rows)
            {
                if (row["Nom_client"].ToString() == "Nouveau Nom" && row["Prenom_client"].ToString() == "Nouveau Prénom")
                {
                    isUpdated = true;
                    break;
                }
            }

            // Assert
            Assert.IsTrue(isUpdated, "The client should be updated in the DataTable");
        }

        [Test]
        public void SupprimerClient()
        {
            Console.WriteLine("Test Start: SupprimerClient");

            // Assign
            var lesAdresses = new string[] {
                "123", "Rue de Test", "Ville Test", "12345", "Pays Test", "Infos supplémentaires"
            };

            // Add client first
            gestionClient.ajouter("Nom Test", "Prénom Test", DateTime.Now, DateTime.Now, lesAdresses);

            // Retrieve the ID of the added client
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

            // Act
            gestionClient.supprimer(idClient);

            // Retrieve the list of clients
            result = gestionClient.listeClients("Client");

            // Check if the client is deleted from the DataTable
            bool isDeleted = true;
            foreach (DataRow row in result.Tables["Client"].Rows)
            {
                if (Convert.ToInt32(row["ID_client"]) == idClient)
                {
                    isDeleted = false;
                    break;
                }
            }

            // Assert
            Assert.IsTrue(isDeleted, "The client should be deleted from the DataTable");
        }
    }
}

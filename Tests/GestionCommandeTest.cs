using System;
using System.Data;
using NS_SVC;
using NUnit.Framework; // Assurez-vous d'importer la bonne référence pour NUnit
using NS_Composants;

namespace Tests
{
    public class GestionCommandesTests
    {
        private gestionCommandes gestionCommandes; // Supprimer l'alias NS_SVC

        [SetUp]
        public void Setup()
        {
            gestionCommandes = new gestionCommandes(); // Utilisez 'new' au lieu de 'gcnew'
        }

        [Test]
        public void TestAjouterCommande()
        {
            gestionCommandes.ajouter(1, 1, DateTime.Now, DateTime.Now, DateTime.Now, DateTime.Now, "Paiement", 4);

            DataSet dsCommande = gestionCommandes.listeCommandes("Commande");
            Assert.NotNull(dsCommande);
            Assert.That(dsCommande.Tables["Commande"].Rows.Count, Is.GreaterThan(0)); // Utilisez la syntaxe de contrainte NUnit
        }

        [Test]
        public void TestModifierCommande()
        {
            DataSet dsCommandeAvant = gestionCommandes.listeCommandes("Commandes");
            Assert.NotNull(dsCommandeAvant);
            DataRow[] rowsAvant = dsCommandeAvant.Tables["Commandes"].Select("Ref_com = 'BÉDU2023STR000'");
            if (rowsAvant.Length == 0)
            {
                gestionCommandes.ajouter(1, 1, DateTime.Now, DateTime.Now, DateTime.Now, DateTime.Now, "Paiement", 4);
            }

            DataSet dsClients = gestionCommandes.listeClients("Clients");
            Assert.NotNull(dsClients);
            DataRow[] clientRows = dsClients.Tables["Clients"].Select("ID_client = 4");
            
            gestionCommandes.modifier("BÉDU2023STR000", 5, 4, DateTime.Now, DateTime.Now, DateTime.Now, DateTime.Now, "Paiement", 4);

            DataSet dsCommandes = gestionCommandes.listeCommandes("Commandes");
            Assert.NotNull(dsCommandes);
            DataRow[] rows = dsCommandes.Tables["Commandes"].Select("Ref_com = 'BÉDU2023STR000'");
            Assert.AreEqual(1, rows.Length);
            DataRow row = rows[0];
            Assert.AreEqual(4, row["ID_client"]);
            Assert.AreEqual(4, row["ID_adresse_facturation"]);
        }

    }
}

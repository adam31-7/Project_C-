using NUnit.Framework;
using System;
using System.Data;
using NS_SVC;

namespace Tests
{
    public class GestionArticleTest
    {
        private gestionArticle gestionArticle;

        [SetUp]
        public void Setup()
        {
            this.gestionArticle = new gestionArticle();
        }

        [TearDown]
        public void Cleanup()
        {
            // Nettoyer les données après chaque test
            gestionArticle.supprimer("PB00518880");
            gestionArticle.supprimer("PB00518888");
        }

        [Test]
        public void AjouterArticle()
        {
            Console.WriteLine("Test Start: AjouterArticle");

            // Assign
            var infoArticle = new string[] {
                "PB00518880", "Rouge", "Electronique", "Téléphone",
                "50", "20.0", "100.0", "10"
            };

            // Act
            gestionArticle.ajouter(infoArticle);

            // Retrieve the list of articles
            DataSet result = gestionArticle.listeArticles("Article");
            Assert.IsNotNull(result, "DataSet should not be null");
            Assert.IsTrue(result.Tables.Contains("Article"), "DataTable 'Article' should exist");

            // Check if the new article is in the DataTable
            bool isAdded = false;
            foreach (DataRow row in result.Tables["Article"].Rows)
            {
                if (row["Ref_Art"].ToString() == "PB00518880")
                {
                    isAdded = true;
                    break;
                }
            }

            // Assert
            Assert.IsTrue(isAdded, "The article should be added to the DataTable");
        }

        [Test]
        public void ModifierArticle()
        {
            Console.WriteLine("Test Start: ModifierArticle");

            // Assign
            var infoArticle = new string[] {
                "PB00518888", "Rouge", "Electronique", "Téléphone",
                "50", "20.0", "100.0", "10"
            };

            // Add article first
            gestionArticle.ajouter(infoArticle);

            // Update article info
            var updatedInfoArticle = new string[] {
                "PB00518888", "Bleu", "Electronique", "Smartphone",
                "100", "20.0", "150.0", "5"
            };

            // Act
            gestionArticle.modifier(updatedInfoArticle);

            // Retrieve the list of articles
            DataSet result = gestionArticle.listeArticles("Article");

            // Check if the article is updated in the DataTable
            bool isUpdated = false;
            foreach (DataRow row in result.Tables["Article"].Rows)
            {
                if (row["Ref_Art"].ToString() == "PB00518888" &&
                    row["Couleur_Art"].ToString() == "Bleu" &&
                    row["Nom_Art"].ToString() == "Smartphone")
                {
                    isUpdated = true;
                    break;
                }
            }

            // Assert
            Assert.IsTrue(isUpdated, "The article should be updated in the DataTable");
        }

        [Test]
        public void SupprimerArticle()
        {
            Console.WriteLine("Test Start: SupprimerArticle");

            // Assign
            var infoArticle = new string[] {
                "PB00518869", "Rouge", "Electronique", "Téléphone",
                "50", "20.0", "100.0", "10"
            };

            // Add article first
            gestionArticle.ajouter(infoArticle);

            // Act
            gestionArticle.supprimer("PB00518869");

            // Retrieve the list of articles
            DataSet result = gestionArticle.listeArticles("Article");

            // Check if the article is deleted from the DataTable
            bool isDeleted = true;
            foreach (DataRow row in result.Tables["Article"].Rows)
            {
                if (row["Ref_Art"].ToString() == "PB00518869")
                {
                    isDeleted = false;
                    break;
                }
            }

            // Assert
            Assert.IsTrue(isDeleted, "The article should be deleted from the DataTable");
        }
    }
}

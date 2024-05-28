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
            gestionArticle.supprimer("PB00518880");
            gestionArticle.supprimer("PB00518888");
        }

        [Test]
        public void AjouterArticle()
        {
            Console.WriteLine("Test Start: AjouterArticle");

            var infoArticle = new string[] {
                "PB00518880", "Rouge", "Electronique", "Téléphone",
                "50", "20.0", "100.0", "10"
            };

            gestionArticle.ajouter(infoArticle);

            DataSet result = gestionArticle.listeArticles("Article");
            Assert.IsNotNull(result, "DataSet should not be null");
            Assert.IsTrue(result.Tables.Contains("Article"), "DataTable 'Article' should exist");

            bool isAdded = false;
            foreach (DataRow row in result.Tables["Article"].Rows)
            {
                if (row["Ref_Art"].ToString() == "PB00518880")
                {
                    isAdded = true;
                    break;
                }
            }

            Assert.IsTrue(isAdded, "The article should be added to the DataTable");
        }

        [Test]
        public void ModifierArticle()
        {
            Console.WriteLine("Test Start: ModifierArticle");

            var infoArticle = new string[] {
                "PB00518888", "Rouge", "Electronique", "Téléphone",
                "50", "20.0", "100.0", "10"
            };

            gestionArticle.ajouter(infoArticle);

            var updatedInfoArticle = new string[] {
                "PB00518888", "Bleu", "Electronique", "Smartphone",
                "100", "20.0", "150.0", "5"
            };

            gestionArticle.modifier(updatedInfoArticle);

            DataSet result = gestionArticle.listeArticles("Article");

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

            Assert.IsTrue(isUpdated, "The article should be updated in the DataTable");
        }

        [Test]
        public void SupprimerArticle()
        {
            Console.WriteLine("Test Start: SupprimerArticle");

            var infoArticle = new string[] {
                "PB00518869", "Rouge", "Electronique", "Téléphone",
                "50", "20.0", "100.0", "10"
            };

            gestionArticle.ajouter(infoArticle);

            gestionArticle.supprimer("PB00518869");

            DataSet result = gestionArticle.listeArticles("Article");

            bool isDeleted = true;
            foreach (DataRow row in result.Tables["Article"].Rows)
            {
                if (row["Ref_Art"].ToString() == "PB00518869")
                {
                    isDeleted = false;
                    break;
                }
            }

            Assert.IsTrue(isDeleted, "The article should be deleted from the DataTable");
        }
    }
}

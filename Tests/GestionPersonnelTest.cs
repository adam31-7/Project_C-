using NUnit.Framework;
using System;
using System.Data;
using NS_SVC;

namespace Tests
{
    public class GestionPersonnelTest
    {
        private gestionPersonnels Personnel { get; set; } = null!;

        [SetUp]
        public void Setup()
        {
            Console.WriteLine("Setup: Initializing gestionPersonnels object");
            Personnel = new gestionPersonnels();
            Console.WriteLine("Setup: Initialization complete");
        }

        [Test]
        public void AjouterPersonnel()
        {
            Console.WriteLine("Test Start: AjouterPersonnel");

            // Assign
            var nom = "JeanDav";
            var prenom = "David";
            var dateNaissance = new DateTime(1990, 5, 10);
            var dateEmbauche = new DateTime(2024, 5, 25);
            int idSupH = 1;
            int idAdresse = 2;

            var resultString = "";

            // Act
            try
            {
                Personnel.ajouter(nom, prenom, dateNaissance, dateEmbauche, idSupH, idAdresse);

                // Retrieve the list of personnel
                DataSet result = Personnel.listePersonnels("Personnel");
                Assert.IsNotNull(result, "DataSet should not be null");
                Assert.IsTrue(result.Tables.Contains("Personnel"), "DataTable 'Personnel' should exist");
                Assert.IsTrue(result.Tables["Personnel"].Rows.Count > 0, "DataTable 'Personnel' should have at least one row");

                // Get the last added row
                DataRow row = result.Tables["Personnel"].Rows[result.Tables["Personnel"].Rows.Count - 1];

                // Construct the result string from the data row
                resultString = row["Prenom_perso"].ToString() + row["Nom_perso"].ToString() + row["Date_Naissance_perso"].ToString() + row["Date_embauche"].ToString() + row["ID_SupH"].ToString() + row["ID_adresse"].ToString();

                // Construct the expected string
                var expectedString = prenom + nom + dateNaissance.ToString() + dateEmbauche.ToString() + idSupH.ToString() + idAdresse.ToString();

                // Log the result and expected strings for debugging
                Console.WriteLine("Result String: " + resultString);
                Console.WriteLine("Expected String: " + expectedString);

                // Assert
                Assert.That(resultString, Is.EqualTo(expectedString));
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception occurred: " + ex.Message);
                throw;
            }
        }

        [Test]
        public void ModifierPersonnel()
        {
            Console.WriteLine("Test Start: ModifierPersonnel");

            // Assign
            var nom = "JeanDav";
            var prenom = "David";
            var dateNaissance = new DateTime(1990, 5, 10);
            var dateEmbauche = new DateTime(2024, 5, 25);
            int idSupH = 1;
            int idAdresse = 2;

            Personnel.ajouter(nom, prenom, dateNaissance, dateEmbauche, idSupH, idAdresse);

            DataSet result = Personnel.listePersonnels("Personnel");
            DataRow row = result.Tables["Personnel"].Rows[result.Tables["Personnel"].Rows.Count - 1];
            int id = Convert.ToInt32(row["ID_perso"]);

            // New values for modification
            var newNom = "Doe";
            var newPrenom = "John";
            var newDateNaissance = new DateTime(1985, 1, 1);
            var newDateEmbauche = new DateTime(2023, 1, 1);

            // Act
            Personnel.modifier(id, newNom, newPrenom, newDateNaissance, newDateEmbauche, idSupH, idAdresse);

            result = Personnel.listePersonnels("Personnel");
            row = result.Tables["Personnel"].Rows[result.Tables["Personnel"].Rows.Count - 1];

            var resultString = row["Prenom_perso"].ToString() + row["Nom_perso"].ToString() + row["Date_Naissance_perso"].ToString() + row["Date_embauche"].ToString() + row["ID_SupH"].ToString() + row["ID_adresse"].ToString();
            var expectedString = newPrenom + newNom + newDateNaissance.ToString() + newDateEmbauche.ToString() + idSupH.ToString() + idAdresse.ToString();

            // Log the result and expected strings for debugging
            Console.WriteLine("Result String: " + resultString);
            Console.WriteLine("Expected String: " + expectedString);

            // Assert
            Assert.That(resultString, Is.EqualTo(expectedString));
        }

        [Test]
        public void SupprimerPersonnel()
        {
            Console.WriteLine("Test Start: SupprimerPersonnel");

            // Assign
            var nom = "JeanDav";
            var prenom = "David";
            var dateNaissance = new DateTime(1990, 5, 10);
            var dateEmbauche = new DateTime(2024, 5, 25);
            int idSupH = 1;
            int idAdresse = 2;

            // Add personnel
            Personnel.ajouter(nom, prenom, dateNaissance, dateEmbauche, idSupH, idAdresse);

            // Retrieve the list of personnel
            DataSet resultBeforeDeletion = Personnel.listePersonnels("Personnel");
            Assert.IsNotNull(resultBeforeDeletion, "DataSet should not be null");
            Assert.IsTrue(resultBeforeDeletion.Tables.Contains("Personnel"), "DataTable 'Personnel' should exist");
            Assert.IsTrue(resultBeforeDeletion.Tables["Personnel"].Rows.Count > 0, "DataTable 'Personnel' should have at least one row");

            // Get the ID of the last added row
            DataRow row = resultBeforeDeletion.Tables["Personnel"].Rows[resultBeforeDeletion.Tables["Personnel"].Rows.Count - 1];
            int id = Convert.ToInt32(row["ID_perso"]);

            // Act - Delete the added personnel
            Personnel.supprimer(id);

            // Retrieve the list of personnel after deletion
            DataSet resultAfterDeletion = Personnel.listePersonnels("Personnel");

            // Assert
            bool isDeleted = true;

            // Check if the deleted user is still present in the DataTable
            foreach (DataRow newRow in resultAfterDeletion.Tables["Personnel"].Rows)
            {
                if (Convert.ToInt32(newRow["ID_perso"]) == id)
                {
                    isDeleted = false;
                    break;
                }
            }

            Assert.IsTrue(isDeleted, "Personnel with ID " + id + " should be deleted from the DataTable");
        }


    }
}

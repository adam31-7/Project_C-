#pragma once
#include "mappStats.h"
#include "CAD.h"
#include "mappTableCommande.h"
#include "mappTableArticle.h"
#include "mappTableClient.h"
#include "mappTableAdresse.h"
#include "mappTableArticleCommande.h"
#include "gestionStats.h"

namespace ProjetPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Data::SqlClient;
	using namespace System::Xml;
	using namespace System::Text;

	/// <summary>
	/// Description résumée de PageStats
	/// </summary>
	public ref class PageStats : public System::Windows::Forms::Form
	{
	public:
		PageStats(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~PageStats()
		{
			if (components)
			{
				delete components;
			}
		}










	private: System::Windows::Forms::Label^ label3;






	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;




	private: System::Windows::Forms::Label^ label6;







	private: System::Windows::Forms::Label^ label10;





	private: System::Windows::Forms::TextBox^ txt_CA;
	private: System::Windows::Forms::TextBox^ txt_ID_Client;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonID;
	private: System::Windows::Forms::DataGridView^ dgv_meilleur_art;
	private: System::Windows::Forms::DataGridView^ dgv_pire_art;
	private: System::Windows::Forms::Button^ afficherMeilleur;
	private: System::Windows::Forms::Button^ AfficherPire;

	private: DataSet^ dsMeilleurArt;
	private: DataSet^ dsPireArt;
	private: DataSet^ MontantTotal;
	private: DataSet^ ChiffreAffaire;


	private: NS_SVC::gestionStats^ Stats;
	private: System::Windows::Forms::DataGridView^ dgv_client;



















	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txt_CA = (gcnew System::Windows::Forms::TextBox());
			this->txt_ID_Client = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonID = (gcnew System::Windows::Forms::Button());
			this->dgv_meilleur_art = (gcnew System::Windows::Forms::DataGridView());
			this->dgv_pire_art = (gcnew System::Windows::Forms::DataGridView());
			this->afficherMeilleur = (gcnew System::Windows::Forms::Button());
			this->AfficherPire = (gcnew System::Windows::Forms::Button());
			this->dgv_client = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_meilleur_art))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_pire_art))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_client))->BeginInit();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(347, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(181, 36);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Statistiques";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(82, 109);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(205, 20);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Nos 10 meilleurs articles :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(555, 109);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(174, 20);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Nos 10 pires articles :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(2, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(297, 20);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Chiffre d\'Affaire actuel de l\'entreprise :";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(12, 338);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(126, 20);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Entrer ID_client";
			this->label10->Click += gcnew System::EventHandler(this, &PageStats::label10_Click);
			// 
			// txt_CA
			// 
			this->txt_CA->Location = System::Drawing::Point(305, 63);
			this->txt_CA->Name = L"txt_CA";
			this->txt_CA->Size = System::Drawing::Size(204, 22);
			this->txt_CA->TabIndex = 26;
			this->txt_CA->TextChanged += gcnew System::EventHandler(this, &PageStats::txt_CA_TextChanged);
			// 
			// txt_ID_Client
			// 
			this->txt_ID_Client->Location = System::Drawing::Point(144, 338);
			this->txt_ID_Client->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_ID_Client->Name = L"txt_ID_Client";
			this->txt_ID_Client->Size = System::Drawing::Size(175, 22);
			this->txt_ID_Client->TabIndex = 27;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 372);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(551, 20);
			this->label1->TabIndex = 28;
			this->label1->Text = L"Information sur le client et le montant total des achats associé au client :";
			// 
			// buttonID
			// 
			this->buttonID->Location = System::Drawing::Point(325, 336);
			this->buttonID->Name = L"buttonID";
			this->buttonID->Size = System::Drawing::Size(89, 27);
			this->buttonID->TabIndex = 29;
			this->buttonID->Text = L"Vailder";
			this->buttonID->UseVisualStyleBackColor = true;
			// 
			// dgv_meilleur_art
			// 
			this->dgv_meilleur_art->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_meilleur_art->Location = System::Drawing::Point(6, 132);
			this->dgv_meilleur_art->Name = L"dgv_meilleur_art";
			this->dgv_meilleur_art->RowHeadersWidth = 51;
			this->dgv_meilleur_art->RowTemplate->Height = 24;
			this->dgv_meilleur_art->Size = System::Drawing::Size(372, 150);
			this->dgv_meilleur_art->TabIndex = 30;
			// 
			// dgv_pire_art
			// 
			this->dgv_pire_art->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_pire_art->Location = System::Drawing::Point(447, 132);
			this->dgv_pire_art->Name = L"dgv_pire_art";
			this->dgv_pire_art->RowHeadersWidth = 51;
			this->dgv_pire_art->RowTemplate->Height = 24;
			this->dgv_pire_art->Size = System::Drawing::Size(372, 150);
			this->dgv_pire_art->TabIndex = 31;
			// 
			// afficherMeilleur
			// 
			this->afficherMeilleur->Location = System::Drawing::Point(283, 288);
			this->afficherMeilleur->Name = L"afficherMeilleur";
			this->afficherMeilleur->Size = System::Drawing::Size(95, 27);
			this->afficherMeilleur->TabIndex = 32;
			this->afficherMeilleur->Text = L"Afficher";
			this->afficherMeilleur->UseVisualStyleBackColor = true;
			this->afficherMeilleur->Click += gcnew System::EventHandler(this, &PageStats::afficher1);
			// 
			// AfficherPire
			// 
			this->AfficherPire->Location = System::Drawing::Point(724, 288);
			this->AfficherPire->Name = L"AfficherPire";
			this->AfficherPire->Size = System::Drawing::Size(95, 27);
			this->AfficherPire->TabIndex = 33;
			this->AfficherPire->Text = L"Afficher";
			this->AfficherPire->UseVisualStyleBackColor = true;
			this->AfficherPire->Click += gcnew System::EventHandler(this, &PageStats::afficher2);
			// 
			// dgv_client
			// 
			this->dgv_client->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_client->Location = System::Drawing::Point(6, 395);
			this->dgv_client->Name = L"dgv_client";
			this->dgv_client->RowHeadersWidth = 51;
			this->dgv_client->RowTemplate->Height = 24;
			this->dgv_client->Size = System::Drawing::Size(813, 70);
			this->dgv_client->TabIndex = 34;
			// 
			// PageStats
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(843, 489);
			this->Controls->Add(this->dgv_client);
			this->Controls->Add(this->AfficherPire);
			this->Controls->Add(this->afficherMeilleur);
			this->Controls->Add(this->dgv_pire_art);
			this->Controls->Add(this->dgv_meilleur_art);
			this->Controls->Add(this->buttonID);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_ID_Client);
			this->Controls->Add(this->txt_CA);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximumSize = System::Drawing::Size(927, 536);
			this->MinimumSize = System::Drawing::Size(861, 536);
			this->Name = L"PageStats";
			this->Load += gcnew System::EventHandler(this, &PageStats::PageStats_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_meilleur_art))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_pire_art))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_client))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RETOUR_Click(System::Object^ sender, System::EventArgs^ e) {

	};

		   void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		   {}

	private: System::Void PageStats_Load(System::Object^ sender, System::EventArgs^ e) {
		refresh();


	}
	private: System::Void ProduitsSousSeuil_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: void refresh(void) {
		NS_Composants::mappStats^ stats;
		this->txt_CA->Text = System::Convert::ToString(this->Stats->CA("ChiffreAffaireEntreprise"));
	}

	private: System::Void txt_CA_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void button_ID(System::Object^ sender, System::EventArgs^ e) {
		String^ ID = txt_ID_Client->Text;
		NS_Composants::mappStats^ stats;
		stats->setID(Convert::ToInt32(ID));
		this->MontantTotal = this->Stats->Montant("MontantDuClient");
		this->dgv_client->DataSource = this->MontantTotal;
	}

	private: System::Void afficher1(System::Object^ sender, System::EventArgs^ e) {
		NS_Composants::mappStats^ stats;
		this->dsMeilleurArt = this->Stats->listeArticlePV("Article");
		this->dgv_meilleur_art->DataSource = this->dsMeilleurArt;
	}

	private: System::Void afficher2(System::Object^ sender, System::EventArgs^ e) {
		NS_Composants::mappStats^ stats;
		this->dgv_meilleur_art->DataSource = this->dsPireArt;
		this->dsPireArt = this->Stats->listeArticleMV("Article");
	}

private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

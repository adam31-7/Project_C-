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





	private: System::Windows::Forms::Label^ label6;







	private: System::Windows::Forms::Label^ label10;





	private: System::Windows::Forms::TextBox^ txt_CA;
	private: System::Windows::Forms::TextBox^ txt_ID_Client;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btn_valider;

	private: System::Windows::Forms::DataGridView^ dgv_meilleur_art;
	private: System::Windows::Forms::DataGridView^ dgv_pire_art;
	private: System::Windows::Forms::Button^ afficherMeilleur;
	private: System::Windows::Forms::Button^ AfficherPire;

	private: DataSet^ dsMeilleurArt;
	private: DataSet^ dsPireArt;
	private: DataSet^ dsMontantTotal;
	private: DataSet^ ChiffreAffaire;


	private: NS_SVC::gestionStats^ Stats;
	private: System::Windows::Forms::DataGridView^ dgv_client;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txt_meilleurs;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txt_pires;

	private: System::Windows::Forms::Label^ label9;



















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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txt_CA = (gcnew System::Windows::Forms::TextBox());
			this->txt_ID_Client = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_valider = (gcnew System::Windows::Forms::Button());
			this->dgv_meilleur_art = (gcnew System::Windows::Forms::DataGridView());
			this->dgv_pire_art = (gcnew System::Windows::Forms::DataGridView());
			this->afficherMeilleur = (gcnew System::Windows::Forms::Button());
			this->AfficherPire = (gcnew System::Windows::Forms::Button());
			this->dgv_client = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_meilleurs = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txt_pires = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_meilleur_art))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_pire_art))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_client))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(739, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(215, 40);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Statistiques";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(17, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 25);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Nos";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(18, 82);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(339, 25);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Chiffre d\'Affaire actuel de l\'entreprise :";
			// 
			// label10
			// 
			this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(18, 542);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(144, 25);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Entrer ID_client";
			// 
			// txt_CA
			// 
			this->txt_CA->Location = System::Drawing::Point(397, 82);
			this->txt_CA->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_CA->Name = L"txt_CA";
			this->txt_CA->ReadOnly = true;
			this->txt_CA->Size = System::Drawing::Size(229, 26);
			this->txt_CA->TabIndex = 26;
			// 
			// txt_ID_Client
			// 
			this->txt_ID_Client->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->txt_ID_Client->Location = System::Drawing::Point(195, 541);
			this->txt_ID_Client->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_ID_Client->Name = L"txt_ID_Client";
			this->txt_ID_Client->Size = System::Drawing::Size(196, 26);
			this->txt_ID_Client->TabIndex = 27;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(18, 583);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(627, 25);
			this->label1->TabIndex = 28;
			this->label1->Text = L"Information sur le client et le montant total des achats associé au client :";
			// 
			// btn_valider
			// 
			this->btn_valider->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_valider->Location = System::Drawing::Point(398, 540);
			this->btn_valider->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_valider->Name = L"btn_valider";
			this->btn_valider->Size = System::Drawing::Size(100, 34);
			this->btn_valider->TabIndex = 29;
			this->btn_valider->Text = L"Vailder";
			this->btn_valider->UseVisualStyleBackColor = true;
			this->btn_valider->Click += gcnew System::EventHandler(this, &PageStats::btn_valider_Click);
			// 
			// dgv_meilleur_art
			// 
			this->dgv_meilleur_art->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dgv_meilleur_art->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgv_meilleur_art->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_meilleur_art->Location = System::Drawing::Point(21, 165);
			this->dgv_meilleur_art->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgv_meilleur_art->Name = L"dgv_meilleur_art";
			this->dgv_meilleur_art->RowHeadersWidth = 51;
			this->dgv_meilleur_art->RowTemplate->Height = 24;
			this->dgv_meilleur_art->Size = System::Drawing::Size(770, 318);
			this->dgv_meilleur_art->TabIndex = 30;
			// 
			// dgv_pire_art
			// 
			this->dgv_pire_art->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgv_pire_art->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgv_pire_art->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_pire_art->Location = System::Drawing::Point(860, 165);
			this->dgv_pire_art->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgv_pire_art->Name = L"dgv_pire_art";
			this->dgv_pire_art->RowHeadersWidth = 51;
			this->dgv_pire_art->RowTemplate->Height = 24;
			this->dgv_pire_art->Size = System::Drawing::Size(775, 318);
			this->dgv_pire_art->TabIndex = 31;
			// 
			// afficherMeilleur
			// 
			this->afficherMeilleur->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->afficherMeilleur->Location = System::Drawing::Point(684, 487);
			this->afficherMeilleur->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->afficherMeilleur->Name = L"afficherMeilleur";
			this->afficherMeilleur->Size = System::Drawing::Size(107, 34);
			this->afficherMeilleur->TabIndex = 32;
			this->afficherMeilleur->Text = L"Afficher";
			this->afficherMeilleur->UseVisualStyleBackColor = true;
			this->afficherMeilleur->Click += gcnew System::EventHandler(this, &PageStats::afficher1);
			// 
			// AfficherPire
			// 
			this->AfficherPire->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->AfficherPire->Location = System::Drawing::Point(860, 487);
			this->AfficherPire->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AfficherPire->Name = L"AfficherPire";
			this->AfficherPire->Size = System::Drawing::Size(107, 34);
			this->AfficherPire->TabIndex = 33;
			this->AfficherPire->Text = L"Afficher";
			this->AfficherPire->UseVisualStyleBackColor = true;
			this->AfficherPire->Click += gcnew System::EventHandler(this, &PageStats::afficher2);
			// 
			// dgv_client
			// 
			this->dgv_client->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgv_client->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dgv_client->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_client->Location = System::Drawing::Point(13, 610);
			this->dgv_client->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgv_client->Name = L"dgv_client";
			this->dgv_client->RowHeadersWidth = 51;
			this->dgv_client->RowTemplate->Height = 24;
			this->dgv_client->Size = System::Drawing::Size(1623, 177);
			this->dgv_client->TabIndex = 34;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(-57, -38);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1729, 100);
			this->panel1->TabIndex = 35;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(687, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(467, 46);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Statistiques de l\'entreprise";
			// 
			// txt_meilleurs
			// 
			this->txt_meilleurs->Location = System::Drawing::Point(70, 134);
			this->txt_meilleurs->Name = L"txt_meilleurs";
			this->txt_meilleurs->Size = System::Drawing::Size(127, 26);
			this->txt_meilleurs->TabIndex = 36;
			this->txt_meilleurs->Text = L"10";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(203, 133);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(166, 25);
			this->label7->TabIndex = 37;
			this->label7->Text = L"meilleurs articles :";
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(1504, 133);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(131, 25);
			this->label8->TabIndex = 40;
			this->label8->Text = L"pires articles :";
			// 
			// txt_pires
			// 
			this->txt_pires->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txt_pires->Location = System::Drawing::Point(1371, 134);
			this->txt_pires->Name = L"txt_pires";
			this->txt_pires->Size = System::Drawing::Size(127, 26);
			this->txt_pires->TabIndex = 39;
			this->txt_pires->Text = L"10";
			// 
			// label9
			// 
			this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(1318, 135);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(47, 25);
			this->label9->TabIndex = 38;
			this->label9->Text = L"Nos";
			// 
			// PageStats
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1647, 798);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->txt_pires);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->txt_meilleurs);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dgv_client);
			this->Controls->Add(this->AfficherPire);
			this->Controls->Add(this->afficherMeilleur);
			this->Controls->Add(this->dgv_pire_art);
			this->Controls->Add(this->dgv_meilleur_art);
			this->Controls->Add(this->btn_valider);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_ID_Client);
			this->Controls->Add(this->txt_CA);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"PageStats";
			this->Load += gcnew System::EventHandler(this, &PageStats::PageStats_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_meilleur_art))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_pire_art))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_client))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void PageStats_Load(System::Object^ sender, System::EventArgs^ e) {
		refresh();
	}


	private: void refresh(void) {
		Stats = gcnew NS_SVC::gestionStats();
		this->txt_CA->Text = System::Convert::ToString(this->Stats->CA());
	}

	private: System::Void afficher1(System::Object^ sender, System::EventArgs^ e) {
		Stats = gcnew NS_SVC::gestionStats();
		this->dsMeilleurArt = this->Stats->listeArticlePV(Convert::ToInt32(this->txt_meilleurs->Text),"PlusVendus");
		this->dgv_meilleur_art->DataSource = this->dsMeilleurArt;
		this->dgv_meilleur_art->DataMember = "PlusVendus";
		refresh();
	}

	private: System::Void afficher2(System::Object^ sender, System::EventArgs^ e) {
		Stats = gcnew NS_SVC::gestionStats();
		this->dsPireArt = this->Stats->listeArticleMV(Convert::ToInt32(this->txt_pires->Text),"MoinsVendus");
		this->dgv_pire_art->DataSource = this->dsPireArt;
		this->dgv_pire_art->DataMember = "MoinsVendus";
		refresh();
	}
	private: System::Void btn_valider_Click(System::Object^ sender, System::EventArgs^ e) {
		Stats = gcnew NS_SVC::gestionStats();
		int ID = Convert::ToInt32(txt_ID_Client->Text);
		this->dsMontantTotal = this->Stats->Montant(ID, "MontantDuClient");
		this->dgv_client->DataSource = this->dsMontantTotal;
		this->dgv_client->DataMember = "MontantDuClient";
		refresh();
	}
};
}

#pragma once
#include "PageClient.h"
#include "PageStats.h"
#include "PageCommande.h"
#include "PagePersonnel.h"

namespace ProjetPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
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
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ bouton_page_clients;
	protected:

	private: System::Windows::Forms::Button^ bouton_page_statistiques;
	private: System::Windows::Forms::Button^ bouton_page_commande;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;



	protected:

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->bouton_page_clients = (gcnew System::Windows::Forms::Button());
			this->bouton_page_statistiques = (gcnew System::Windows::Forms::Button());
			this->bouton_page_commande = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// bouton_page_clients
			// 
			this->bouton_page_clients->Location = System::Drawing::Point(59, 86);
			this->bouton_page_clients->Margin = System::Windows::Forms::Padding(2);
			this->bouton_page_clients->Name = L"bouton_page_clients";
			this->bouton_page_clients->Size = System::Drawing::Size(143, 38);
			this->bouton_page_clients->TabIndex = 0;
			this->bouton_page_clients->Text = L"Gestion Client";
			this->bouton_page_clients->UseVisualStyleBackColor = true;
			this->bouton_page_clients->Click += gcnew System::EventHandler(this, &Main::bouton_page_clients_Click);
			// 
			// bouton_page_statistiques
			// 
			this->bouton_page_statistiques->Location = System::Drawing::Point(59, 160);
			this->bouton_page_statistiques->Margin = System::Windows::Forms::Padding(2);
			this->bouton_page_statistiques->Name = L"bouton_page_statistiques";
			this->bouton_page_statistiques->Size = System::Drawing::Size(465, 38);
			this->bouton_page_statistiques->TabIndex = 1;
			this->bouton_page_statistiques->Text = L"Statistiques de l\'entreprise";
			this->bouton_page_statistiques->UseVisualStyleBackColor = true;
			this->bouton_page_statistiques->Click += gcnew System::EventHandler(this, &Main::bouton_page_statistiques_Click);
			// 
			// bouton_page_commande
			// 
			this->bouton_page_commande->Location = System::Drawing::Point(207, 86);
			this->bouton_page_commande->Name = L"bouton_page_commande";
			this->bouton_page_commande->Size = System::Drawing::Size(166, 38);
			this->bouton_page_commande->TabIndex = 2;
			this->bouton_page_commande->Text = L"Gestion Commandes";
			this->bouton_page_commande->UseVisualStyleBackColor = true;
			this->bouton_page_commande->Click += gcnew System::EventHandler(this, &Main::bouton_page_commande_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(379, 86);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 38);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Gestion Personnel";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(6, 59);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(562, 12);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(6, 137);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(562, 12);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(174, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 48);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Bienvenue";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(574, 299);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->bouton_page_commande);
			this->Controls->Add(this->bouton_page_statistiques);
			this->Controls->Add(this->bouton_page_clients);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Main";
			this->Text = L"Main";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bouton_page_clients_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjetPOO::PageClient page_client;
		page_client.ShowDialog();
	}
	private: System::Void bouton_page_statistiques_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjetPOO::PageStats page_stats;
		page_stats.ShowDialog();
	}
	private: System::Void bouton_page_commande_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjetPOO::PageCommande page_commande;
		page_commande.ShowDialog();
	}

	private: System::Void bouton_page_personnel(System::Object^ sender, System::EventArgs^ e) {
		ProjetPOO::PagePersonnel page_personnel;
		page_personnel.ShowDialog();
	}
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

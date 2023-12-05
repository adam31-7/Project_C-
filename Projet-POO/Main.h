#pragma once
#include "PageClient.h"
#include "PageStats.h"
#include "PageCommande.h"

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
	private: System::Windows::Forms::Button^ bouton_commandes;
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
			this->bouton_page_clients = (gcnew System::Windows::Forms::Button());
			this->bouton_page_statistiques = (gcnew System::Windows::Forms::Button());
			this->bouton_commandes = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bouton_page_clients
			// 
			this->bouton_page_clients->Location = System::Drawing::Point(89, 61);
			this->bouton_page_clients->Name = L"bouton_page_clients";
			this->bouton_page_clients->Size = System::Drawing::Size(214, 60);
			this->bouton_page_clients->TabIndex = 0;
			this->bouton_page_clients->Text = L"Gestion Client";
			this->bouton_page_clients->UseVisualStyleBackColor = true;
			this->bouton_page_clients->Click += gcnew System::EventHandler(this, &Main::bouton_page_clients_Click);
			// 
			// bouton_page_statistiques
			// 
			this->bouton_page_statistiques->Location = System::Drawing::Point(89, 127);
			this->bouton_page_statistiques->Name = L"bouton_page_statistiques";
			this->bouton_page_statistiques->Size = System::Drawing::Size(214, 59);
			this->bouton_page_statistiques->TabIndex = 1;
			this->bouton_page_statistiques->Text = L"Statistiques";
			this->bouton_page_statistiques->UseVisualStyleBackColor = true;
			this->bouton_page_statistiques->Click += gcnew System::EventHandler(this, &Main::bouton_page_statistiques_Click);
			// 
			// bouton_commandes
			// 
			this->bouton_commandes->Location = System::Drawing::Point(89, 192);
			this->bouton_commandes->Name = L"bouton_commandes";
			this->bouton_commandes->Size = System::Drawing::Size(214, 59);
			this->bouton_commandes->TabIndex = 2;
			this->bouton_commandes->Text = L"Commandes";
			this->bouton_commandes->UseVisualStyleBackColor = true;
			this->bouton_commandes->Click += gcnew System::EventHandler(this, &Main::bouton_commandes_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(858, 365);
			this->Controls->Add(this->bouton_commandes);
			this->Controls->Add(this->bouton_page_statistiques);
			this->Controls->Add(this->bouton_page_clients);
			this->Name = L"Main";
			this->Text = L"Main";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->ResumeLayout(false);

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
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void bouton_commandes_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjetPOO::PageCommande page_commandes;
		page_commandes.ShowDialog();
	}
};
}

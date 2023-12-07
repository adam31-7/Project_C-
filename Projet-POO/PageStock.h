#pragma once
#include "CAD.h";
#include "mappTableClient.h"
#include "gestionArticle.h"
#include <iostream>

namespace ProjetPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de PageStock
	/// </summary>
	public ref class PageStock : public System::Windows::Forms::Form
	{
	public:
		PageStock(void)
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
		~PageStock()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgv_articles;
	private: System::Windows::Forms::Button^ btn_ajouter;
	private: System::Windows::Forms::Button^ btn_enregistrer;

	private: NS_SVC::gestionArticle^ gestionArticle;

	private: DataSet^ dsArticle;
	private: System::Windows::Forms::TextBox^ txt_message;
	private: System::Windows::Forms::Label^ lbl_message;



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
			this->dgv_articles = (gcnew System::Windows::Forms::DataGridView());
			this->btn_ajouter = (gcnew System::Windows::Forms::Button());
			this->btn_enregistrer = (gcnew System::Windows::Forms::Button());
			this->txt_message = (gcnew System::Windows::Forms::TextBox());
			this->lbl_message = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_articles))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv_articles
			// 
			this->dgv_articles->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgv_articles->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_articles->Location = System::Drawing::Point(51, 38);
			this->dgv_articles->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dgv_articles->Name = L"dgv_articles";
			this->dgv_articles->RowHeadersWidth = 62;
			this->dgv_articles->RowTemplate->Height = 28;
			this->dgv_articles->Size = System::Drawing::Size(677, 309);
			this->dgv_articles->TabIndex = 0;
			// 
			// btn_ajouter
			// 
			this->btn_ajouter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btn_ajouter->Location = System::Drawing::Point(394, 440);
			this->btn_ajouter->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_ajouter->Name = L"btn_ajouter";
			this->btn_ajouter->Size = System::Drawing::Size(155, 49);
			this->btn_ajouter->TabIndex = 1;
			this->btn_ajouter->Text = L"Nouvel article";
			this->btn_ajouter->UseVisualStyleBackColor = true;
			this->btn_ajouter->Click += gcnew System::EventHandler(this, &PageStock::btn_ajouter_Click);
			// 
			// btn_enregistrer
			// 
			this->btn_enregistrer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btn_enregistrer->Location = System::Drawing::Point(573, 440);
			this->btn_enregistrer->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_enregistrer->Name = L"btn_enregistrer";
			this->btn_enregistrer->Size = System::Drawing::Size(155, 49);
			this->btn_enregistrer->TabIndex = 2;
			this->btn_enregistrer->Text = L"Enregistrer";
			this->btn_enregistrer->UseVisualStyleBackColor = true;
			this->btn_enregistrer->Click += gcnew System::EventHandler(this, &PageStock::btn_enregistrer_Click);
			// 
			// txt_message
			// 
			this->txt_message->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txt_message->Location = System::Drawing::Point(51, 443);
			this->txt_message->Multiline = true;
			this->txt_message->Name = L"txt_message";
			this->txt_message->Size = System::Drawing::Size(311, 48);
			this->txt_message->TabIndex = 19;
			// 
			// lbl_message
			// 
			this->lbl_message->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lbl_message->AutoSize = true;
			this->lbl_message->Location = System::Drawing::Point(48, 427);
			this->lbl_message->Name = L"lbl_message";
			this->lbl_message->Size = System::Drawing::Size(50, 13);
			this->lbl_message->TabIndex = 18;
			this->lbl_message->Text = L"Message";
			// 
			// PageStock
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(779, 499);
			this->Controls->Add(this->txt_message);
			this->Controls->Add(this->lbl_message);
			this->Controls->Add(this->btn_enregistrer);
			this->Controls->Add(this->btn_ajouter);
			this->Controls->Add(this->dgv_articles);
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"PageStock";
			this->Text = L"PageStock";
			this->Load += gcnew System::EventHandler(this, &PageStock::PageStock_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_articles))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void PageStock_Load(System::Object^ sender, System::EventArgs^ e) {
		this->gestionArticle = gcnew NS_SVC::gestionArticle();
		this->refresh();
	}
	private: System::Void btn_ajouter_Click(System::Object^ sender, System::EventArgs^ e) {

		this->gestionArticle = gcnew NS_SVC::gestionArticle();

		array<String^>^ infoArticle = gcnew array<String^>(dgv_articles->ColumnCount);

		for (int i = 0; i < dgv_articles->ColumnCount; i++)
		{
			infoArticle[i] = Convert::ToString(dgv_articles[i, dgv_articles->RowCount - 2]->Value);
		}

		gestionArticle->ajouter(infoArticle);

		refresh();
		this->txt_message->Text = "Ajout effectué";
	}
	private: void refresh(void)
		{
			this->dsArticle = this->gestionArticle->listeArticles("Articles");
			this->dgv_articles->DataSource = this->dsArticle;
			this->dgv_articles->DataMember = "Articles";
		}
	private: System::Void btn_enregistrer_Click(System::Object^ sender, System::EventArgs^ e) {
		array<String^>^ infoArticle = gcnew array<String^>(dgv_articles->ColumnCount);
		for (int i = 0; i < dgv_articles->RowCount-1; i++)
		{
			this->gestionArticle = gcnew NS_SVC::gestionArticle();
			for (int j = 0; j < dgv_articles->ColumnCount; j++)
			{
				infoArticle[j] = Convert::ToString(dgv_articles[j, i]->Value);
			}
			gestionArticle->modifier(infoArticle);
		}
		refresh();
		this->txt_message->Text = "Enregistrement effectué";
	}
};
}

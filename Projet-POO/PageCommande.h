#pragma once
#include "CAD.h"
#include "mappTableCommande.h"
#include "mappTableArticle.h"
#include "mappTableClient.h"
#include "mappTableAdresse.h"
#include "mappTableArticleCommande.h"
#include "gestionCommandes.h"

namespace ProjetPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de PageCommande
	/// </summary>
	public ref class PageCommande : public System::Windows::Forms::Form
	{
	public:
		PageCommande(void)
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
		~PageCommande()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ DebugBox;
	protected:
	private: System::Windows::Forms::TextBox^ debugText;
	private: System::Windows::Forms::TextBox^ txt_message;
	private: System::Windows::Forms::Label^ lbl_message;
	private: System::Windows::Forms::Button^ btn_enr;
	private: System::Windows::Forms::Button^ btn_sup;
	private: System::Windows::Forms::Button^ btn_maj;
	private: System::Windows::Forms::Button^ btn_nouveau;
	private: System::Windows::Forms::Label^ lbl_commandes;

	private: System::Windows::Forms::DataGridView^ dgv_commandes;
	private: System::Windows::Forms::Button^ btn_next;
	private: System::Windows::Forms::Button^ btn_last;



	private: System::Windows::Forms::Button^ btn_previous;
	private: System::Windows::Forms::Label^ lbl_ref;
	private: System::Windows::Forms::TextBox^ txt_ref;
	private: System::Windows::Forms::Button^ btn_first;
	private: System::Windows::Forms::DataGridView^ dgv_articles;
	private: System::Windows::Forms::Label^ label1;

	private: NS_SVC::gestionCommandes^ gestionCommandes;
	private: DataSet^ dsCommande;
	private: DataSet^ dsCommandeArticles;
	private: int rowsCount;
	private: int index;

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
			this->DebugBox = (gcnew System::Windows::Forms::Label());
			this->debugText = (gcnew System::Windows::Forms::TextBox());
			this->txt_message = (gcnew System::Windows::Forms::TextBox());
			this->lbl_message = (gcnew System::Windows::Forms::Label());
			this->btn_enr = (gcnew System::Windows::Forms::Button());
			this->btn_sup = (gcnew System::Windows::Forms::Button());
			this->btn_maj = (gcnew System::Windows::Forms::Button());
			this->btn_nouveau = (gcnew System::Windows::Forms::Button());
			this->lbl_commandes = (gcnew System::Windows::Forms::Label());
			this->dgv_commandes = (gcnew System::Windows::Forms::DataGridView());
			this->btn_next = (gcnew System::Windows::Forms::Button());
			this->btn_last = (gcnew System::Windows::Forms::Button());
			this->btn_previous = (gcnew System::Windows::Forms::Button());
			this->lbl_ref = (gcnew System::Windows::Forms::Label());
			this->txt_ref = (gcnew System::Windows::Forms::TextBox());
			this->btn_first = (gcnew System::Windows::Forms::Button());
			this->dgv_articles = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_commandes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_articles))->BeginInit();
			this->SuspendLayout();
			// 
			// DebugBox
			// 
			this->DebugBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->DebugBox->AutoSize = true;
			this->DebugBox->Location = System::Drawing::Point(1793, 855);
			this->DebugBox->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->DebugBox->Name = L"DebugBox";
			this->DebugBox->Size = System::Drawing::Size(87, 25);
			this->DebugBox->TabIndex = 39;
			this->DebugBox->Text = L"Debug :";
			// 
			// debugText
			// 
			this->debugText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->debugText->Location = System::Drawing::Point(1896, 849);
			this->debugText->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->debugText->Name = L"debugText";
			this->debugText->Size = System::Drawing::Size(216, 31);
			this->debugText->TabIndex = 38;
			// 
			// txt_message
			// 
			this->txt_message->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txt_message->Location = System::Drawing::Point(55, 899);
			this->txt_message->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->txt_message->Multiline = true;
			this->txt_message->Name = L"txt_message";
			this->txt_message->Size = System::Drawing::Size(2057, 89);
			this->txt_message->TabIndex = 37;
			// 
			// lbl_message
			// 
			this->lbl_message->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_message->AutoSize = true;
			this->lbl_message->Location = System::Drawing::Point(48, 869);
			this->lbl_message->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->lbl_message->Name = L"lbl_message";
			this->lbl_message->Size = System::Drawing::Size(100, 25);
			this->lbl_message->TabIndex = 36;
			this->lbl_message->Text = L"Message";
			// 
			// btn_enr
			// 
			this->btn_enr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btn_enr->Location = System::Drawing::Point(1526, 836);
			this->btn_enr->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->btn_enr->Name = L"btn_enr";
			this->btn_enr->Size = System::Drawing::Size(172, 44);
			this->btn_enr->TabIndex = 35;
			this->btn_enr->Text = L"Enregistrer";
			this->btn_enr->UseVisualStyleBackColor = true;
			// 
			// btn_sup
			// 
			this->btn_sup->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btn_sup->Location = System::Drawing::Point(1344, 836);
			this->btn_sup->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->btn_sup->Name = L"btn_sup";
			this->btn_sup->Size = System::Drawing::Size(172, 44);
			this->btn_sup->TabIndex = 34;
			this->btn_sup->Text = L"Supprimer";
			this->btn_sup->UseVisualStyleBackColor = true;
			// 
			// btn_maj
			// 
			this->btn_maj->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btn_maj->Location = System::Drawing::Point(1162, 836);
			this->btn_maj->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->btn_maj->Name = L"btn_maj";
			this->btn_maj->Size = System::Drawing::Size(172, 44);
			this->btn_maj->TabIndex = 33;
			this->btn_maj->Text = L"Mise à jour";
			this->btn_maj->UseVisualStyleBackColor = true;
			// 
			// btn_nouveau
			// 
			this->btn_nouveau->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btn_nouveau->Location = System::Drawing::Point(978, 836);
			this->btn_nouveau->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->btn_nouveau->Name = L"btn_nouveau";
			this->btn_nouveau->Size = System::Drawing::Size(172, 44);
			this->btn_nouveau->TabIndex = 32;
			this->btn_nouveau->Text = L"Nouveau";
			this->btn_nouveau->UseVisualStyleBackColor = true;
			// 
			// lbl_commandes
			// 
			this->lbl_commandes->AutoSize = true;
			this->lbl_commandes->Location = System::Drawing::Point(14, 9);
			this->lbl_commandes->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->lbl_commandes->Name = L"lbl_commandes";
			this->lbl_commandes->Size = System::Drawing::Size(132, 25);
			this->lbl_commandes->TabIndex = 31;
			this->lbl_commandes->Text = L"Commandes";
			// 
			// dgv_commandes
			// 
			this->dgv_commandes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dgv_commandes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_commandes->Location = System::Drawing::Point(19, 40);
			this->dgv_commandes->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->dgv_commandes->Name = L"dgv_commandes";
			this->dgv_commandes->RowHeadersWidth = 82;
			this->dgv_commandes->Size = System::Drawing::Size(938, 759);
			this->dgv_commandes->TabIndex = 30;
			// 
			// btn_next
			// 
			this->btn_next->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_next->Location = System::Drawing::Point(785, 836);
			this->btn_next->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->btn_next->Name = L"btn_next";
			this->btn_next->Size = System::Drawing::Size(80, 44);
			this->btn_next->TabIndex = 29;
			this->btn_next->Text = L">";
			this->btn_next->UseVisualStyleBackColor = true;
			// 
			// btn_last
			// 
			this->btn_last->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_last->Location = System::Drawing::Point(877, 836);
			this->btn_last->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->btn_last->Name = L"btn_last";
			this->btn_last->Size = System::Drawing::Size(80, 44);
			this->btn_last->TabIndex = 28;
			this->btn_last->Text = L">>";
			this->btn_last->UseVisualStyleBackColor = true;
			// 
			// btn_previous
			// 
			this->btn_previous->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_previous->Location = System::Drawing::Point(693, 836);
			this->btn_previous->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->btn_previous->Name = L"btn_previous";
			this->btn_previous->Size = System::Drawing::Size(80, 44);
			this->btn_previous->TabIndex = 27;
			this->btn_previous->Text = L"<";
			this->btn_previous->UseVisualStyleBackColor = true;
			// 
			// lbl_ref
			// 
			this->lbl_ref->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lbl_ref->AutoSize = true;
			this->lbl_ref->Location = System::Drawing::Point(204, 805);
			this->lbl_ref->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->lbl_ref->Name = L"lbl_ref";
			this->lbl_ref->Size = System::Drawing::Size(111, 25);
			this->lbl_ref->TabIndex = 23;
			this->lbl_ref->Text = L"Référence";
			// 
			// txt_ref
			// 
			this->txt_ref->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->txt_ref->Location = System::Drawing::Point(211, 836);
			this->txt_ref->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->txt_ref->Name = L"txt_ref";
			this->txt_ref->ReadOnly = true;
			this->txt_ref->Size = System::Drawing::Size(352, 31);
			this->txt_ref->TabIndex = 21;
			// 
			// btn_first
			// 
			this->btn_first->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_first->Location = System::Drawing::Point(601, 836);
			this->btn_first->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->btn_first->Name = L"btn_first";
			this->btn_first->Size = System::Drawing::Size(80, 44);
			this->btn_first->TabIndex = 20;
			this->btn_first->Text = L"<<";
			this->btn_first->UseVisualStyleBackColor = true;
			// 
			// dgv_articles
			// 
			this->dgv_articles->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgv_articles->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_articles->Location = System::Drawing::Point(978, 40);
			this->dgv_articles->Name = L"dgv_articles";
			this->dgv_articles->RowHeadersWidth = 82;
			this->dgv_articles->RowTemplate->Height = 33;
			this->dgv_articles->Size = System::Drawing::Size(1134, 759);
			this->dgv_articles->TabIndex = 40;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(973, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 25);
			this->label1->TabIndex = 41;
			this->label1->Text = L"Articles";
			// 
			// PageCommande
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2200, 1100);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgv_articles);
			this->Controls->Add(this->DebugBox);
			this->Controls->Add(this->debugText);
			this->Controls->Add(this->txt_message);
			this->Controls->Add(this->lbl_message);
			this->Controls->Add(this->btn_enr);
			this->Controls->Add(this->btn_sup);
			this->Controls->Add(this->btn_maj);
			this->Controls->Add(this->btn_nouveau);
			this->Controls->Add(this->lbl_commandes);
			this->Controls->Add(this->dgv_commandes);
			this->Controls->Add(this->btn_next);
			this->Controls->Add(this->btn_last);
			this->Controls->Add(this->btn_previous);
			this->Controls->Add(this->lbl_ref);
			this->Controls->Add(this->txt_ref);
			this->Controls->Add(this->btn_first);
			this->MinimumSize = System::Drawing::Size(2152, 1098);
			this->Name = L"PageCommande";
			this->Text = L"PageCommande";
			this->Load += gcnew System::EventHandler(this, &PageCommande::PageCommande_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_commandes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_articles))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			private: System::Void PageCommande_Load(System::Object^ sender, System::EventArgs^ e)
			{
				this->initCommande();
				this->txt_message->Text = "Cnx SQL SERVER ok \r\nEnregistrement chargés";
			}
			private: void initCommande(void)
			{
				this->gestionCommandes = gcnew NS_SVC::gestionCommandes();
				this->dgv_commandes->Columns->Clear();
				this->dgv_articles->Columns->Clear();
				this->index = 0;
				refresh();
			}
			private: void refresh(void)
			{
				this->dsCommande = this->gestionCommandes->listeCommandes("LesCommandes");
				this->rowsCount = this->dsCommande->Tables["LesCommandes"]->Rows->Count;
				this->dgv_commandes->DataSource = this->dsCommande;
				this->dgv_commandes->DataMember = "LesCommandes";
				this->txt_ref->Text = Convert::ToString(this->dsCommande->Tables["LesCommandes"]->Rows[this->index]->ItemArray[0]);
				this->dsCommandeArticles = this->gestionCommandes->listeArticlesCommande(this->txt_ref->Text, "Articles");
				this->dgv_articles->DataSource = this->dsCommandeArticles;
				this->dgv_articles->DataMember = "Articles";
				this->txt_message->Text = "Chargement de l'enregistrement : " + (this->index + 1);
			}
	};
}

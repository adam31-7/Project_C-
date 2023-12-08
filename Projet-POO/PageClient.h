#pragma once
#include "CAD.h";
#include "mappTableClient.h"
#include "gestionClients.h"
#include <iostream>

namespace ProjetPOO {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;
	using namespace System::Text; // Pour utiliser la classe StringBuilder
	/// <summary>
	/// Description résumée de PageClient
	/// </summary>
	public ref class PageClient : public System::Windows::Forms::Form
	{
	public:
		PageClient(void)
		{
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~PageClient()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_first;
	private: System::Windows::Forms::TextBox^ txt_id;
	private: System::Windows::Forms::TextBox^ txt_nom;
	private: System::Windows::Forms::Label^ lbl_id;
	private: System::Windows::Forms::Label^ lbl_nom;
	private: System::Windows::Forms::Label^ lbl_prenom;
	private: System::Windows::Forms::TextBox^ txt_prenom;
	private: System::Windows::Forms::Button^ btn_previous;
	private: System::Windows::Forms::Button^ btn_last;
	private: System::Windows::Forms::Button^ btn_next;


	private: System::Windows::Forms::DataGridView^ dgv_adresses;
	private: System::Windows::Forms::Label^ lbl_adresse;
	private: System::Windows::Forms::Button^ btn_nouveau;
	private: System::Windows::Forms::Button^ btn_maj;
	private: System::Windows::Forms::Button^ btn_sup;
	private: System::Windows::Forms::Button^ btn_enr;
	private: System::Windows::Forms::Label^ lbl_message;
	private: System::Windows::Forms::TextBox^ txt_message;
	private: NS_SVC::gestionClients^ gestionClients;
	private: DataSet^ dsPersonne;
	private: DataSet^ dsPersonneAdresses;
	private: String^ mode;
	private: int index;
	private: int rowsCount;
	private: int id;
	private: System::Windows::Forms::TextBox^ debugText;
	private: System::Windows::Forms::Label^ DebugBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DateTimePicker^ dt_date_naissance;
	private: System::Windows::Forms::Label^ lbl_date_naissance;
	private: System::Windows::Forms::DateTimePicker^ dt_date_pr;
	private: System::Windows::Forms::Label^ lbl_date_pr;



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
			   this->btn_first = (gcnew System::Windows::Forms::Button());
			   this->txt_id = (gcnew System::Windows::Forms::TextBox());
			   this->txt_nom = (gcnew System::Windows::Forms::TextBox());
			   this->lbl_id = (gcnew System::Windows::Forms::Label());
			   this->lbl_nom = (gcnew System::Windows::Forms::Label());
			   this->lbl_prenom = (gcnew System::Windows::Forms::Label());
			   this->txt_prenom = (gcnew System::Windows::Forms::TextBox());
			   this->btn_previous = (gcnew System::Windows::Forms::Button());
			   this->btn_last = (gcnew System::Windows::Forms::Button());
			   this->btn_next = (gcnew System::Windows::Forms::Button());
			   this->dgv_adresses = (gcnew System::Windows::Forms::DataGridView());
			   this->lbl_adresse = (gcnew System::Windows::Forms::Label());
			   this->btn_nouveau = (gcnew System::Windows::Forms::Button());
			   this->btn_maj = (gcnew System::Windows::Forms::Button());
			   this->btn_sup = (gcnew System::Windows::Forms::Button());
			   this->btn_enr = (gcnew System::Windows::Forms::Button());
			   this->lbl_message = (gcnew System::Windows::Forms::Label());
			   this->txt_message = (gcnew System::Windows::Forms::TextBox());
			   this->debugText = (gcnew System::Windows::Forms::TextBox());
			   this->DebugBox = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->dt_date_naissance = (gcnew System::Windows::Forms::DateTimePicker());
			   this->lbl_date_naissance = (gcnew System::Windows::Forms::Label());
			   this->dt_date_pr = (gcnew System::Windows::Forms::DateTimePicker());
			   this->lbl_date_pr = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_adresses))->BeginInit();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // btn_first
			   // 
			   this->btn_first->Location = System::Drawing::Point(34, 282);
			   this->btn_first->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_first->Name = L"btn_first";
			   this->btn_first->Size = System::Drawing::Size(55, 66);
			   this->btn_first->TabIndex = 0;
			   this->btn_first->Text = L"<<";
			   this->btn_first->UseVisualStyleBackColor = true;
			   this->btn_first->Click += gcnew System::EventHandler(this, &PageClient::button1_Click);
			   // 
			   // txt_id
			   // 
			   this->txt_id->Location = System::Drawing::Point(33, 100);
			   this->txt_id->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->txt_id->Name = L"txt_id";
			   this->txt_id->ReadOnly = true;
			   this->txt_id->Size = System::Drawing::Size(265, 26);
			   this->txt_id->TabIndex = 1;
			   // 
			   // txt_nom
			   // 
			   this->txt_nom->Location = System::Drawing::Point(33, 169);
			   this->txt_nom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->txt_nom->Name = L"txt_nom";
			   this->txt_nom->Size = System::Drawing::Size(265, 26);
			   this->txt_nom->TabIndex = 2;
			   // 
			   // lbl_id
			   // 
			   this->lbl_id->AutoSize = true;
			   this->lbl_id->Location = System::Drawing::Point(28, 75);
			   this->lbl_id->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_id->Name = L"lbl_id";
			   this->lbl_id->Size = System::Drawing::Size(23, 20);
			   this->lbl_id->TabIndex = 3;
			   this->lbl_id->Text = L"Id";
			   // 
			   // lbl_nom
			   // 
			   this->lbl_nom->AutoSize = true;
			   this->lbl_nom->Location = System::Drawing::Point(28, 145);
			   this->lbl_nom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_nom->Name = L"lbl_nom";
			   this->lbl_nom->Size = System::Drawing::Size(42, 20);
			   this->lbl_nom->TabIndex = 4;
			   this->lbl_nom->Text = L"Nom";
			   // 
			   // lbl_prenom
			   // 
			   this->lbl_prenom->AutoSize = true;
			   this->lbl_prenom->Location = System::Drawing::Point(28, 218);
			   this->lbl_prenom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_prenom->Name = L"lbl_prenom";
			   this->lbl_prenom->Size = System::Drawing::Size(64, 20);
			   this->lbl_prenom->TabIndex = 5;
			   this->lbl_prenom->Text = L"Prénom";
			   // 
			   // txt_prenom
			   // 
			   this->txt_prenom->Location = System::Drawing::Point(33, 242);
			   this->txt_prenom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->txt_prenom->Name = L"txt_prenom";
			   this->txt_prenom->Size = System::Drawing::Size(265, 26);
			   this->txt_prenom->TabIndex = 6;
			   // 
			   // btn_previous
			   // 
			   this->btn_previous->Location = System::Drawing::Point(89, 282);
			   this->btn_previous->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_previous->Name = L"btn_previous";
			   this->btn_previous->Size = System::Drawing::Size(78, 32);
			   this->btn_previous->TabIndex = 7;
			   this->btn_previous->Text = L"<";
			   this->btn_previous->UseVisualStyleBackColor = true;
			   this->btn_previous->Click += gcnew System::EventHandler(this, &PageClient::button1_Click_1);
			   // 
			   // btn_last
			   // 
			   this->btn_last->Location = System::Drawing::Point(242, 282);
			   this->btn_last->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_last->Name = L"btn_last";
			   this->btn_last->Size = System::Drawing::Size(54, 66);
			   this->btn_last->TabIndex = 8;
			   this->btn_last->Text = L">>";
			   this->btn_last->UseVisualStyleBackColor = true;
			   this->btn_last->Click += gcnew System::EventHandler(this, &PageClient::button2_Click);
			   // 
			   // btn_next
			   // 
			   this->btn_next->Location = System::Drawing::Point(166, 282);
			   this->btn_next->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_next->Name = L"btn_next";
			   this->btn_next->Size = System::Drawing::Size(75, 32);
			   this->btn_next->TabIndex = 9;
			   this->btn_next->Text = L">";
			   this->btn_next->UseVisualStyleBackColor = true;
			   this->btn_next->Click += gcnew System::EventHandler(this, &PageClient::button3_Click);
			   // 
			   // dgv_adresses
			   // 
			   this->dgv_adresses->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->dgv_adresses->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			   this->dgv_adresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dgv_adresses->Location = System::Drawing::Point(325, 246);
			   this->dgv_adresses->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->dgv_adresses->Name = L"dgv_adresses";
			   this->dgv_adresses->RowHeadersWidth = 82;
			   this->dgv_adresses->Size = System::Drawing::Size(682, 226);
			   this->dgv_adresses->TabIndex = 10;
			   // 
			   // lbl_adresse
			   // 
			   this->lbl_adresse->AutoSize = true;
			   this->lbl_adresse->Location = System::Drawing::Point(321, 218);
			   this->lbl_adresse->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_adresse->Name = L"lbl_adresse";
			   this->lbl_adresse->Size = System::Drawing::Size(76, 20);
			   this->lbl_adresse->TabIndex = 11;
			   this->lbl_adresse->Text = L"Adresses";
			   // 
			   // btn_nouveau
			   // 
			   this->btn_nouveau->Location = System::Drawing::Point(32, 385);
			   this->btn_nouveau->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_nouveau->Name = L"btn_nouveau";
			   this->btn_nouveau->Size = System::Drawing::Size(90, 42);
			   this->btn_nouveau->TabIndex = 12;
			   this->btn_nouveau->Text = L"Nouveau";
			   this->btn_nouveau->UseVisualStyleBackColor = true;
			   this->btn_nouveau->Click += gcnew System::EventHandler(this, &PageClient::btn_nouveau_Click);
			   // 
			   // btn_maj
			   // 
			   this->btn_maj->Location = System::Drawing::Point(120, 385);
			   this->btn_maj->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_maj->Name = L"btn_maj";
			   this->btn_maj->Size = System::Drawing::Size(86, 42);
			   this->btn_maj->TabIndex = 13;
			   this->btn_maj->Text = L"Modifier";
			   this->btn_maj->UseVisualStyleBackColor = true;
			   this->btn_maj->Click += gcnew System::EventHandler(this, &PageClient::btn_maj_Click);
			   // 
			   // btn_sup
			   // 
			   this->btn_sup->Location = System::Drawing::Point(205, 385);
			   this->btn_sup->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_sup->Name = L"btn_sup";
			   this->btn_sup->Size = System::Drawing::Size(97, 42);
			   this->btn_sup->TabIndex = 14;
			   this->btn_sup->Text = L"Supprimer";
			   this->btn_sup->UseVisualStyleBackColor = true;
			   this->btn_sup->Click += gcnew System::EventHandler(this, &PageClient::btn_sup_Click);
			   // 
			   // btn_enr
			   // 
			   this->btn_enr->Location = System::Drawing::Point(33, 430);
			   this->btn_enr->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_enr->Name = L"btn_enr";
			   this->btn_enr->Size = System::Drawing::Size(269, 42);
			   this->btn_enr->TabIndex = 15;
			   this->btn_enr->Text = L"Enregistrer";
			   this->btn_enr->UseVisualStyleBackColor = true;
			   this->btn_enr->Click += gcnew System::EventHandler(this, &PageClient::btn_enr_Click);
			   // 
			   // lbl_message
			   // 
			   this->lbl_message->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->lbl_message->AutoSize = true;
			   this->lbl_message->Location = System::Drawing::Point(28, 574);
			   this->lbl_message->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_message->Name = L"lbl_message";
			   this->lbl_message->Size = System::Drawing::Size(74, 20);
			   this->lbl_message->TabIndex = 16;
			   this->lbl_message->Text = L"Message";
			   // 
			   // txt_message
			   // 
			   this->txt_message->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->txt_message->Location = System::Drawing::Point(33, 598);
			   this->txt_message->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->txt_message->Multiline = true;
			   this->txt_message->Name = L"txt_message";
			   this->txt_message->Size = System::Drawing::Size(972, 72);
			   this->txt_message->TabIndex = 17;
			   // 
			   // debugText
			   // 
			   this->debugText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->debugText->Location = System::Drawing::Point(842, 558);
			   this->debugText->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->debugText->Name = L"debugText";
			   this->debugText->Size = System::Drawing::Size(163, 26);
			   this->debugText->TabIndex = 18;
			   // 
			   // DebugBox
			   // 
			   this->DebugBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->DebugBox->AutoSize = true;
			   this->DebugBox->Location = System::Drawing::Point(765, 562);
			   this->DebugBox->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->DebugBox->Name = L"DebugBox";
			   this->DebugBox->Size = System::Drawing::Size(65, 20);
			   this->DebugBox->TabIndex = 19;
			   this->DebugBox->Text = L"Debug :";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(37, 350);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(52, 19);
			   this->label1->TabIndex = 20;
			   this->label1->Text = L"Début";
			   this->label1->Click += gcnew System::EventHandler(this, &PageClient::label1_Click);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(255, 350);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(32, 19);
			   this->label2->TabIndex = 21;
			   this->label2->Text = L"Fin";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(91, 316);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(82, 19);
			   this->label3->TabIndex = 22;
			   this->label3->Text = L"Précédent";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(177, 316);
			   this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(63, 19);
			   this->label4->TabIndex = 23;
			   this->label4->Text = L"Suivant";
			   // 
			   // panel1
			   // 
			   this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->panel1->BackColor = System::Drawing::Color::White;
			   this->panel1->Controls->Add(this->label5);
			   this->panel1->Location = System::Drawing::Point(-18, -19);
			   this->panel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1066, 76);
			   this->panel1->TabIndex = 24;
			   // 
			   // label5
			   // 
			   this->label5->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->label5->Location = System::Drawing::Point(363, 24);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(339, 46);
			   this->label5->TabIndex = 25;
			   this->label5->Text = L"Gestion des Clients";
			   // 
			   // dt_date_naissance
			   // 
			   this->dt_date_naissance->Location = System::Drawing::Point(329, 99);
			   this->dt_date_naissance->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->dt_date_naissance->MaxDate = DateTime::Now;
			   this->dt_date_naissance->Name = L"dt_date_naissance";
			   this->dt_date_naissance->Size = System::Drawing::Size(262, 26);
			   this->dt_date_naissance->TabIndex = 50;
			   this->dt_date_naissance->Value = System::DateTime(2023, 12, 8, 0, 0, 0, 0);
			   // 
			   // lbl_date_naissance
			   // 
			   this->lbl_date_naissance->AutoSize = true;
			   this->lbl_date_naissance->Location = System::Drawing::Point(321, 75);
			   this->lbl_date_naissance->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_date_naissance->Name = L"lbl_date_naissance";
			   this->lbl_date_naissance->Size = System::Drawing::Size(142, 20);
			   this->lbl_date_naissance->TabIndex = 49;
			   this->lbl_date_naissance->Text = L"Date de naissance";
			   // 
			   // dt_date_pr
			   // 
			   this->dt_date_pr->Checked = false;
			   this->dt_date_pr->Location = System::Drawing::Point(332, 169);
			   this->dt_date_pr->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->dt_date_pr->MaxDate = DateTime::Now;
			   this->dt_date_pr->Name = L"dt_date_pr";
			   this->dt_date_pr->Size = System::Drawing::Size(268, 26);
			   this->dt_date_pr->TabIndex = 52;
			   this->dt_date_pr->Value = System::DateTime(2023, 12, 8, 9, 58, 12, 904);
			   // 
			   // lbl_date_pr
			   // 
			   this->lbl_date_pr->AutoSize = true;
			   this->lbl_date_pr->Location = System::Drawing::Point(328, 145);
			   this->lbl_date_pr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_date_pr->Name = L"lbl_date_pr";
			   this->lbl_date_pr->Size = System::Drawing::Size(167, 20);
			   this->lbl_date_pr->TabIndex = 51;
			   this->lbl_date_pr->Text = L"Date du premier achat";
			   // 
			   // PageClient
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->ClientSize = System::Drawing::Size(1036, 680);
			   this->Controls->Add(this->dt_date_pr);
			   this->Controls->Add(this->lbl_date_pr);
			   this->Controls->Add(this->dt_date_naissance);
			   this->Controls->Add(this->lbl_date_naissance);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->DebugBox);
			   this->Controls->Add(this->debugText);
			   this->Controls->Add(this->txt_message);
			   this->Controls->Add(this->lbl_message);
			   this->Controls->Add(this->btn_enr);
			   this->Controls->Add(this->btn_sup);
			   this->Controls->Add(this->btn_maj);
			   this->Controls->Add(this->btn_nouveau);
			   this->Controls->Add(this->lbl_adresse);
			   this->Controls->Add(this->dgv_adresses);
			   this->Controls->Add(this->btn_next);
			   this->Controls->Add(this->btn_last);
			   this->Controls->Add(this->btn_previous);
			   this->Controls->Add(this->txt_prenom);
			   this->Controls->Add(this->lbl_prenom);
			   this->Controls->Add(this->lbl_nom);
			   this->Controls->Add(this->lbl_id);
			   this->Controls->Add(this->txt_nom);
			   this->Controls->Add(this->txt_id);
			   this->Controls->Add(this->btn_first);
			   this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->MaximumSize = System::Drawing::Size(1058, 736);
			   this->MinimumSize = System::Drawing::Size(1058, 606);
			   this->Name = L"PageClient";
			   this->Text = L"PageClient";
			   this->Load += gcnew System::EventHandler(this, &PageClient::PageClient_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_adresses))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = 0;
		refresh();
	}
	private: System::Void PageClient_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->initialisationENR();
		this->txt_message->Text = "Cnx SQL SERVER ok \r\nEnregistrement chargés";
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->index > 0)
		{
			this->index--;
			refresh();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->index < this->rowsCount - 1)
		{
			this->index++;
			refresh();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = this->rowsCount - 1;
		refresh();
	}
	private: System::Void btn_nouveau_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->txt_id->Text = "";
		this->txt_nom->Text = "";
		this->txt_prenom->Text = "";
		this->dgv_adresses->DataSource = nullptr;
		this->dgv_adresses->Columns->Add("Adresse", "Adresse");
		this->dgv_adresses->Columns->Add("Ville", "Ville");
		this->dgv_adresses->Columns->Add("Cp", "Cp");
		this->txt_message->Text = "Veuillez saisir les renseignements avant d'enregister";
		this->mode = "nouveau";
	}
	private: System::Void btn_enr_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->mode == "nouveau")
		{
			int i;
			int ii;
			int taille = (this->dgv_adresses->RowCount - 1) * 3;
			array<String^>^ lesAdresses = gcnew array<String^>(taille);
			ii = 0;
			for (i = 0; i < taille - 1; i++)
			{
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[0, ii]->Value);
				i++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[1, ii]->Value);
				i++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[2, ii]->Value);
				ii++;
			}
			this->gestionClients->ajouter(this->txt_nom->Text, this->txt_prenom->Text, this->dt_date_naissance->Value, this->dt_date_pr->Value, lesAdresses);
		}
		else if (this->mode == "supprimer")
		{
			this->gestionClients->supprimer(id);
		}
		else if (this->mode == "maj")
		{
			int i;
			int ii;
			int taille = (this->dgv_adresses->RowCount - 1) * 4;
			array<String^>^ lesAdresses = gcnew array<String^>(taille);
			ii = 0;
			this->dgv_adresses->Columns["id_adresse"]->Visible = true;

			for (i = 0; i < taille - 1; i++)
			{
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[0, ii]->Value);
				i++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[1, ii]->Value);
				i++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[2, ii]->Value);
				i++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[3, ii]->Value);
				ii++;
			}

			/////////////////////////
			// Utilisation de StringBuilder pour concaténer les éléments du tableau en une seule chaîne
			StringBuilder^ resultat = gcnew StringBuilder();
			for (int i = 0; i < taille; ++i)
			{
				resultat->Append(lesAdresses[i]);
				// Ajouter une virgule et un espace si ce n'est pas le dernier élément
				if (i < taille - 1)
				{
					resultat->Append(", ");
				}
			}
			/////////////////////////
			this->debugText->Text = resultat->ToString();
			this->gestionClients->modifier(Convert::ToInt32(this->txt_id->Text), this->txt_nom->Text, this->txt_prenom->Text, this->dt_date_naissance->Value, this->dt_date_pr->Value, lesAdresses);
		}
		this->initialisationENR();
	}
	private: System::Void btn_sup_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->id = Convert::ToInt32(this->txt_id->Text);
		this->mode = "supprimer";
		this->txt_id->Text = "";
		this->txt_nom->Text = "";
		this->txt_prenom->Text = "";
		this->dt_date_naissance->Value = dt_date_naissance->MinDateTime;
		this->dt_date_pr->Value = dt_date_pr->MinDateTime;
		this->dgv_adresses->DataSource = nullptr;
		this->txt_message->Text = "L'enregistrement a été supprimer.";
	}
	private: void initialisationENR(void)
	{
		this->gestionClients = gcnew NS_SVC::gestionClients();
		this->dgv_adresses->Columns->Clear();
		this->dsPersonne = this->gestionClients->listeClients("LesClients");
		this->rowsCount = this->dsPersonne->Tables["LesClients"]->Rows->Count;
		this->index = 0;
		refresh();
	}
	private: void refresh(void)
	{
		this->txt_id->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[0]);
		this->txt_nom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[1]);
		this->txt_prenom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[2]);
		this->dt_date_naissance->Value = Convert::ToDateTime(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[3]);
		this->dt_date_pr->Value = Convert::ToDateTime(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[4]);
		this->dsPersonneAdresses = this->gestionClients->adressesClient(Convert::ToInt32(this->txt_id->Text), "AdressesPersonnes");
		this->dgv_adresses->DataSource = this->dsPersonneAdresses;
		this->dgv_adresses->DataMember = "AdressesPersonnes";
		//this->dgv_adresses->Columns["ID_adresse"]->Visible = false;
		this->dgv_adresses->Columns["ID_client"]->Visible = false;
		this->txt_message->Text = "Chargement de l'enregistrement : " + (this->index + 1);
	}
	private: System::Void btn_maj_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->mode = "maj";
		this->txt_message->Text = "Enregistrement en attente de validation";
	}
		   //private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		   //}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void lbl_date_embauche_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
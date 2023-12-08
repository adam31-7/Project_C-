#pragma once
#include "gestionPersonnels.h"

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
	using namespace System::Text;

	/// <summary>
	/// Description résumée de PagePersonnel
	/// </summary>
	public ref class PagePersonnel : public System::Windows::Forms::Form
	{
	public:
		PagePersonnel(void)
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
		~PagePersonnel()
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
	private: System::Windows::Forms::Button^ btn_next;
	private: System::Windows::Forms::Button^ btn_last;




	private: System::Windows::Forms::Button^ btn_previous;
	private: System::Windows::Forms::TextBox^ txt_prenom;
	private: System::Windows::Forms::Label^ lbl_prenom;
	private: System::Windows::Forms::Label^ lbl_nom;
	private: System::Windows::Forms::Label^ lbl_id;
	private: System::Windows::Forms::TextBox^ txt_nom;
	private: System::Windows::Forms::TextBox^ txt_id;
	private: System::Windows::Forms::Button^ btn_first;

	private: System::Windows::Forms::Label^ lbl_date_naissance;



	private: System::Windows::Forms::Label^ lbl_date_embauche;


	private: System::Windows::Forms::TextBox^ txt_id_suph;
	private: System::Windows::Forms::Label^ lbl_id_suph;


	private: System::Windows::Forms::TextBox^ txt_id_adresse;
	private: System::Windows::Forms::Label^ lbl_id_adresse;


	private: NS_SVC::gestionPersonnels^ gestionPersonnels;
	private: DataSet^ dsPersonnel;

	private: String^ mode;

	private: int index;
	private: int rowsCount;
	private: int id;
	private: System::Windows::Forms::DateTimePicker^ dt_date_naissance;
	private: System::Windows::Forms::DateTimePicker^ dt_date_embauche;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label5;






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
			this->btn_next = (gcnew System::Windows::Forms::Button());
			this->btn_last = (gcnew System::Windows::Forms::Button());
			this->btn_previous = (gcnew System::Windows::Forms::Button());
			this->txt_prenom = (gcnew System::Windows::Forms::TextBox());
			this->lbl_prenom = (gcnew System::Windows::Forms::Label());
			this->lbl_nom = (gcnew System::Windows::Forms::Label());
			this->lbl_id = (gcnew System::Windows::Forms::Label());
			this->txt_nom = (gcnew System::Windows::Forms::TextBox());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->btn_first = (gcnew System::Windows::Forms::Button());
			this->lbl_date_naissance = (gcnew System::Windows::Forms::Label());
			this->lbl_date_embauche = (gcnew System::Windows::Forms::Label());
			this->txt_id_suph = (gcnew System::Windows::Forms::TextBox());
			this->lbl_id_suph = (gcnew System::Windows::Forms::Label());
			this->txt_id_adresse = (gcnew System::Windows::Forms::TextBox());
			this->lbl_id_adresse = (gcnew System::Windows::Forms::Label());
			this->dt_date_naissance = (gcnew System::Windows::Forms::DateTimePicker());
			this->dt_date_embauche = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// DebugBox
			// 
			this->DebugBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DebugBox->AutoSize = true;
			this->DebugBox->Location = System::Drawing::Point(381, 491);
			this->DebugBox->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DebugBox->Name = L"DebugBox";
			this->DebugBox->Size = System::Drawing::Size(65, 20);
			this->DebugBox->TabIndex = 39;
			this->DebugBox->Text = L"Debug :";
			this->DebugBox->Click += gcnew System::EventHandler(this, &PagePersonnel::DebugBox_Click);
			// 
			// debugText
			// 
			this->debugText->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->debugText->Location = System::Drawing::Point(458, 488);
			this->debugText->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->debugText->Name = L"debugText";
			this->debugText->Size = System::Drawing::Size(163, 26);
			this->debugText->TabIndex = 38;
			this->debugText->TextChanged += gcnew System::EventHandler(this, &PagePersonnel::debugText_TextChanged);
			// 
			// txt_message
			// 
			this->txt_message->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txt_message->Location = System::Drawing::Point(33, 528);
			this->txt_message->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txt_message->Multiline = true;
			this->txt_message->Name = L"txt_message";
			this->txt_message->Size = System::Drawing::Size(588, 72);
			this->txt_message->TabIndex = 37;
			this->txt_message->TextChanged += gcnew System::EventHandler(this, &PagePersonnel::txt_message_TextChanged);
			// 
			// lbl_message
			// 
			this->lbl_message->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_message->AutoSize = true;
			this->lbl_message->Location = System::Drawing::Point(27, 501);
			this->lbl_message->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_message->Name = L"lbl_message";
			this->lbl_message->Size = System::Drawing::Size(74, 20);
			this->lbl_message->TabIndex = 36;
			this->lbl_message->Text = L"Message";
			this->lbl_message->Click += gcnew System::EventHandler(this, &PagePersonnel::lbl_message_Click);
			// 
			// btn_enr
			// 
			this->btn_enr->Location = System::Drawing::Point(349, 374);
			this->btn_enr->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_enr->Name = L"btn_enr";
			this->btn_enr->Size = System::Drawing::Size(268, 38);
			this->btn_enr->TabIndex = 35;
			this->btn_enr->Text = L"Enregistrer";
			this->btn_enr->UseVisualStyleBackColor = true;
			this->btn_enr->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_enr_Click);
			// 
			// btn_sup
			// 
			this->btn_sup->Location = System::Drawing::Point(523, 334);
			this->btn_sup->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_sup->Name = L"btn_sup";
			this->btn_sup->Size = System::Drawing::Size(93, 35);
			this->btn_sup->TabIndex = 34;
			this->btn_sup->Text = L"Supprimer";
			this->btn_sup->UseVisualStyleBackColor = true;
			this->btn_sup->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_sup_Click);
			// 
			// btn_maj
			// 
			this->btn_maj->Location = System::Drawing::Point(441, 334);
			this->btn_maj->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_maj->Name = L"btn_maj";
			this->btn_maj->Size = System::Drawing::Size(82, 35);
			this->btn_maj->TabIndex = 33;
			this->btn_maj->Text = L"Modifier";
			this->btn_maj->UseVisualStyleBackColor = true;
			this->btn_maj->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_maj_Click);
			// 
			// btn_nouveau
			// 
			this->btn_nouveau->Location = System::Drawing::Point(349, 334);
			this->btn_nouveau->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_nouveau->Name = L"btn_nouveau";
			this->btn_nouveau->Size = System::Drawing::Size(93, 35);
			this->btn_nouveau->TabIndex = 32;
			this->btn_nouveau->Text = L"Nouveau";
			this->btn_nouveau->UseVisualStyleBackColor = true;
			this->btn_nouveau->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_nouveau_Click);
			// 
			// btn_next
			// 
			this->btn_next->Location = System::Drawing::Point(165, 375);
			this->btn_next->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_next->Name = L"btn_next";
			this->btn_next->Size = System::Drawing::Size(78, 35);
			this->btn_next->TabIndex = 29;
			this->btn_next->Text = L">";
			this->btn_next->UseVisualStyleBackColor = true;
			this->btn_next->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_next_Click);
			// 
			// btn_last
			// 
			this->btn_last->Location = System::Drawing::Point(244, 375);
			this->btn_last->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_last->Name = L"btn_last";
			this->btn_last->Size = System::Drawing::Size(61, 69);
			this->btn_last->TabIndex = 28;
			this->btn_last->Text = L">>";
			this->btn_last->UseVisualStyleBackColor = true;
			this->btn_last->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_last_Click);
			// 
			// btn_previous
			// 
			this->btn_previous->Location = System::Drawing::Point(92, 375);
			this->btn_previous->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_previous->Name = L"btn_previous";
			this->btn_previous->Size = System::Drawing::Size(73, 35);
			this->btn_previous->TabIndex = 27;
			this->btn_previous->Text = L"<";
			this->btn_previous->UseVisualStyleBackColor = true;
			this->btn_previous->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_previous_Click);
			// 
			// txt_prenom
			// 
			this->txt_prenom->Location = System::Drawing::Point(33, 248);
			this->txt_prenom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txt_prenom->Name = L"txt_prenom";
			this->txt_prenom->Size = System::Drawing::Size(265, 26);
			this->txt_prenom->TabIndex = 26;
			this->txt_prenom->TextChanged += gcnew System::EventHandler(this, &PagePersonnel::txt_prenom_TextChanged);
			// 
			// lbl_prenom
			// 
			this->lbl_prenom->AutoSize = true;
			this->lbl_prenom->Location = System::Drawing::Point(27, 222);
			this->lbl_prenom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_prenom->Name = L"lbl_prenom";
			this->lbl_prenom->Size = System::Drawing::Size(64, 20);
			this->lbl_prenom->TabIndex = 25;
			this->lbl_prenom->Text = L"Prénom";
			this->lbl_prenom->Click += gcnew System::EventHandler(this, &PagePersonnel::lbl_prenom_Click);
			// 
			// lbl_nom
			// 
			this->lbl_nom->AutoSize = true;
			this->lbl_nom->Location = System::Drawing::Point(27, 150);
			this->lbl_nom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_nom->Name = L"lbl_nom";
			this->lbl_nom->Size = System::Drawing::Size(42, 20);
			this->lbl_nom->TabIndex = 24;
			this->lbl_nom->Text = L"Nom";
			this->lbl_nom->Click += gcnew System::EventHandler(this, &PagePersonnel::lbl_nom_Click);
			// 
			// lbl_id
			// 
			this->lbl_id->AutoSize = true;
			this->lbl_id->Location = System::Drawing::Point(27, 80);
			this->lbl_id->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_id->Name = L"lbl_id";
			this->lbl_id->Size = System::Drawing::Size(23, 20);
			this->lbl_id->TabIndex = 23;
			this->lbl_id->Text = L"Id";
			this->lbl_id->Click += gcnew System::EventHandler(this, &PagePersonnel::lbl_id_Click);
			// 
			// txt_nom
			// 
			this->txt_nom->Location = System::Drawing::Point(33, 174);
			this->txt_nom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txt_nom->Name = L"txt_nom";
			this->txt_nom->Size = System::Drawing::Size(265, 26);
			this->txt_nom->TabIndex = 22;
			this->txt_nom->TextChanged += gcnew System::EventHandler(this, &PagePersonnel::txt_nom_TextChanged);
			// 
			// txt_id
			// 
			this->txt_id->Location = System::Drawing::Point(33, 105);
			this->txt_id->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txt_id->Name = L"txt_id";
			this->txt_id->ReadOnly = true;
			this->txt_id->Size = System::Drawing::Size(265, 26);
			this->txt_id->TabIndex = 21;
			this->txt_id->TextChanged += gcnew System::EventHandler(this, &PagePersonnel::txt_id_TextChanged);
			// 
			// btn_first
			// 
			this->btn_first->Location = System::Drawing::Point(30, 375);
			this->btn_first->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_first->Name = L"btn_first";
			this->btn_first->Size = System::Drawing::Size(62, 69);
			this->btn_first->TabIndex = 20;
			this->btn_first->Text = L"<<";
			this->btn_first->UseVisualStyleBackColor = true;
			this->btn_first->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_first_Click);
			// 
			// lbl_date_naissance
			// 
			this->lbl_date_naissance->AutoSize = true;
			this->lbl_date_naissance->Location = System::Drawing::Point(28, 298);
			this->lbl_date_naissance->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_date_naissance->Name = L"lbl_date_naissance";
			this->lbl_date_naissance->Size = System::Drawing::Size(142, 20);
			this->lbl_date_naissance->TabIndex = 40;
			this->lbl_date_naissance->Text = L"Date de naissance";
			this->lbl_date_naissance->Click += gcnew System::EventHandler(this, &PagePersonnel::lbl_date_naissance_Click);
			// 
			// lbl_date_embauche
			// 
			this->lbl_date_embauche->AutoSize = true;
			this->lbl_date_embauche->Location = System::Drawing::Point(348, 81);
			this->lbl_date_embauche->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_date_embauche->Name = L"lbl_date_embauche";
			this->lbl_date_embauche->Size = System::Drawing::Size(135, 20);
			this->lbl_date_embauche->TabIndex = 42;
			this->lbl_date_embauche->Text = L"Date d\'embauche";
			this->lbl_date_embauche->Click += gcnew System::EventHandler(this, &PagePersonnel::lbl_date_embauche_Click);
			// 
			// txt_id_suph
			// 
			this->txt_id_suph->Location = System::Drawing::Point(352, 179);
			this->txt_id_suph->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txt_id_suph->Name = L"txt_id_suph";
			this->txt_id_suph->Size = System::Drawing::Size(265, 26);
			this->txt_id_suph->TabIndex = 45;
			this->txt_id_suph->TextChanged += gcnew System::EventHandler(this, &PagePersonnel::txt_id_suph_TextChanged);
			// 
			// lbl_id_suph
			// 
			this->lbl_id_suph->AutoSize = true;
			this->lbl_id_suph->Location = System::Drawing::Point(348, 154);
			this->lbl_id_suph->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_id_suph->Name = L"lbl_id_suph";
			this->lbl_id_suph->Size = System::Drawing::Size(115, 20);
			this->lbl_id_suph->TabIndex = 44;
			this->lbl_id_suph->Text = L"Id du supérieur";
			this->lbl_id_suph->Click += gcnew System::EventHandler(this, &PagePersonnel::lbl_id_suph_Click);
			// 
			// txt_id_adresse
			// 
			this->txt_id_adresse->Location = System::Drawing::Point(354, 254);
			this->txt_id_adresse->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txt_id_adresse->Name = L"txt_id_adresse";
			this->txt_id_adresse->Size = System::Drawing::Size(265, 26);
			this->txt_id_adresse->TabIndex = 47;
			this->txt_id_adresse->TextChanged += gcnew System::EventHandler(this, &PagePersonnel::txt_id_adresse_TextChanged);
			// 
			// lbl_id_adresse
			// 
			this->lbl_id_adresse->AutoSize = true;
			this->lbl_id_adresse->Location = System::Drawing::Point(349, 229);
			this->lbl_id_adresse->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_id_adresse->Name = L"lbl_id_adresse";
			this->lbl_id_adresse->Size = System::Drawing::Size(112, 20);
			this->lbl_id_adresse->TabIndex = 46;
			this->lbl_id_adresse->Text = L"Id de l\'adresse";
			this->lbl_id_adresse->Click += gcnew System::EventHandler(this, &PagePersonnel::lbl_id_adresse_Click);
			// 
			// dt_date_naissance
			// 
			this->dt_date_naissance->Location = System::Drawing::Point(36, 322);
			this->dt_date_naissance->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dt_date_naissance->MaxDate = System::DateTime::Now;
			this->dt_date_naissance->Name = L"dt_date_naissance";
			this->dt_date_naissance->Size = System::Drawing::Size(262, 26);
			this->dt_date_naissance->TabIndex = 48;
			this->dt_date_naissance->Value = System::DateTime(2023, 12, 8, 0, 0, 0, 0);
			this->dt_date_naissance->ValueChanged += gcnew System::EventHandler(this, &PagePersonnel::dt_date_naissance_ValueChanged);
			// 
			// dt_date_embauche
			// 
			this->dt_date_embauche->Location = System::Drawing::Point(352, 105);
			this->dt_date_embauche->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dt_date_embauche->MaxDate = System::DateTime::Now;
			this->dt_date_embauche->Name = L"dt_date_embauche";
			this->dt_date_embauche->Size = System::Drawing::Size(268, 26);
			this->dt_date_embauche->TabIndex = 49;
			this->dt_date_embauche->ValueChanged += gcnew System::EventHandler(this, &PagePersonnel::dt_date_embauche_ValueChanged);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(36, 445);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 19);
			this->label1->TabIndex = 50;
			this->label1->Text = L"Début";
			this->label1->Click += gcnew System::EventHandler(this, &PagePersonnel::label1_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(260, 445);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 19);
			this->label2->TabIndex = 51;
			this->label2->Text = L"Fin";
			this->label2->Click += gcnew System::EventHandler(this, &PagePersonnel::label2_Click);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(93, 411);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 19);
			this->label3->TabIndex = 52;
			this->label3->Text = L"Précédent";
			this->label3->Click += gcnew System::EventHandler(this, &PagePersonnel::label3_Click);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(176, 411);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 19);
			this->label4->TabIndex = 53;
			this->label4->Text = L"Suivant";
			this->label4->Click += gcnew System::EventHandler(this, &PagePersonnel::label4_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->label5);
			this->panel1->Location = System::Drawing::Point(-27, -11);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(698, 70);
			this->panel1->TabIndex = 54;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(172, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(379, 46);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Gestion du Personnel";
			// 
			// PagePersonnel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(652, 599);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dt_date_embauche);
			this->Controls->Add(this->dt_date_naissance);
			this->Controls->Add(this->txt_id_adresse);
			this->Controls->Add(this->lbl_id_adresse);
			this->Controls->Add(this->txt_id_suph);
			this->Controls->Add(this->lbl_id_suph);
			this->Controls->Add(this->lbl_date_embauche);
			this->Controls->Add(this->lbl_date_naissance);
			this->Controls->Add(this->DebugBox);
			this->Controls->Add(this->debugText);
			this->Controls->Add(this->txt_message);
			this->Controls->Add(this->lbl_message);
			this->Controls->Add(this->btn_enr);
			this->Controls->Add(this->btn_sup);
			this->Controls->Add(this->btn_maj);
			this->Controls->Add(this->btn_nouveau);
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
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximumSize = System::Drawing::Size(674, 655);
			this->MinimumSize = System::Drawing::Size(674, 655);
			this->Name = L"PagePersonnel";
			this->Load += gcnew System::EventHandler(this, &PagePersonnel::PagePerso_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void PagePerso_Load(System::Object^ sender, System::EventArgs^ e) {
		initialisationENR();
		this->txt_message->Text = "Cnx SQL SERVER ok \r\nEnregistrement chargés";
	}
	
	private: void initialisationENR(void)
	{
		this->gestionPersonnels = gcnew NS_SVC::gestionPersonnels();
		this->dsPersonnel = this->gestionPersonnels->listePersonnels("LesPersonnels");
		this->rowsCount = this->dsPersonnel->Tables["LesPersonnels"]->Rows->Count;
		this->index = 0;
		refresh();
	}
	private: void refresh(void)
	{
		this->txt_id->Text = Convert::ToString(this->dsPersonnel->Tables["LesPersonnels"]->Rows[this->index]->ItemArray[0]);
		this->txt_nom->Text = Convert::ToString(this->dsPersonnel->Tables["LesPersonnels"]->Rows[this->index]->ItemArray[1]);
		this->txt_prenom->Text = Convert::ToString(this->dsPersonnel->Tables["LesPersonnels"]->Rows[this->index]->ItemArray[2]);
		this->dt_date_naissance->Value = Convert::ToDateTime(this->dsPersonnel->Tables["LesPersonnels"]->Rows[this->index]->ItemArray[3]);
		this->dt_date_embauche->Value= Convert::ToDateTime(this->dsPersonnel->Tables["LesPersonnels"]->Rows[this->index]->ItemArray[4]);
		this->txt_id_suph->Text = Convert::ToString(this->dsPersonnel->Tables["LesPersonnels"]->Rows[this->index]->ItemArray[5]);
		this->txt_id_adresse->Text = Convert::ToString(this->dsPersonnel->Tables["LesPersonnels"]->Rows[this->index]->ItemArray[6]);
		this->txt_message->Text = "Chargement de l'enregistrement : " + (this->index + 1);
	}
	private: System::Void btn_last_Click(System::Object^ sender, System::EventArgs^ e) {
		this->index = this->rowsCount - 1;
		refresh();
	}
	private: System::Void btn_next_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->index < this->rowsCount - 1)
		{
			this->index++;
			refresh();
		}
	}
	private: System::Void btn_previous_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->index > 0)
		{
			this->index--;
			refresh();
		}
	}

	private: System::Void btn_first_Click(System::Object^ sender, System::EventArgs^ e) {
		this->index = 0;
		refresh();
	}
	private: System::Void btn_nouveau_Click(System::Object^ sender, System::EventArgs^ e) {
		this->txt_id->Text = "";
		this->txt_nom->Text = "";
		this->txt_prenom->Text = "";
		this->txt_id_suph->Text = "";
		this->txt_id_adresse->Text = "";
		this->txt_message->Text = "Nouvel enregistrement";
		this->mode = "nouveau";
	}
	private: System::Void btn_maj_Click(System::Object^ sender, System::EventArgs^ e) {
		this->txt_message->Text = "Enregistrement modifié";
		this->mode = "maj";
	}
private: System::Void btn_sup_Click(System::Object^ sender, System::EventArgs^ e) {
	this->txt_prenom->Text = "";
	this->txt_nom->Text = "";
	this->dt_date_naissance->Value = dt_date_naissance->MinDateTime;
	this->dt_date_embauche->Value = dt_date_embauche->MinDateTime;
	this->txt_id_suph->Text = "";
	this->txt_id_adresse->Text = "";
	this->txt_message->Text = "Enregistrement supprimé";
	this->mode = "sup";
}
private: System::Void btn_enr_Click(System::Object^ sender, System::EventArgs^ e) {
if (this->mode == "nouveau")
	{
		this->gestionPersonnels->ajouter(this->txt_nom->Text, this->txt_prenom->Text, this->dt_date_naissance->Value, this->dt_date_embauche->Value, Convert::ToInt32(this->txt_id_suph->Text), Convert::ToInt32(this->txt_id_adresse->Text));
		this->txt_id->Text = Convert::ToString(this->id);
		this->dsPersonnel = this->gestionPersonnels->listePersonnels("LesPersonnels");
		this->rowsCount = this->dsPersonnel->Tables["LesPersonnels"]->Rows->Count;
		this->index = this->rowsCount - 1;
		refresh();
	}
	else if (this->mode == "maj")
	{
		this->gestionPersonnels->modifier(Convert::ToInt32(this->txt_id->Text), this->txt_nom->Text, this->txt_prenom->Text, this->dt_date_naissance->Value, this->dt_date_embauche->Value, Convert::ToInt32(this->txt_id_suph->Text), Convert::ToInt32(this->txt_id_adresse->Text));
		this->dsPersonnel = this->gestionPersonnels->listePersonnels("LesPersonnels");
		refresh();
	}
	else if (this->mode == "sup")
	{
		this->gestionPersonnels->supprimer(Convert::ToInt32(this->txt_id->Text));
		this->dsPersonnel = this->gestionPersonnels->listePersonnels("LesPersonnels");
		this->rowsCount = this->dsPersonnel->Tables["LesPersonnels"]->Rows->Count;
		this->index = this->rowsCount - 1;
		refresh();
	}
}
private: System::Void txt_prenom_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txt_message_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbl_message_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void DebugBox_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void debugText_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dt_date_naissance_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbl_date_naissance_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txt_id_adresse_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbl_id_adresse_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbl_prenom_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txt_nom_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbl_nom_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbl_id_suph_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txt_id_suph_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dt_date_embauche_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbl_date_embauche_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txt_id_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbl_id_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

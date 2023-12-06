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
			this->SuspendLayout();
			// 
			// DebugBox
			// 
			this->DebugBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DebugBox->AutoSize = true;
			this->DebugBox->Location = System::Drawing::Point(343, 345);
			this->DebugBox->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DebugBox->Name = L"DebugBox";
			this->DebugBox->Size = System::Drawing::Size(54, 16);
			this->DebugBox->TabIndex = 39;
			this->DebugBox->Text = L"Debug :";
			// 
			// debugText
			// 
			this->debugText->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->debugText->Location = System::Drawing::Point(411, 342);
			this->debugText->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->debugText->Name = L"debugText";
			this->debugText->Size = System::Drawing::Size(145, 22);
			this->debugText->TabIndex = 38;
			// 
			// txt_message
			// 
			this->txt_message->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txt_message->Location = System::Drawing::Point(33, 374);
			this->txt_message->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txt_message->Multiline = true;
			this->txt_message->Name = L"txt_message";
			this->txt_message->Size = System::Drawing::Size(523, 58);
			this->txt_message->TabIndex = 37;
			// 
			// lbl_message
			// 
			this->lbl_message->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_message->AutoSize = true;
			this->lbl_message->Location = System::Drawing::Point(28, 353);
			this->lbl_message->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_message->Name = L"lbl_message";
			this->lbl_message->Size = System::Drawing::Size(64, 16);
			this->lbl_message->TabIndex = 36;
			this->lbl_message->Text = L"Message";
			// 
			// btn_enr
			// 
			this->btn_enr->Location = System::Drawing::Point(324, 251);
			this->btn_enr->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_enr->Name = L"btn_enr";
			this->btn_enr->Size = System::Drawing::Size(228, 30);
			this->btn_enr->TabIndex = 35;
			this->btn_enr->Text = L"Enregistrer";
			this->btn_enr->UseVisualStyleBackColor = true;
			this->btn_enr->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_enr_Click);
			// 
			// btn_sup
			// 
			this->btn_sup->Location = System::Drawing::Point(472, 219);
			this->btn_sup->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_sup->Name = L"btn_sup";
			this->btn_sup->Size = System::Drawing::Size(80, 28);
			this->btn_sup->TabIndex = 34;
			this->btn_sup->Text = L"Supprimer";
			this->btn_sup->UseVisualStyleBackColor = true;
			this->btn_sup->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_sup_Click);
			// 
			// btn_maj
			// 
			this->btn_maj->Location = System::Drawing::Point(400, 219);
			this->btn_maj->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_maj->Name = L"btn_maj";
			this->btn_maj->Size = System::Drawing::Size(73, 28);
			this->btn_maj->TabIndex = 33;
			this->btn_maj->Text = L"Modifier";
			this->btn_maj->UseVisualStyleBackColor = true;
			this->btn_maj->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_maj_Click);
			// 
			// btn_nouveau
			// 
			this->btn_nouveau->Location = System::Drawing::Point(324, 219);
			this->btn_nouveau->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_nouveau->Name = L"btn_nouveau";
			this->btn_nouveau->Size = System::Drawing::Size(76, 28);
			this->btn_nouveau->TabIndex = 32;
			this->btn_nouveau->Text = L"Nouveau";
			this->btn_nouveau->UseVisualStyleBackColor = true;
			this->btn_nouveau->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_nouveau_Click);
			// 
			// btn_next
			// 
			this->btn_next->Location = System::Drawing::Point(151, 252);
			this->btn_next->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_next->Name = L"btn_next";
			this->btn_next->Size = System::Drawing::Size(69, 28);
			this->btn_next->TabIndex = 29;
			this->btn_next->Text = L">";
			this->btn_next->UseVisualStyleBackColor = true;
			this->btn_next->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_next_Click);
			// 
			// btn_last
			// 
			this->btn_last->Location = System::Drawing::Point(221, 252);
			this->btn_last->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_last->Name = L"btn_last";
			this->btn_last->Size = System::Drawing::Size(54, 55);
			this->btn_last->TabIndex = 28;
			this->btn_last->Text = L">>";
			this->btn_last->UseVisualStyleBackColor = true;
			this->btn_last->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_last_Click);
			// 
			// btn_previous
			// 
			this->btn_previous->Location = System::Drawing::Point(86, 252);
			this->btn_previous->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_previous->Name = L"btn_previous";
			this->btn_previous->Size = System::Drawing::Size(65, 28);
			this->btn_previous->TabIndex = 27;
			this->btn_previous->Text = L"<";
			this->btn_previous->UseVisualStyleBackColor = true;
			this->btn_previous->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_previous_Click);
			// 
			// txt_prenom
			// 
			this->txt_prenom->Location = System::Drawing::Point(33, 150);
			this->txt_prenom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txt_prenom->Name = L"txt_prenom";
			this->txt_prenom->Size = System::Drawing::Size(236, 22);
			this->txt_prenom->TabIndex = 26;
			// 
			// lbl_prenom
			// 
			this->lbl_prenom->AutoSize = true;
			this->lbl_prenom->Location = System::Drawing::Point(28, 130);
			this->lbl_prenom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_prenom->Name = L"lbl_prenom";
			this->lbl_prenom->Size = System::Drawing::Size(54, 16);
			this->lbl_prenom->TabIndex = 25;
			this->lbl_prenom->Text = L"Prénom";
			// 
			// lbl_nom
			// 
			this->lbl_nom->AutoSize = true;
			this->lbl_nom->Location = System::Drawing::Point(28, 72);
			this->lbl_nom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_nom->Name = L"lbl_nom";
			this->lbl_nom->Size = System::Drawing::Size(36, 16);
			this->lbl_nom->TabIndex = 24;
			this->lbl_nom->Text = L"Nom";
			// 
			// lbl_id
			// 
			this->lbl_id->AutoSize = true;
			this->lbl_id->Location = System::Drawing::Point(28, 16);
			this->lbl_id->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_id->Name = L"lbl_id";
			this->lbl_id->Size = System::Drawing::Size(18, 16);
			this->lbl_id->TabIndex = 23;
			this->lbl_id->Text = L"Id";
			// 
			// txt_nom
			// 
			this->txt_nom->Location = System::Drawing::Point(33, 91);
			this->txt_nom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txt_nom->Name = L"txt_nom";
			this->txt_nom->Size = System::Drawing::Size(236, 22);
			this->txt_nom->TabIndex = 22;
			// 
			// txt_id
			// 
			this->txt_id->Location = System::Drawing::Point(33, 36);
			this->txt_id->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txt_id->Name = L"txt_id";
			this->txt_id->ReadOnly = true;
			this->txt_id->Size = System::Drawing::Size(236, 22);
			this->txt_id->TabIndex = 21;
			// 
			// btn_first
			// 
			this->btn_first->Location = System::Drawing::Point(31, 252);
			this->btn_first->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_first->Name = L"btn_first";
			this->btn_first->Size = System::Drawing::Size(55, 55);
			this->btn_first->TabIndex = 20;
			this->btn_first->Text = L"<<";
			this->btn_first->UseVisualStyleBackColor = true;
			this->btn_first->Click += gcnew System::EventHandler(this, &PagePersonnel::btn_first_Click);
			// 
			// lbl_date_naissance
			// 
			this->lbl_date_naissance->AutoSize = true;
			this->lbl_date_naissance->Location = System::Drawing::Point(29, 190);
			this->lbl_date_naissance->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_date_naissance->Name = L"lbl_date_naissance";
			this->lbl_date_naissance->Size = System::Drawing::Size(120, 16);
			this->lbl_date_naissance->TabIndex = 40;
			this->lbl_date_naissance->Text = L"Date de naissance";
			// 
			// lbl_date_embauche
			// 
			this->lbl_date_embauche->AutoSize = true;
			this->lbl_date_embauche->Location = System::Drawing::Point(313, 17);
			this->lbl_date_embauche->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_date_embauche->Name = L"lbl_date_embauche";
			this->lbl_date_embauche->Size = System::Drawing::Size(114, 16);
			this->lbl_date_embauche->TabIndex = 42;
			this->lbl_date_embauche->Text = L"Date d\'embauche";
			// 
			// txt_id_suph
			// 
			this->txt_id_suph->Location = System::Drawing::Point(317, 95);
			this->txt_id_suph->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txt_id_suph->Name = L"txt_id_suph";
			this->txt_id_suph->Size = System::Drawing::Size(236, 22);
			this->txt_id_suph->TabIndex = 45;
			// 
			// lbl_id_suph
			// 
			this->lbl_id_suph->AutoSize = true;
			this->lbl_id_suph->Location = System::Drawing::Point(313, 75);
			this->lbl_id_suph->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_id_suph->Name = L"lbl_id_suph";
			this->lbl_id_suph->Size = System::Drawing::Size(95, 16);
			this->lbl_id_suph->TabIndex = 44;
			this->lbl_id_suph->Text = L"Id du supérieur";
			// 
			// txt_id_adresse
			// 
			this->txt_id_adresse->Location = System::Drawing::Point(319, 155);
			this->txt_id_adresse->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txt_id_adresse->Name = L"txt_id_adresse";
			this->txt_id_adresse->Size = System::Drawing::Size(236, 22);
			this->txt_id_adresse->TabIndex = 47;
			// 
			// lbl_id_adresse
			// 
			this->lbl_id_adresse->AutoSize = true;
			this->lbl_id_adresse->Location = System::Drawing::Point(314, 135);
			this->lbl_id_adresse->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_id_adresse->Name = L"lbl_id_adresse";
			this->lbl_id_adresse->Size = System::Drawing::Size(96, 16);
			this->lbl_id_adresse->TabIndex = 46;
			this->lbl_id_adresse->Text = L"Id de l\'adresse";
			// 
			// dt_date_naissance
			// 
			this->dt_date_naissance->Location = System::Drawing::Point(36, 210);
			this->dt_date_naissance->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dt_date_naissance->Name = L"dt_date_naissance";
			this->dt_date_naissance->Size = System::Drawing::Size(233, 22);
			this->dt_date_naissance->TabIndex = 48;
			// 
			// dt_date_embauche
			// 
			this->dt_date_embauche->Location = System::Drawing::Point(317, 36);
			this->dt_date_embauche->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dt_date_embauche->Name = L"dt_date_embauche";
			this->dt_date_embauche->Size = System::Drawing::Size(239, 22);
			this->dt_date_embauche->TabIndex = 49;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(36, 308);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 16);
			this->label1->TabIndex = 50;
			this->label1->Text = L"Début";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(235, 308);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 16);
			this->label2->TabIndex = 51;
			this->label2->Text = L"Fin";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(87, 281);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 16);
			this->label3->TabIndex = 52;
			this->label3->Text = L"Précédent";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(160, 281);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 16);
			this->label4->TabIndex = 53;
			this->label4->Text = L"Suivant";
			// 
			// PagePersonnel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(584, 454);
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
			this->MaximumSize = System::Drawing::Size(602, 501);
			this->MinimumSize = System::Drawing::Size(602, 501);
			this->Name = L"PagePersonnel";
			this->Load += gcnew System::EventHandler(this, &PagePersonnel::PagePerso_Load);
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
		this->dt_date_naissance->Value = DateTime::Now;
		this->dt_date_embauche->Value = DateTime::Now;
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
	this->dt_date_naissance->Value = DateTime::Now;
	this->dt_date_embauche->Value = DateTime::Now;
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
};
}

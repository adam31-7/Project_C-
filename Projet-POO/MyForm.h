#pragma once

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
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::DataGridView^ dgv;
		DataSet^ dsClient;
		int index;
		int rowsCount;
		int id;
	private: System::Windows::Forms::Label^ lbl_id;
	private: System::Windows::Forms::TextBox^ txt_id;
	private: System::Windows::Forms::Button^ btn_enr;
	private: System::Windows::Forms::Button^ btn_sup;
	private: System::Windows::Forms::Button^ btn_maj;
	private: System::Windows::Forms::Button^ btn_nouveau;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ btn_previous;
	private: System::Windows::Forms::Button^ btn_first;

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
			this->dgv = (gcnew System::Windows::Forms::DataGridView());
			this->lbl_id = (gcnew System::Windows::Forms::Label());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->btn_enr = (gcnew System::Windows::Forms::Button());
			this->btn_sup = (gcnew System::Windows::Forms::Button());
			this->btn_maj = (gcnew System::Windows::Forms::Button());
			this->btn_nouveau = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btn_previous = (gcnew System::Windows::Forms::Button());
			this->btn_first = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv
			// 
			this->dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv->Location = System::Drawing::Point(290, 12);
			this->dgv->Name = L"dgv";
			this->dgv->RowHeadersWidth = 62;
			this->dgv->RowTemplate->Height = 28;
			this->dgv->Size = System::Drawing::Size(525, 369);
			this->dgv->TabIndex = 0;
			// 
			// lbl_id
			// 
			this->lbl_id->AutoSize = true;
			this->lbl_id->Location = System::Drawing::Point(13, 12);
			this->lbl_id->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_id->Name = L"lbl_id";
			this->lbl_id->Size = System::Drawing::Size(23, 20);
			this->lbl_id->TabIndex = 5;
			this->lbl_id->Text = L"Id";
			// 
			// txt_id
			// 
			this->txt_id->Location = System::Drawing::Point(18, 37);
			this->txt_id->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txt_id->Name = L"txt_id";
			this->txt_id->ReadOnly = true;
			this->txt_id->Size = System::Drawing::Size(265, 26);
			this->txt_id->TabIndex = 4;
			// 
			// btn_enr
			// 
			this->btn_enr->Location = System::Drawing::Point(154, 254);
			this->btn_enr->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_enr->Name = L"btn_enr";
			this->btn_enr->Size = System::Drawing::Size(129, 125);
			this->btn_enr->TabIndex = 23;
			this->btn_enr->Text = L"Enregistrer";
			this->btn_enr->UseVisualStyleBackColor = true;
			// 
			// btn_sup
			// 
			this->btn_sup->Location = System::Drawing::Point(16, 343);
			this->btn_sup->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_sup->Name = L"btn_sup";
			this->btn_sup->Size = System::Drawing::Size(129, 35);
			this->btn_sup->TabIndex = 22;
			this->btn_sup->Text = L"Supprimer";
			this->btn_sup->UseVisualStyleBackColor = true;
			// 
			// btn_maj
			// 
			this->btn_maj->Location = System::Drawing::Point(16, 299);
			this->btn_maj->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_maj->Name = L"btn_maj";
			this->btn_maj->Size = System::Drawing::Size(129, 35);
			this->btn_maj->TabIndex = 21;
			this->btn_maj->Text = L"Mise à jour";
			this->btn_maj->UseVisualStyleBackColor = true;
			// 
			// btn_nouveau
			// 
			this->btn_nouveau->Location = System::Drawing::Point(16, 254);
			this->btn_nouveau->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_nouveau->Name = L"btn_nouveau";
			this->btn_nouveau->Size = System::Drawing::Size(129, 35);
			this->btn_nouveau->TabIndex = 20;
			this->btn_nouveau->Text = L"Nouveau";
			this->btn_nouveau->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(154, 210);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(60, 35);
			this->button3->TabIndex = 19;
			this->button3->Text = L">";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(223, 210);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(60, 35);
			this->button2->TabIndex = 18;
			this->button2->Text = L">>";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// btn_previous
			// 
			this->btn_previous->Location = System::Drawing::Point(85, 210);
			this->btn_previous->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_previous->Name = L"btn_previous";
			this->btn_previous->Size = System::Drawing::Size(60, 35);
			this->btn_previous->TabIndex = 17;
			this->btn_previous->Text = L"<";
			this->btn_previous->UseVisualStyleBackColor = true;
			// 
			// btn_first
			// 
			this->btn_first->Location = System::Drawing::Point(16, 210);
			this->btn_first->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_first->Name = L"btn_first";
			this->btn_first->Size = System::Drawing::Size(60, 35);
			this->btn_first->TabIndex = 16;
			this->btn_first->Text = L"<<";
			this->btn_first->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(827, 393);
			this->Controls->Add(this->btn_enr);
			this->Controls->Add(this->btn_sup);
			this->Controls->Add(this->btn_maj);
			this->Controls->Add(this->btn_nouveau);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btn_previous);
			this->Controls->Add(this->btn_first);
			this->Controls->Add(this->lbl_id);
			this->Controls->Add(this->txt_id);
			this->Controls->Add(this->dgv);
			this->Name = L"MyForm";
			this->Text = L"Projet-POO";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->initialisationENR();
	}
	private: void initialisationENR(void)
	{
		this->gestionClients = gcnew NS_SVC::CL_svc_gestionClients();
		this->dgv->Columns->Clear();
		this->dsClient = this->gestionClients->listeClients("LesClients");
		this->rowsCount = this->dsClient->Tables["LesClients"]->Rows->Count;
		this->index = 0;
		this->txt_id->Text = Convert::ToString(this->dsClient->Tables["LesClients"]->Rows[0]->ItemArray[0]);
		this->dgv->DataMember = "AdressesPersonnes";
		this->dgv->Columns["id_personne"]->Visible = false;
		this->dgv->Columns["id_adresse"]->Visible = false;	}
	};
}

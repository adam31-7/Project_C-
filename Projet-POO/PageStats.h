#pragma once
#include "mappStats.h"
#include "CAD.h"
#include "mappTableCommande.h"
#include "mappTableArticle.h"
#include "mappTableClient.h"
#include "mappTableAdresse.h"
#include "mappTableArticleCommande.h"

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
	private: System::Windows::Forms::TextBox^ txt_MontantTC;




	private: System::Windows::Forms::TextBox^ txt_CA;
	private: System::Windows::Forms::TextBox^ txt_ID_Client;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonID;


















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
			this->txt_MontantTC = (gcnew System::Windows::Forms::TextBox());
			this->txt_CA = (gcnew System::Windows::Forms::TextBox());
			this->txt_ID_Client = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonID = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(359, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Statistiques";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(82, 145);
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
			this->label5->Location = System::Drawing::Point(452, 145);
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
			this->label6->Location = System::Drawing::Point(2, 95);
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
			this->label10->Location = System::Drawing::Point(12, 329);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(126, 20);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Entrer ID_client";
			this->label10->Click += gcnew System::EventHandler(this, &PageStats::label10_Click);
			// 
			// txt_MontantTC
			// 
			this->txt_MontantTC->Location = System::Drawing::Point(342, 363);
			this->txt_MontantTC->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_MontantTC->Name = L"txt_MontantTC";
			this->txt_MontantTC->Size = System::Drawing::Size(175, 22);
			this->txt_MontantTC->TabIndex = 25;
			this->txt_MontantTC->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PageStats::textBox1_KeyPress);
			// 
			// txt_CA
			// 
			this->txt_CA->Location = System::Drawing::Point(305, 95);
			this->txt_CA->Name = L"txt_CA";
			this->txt_CA->Size = System::Drawing::Size(204, 22);
			this->txt_CA->TabIndex = 26;
			this->txt_CA->TextChanged += gcnew System::EventHandler(this, &PageStats::txt_CA_TextChanged);
			// 
			// txt_ID_Client
			// 
			this->txt_ID_Client->Location = System::Drawing::Point(144, 329);
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
			this->label1->Location = System::Drawing::Point(12, 363);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(324, 20);
			this->label1->TabIndex = 28;
			this->label1->Text = L"Montant total des achats associé au client";
			// 
			// buttonID
			// 
			this->buttonID->Location = System::Drawing::Point(325, 327);
			this->buttonID->Name = L"buttonID";
			this->buttonID->Size = System::Drawing::Size(89, 27);
			this->buttonID->TabIndex = 29;
			this->buttonID->Text = L"Vailder";
			this->buttonID->UseVisualStyleBackColor = true;
			// 
			// PageStats
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(831, 413);
			this->Controls->Add(this->buttonID);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_ID_Client);
			this->Controls->Add(this->txt_CA);
			this->Controls->Add(this->txt_MontantTC);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximumSize = System::Drawing::Size(849, 460);
			this->MinimumSize = System::Drawing::Size(849, 460);
			this->Name = L"PageStats";
			this->Load += gcnew System::EventHandler(this, &PageStats::PageStats_Load);
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
		this->txt_CA->Text = System::Convert::ToString(stats->getChiffreAffaire());

		this->txt_MontantTC->Text = System::Convert::ToString(stats->getMontantTotalClient());

	}
private: System::Void txt_CA_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void button_ID(System::Object^ sender, System::EventArgs^ e) {
		this->txt_ID_Client;
	refresh();
	}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

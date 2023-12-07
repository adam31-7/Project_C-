#pragma once
#include "mappStock.h"
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

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ txt_CA;


















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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->txt_CA = (gcnew System::Windows::Forms::TextBox());
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
			this->label4->Location = System::Drawing::Point(150, 204);
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
			this->label5->Location = System::Drawing::Point(402, 204);
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
			this->label6->Location = System::Drawing::Point(44, 103);
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
			this->label10->Location = System::Drawing::Point(12, 414);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(275, 20);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Montant total des achats du clients ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(293, 414);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(175, 22);
			this->textBox1->TabIndex = 25;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PageStats::textBox1_KeyPress);
			// 
			// txt_CA
			// 
			this->txt_CA->Location = System::Drawing::Point(345, 105);
			this->txt_CA->Name = L"txt_CA";
			this->txt_CA->Size = System::Drawing::Size(204, 22);
			this->txt_CA->TabIndex = 26;
			// 
			// PageStats
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(831, 472);
			this->Controls->Add(this->txt_CA);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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



	}
	private: System::Void ProduitsSousSeuil_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: void refresh(void) {
	}
};
}

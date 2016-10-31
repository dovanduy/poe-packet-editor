#pragma once
#include <windows.h>
#include <atlstr.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <msclr\marshal_cppstd.h>

namespace FearPE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		boolean log = true;
		boolean formatPackets = true;
	private: System::Windows::Forms::CheckBox^  checkBox_formattedPacket;
			 int maxWidth = 0;
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
		System::Void printPacket(String^ formattedPacket, String^ rawPacket) {
			if (formatPackets) {
				Log(formattedPacket);
			} else {
				Log(rawPacket);
			}
		}

		System::Void Log(String ^str) {
			if (log) {
				listBox_packetLog->Items->Add(str);
				listBox_packetLog->TopIndex = listBox_packetLog->Items->Count - 1;
				int testWidth = System::Windows::Forms::TextRenderer::MeasureText(str,
					listBox_packetLog->Font, listBox_packetLog->ClientSize,
					System::Windows::Forms::TextFormatFlags::NoPrefix).Width;
				
				if (testWidth > maxWidth) maxWidth = testWidth;

				listBox_packetLog->HorizontalExtent = maxWidth;
				listBox_packetLog->HorizontalScrollbar = true;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::CheckBox^  checkBox_packetLog;

	private: System::Windows::Forms::ListBox^  listBox_packetLog;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_packetLog;

	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem_copyPacket;
	private: System::Windows::Forms::TabControl^  tabControl_Main;
	private: System::Windows::Forms::TabPage^  tabPage_packetLogs;


	private: System::Windows::Forms::TabPage^  tabPage_packetControl;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox_sendPacket;

	private: System::Windows::Forms::Button^  button_sendPacket;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem_clearPacketLog;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->checkBox_packetLog = (gcnew System::Windows::Forms::CheckBox());
			this->listBox_packetLog = (gcnew System::Windows::Forms::ListBox());
			this->contextMenuStrip_packetLog = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem_copyPacket = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem_clearPacketLog = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl_Main = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_packetLogs = (gcnew System::Windows::Forms::TabPage());
			this->checkBox_formattedPacket = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage_packetControl = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_sendPacket = (gcnew System::Windows::Forms::TextBox());
			this->button_sendPacket = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip_packetLog->SuspendLayout();
			this->tabControl_Main->SuspendLayout();
			this->tabPage_packetLogs->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox_packetLog
			// 
			this->checkBox_packetLog->AutoSize = true;
			this->checkBox_packetLog->Checked = true;
			this->checkBox_packetLog->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_packetLog->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_packetLog->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox_packetLog->Location = System::Drawing::Point(10, 310);
			this->checkBox_packetLog->Name = L"checkBox_packetLog";
			this->checkBox_packetLog->Size = System::Drawing::Size(70, 16);
			this->checkBox_packetLog->TabIndex = 3;
			this->checkBox_packetLog->Text = L"Log Send";
			this->checkBox_packetLog->UseVisualStyleBackColor = true;
			this->checkBox_packetLog->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_Log_CheckedChanged);
			// 
			// listBox_packetLog
			// 
			this->listBox_packetLog->BackColor = System::Drawing::Color::Azure;
			this->listBox_packetLog->FormattingEnabled = true;
			this->listBox_packetLog->HorizontalScrollbar = true;
			this->listBox_packetLog->ItemHeight = 12;
			this->listBox_packetLog->Location = System::Drawing::Point(10, 10);
			this->listBox_packetLog->Name = L"listBox_packetLog";
			this->listBox_packetLog->Size = System::Drawing::Size(794, 292);
			this->listBox_packetLog->TabIndex = 4;
			this->listBox_packetLog->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::listBox_packetLog_MouseDown);
			// 
			// contextMenuStrip_packetLog
			// 
			this->contextMenuStrip_packetLog->BackColor = System::Drawing::Color::Azure;
			this->contextMenuStrip_packetLog->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem_copyPacket,
					this->toolStripMenuItem_clearPacketLog
			});
			this->contextMenuStrip_packetLog->Name = L"contextMenuStrip1";
			this->contextMenuStrip_packetLog->Size = System::Drawing::Size(210, 48);
			this->contextMenuStrip_packetLog->Text = L"Clear Packet Log";
			this->contextMenuStrip_packetLog->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MainForm::contextMenuStrip_packetLog_ItemClicked);
			// 
			// toolStripMenuItem_copyPacket
			// 
			this->toolStripMenuItem_copyPacket->BackColor = System::Drawing::Color::Azure;
			this->toolStripMenuItem_copyPacket->Name = L"toolStripMenuItem_copyPacket";
			this->toolStripMenuItem_copyPacket->Size = System::Drawing::Size(209, 22);
			this->toolStripMenuItem_copyPacket->Text = L"Copy Packet to Clipboard";
			// 
			// toolStripMenuItem_clearPacketLog
			// 
			this->toolStripMenuItem_clearPacketLog->BackColor = System::Drawing::Color::Azure;
			this->toolStripMenuItem_clearPacketLog->Name = L"toolStripMenuItem_clearPacketLog";
			this->toolStripMenuItem_clearPacketLog->Size = System::Drawing::Size(209, 22);
			this->toolStripMenuItem_clearPacketLog->Text = L"Clear Packet Log";
			// 
			// tabControl_Main
			// 
			this->tabControl_Main->Controls->Add(this->tabPage_packetLogs);
			this->tabControl_Main->Controls->Add(this->tabPage_packetControl);
			this->tabControl_Main->Location = System::Drawing::Point(11, 5);
			this->tabControl_Main->Name = L"tabControl_Main";
			this->tabControl_Main->SelectedIndex = 0;
			this->tabControl_Main->Size = System::Drawing::Size(822, 357);
			this->tabControl_Main->TabIndex = 5;
			// 
			// tabPage_packetLogs
			// 
			this->tabPage_packetLogs->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_packetLogs->Controls->Add(this->checkBox_formattedPacket);
			this->tabPage_packetLogs->Controls->Add(this->checkBox2);
			this->tabPage_packetLogs->Controls->Add(this->listBox_packetLog);
			this->tabPage_packetLogs->Controls->Add(this->checkBox_packetLog);
			this->tabPage_packetLogs->Location = System::Drawing::Point(4, 21);
			this->tabPage_packetLogs->Name = L"tabPage_packetLogs";
			this->tabPage_packetLogs->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_packetLogs->Size = System::Drawing::Size(814, 332);
			this->tabPage_packetLogs->TabIndex = 0;
			this->tabPage_packetLogs->Text = L"Packet Logs";
			// 
			// checkBox_formattedPacket
			// 
			this->checkBox_formattedPacket->AutoSize = true;
			this->checkBox_formattedPacket->Checked = true;
			this->checkBox_formattedPacket->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_formattedPacket->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_formattedPacket->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox_formattedPacket->Location = System::Drawing::Point(160, 310);
			this->checkBox_formattedPacket->Name = L"checkBox_formattedPacket";
			this->checkBox_formattedPacket->Size = System::Drawing::Size(102, 16);
			this->checkBox_formattedPacket->TabIndex = 6;
			this->checkBox_formattedPacket->Text = L"Format Packets";
			this->checkBox_formattedPacket->UseVisualStyleBackColor = true;
			this->checkBox_formattedPacket->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_formattedPacket_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox2->Location = System::Drawing::Point(86, 310);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(68, 16);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"Log Recv";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// tabPage_packetControl
			// 
			this->tabPage_packetControl->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_packetControl->Location = System::Drawing::Point(4, 21);
			this->tabPage_packetControl->Name = L"tabPage_packetControl";
			this->tabPage_packetControl->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_packetControl->Size = System::Drawing::Size(814, 332);
			this->tabPage_packetControl->TabIndex = 1;
			this->tabPage_packetControl->Text = L"Packet Control";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->textBox_sendPacket);
			this->groupBox2->Controls->Add(this->button_sendPacket);
			this->groupBox2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->groupBox2->Location = System::Drawing::Point(10, 368);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(821, 45);
			this->groupBox2->TabIndex = 1109;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Packet Sender";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Azure;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textBox2->Location = System::Drawing::Point(708, 18);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(54, 20);
			this->textBox2->TabIndex = 1202;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox1->Location = System::Drawing::Point(768, 19);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(59, 17);
			this->checkBox1->TabIndex = 1203;
			this->checkBox1->Text = L"Spam";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(641, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 12);
			this->label1->TabIndex = 149;
			this->label1->Text = L"Delay (ms):";
			// 
			// textBox_sendPacket
			// 
			this->textBox_sendPacket->BackColor = System::Drawing::Color::Azure;
			this->textBox_sendPacket->Location = System::Drawing::Point(5, 18);
			this->textBox_sendPacket->Name = L"textBox_sendPacket";
			this->textBox_sendPacket->Size = System::Drawing::Size(576, 20);
			this->textBox_sendPacket->TabIndex = 1;
			// 
			// button_sendPacket
			// 
			this->button_sendPacket->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_sendPacket->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_sendPacket->Location = System::Drawing::Point(587, 18);
			this->button_sendPacket->Name = L"button_sendPacket";
			this->button_sendPacket->Size = System::Drawing::Size(50, 20);
			this->button_sendPacket->TabIndex = 1201;
			this->button_sendPacket->Text = L"Send";
			this->button_sendPacket->UseVisualStyleBackColor = true;
			this->button_sendPacket->Click += gcnew System::EventHandler(this, &MainForm::button_sendPacket_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(842, 425);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->tabControl_Main);
			this->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Fear Packet Engine";
			this->contextMenuStrip_packetLog->ResumeLayout(false);
			this->tabControl_Main->ResumeLayout(false);
			this->tabPage_packetLogs->ResumeLayout(false);
			this->tabPage_packetLogs->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void checkBox_Log_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		log = !log;
	}
	private: System::Void contextMenuStrip_packetLog_ItemClicked(System::Object^ sender, ToolStripItemClickedEventArgs^ e) {
		ToolStripItem^ item = e->ClickedItem;
		if (item->Name == "toolStripMenuItem_copyPacket") {
			if (OpenClipboard(NULL)) {
				String^ packet = listBox_packetLog->Items[listBox_packetLog->SelectedIndex]->ToString();
				HGLOBAL clipbuffer;
				char * buffer;
				EmptyClipboard();
				clipbuffer = GlobalAlloc(GMEM_DDESHARE, packet->Length + 1);
				buffer = (char*) GlobalLock(clipbuffer);
				strcpy(buffer, CString(packet));
				GlobalUnlock(clipbuffer);
				SetClipboardData(CF_TEXT, clipbuffer);
				CloseClipboard();
			}
		}
		else if (item->Name == "toolStripMenuItem_clearPacketLog") {
			listBox_packetLog->Items->Clear();
		}
	}
	private: System::Void listBox_packetLog_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			listBox_packetLog->SelectedIndex = listBox_packetLog->IndexFromPoint(e->Location);
			if (listBox_packetLog->SelectedIndex != -1) {
				contextMenuStrip_packetLog->Items->Clear();
				contextMenuStrip_packetLog->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->toolStripMenuItem_copyPacket,
						this->toolStripMenuItem_clearPacketLog
				});
				contextMenuStrip_packetLog->Show(listBox_packetLog, e->Location);
			}
			else {
				contextMenuStrip_packetLog->Items->Clear();
				contextMenuStrip_packetLog->Items->Add(this->toolStripMenuItem_clearPacketLog);
				contextMenuStrip_packetLog->Show(listBox_packetLog, e->Location);
			}
		}
	}
private: System::Void button_sendPacket_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox_formattedPacket_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	formatPackets = !formatPackets;
}
};

}

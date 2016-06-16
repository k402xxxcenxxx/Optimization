#pragma once
#include "ShaderManager.h"
#include "DataManager.h"
#include "DotNetUtilities.h"
#include "Expression.h"
#include "NewtonMethod.h"
#include "GMethod.h"
#include "QNewton.h"

glm::mat4 ProjectionMatrix;
glm::mat4 ViewMatrix;
glm::mat4 ModelMatrix;

//儲存點位置指標
std::vector<glm::vec3>* Points;
//儲存點顏色指標
std::vector<glm::vec3>* PColors;
//儲存線頭尾點位置指標 
// [0]head [1]tail [2]head [3]tail....
std::vector<glm::vec3>* Lines;
//儲存線頭尾點顏色指標
std::vector<glm::vec3>* LColors;

ShaderManager* shaderManager;


//For OpenGL
double deltaMove = 0;
double x = 0.0f, z = 15, y = 0;
double lx = 0.0f, lz = -1.0f, ly = 0.0f;
double angleH = 90;
double angleV = 90;
double newCameraPosition[3] = { 0,40,40 };
double cameraDistance = 40;
double translateDelta[3];
double targetPosition[3] = { 0,0,0};
double ZoomValue = 0.08;
double prelx = 0.0f;
double prely = 0.0f;
bool isRotate = false;
bool isTranslate = false;
int xOrigin = -1;
int yOrigin = -1;
double maxAngleV = 180;
double minAngleV = 0;
double minDistance = 0.1;

int selectedFunction = -1;
std::vector<Expression> equations;



namespace Optimization {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::TextBox^  Input;

	private: System::Windows::Forms::Label^  InputText;
	private: System::Windows::Forms::Label^  OutputText;
	private: System::Windows::Forms::TextBox^  Output;

	private: HKOGLPanel::HKOGLPanelControl^  hkoglPanelControl1;
	private: System::Windows::Forms::Label^  GraphText;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel3;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadEquationToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;





	protected:

	private:
		DataManager* dataManager;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::SplitContainer^  splitContainer3;
	private: System::Windows::Forms::Button^  NewtonButton;
	private: System::Windows::Forms::Button^  CGButton;
	private: System::Windows::Forms::TextBox^  maxValueBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  minValueBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  initY;
	private: System::Windows::Forms::TextBox^  initX;
	private: System::Windows::Forms::Button^  QnewtonButton;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  minYValueBox;
	private: System::Windows::Forms::TextBox^  maxYValueBox;
	private:System::Windows::Forms::ListBox^  listBox1;

	
			 /// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			HKOGLPanel::HKCOGLPanelCameraSetting^  hkcoglPanelCameraSetting1 = (gcnew HKOGLPanel::HKCOGLPanelCameraSetting());
			HKOGLPanel::HKCOGLPanelPixelFormat^  hkcoglPanelPixelFormat1 = (gcnew HKOGLPanel::HKCOGLPanelPixelFormat());
			
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->GraphText = (gcnew System::Windows::Forms::Label());
			this->hkoglPanelControl1 = (gcnew HKOGLPanel::HKOGLPanelControl());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadEquationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->InputText = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->OutputText = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->QnewtonButton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->initY = (gcnew System::Windows::Forms::TextBox());
			this->initX = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->minValueBox = (gcnew System::Windows::Forms::TextBox());
			this->maxValueBox = (gcnew System::Windows::Forms::TextBox());
			this->CGButton = (gcnew System::Windows::Forms::Button());
			this->NewtonButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->minYValueBox = (gcnew System::Windows::Forms::TextBox());
			this->maxYValueBox = (gcnew System::Windows::Forms::TextBox());
			listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 78.65353F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(957, 609);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::tableLayoutPanel1_Paint);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->GraphText);
			this->flowLayoutPanel1->Controls->Add(this->hkoglPanelControl1);
			this->flowLayoutPanel1->Location = System::Drawing::Point(481, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(473, 603);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// GraphText
			// 
			this->GraphText->AutoSize = true;
			this->GraphText->Location = System::Drawing::Point(3, 0);
			this->GraphText->Name = L"GraphText";
			this->GraphText->Size = System::Drawing::Size(34, 12);
			this->GraphText->TabIndex = 1;
			this->GraphText->Text = L"Graph";
			// 
			// hkoglPanelControl1
			// 
			hkcoglPanelCameraSetting1->Far = 1000;
			hkcoglPanelCameraSetting1->Fov = 45;
			hkcoglPanelCameraSetting1->Near = -1000;
			hkcoglPanelCameraSetting1->Type = HKOGLPanel::HKCOGLPanelCameraSetting::CAMERATYPE::ORTHOGRAPHIC;
			this->hkoglPanelControl1->Camera_Setting = hkcoglPanelCameraSetting1;
			this->hkoglPanelControl1->Location = System::Drawing::Point(3, 15);
			this->hkoglPanelControl1->Name = L"hkoglPanelControl1";
			hkcoglPanelPixelFormat1->Accumu_Buffer_Bits = HKOGLPanel::HKCOGLPanelPixelFormat::PIXELBITS::BITS_0;
			hkcoglPanelPixelFormat1->Alpha_Buffer_Bits = HKOGLPanel::HKCOGLPanelPixelFormat::PIXELBITS::BITS_0;
			hkcoglPanelPixelFormat1->Stencil_Buffer_Bits = HKOGLPanel::HKCOGLPanelPixelFormat::PIXELBITS::BITS_0;
			this->hkoglPanelControl1->Pixel_Format = hkcoglPanelPixelFormat1;
			this->hkoglPanelControl1->Size = System::Drawing::Size(470, 588);
			this->hkoglPanelControl1->TabIndex = 0;
			this->hkoglPanelControl1->Load += gcnew System::EventHandler(this, &MyForm::hkoglPanelControl1_Load);
			this->hkoglPanelControl1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::hkoglPanelControl1_Paint);
			this->hkoglPanelControl1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseDown);
			this->hkoglPanelControl1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseMove);
			this->hkoglPanelControl1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseUp);
			this->hkoglPanelControl1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseWheel);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->splitContainer2);
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(472, 603);
			this->flowLayoutPanel2->TabIndex = 1;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Location = System::Drawing::Point(3, 3);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->splitContainer1);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->splitContainer3);
			this->splitContainer2->Size = System::Drawing::Size(469, 600);
			this->splitContainer2->SplitterDistance = 187;
			this->splitContainer2->TabIndex = 9;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Location = System::Drawing::Point(6, 6);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->flowLayoutPanel3);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->InputText);
			this->splitContainer1->Panel2->Controls->Add(this->Input);
			this->splitContainer1->Size = System::Drawing::Size(467, 177);
			this->splitContainer1->SplitterDistance = 26;
			this->splitContainer1->TabIndex = 8;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Controls->Add(this->menuStrip1);
			this->flowLayoutPanel3->Location = System::Drawing::Point(6, 3);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(467, 33);
			this->flowLayoutPanel3->TabIndex = 5;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(138, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->loadEquationToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadEquationToolStripMenuItem
			// 
			this->loadEquationToolStripMenuItem->Name = L"loadEquationToolStripMenuItem";
			this->loadEquationToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->loadEquationToolStripMenuItem->Text = L"Load Equation";
			this->loadEquationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadEquationToolStripMenuItem_Click);
			// 
			// InputText
			// 
			this->InputText->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InputText->AutoSize = true;
			this->InputText->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->InputText->Location = System::Drawing::Point(4, 9);
			this->InputText->Name = L"InputText";
			this->InputText->Size = System::Drawing::Size(30, 12);
			this->InputText->TabIndex = 2;
			this->InputText->Text = L"Input";
			this->InputText->Click += gcnew System::EventHandler(this, &MyForm::InputText_Click);
			// 
			// Input
			// 
			this->Input->Location = System::Drawing::Point(3, 28);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(460, 119);
			this->Input->TabIndex = 0;
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Name = L"splitContainer3";
			this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->OutputText);
			this->splitContainer3->Panel1->Controls->Add(this->Output);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->label4);
			this->splitContainer3->Panel2->Controls->Add(this->label5);
			this->splitContainer3->Panel2->Controls->Add(this->minYValueBox);
			this->splitContainer3->Panel2->Controls->Add(this->maxYValueBox);
			this->splitContainer3->Panel2->Controls->Add(this->QnewtonButton);
			this->splitContainer3->Panel2->Controls->Add(this->label3);
			this->splitContainer3->Panel2->Controls->Add(this->initY);
			this->splitContainer3->Panel2->Controls->Add(this->initX);
			this->splitContainer3->Panel2->Controls->Add(this->label2);
			this->splitContainer3->Panel2->Controls->Add(this->label1);
			this->splitContainer3->Panel2->Controls->Add(this->minValueBox);
			this->splitContainer3->Panel2->Controls->Add(this->maxValueBox);
			this->splitContainer3->Panel2->Controls->Add(this->CGButton);
			this->splitContainer3->Panel2->Controls->Add(this->NewtonButton);
			this->splitContainer3->Panel2->Controls->Add(this->button1);
			this->splitContainer3->Panel2->Controls->Add(listBox1);
			this->splitContainer3->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::splitContainer3_Panel2_Paint);
			this->splitContainer3->Size = System::Drawing::Size(469, 409);
			this->splitContainer3->SplitterDistance = 204;
			this->splitContainer3->TabIndex = 8;
			// 
			// OutputText
			// 
			this->OutputText->AutoSize = true;
			this->OutputText->Location = System::Drawing::Point(6, 16);
			this->OutputText->Name = L"OutputText";
			this->OutputText->Size = System::Drawing::Size(37, 12);
			this->OutputText->TabIndex = 3;
			this->OutputText->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Output->Location = System::Drawing::Point(0, 31);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Output->Size = System::Drawing::Size(469, 173);
			this->Output->TabIndex = 4;
			// 
			// QnewtonButton
			// 
			this->QnewtonButton->Location = System::Drawing::Point(301, 2);
			this->QnewtonButton->Name = L"QnewtonButton";
			this->QnewtonButton->Size = System::Drawing::Size(84, 23);
			this->QnewtonButton->TabIndex = 17;
			this->QnewtonButton->Text = L"Quasi-newton";
			this->QnewtonButton->UseVisualStyleBackColor = true;
			this->QnewtonButton->Click += gcnew System::EventHandler(this, &MyForm::QnewtonButton_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(283, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 12);
			this->label3->TabIndex = 16;
			this->label3->Text = L"initial point";
			// 
			// initY
			// 
			this->initY->Location = System::Drawing::Point(321, 143);
			this->initY->Name = L"initY";
			this->initY->Size = System::Drawing::Size(32, 22);
			this->initY->TabIndex = 15;
			this->initY->Text = L"0";
			// 
			// initX
			// 
			this->initX->Location = System::Drawing::Point(285, 143);
			this->initX->Name = L"initX";
			this->initX->Size = System::Drawing::Size(30, 22);
			this->initX->TabIndex = 14;
			this->initX->Text = L"0.3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(285, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 12);
			this->label2->TabIndex = 13;
			this->label2->Text = L"X min value";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(362, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 12);
			this->label1->TabIndex = 12;
			this->label1->Text = L"X max value";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// minValueBox
			// 
			this->minValueBox->Location = System::Drawing::Point(285, 47);
			this->minValueBox->Name = L"minValueBox";
			this->minValueBox->Size = System::Drawing::Size(62, 22);
			this->minValueBox->TabIndex = 11;
			this->minValueBox->Text = L"0";
			// 
			// maxValueBox
			// 
			this->maxValueBox->Location = System::Drawing::Point(364, 47);
			this->maxValueBox->Name = L"maxValueBox";
			this->maxValueBox->Size = System::Drawing::Size(62, 22);
			this->maxValueBox->TabIndex = 10;
			this->maxValueBox->Text = L"2";
			// 
			// CGButton
			// 
			this->CGButton->Location = System::Drawing::Point(105, 3);
			this->CGButton->Name = L"CGButton";
			this->CGButton->Size = System::Drawing::Size(109, 23);
			this->CGButton->TabIndex = 9;
			this->CGButton->Text = L"Conjugate Gradient ";
			this->CGButton->UseVisualStyleBackColor = true;
			this->CGButton->Click += gcnew System::EventHandler(this, &MyForm::CGButton_Click);
			// 
			// NewtonButton
			// 
			this->NewtonButton->Location = System::Drawing::Point(220, 3);
			this->NewtonButton->Name = L"NewtonButton";
			this->NewtonButton->Size = System::Drawing::Size(75, 23);
			this->NewtonButton->TabIndex = 8;
			this->NewtonButton->Text = L"Newton";
			this->NewtonButton->UseVisualStyleBackColor = true;
			this->NewtonButton->Click += gcnew System::EventHandler(this, &MyForm::NewtonButton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"clear log";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listBox1
			// 
			listBox1->FormattingEnabled = true;
			listBox1->ItemHeight = 12;
			listBox1->Location = System::Drawing::Point(8, 32);
			listBox1->Name = L"listBox1";
			listBox1->Size = System::Drawing::Size(271, 160);
			listBox1->TabIndex = 7;
			listBox1->Tag = L"";
			listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(285, 77);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 12);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Y min value";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(362, 77);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(64, 12);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Y max value";
			// 
			// minYValueBox
			// 
			this->minYValueBox->Location = System::Drawing::Point(285, 92);
			this->minYValueBox->Name = L"minYValueBox";
			this->minYValueBox->Size = System::Drawing::Size(62, 22);
			this->minYValueBox->TabIndex = 19;
			this->minYValueBox->Text = L"0";
			// 
			// maxYValueBox
			// 
			this->maxYValueBox->Location = System::Drawing::Point(364, 92);
			this->maxYValueBox->Name = L"maxYValueBox";
			this->maxYValueBox->Size = System::Drawing::Size(62, 22);
			this->maxYValueBox->TabIndex = 18;
			this->maxYValueBox->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 609);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"MyForm";
			this->Text = L"Optimization";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel1->PerformLayout();
			this->splitContainer3->Panel2->ResumeLayout(false);
			this->splitContainer3->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	void UpdateViewMatrix()
	{
		double theta = angleV * (3.14159f / 180.0f);
		double phi = angleH * (3.14159f / 180.0f);

		newCameraPosition[0] = cameraDistance * sin(theta) * cos(phi);
		newCameraPosition[1] = cameraDistance * cos(theta);
		newCameraPosition[2] = cameraDistance * sin(theta) * sin(phi);

		for (int i = 0; i<3; i++)
			targetPosition[i] += translateDelta[i];
		for (int i = 0; i<3; i++)
			newCameraPosition[i] += targetPosition[i];

		ViewMatrix = glm::lookAt(
			glm::vec3(newCameraPosition[0], newCameraPosition[1], newCameraPosition[2]), // Camera in World Space
			glm::vec3(targetPosition[0], targetPosition[1], targetPosition[2]), // and looks at the origin
			glm::vec3(0, 1, 0)  // Head is up (set to 0,1,0 to look upside-down)
			);
	}




	glm::mediump_float function1(glm::vec2 &p)
	{
		return (p.x - 10)*(5 * p.x - 10) / 50 + (p.y - 10)*(p.y - 10) / 50;//x[0]*x[0]/50+x[1]*x[1]/50;
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
	{
		
	}
	private: System::Void hkoglPanelControl1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		GLenum res = glewInit();
		if (res != GLEW_OK) {
			fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		}
		glClearColor(0, 0, 0, 1);

		//Set up MVP matrix
		ProjectionMatrix = glm::perspective(60.0f, 588.0f / 470.0f, 0.1f, 2000.0f);

		ViewMatrix = glm::lookAt(
			glm::vec3(newCameraPosition[0], newCameraPosition[1], newCameraPosition[2]), // Camera in World Space
			glm::vec3(targetPosition[0],    targetPosition[1],    targetPosition[2]), // and looks at the origin
			glm::vec3(0, 1, 0)  // Head is up (set to 0,1,0 to look upside-down)
			);

		ModelMatrix = glm::mat4(0);
		ModelMatrix[0][0] = 1.0;
		ModelMatrix[1][1] = 1.0;
		ModelMatrix[2][2] = 1.0;
		ModelMatrix[3][3] = 1.0;

		shaderManager = new ShaderManager();

		 Points = &shaderManager->Points;
		 PColors = &shaderManager->PColors;
		 Lines = &shaderManager->Lines;
		 LColors = &shaderManager->LColors;
		
		 //將點丟入資料結構範例
		glPointSize(1);
		glm::vec3 initialpoint;
		initialpoint.x = 50;
		initialpoint.y = 30;
		initialpoint.z = function1(glm::vec2(initialpoint.x, initialpoint.y));
		Points->push_back(initialpoint);
		PColors->push_back(glm::vec3(0.3921, 0, 0.6078));
		for (int i = -50; i < 70; i += 2)
		{
			for (int j = -70; j < 70; j += 2)
			{
				glm::vec3 p;
				p.x = (float)i;
				p.y = (float)j;
				p.z = function1(glm::vec2(i, j));
				Points->push_back(p);
				PColors->push_back(glm::vec3(1, 0, 0));
			}
		}
		//將線丟入資料結構範例
		Lines->push_back(initialpoint);
		LColors->push_back(glm::vec3(0, 0, 1));
		Lines->push_back(glm::vec3(0, 0, 0));
		LColors->push_back(glm::vec3(0, 0, 1));
		
	}
private: System::Void hkoglPanelControl1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
{
	UpdateViewMatrix();

	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shaderManager->Render(ProjectionMatrix, ViewMatrix, ModelMatrix);
}

private: System::Void hkoglPanelControl1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		isRotate = true;
		xOrigin = e->X;
		yOrigin = e->Y;
	}
	if (e->Button == System::Windows::Forms::MouseButtons::Middle)
	{
		isTranslate = true;
		xOrigin = e->X;
		yOrigin = e->Y;
	}
	hkoglPanelControl1->Invalidate();
}
private: System::Void hkoglPanelControl1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		isRotate = false;
		prelx = lx;
		prely = ly;
	}
	if (e->Button == System::Windows::Forms::MouseButtons::Middle)
	{
		isTranslate = false;
		translateDelta[0] = 0;
		translateDelta[1] = 0;
		translateDelta[2] = 0;
	}
	hkoglPanelControl1->Invalidate();
}
private: System::Void hkoglPanelControl1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
	if (isRotate)
	{
		angleV -= (e->Y - yOrigin) / 10.0f;
		angleH += (e->X - xOrigin) / 10.0f;
		angleV = (((angleV) > (minAngleV)) ? (angleV) : (minAngleV));
		angleV = (((angleV) < (maxAngleV)) ? (angleV) : (maxAngleV));
		xOrigin = e->X;
		yOrigin = e->Y;
	}
	if (isTranslate)
	{
		double phi = angleH * (3.14159f / 180.0f);
		translateDelta[0] = (e->X - xOrigin) / 10.0f;
		translateDelta[1] = (e->Y - yOrigin) / 10.0f;
		translateDelta[2] = 0.0f;

		translateDelta[2] = translateDelta[0] * cos(phi);
		translateDelta[0] = -1.0*translateDelta[0] * sin(phi);
		xOrigin = e->X;
		yOrigin = e->Y;
	}
	hkoglPanelControl1->Invalidate();
}
private: System::Void hkoglPanelControl1_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (e->Delta > 0)
	{
		cameraDistance -= 0.05f * abs(cameraDistance);
		cameraDistance = (((cameraDistance) > (minDistance)) ? (cameraDistance) : (minDistance));	
	}
	else
	{
		cameraDistance += 0.05f * abs(cameraDistance);
		cameraDistance = (((cameraDistance) > (minDistance)) ? (cameraDistance) : (minDistance));
	}
	hkoglPanelControl1->Invalidate();
}
private: System::Void loadEquationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	openFileDialog1->InitialDirectory = "../";
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->ShowDialog();
}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
{
	//在Dialog按下OK便會進入此函式
	//字串轉制string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	//將檔案路徑名稱傳入dataManager
	dataManager->SetFileName(tempFileName);
	//從讀取讀取向量資料
	if (dataManager->LoadEquationData())
	{
		equations = dataManager->GetExpressions();
		Output->Multiline = true;
		
		listBox1->Items->Clear();

		for (unsigned int i = 0; i < equations.size(); i++)
		{
			Output->Text += gcnew String(equations[i].toString().c_str());
			listBox1->Items->Add(gcnew String(equations[i].toString().c_str()));
			Output->Text += Environment::NewLine;
		}
	}
}
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Output->Text = "";
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	selectedFunction = listBox1->SelectedIndex;
}
private: System::Void InputText_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void splitContainer3_Panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void NewtonButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (selectedFunction != -1) {
		NewtonMethod N;
		Expression tempExpression;
		std::vector<Point2d> result_points;

		Point2d init_point;
		init_point = Point2d(System::Convert::ToDouble(initX->Text), System::Convert::ToDouble(initY->Text));

		tempExpression = equations[selectedFunction];

		std::string *s = new std::string();

		result_points = N.Newton(tempExpression, init_point, s);

		Output->Text += gcnew String("newton :");
		Output->Text += gcnew String(tempExpression.toString().c_str());
		Output->Text += Environment::NewLine;
		Output->Text += gcnew String(s->c_str());
		Output->Text += Environment::NewLine;

		Points->clear();
		PColors->clear();
		Lines->clear();
		LColors->clear();

		//將點丟入資料結構範例
		glPointSize(1);
		glm::vec3 initialpoint;
		initialpoint.x = init_point.x;
		initialpoint.y = init_point.y;
		initialpoint.z = tempExpression.getValue(init_point.x, init_point.y);

		Points->push_back(initialpoint);
		PColors->push_back(glm::vec3(0.3921, 0, 0.6078));
		for (float i = -50; i < 70; i += 0.5f)
		{
			for (float j = -70; j < 70; j += 0.5f)
			{
				glm::vec3 p;
				p.x = (float)i;
				p.y = (float)j;
				p.z = tempExpression.getValue(i, j);
				Points->push_back(p);
				PColors->push_back(glm::vec3(1, 0, 0));
			}
		}
		//將線丟入資料結構範例
		Lines->push_back(initialpoint);
		LColors->push_back(glm::vec3(0, 0, 1));

		for (int i = 0; i < result_points.size(); i++) {
			glm::vec3 p;
			p.x = (float)result_points[i].x;
			p.y = (float)result_points[i].y;
			p.z = tempExpression.getValue(result_points[i].x, result_points[i].y);
			std::cout << "line" << result_points[i].toString() << std::endl;
			Lines->push_back(p);
			LColors->push_back(glm::vec3(0, 0, 1));
		}

		std::cout << "line size = " << Lines->size() << std::endl;
	}
}
private: System::Void CGButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (selectedFunction != -1) {
		CGMethod CG;
		Expression tempExpression;
		std::vector<Point2d> result_points;
		Point2d init_point;
		init_point = Point2d(System::Convert::ToDouble(initX->Text), System::Convert::ToDouble(initY->Text));

		tempExpression = equations[selectedFunction];

		std::string *s = new std::string();

		result_points = CG.CG(tempExpression, init_point, s, System::Convert::ToDouble(maxValueBox->Text), System::Convert::ToDouble(minValueBox->Text), System::Convert::ToDouble(maxYValueBox->Text), System::Convert::ToDouble(minYValueBox->Text));

		Output->Text += gcnew String("conjugate gradient :");
		Output->Text += gcnew String(tempExpression.toString().c_str());
		Output->Text += Environment::NewLine;
		Output->Text += gcnew String(s->c_str());
		Output->Text += Environment::NewLine;

		Points->clear();
		PColors->clear();
		Lines->clear();
		LColors->clear();

		//將點丟入資料結構範例
		glPointSize(1);
		glm::vec3 initialpoint;
		initialpoint.x = init_point.x;
		initialpoint.y = init_point.y;
		initialpoint.z = tempExpression.getValue(init_point.x, init_point.y);

		Points->push_back(initialpoint);
		PColors->push_back(glm::vec3(0.3921, 0, 0.6078));
		for (float i = -50; i < 70; i += 0.5f)
		{
			for (float j = -70; j < 70; j += 0.5f)
			{
				glm::vec3 p;
				p.x = (float)i;
				p.y = (float)j;
				p.z = tempExpression.getValue(i, j);
				Points->push_back(p);
				PColors->push_back(glm::vec3(1, 0, 0));
			}
		}
		//將線丟入資料結構範例
		//Lines->push_back(initialpoint);
		//LColors->push_back(glm::vec3(0, 0, 1));

		for (int i = 0; i < result_points.size(); i++) {
			glm::vec3 p;
			p.x = (float)result_points[i].x;
			p.y = (float)result_points[i].y;
			p.z = tempExpression.getValue(result_points[i].x, result_points[i].y);
			std::cout <<"line"<< result_points[i].toString() << std::endl;
			if (i != 0) {
				Lines->push_back(p);
				LColors->push_back(glm::vec3(0, 0, 1));
			}
			Lines->push_back(p);
			LColors->push_back(glm::vec3(0, 0, 1));
		}
		std::cout << "line size = " << Lines->size() << std::endl;
	}
}
private: System::Void QnewtonButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (selectedFunction != -1) {
		QNewton QN;
		Expression tempExpression;
		Point2d init_point;
		std::vector<Point2d> result_points;

		tempExpression = equations[selectedFunction];
		init_point = Point2d(System::Convert::ToDouble(initX->Text), System::Convert::ToDouble(initY->Text));

		std::string *s = new std::string();

		result_points = QN.QuasiNewton(tempExpression, init_point, System::Convert::ToDouble(maxValueBox->Text), System::Convert::ToDouble(minValueBox->Text), s);

		Output->Text += gcnew String("Quasi-Newton :");
		Output->Text += gcnew String(tempExpression.toString().c_str());
		Output->Text += Environment::NewLine;
		Output->Text += gcnew String(s->c_str());
		Output->Text += Environment::NewLine;

		Points->clear();
		PColors->clear();
		Lines->clear();
		LColors->clear();

		//將點丟入資料結構範例
		glPointSize(1);
		glm::vec3 initialpoint;
		initialpoint.x = init_point.x;
		initialpoint.y = init_point.y;
		initialpoint.z = tempExpression.getValue(init_point.x, init_point.y);

		Points->push_back(initialpoint);
		PColors->push_back(glm::vec3(0.3921, 0, 0.6078));
		for (float i = -50; i < 70; i += 0.5f)
		{
			for (float j = -70; j < 70; j += 0.5f)
			{
				glm::vec3 p;
				p.x = (float)i;
				p.y = (float)j;
				p.z = tempExpression.getValue(i, j);
				Points->push_back(p);
				PColors->push_back(glm::vec3(1, 0, 0));
			}
		}
		//將線丟入資料結構範例
		//Lines->push_back(initialpoint);
		//LColors->push_back(glm::vec3(0, 0, 1));

		for (int i = 0; i < result_points.size(); i++) {
			glm::vec3 p;
			p.x = (float)result_points[i].x;
			p.y = (float)result_points[i].y;
			p.z = tempExpression.getValue(result_points[i].x, result_points[i].y);
			if(i != 0){
				Lines->push_back(p);
				LColors->push_back(glm::vec3(0, 0, 1));
			}
			Lines->push_back(p);
			LColors->push_back(glm::vec3(0, 0, 1));
		}
		std::cout << "line size = " << Lines->size() << std::endl;
	}
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}

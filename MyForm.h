#pragma once
#include "ShaderManager.h"
#include "DataManager.h"
#include "DotNetUtilities.h"


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
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadEquationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->InputText = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->OutputText = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			this->menuStrip1->SuspendLayout();
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
			this->flowLayoutPanel2->Controls->Add(this->flowLayoutPanel3);
			this->flowLayoutPanel2->Controls->Add(this->InputText);
			this->flowLayoutPanel2->Controls->Add(this->Input);
			this->flowLayoutPanel2->Controls->Add(this->OutputText);
			this->flowLayoutPanel2->Controls->Add(this->Output);
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(472, 603);
			this->flowLayoutPanel2->TabIndex = 1;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Controls->Add(this->menuStrip1);
			this->flowLayoutPanel3->Location = System::Drawing::Point(3, 3);
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
			this->InputText->Location = System::Drawing::Point(3, 39);
			this->InputText->Name = L"InputText";
			this->InputText->Size = System::Drawing::Size(30, 12);
			this->InputText->TabIndex = 2;
			this->InputText->Text = L"Input";
			// 
			// Input
			// 
			this->Input->Location = System::Drawing::Point(3, 54);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(467, 74);
			this->Input->TabIndex = 0;
			// 
			// OutputText
			// 
			this->OutputText->AutoSize = true;
			this->OutputText->Location = System::Drawing::Point(3, 131);
			this->OutputText->Name = L"OutputText";
			this->OutputText->Size = System::Drawing::Size(37, 12);
			this->OutputText->TabIndex = 3;
			this->OutputText->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Location = System::Drawing::Point(3, 146);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->Size = System::Drawing::Size(467, 347);
			this->Output->TabIndex = 4;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
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
			this->flowLayoutPanel2->PerformLayout();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
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
		std::vector<std::string> equations = dataManager->GetEquations();
		Output->Multiline = true;
		for (unsigned int i = 0; i < equations.size(); i++)
		{
			Output->Text += gcnew String(equations[i].c_str());
			Output->Text += Environment::NewLine;
		}
	}
}
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
};
}

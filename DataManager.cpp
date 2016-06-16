#include "DataManager.h"

DataManager::DataManager()
{
	EquationIndex = 0;
}

bool DataManager::LoadEquationData()
{
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempSring;
		//�w�q�Ȧs��ܦ�
		Expression tempExpression;

		std::vector<std::string> variableStrings;

		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
		//�C�@�泣�O�@�Ӧ��l
		while (!fin.eof())
		{

			//�q�ɮ�Ū���r��
			fin >> tempSring;

			std::cout << "original : " << tempSring << std::endl;

			//���l���l������
			std::istringstream f = std::istringstream(tempSring);
			std::string buf;//�s���X�Ӫ��r��

			//����'+'������
			while (std::getline(f, buf, '+')) {
				//�A��'-'���A�p�G�O���]�t'-'���A�|�b���ĤG������X�{
				std::istringstream f2 = std::istringstream(buf);
				std::string s;
				std::getline(f2, s, '-');

				//'+'��
				variableStrings.push_back(s);

				//�p�G�٥i�H���A�N�O'-'��
				while (std::getline(f2, s, '-')) {
					variableStrings.push_back("-" + s);
				}
			}

			//�z�פW�{�bvariableStrings�O�s�Ҧ���(�`�ơB�ܼ�)���r��

			//�{�b�n�q�Ҧ�������X�Y��
			for each (std::string variableString in variableStrings) {
				std::istringstream f = std::istringstream(variableString);

				double coefficient = 1.0;//�w�]�Y�Ƭ�1
				double powerX = 1.0;//�w�]����Ƭ�1
				double powerY = 1.0;//�w�]����Ƭ�1
				std::string variableX = "";
				std::string variableY = "";

				while (std::getline(f, buf, '*')) {
					//�{�b�w�g��'*'�j�}�F�A�j�}���r��s�bbuf

					std::istringstream f2 = std::istringstream(buf);
					std::string s;
					//�յۤ��X�Ĥ@��'^'�A�p�G�O�Ʀr�N���Y��
					if (std::getline(f2, s, '^')) {

						if (std::atof(s.c_str()) != 0.0) {
							coefficient = std::atof(s.c_str());
						}
						else if(s == "x"){
							variableX += s;
						}
						else if (s == "y") {
							variableY += s;
						}

					}

					//�յۤ��X�ĤG��'^'�A�p�G�O�Ʀr�N�������
					if (std::getline(f2, s, '^')) {
						if (std::atof(s.c_str()) != 0.0) {

							if(variableX == "x" && powerX == 1.0)
								powerX = std::atof(s.c_str());
							else if(variableY == "y" && powerY == 1.0)
								powerY = std::atof(s.c_str());
						}
					}
				}

				if (variableX == "" && variableY =="") {
					//std::cout << "�`�ƶ� : " << coefficient << std::endl;
					tempExpression.add(variable(coefficient));
				}
				else if(variableX != "" && variableY == ""){
					//std::cout << "�ܼ� : "<< coefficient << " * " << variableX << " ^ " << powerX << std::endl;
					tempExpression.add(variable(coefficient,powerX,0));
				}
				else if (variableX == "" && variableY != "") {
					//std::cout << "�ܼ� : " << coefficient << " * " << variableY << " ^ " << powerY << std::endl;
					tempExpression.add(variable(coefficient,0.0, powerY));
				}
				else if (variableX != "" && variableY != "") {
					//std::cout << "�ܼ� : " << coefficient << " * " << variableX << " ^ " << powerX << " * " << variableY << " ^ " << powerY << std::endl;
					tempExpression.add(variable(coefficient, powerX, powerY));
				}
			}

			//���WEquationIndex�A�аO���eŪ���V�qID
			EquationIndex++;
			Expressions.push_back(tempExpression);

			std::cout << EquationIndex<< " : " << tempExpression.toString() << std::endl;

			
			//CGMethod CG;
			//std::string *s = new std::string();
			//CG.CG(tempExpression, Point2d(0.3,0.0), s);
			
			//std::cout << *s << std::endl;

			tempExpression.clear();
			variableStrings.clear();
		}

		

		return true;
	}
}

std::vector<Expression> DataManager::GetExpressions()
{
	return Expressions;
}

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

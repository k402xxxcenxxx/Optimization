#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Expression.h"

//�w�q���޸��class
class DataManager
{
private:
	//�x�s��{�����
	std::vector<Expression> Expressions;
	//�����V�qID�A�Ω󱱺�
	int EquationIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadEquationData();
	//���o�V�q���
	std::vector<Expression> GetExpressions();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
};
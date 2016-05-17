#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include <sstream>

//�w�q���޸��class
class DataManager
{
private:
	//�x�s��{�����
	std::vector<std::string> Equations;
	//�����V�qID�A�Ω󱱺�
	int EquationIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadEquationData();
	//���o�V�q���
	std::vector<std::string> GetEquations();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
};
#include "DataManager.h"

DataManager::DataManager()
{
	EquationIndex = 0;
}

bool DataManager::LoadEquationData()
{
	std::istringstream stringSpliter;

	std::fstream fin;
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{
		//定義讀取檔案字串暫存變數
		std::string tempSring;

		std::vector<std::string> subString;

		//執行讀檔迴圈，並在讀到檔案結尾時結束
		while (!fin.eof())
		{
			//從檔案讀取字串
			fin >> tempSring;

			std::cout << "original : " << tempSring << std::endl;

			subString.clear();

			//對原始式子做切割
			std::istringstream f = std::istringstream(tempSring);
			std::string buf;//存切出來的字串

			//先用'+'做切割
			while (std::getline(f, buf, '+')) {
				//再用'-'切，如果是有包含'-'的，會在切第二次之後出現
				std::istringstream f2 = std::istringstream(buf);
				std::string s;
				std::getline(f2, s, '-');

				//'+'的
				subString.push_back(s);

				//如果還可以切，就是'-'的
				while (std::getline(f2, s, '-')) {
					subString.push_back("-" + s);
				}
			}

			//理論上現在subString是存所有項(常數、變數)的字串

			//現在要從所有項次找出係數
			for each (std::string subEquations in subString) {
				stringSpliter = std::istringstream(subEquations);

				double coefficient = 1.0;//預設係數為1
				double powerX = 1.0;//預設次方數為1
				double powerY = 1.0;//預設次方數為1
				std::string variableX = "";
				std::string variableY = "";

				while (std::getline(stringSpliter, buf, '*')) {
					//現在已經用'*'隔開了，隔開的字串存在buf

					std::istringstream f2 = std::istringstream(buf);
					std::string s;
					//試著切出第一個'^'，如果是數字代表為係數
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

					//試著切出第二個'^'，如果是數字代表為次方數
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
					std::cout << "常數項 : " << coefficient << std::endl;
				}
				else if(variableX != "" && variableY == ""){
					std::cout << "變數 : "<< coefficient << " * " << variableX << " ^ " << powerX << std::endl;
				}
				else if (variableX == "" && variableY != "") {
					std::cout << "變數 : " << coefficient << " * " << variableY << " ^ " << powerY << std::endl;
				}
				else if (variableX != "" && variableY != "") {
					std::cout << "變數 : " << coefficient << " * " << variableX << " ^ " << powerX << " * " << variableY << " ^ " << powerY << std::endl;
				}

			}

			//解析到向量標記"V"
			//Equations.push_back(tempSring);
			//遞增EquationIndex，標記到當前讀取向量ID
			EquationIndex++;

		}
		return true;
	}
}

std::vector<std::string> DataManager::GetEquations()
{
	return Equations;
}

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

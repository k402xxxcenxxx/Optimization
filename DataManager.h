#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Expression.h"

//定義控管資料class
class DataManager
{
private:
	//儲存方程式資料
	std::vector<Expression> Expressions;
	//紀錄向量ID，用於控管
	int EquationIndex;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();
	//讀取向量資料
	bool LoadEquationData();
	//取得向量資料
	std::vector<Expression> GetExpressions();
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
};
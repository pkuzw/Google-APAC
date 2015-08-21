///@file	Moist
///@author	zhaowei
///@date	2015.08.16
///@version	0.1

///@date	2015.08.21
///@version	0.2
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("C:\\Users\\Zhao Wei\\Downloads\\C-small-practice-1.in");
	
	ofstream fout;
	fout.open("C:\\Users\\Zhao Wei\\Downloads\\C-small-practice-1.out");
	if (fin.is_open()){
		int test_num = 0;
		fin >> test_num;
		fout << test_num << endl;
		for (int i = 0; i != test_num; i++)
		{
			int name_num = 0;
			fin >> name_num;	
			fout << name_num << endl;
			vector<string> names;
			for (int j = 0; j <= name_num; j++)
			{
				string name;
				getline(fin, name);
				if (name.empty()) continue;	//	为什么会有一个空字符串呢？
				names.push_back(name);
				fout << name << endl;
			}
		}
	}

	fin.close();
	fout.close();
	return 0;
}
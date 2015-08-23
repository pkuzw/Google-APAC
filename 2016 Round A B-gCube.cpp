#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;



int main()
{
	ifstream fin;
	fin.open("C:\\Users\\Zhao Wei\\Downloads\\B-small-attempt0.in");
	ofstream fout;
	fout.open("C:\\Users\\Zhao Wei\\Downloads\\B-small-attempt0.out");

	int test_num = 0;
	fin >> test_num;
	for (int i = 0; i != test_num; i++)
	{
		int dmn_num = 0;
		fin >> dmn_num;
		int qry_num = 0;
		fin >> qry_num;
		vector<int> lens(dmn_num, 0);
		for (int j = 0; j != dmn_num; j++)
			fin >> lens[j];
		fout << "Case #" << i+1 << ":" << endl;
		for (int k = 0; k != qry_num; k++)
		{
			int l_dmn = 0, r_dmn = 0;
			fin >> l_dmn >> r_dmn;
			double vol = 1;
			for (int l = l_dmn; l <= r_dmn; l++)
			{
				vol *= lens[l];
			}
			double cub_len = pow(vol, double(1.0 / double(r_dmn - l_dmn + 1)));
			fout.setf(ios::fixed);
			fout.precision(9);
			fout << cub_len << endl;
		}
	}
	return 0;
}
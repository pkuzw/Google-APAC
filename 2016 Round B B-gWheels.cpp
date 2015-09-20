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
#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;

//大数据超时

bool helper(vector<double>& pt, vector<double>& et, vector<double>& tt, double p, double q) {
	for (int i = 0; i != pt.size(); i++) {
		double a = pt[i] * q;
		for (int j = 0; j != et.size(); j++) {
			double b = a;
			b /= et[j];
			for (int k = 0; k != et.size(); k++) {
				if (k == j)	continue;
				double c = b;
				c *= et[k];
				c /= p;
				if (binary_search(tt.begin(), tt.end(), c)) return true;				
			}
		}
	}
	return false;
}


		int np = 0, ne = 0, nt = 0;
		fin >> np >> ne >>  nt;
		vector<double> pteeth(np, 0.0);
		vector<double> eteeth(ne, 0.0);
		vector<double> tteeth(nt, 0.0);
		for (int i = 0; i != np; i++)	fin >> pteeth[i];
		for (int i = 0; i != ne; i++)	fin >> eteeth[i];
		for (int i = 0; i != nt; i++)	fin >> tteeth[i];
		sort(tteeth.begin(), tteeth.end());
		int m = 0;
		int question_num = 0;
		fin >> question_num;
		fout << "Case #" << t << ": " << endl;
		while (m < question_num) {
			m++;
			double p = 0.0, q = 0.0;
			fin >> p >> q;
			if (helper(pteeth, eteeth, tteeth, p, q))	fout << "Yes" << endl;
			else fout << "No" << endl;
		}
		t++;
	}

	fin.close();
	fout.close();
	return 0;
}
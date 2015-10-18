#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <list>
#include <stack>
#include <queue>

using namespace std;

struct player {
	string name;
	int scores;
};

struct myObj {
	bool operator() (player a, player b) {
		if (a.scores > b.scores)	return true;
		else if (a.scores == b.scores)	return a.name < b.name;
		else return false;
	}
} myobject;

int main() {
	ifstream fin;
	fin.open("C:\\Users\\Zhao Wei\\Downloads\\A-small.txt");
	ofstream fout;
	fout.open("C:\\Users\\Zhao Wei\\Downloads\\A-small.out");

	int case_num = 0;
	fin >> case_num;
	int num = 1;
	while (num <= case_num) {
		int p = 0;
		fin >> p;
		vector<int> points(p, 0);
		for (int i = 0; i != p; i++)	fin >> points[i];
		int n = 0;
		fin >> n;
		unordered_map<string, multiset<int, greater<int>>> ht;
		vector<int> weights(n, 0);
		for (int i = 0; i != n; i++) {
			fin >> weights[i];
			for (int j = 0; j != p; j++) {
				string name;
				fin >> name;
				ht[name].insert(weights[i] * points[j]);				
			}			
		}
		int comp_num = 0;
		fin >> comp_num;

		vector<player> vec_p(ht.size());
		int k = 0;
		for (unordered_map<string, multiset<int, greater<int>>>::iterator i = ht.begin(); i != ht.end(); i++) {
			vec_p[k].name = i->first;
			int scr = 0;
			int brk = 0;
			for (multiset<int, greater<int>>::iterator j = i->second.begin(); j != i->second.end() && brk < comp_num; j++) {
				scr += *j;
				brk++;
			}
			vec_p[k].scores = scr;
		}
		sort(vec_p.begin(), vec_p.end(), myobject);
		fout << "Case #" << num << ":" << endl;
		int t = 0;
		while (t < vec_p.size()) {
			fout << t << ": " << vec_p[t].name << endl;
			t++;
		}
		num++;
	}

	fin.close();
	fout.close();
	return 0;
}
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

int main() {
	ifstream fin;
	fin.open("C:\\Users\\Zhao Wei\\Downloads\\B-small-attemtp-1.in");
	ofstream fout;
	fout.open("C:\\Users\\Zhao Wei\\Downloads\\B-small-attempt-1.out");

	int case_num = 0;
	fin >> case_num;
	int num = 1;
	while (num <= case_num) {
		int N = 0;
		fin >> N;
		vector<vector<int>> list(N, vector<int>(2, 0));
		for (int i = 0; i < N; i++)
			fin >> list[i][0] >> list[i][1];
		int min = 0;
		int max = INT_MAX;		
		for(int i = 0; i < N; i++){
			int p = list[i][0];
			int k = list[i][1];
			int u = (100*k+p+1)/(p+1);
			int v = (100*k)/p;
			if(u > min){
				min = u;
			}
			if(v < max){
				max = v;
			}
		}
		fout << "Case #" << num << ": " << endl;
		if(min == max){
			fout << max << endl;;
		}else{
			fout << -1 << endl;
			fout << min << endl;
			fout << max << endl;
		}
		num++;
	}
	fin.close();
	fout.close();
	return 0;
}
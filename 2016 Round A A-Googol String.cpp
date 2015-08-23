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

vector<long long> candidates;

int main()
{
	ifstream fin;
	fin.open("C:\\Users\\Zhao Wei\\Downloads\\A-large.in");
	ofstream fout;
	fout.open("C:\\Users\\Zhao Wei\\Downloads\\A-large.out");
	
	for (int i = 0; i <= 60; i++)
	{
		long long k = 1;
		candidates.push_back(k << i);
	}

	int test_num = 0;
	fin >> test_num;
	for (int p = 0; p != test_num; p++)
	{
		
		long long a = 0;
		fin >> a;
		fout << "Case #" << p+1 << ": ";
		int reverse_cnt = 0;

		bool flg = false;
		for (int i = 60; i >= 0; i-- )
		{
			if (a == candidates[i])
			{
				fout << "0" << endl;
				flg = true;
				break;
			}
		}
		if (flg)	continue;

		for (int i = 60; i >= 0; i-- )
		{
			if (a > candidates[i])
			{
				a -= candidates[i];
				a = candidates[i] - a;
				reverse_cnt++;
			}
			else if (a == candidates[i])
			{
				if (reverse_cnt % 2)	fout << "1" << endl;
				else	fout << "0" << endl;
				flg = true;
				break;
			}
		}
		if (flg)	continue;

		if (reverse_cnt % 2)	fout << "1" << endl;		
		else					fout << "0" << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
/*
void switchString(string& s)
{
	for (int i = 0; i != s.size(); i++)
		s[i] = s[i] == '1' ? '0' : '1';
}

void googolString(string& s, int cnt)
{
	if (!cnt)	return;
	string t = s;
	reverse(t.begin(), t.end());
	switchString(t);
	s = s + "0" + t;
	googolString(s, cnt-1);
}

int main()
{
	string s = "";
	int cnt = 17;
	googolString(s, cnt);
	
	ifstream fin;
	fin.open("C:\\Users\\Zhao Wei\\Downloads\\A-small-attempt1.in");
	ofstream fout;
	fout.open("C:\\Users\\Zhao Wei\\Downloads\\A-small-attempt1.out");

	int test_num = 0;
	fin >> test_num;
	for (int i = 0; i != test_num; i++)
	{
		int a = 0;
		fin >> a;
		fout << "Case #" << i+1 << ": " << s[a-1] << endl;
	}

	fin.close();
	fout.close();
	return 0;
}
*/


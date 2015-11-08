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

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())	return 0;
		row = grid.size();
		col = grid[0].size();
		vector<vector<bool>> visited(row, vector<bool>(col, false));

		int islands_cnt = 0;
		for (int i = 0; i != row; i++)
		{
			for (int j = 0; j != col; j++)
			{
				if (!visited[i][j] && grid[i][j] == '1')
				{
					dfs(grid, i, j, visited);
					islands_cnt++;
				}
			}
		}
		return islands_cnt;
	}

private:
	void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited)
	{
		if (i < 0 || i >= row)	return;
		if (j < 0 || j >= col)	return;
		if (visited[i][j] || grid[i][j] == '0')	return;

		visited[i][j] = true;
		dfs(grid, i + 1, j, visited);
		dfs(grid, i - 1, j, visited);
		dfs(grid, i, j + 1, visited);
		dfs(grid, i, j - 1, visited);
	}

	int row, col;
};

int main() {
	ifstream fin;
	fin.open("C:\\Users\\Zhao Wei\\Downloads\\A-large.in");
	ofstream fout;
	fout.open("C:\\Users\\Zhao Wei\\Downloads\\A-large.out");

	int case_num = 0;
	fin >> case_num;
	int num = 1;
	while (num <= case_num) {
		fout << "Case #" << num << ":" << endl;
		int R = 0, C = 0;
		fin >> R >> C;
		vector<vector<char>> matrix(R, vector<char>(C, '0'));
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				fin >> matrix[i][j];

		int op_num = 0;
		fin >> op_num;
		char pre_op = ' ';
		int pre_cnt = 0;
		while (op_num--) {
			char op_type = ' ';			
			fin >> op_type;
			if (op_type == 'M') {
				int i = 0, j = 0;
				char ch = ' ';
				fin >> i >> j >> ch;
				matrix[i][j] = ch;				
			}
			if (op_type == 'Q') {				
				Solution slt;
				if (pre_op == 'Q') fout << pre_cnt << endl;
				else {
					int cnt = slt.numIslands(matrix);
					fout << cnt << endl;
					pre_cnt = cnt;
				}
			}
			pre_op = op_type;
		}
		num++;
	}
	fin.close();
	fout.close();
	return 0;
}
#include <unordered_set>
#include <algorithm>
#include <string>
#include <numeric>
#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;

long long getMax(vector<vector<long>> matrix, int N, int K) {
	for (int len = 2; len <= K; len++) {
		for (int i = 0; i < N - len + 1; i++) {
			for (int j = 0; j < N - len + 1; j++) {
				matrix[i][j] = max(max(matrix[i][j], matrix[i + 1][j]), max(matrix[i][j + 1], matrix[i + 1][j + 1]));
			}
		}
	}

	long long sum = 0;
	for (int i = 0; i < N - K + 1; i++)
		for (int j = 0; j < N - K + 1; j++) 
			sum += matrix[i][j];

	return sum;
}

int main()
{
	ifstream fin;
	fin.open("C:\\Users\\Zhao Wei\\Downloads\\D-Large.in");
	ofstream fout;
	fout.open("C:\\Users\\Zhao Wei\\Downloads\\D-Large.out");

	int testNum = 0;
	int num = 1;
	fin >> testNum;
	while (num <= testNum) {
		int N = 0, K = 0, C = 0, X = 0;
		fin >> N >> K >> C >> X;
		vector<long> A(N, 0), B(N, 0);
		for (int i = 0; i != N; i++)
			fin >> A[i];
		for (int i = 0; i != N; i++)
			fin >> B[i];
		vector<vector<long>> matrix(N, vector<long>(N, 0));
		for (int i = 0; i != N; i++)
			for (int j = 0; j != N; j++)
				matrix[i][j] = (A[i] * (i + 1) + B[j] * (j + 1) + C) % X;

		long long rslt = getMax(matrix, N, K);
		fout << "Case #" << num << ": " << rslt << endl;
		num++;
	}

	fin.close();
	fout.close();
	return 0;
}
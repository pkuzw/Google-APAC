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

class Balloon {
public:
	Balloon() {
		position = 0;
		height = -1;
		origin = -1;
		time = 0;
		energy_consume = 0;
	}

	void setTime(const vector<int>& layers) {
		if (height == -1) height = origin;
		if ((position < 0 && layers[height] < 0) || (position > 0 && layers[height] > 0))	time = INT_MAX;
		else if (position < 0 && layers[height] > 0) time = (-position) % layers[height] > 0 ? (-position) / layers[height] + 1 : (-position) / layers[height];
		else if (position > 0 && layers[height] < 0) time = position % (-layers[height]) > 0 ? position / (-layers[height]) + 1 : position / (-layers[height]);
	}

	int findNearestReduceHeight(const vector<int>& layers, bool& direction, int Q) {
		int rslt = INT_MAX;
		if (position > 0) {			
			for (int i = origin + 1; i < layers.size() && i - origin <= Q; i++) {
				if (layers[i] < 0 && layers[i] < layers[height]) {
					rslt = i;
					direction = true;break;
				}
			}
			for (int i = origin - 1; i >= 0 && origin - i <= Q; i--) {
				if (i < 0)	break;
				if (layers[i] < 0 && layers[i] < layers[height]) {
					rslt = min(rslt, i);
					direction = false;break;
				}
			}			
		}
		else if (position < 0) {
			for (int i = origin + 1; i < layers.size() && i - origin <= Q; i++) {
				if (layers[i] > 0 && layers[i] > layers[height]) {
					rslt = i;
					direction = true;break;
				}
			}
			for (int i = origin - 1; i >= 0 && origin - i <= Q; i--) {
				if (i < 0)	break;
				if (layers[i] > 0 && layers[i] > layers[height]) {
					rslt = min(rslt, i);
					direction = false;break;
				}
			}
		}
		return rslt;
	}
	int position;
	int height;
	int origin;
	int time;
	int energy_consume;
};

struct myObj {
	bool operator() (Balloon a, Balloon b) {
		return a.time < b.time;
	}
}mycmp;

int main() {
	ifstream fin;
	fin.open("C:\\Users\\Zhao Wei\\Downloads\\A-small-attempt0.txt");
	ofstream fout;
	fout.open("C:\\Users\\Zhao Wei\\Downloads\\A-small-attempt0.out");

	int case_num = 0;
	fin >> case_num;
	int num = 1;
	while (num <= case_num) {
		fout << "Case #" << num << ": " << endl;
		int N = 0, M = 0, Q = 0;
		fin >> N >> M >> Q;
		priority_queue<Balloon, vector<Balloon>, myObj> balloons;
		vector<int> layers(M, 0);
		for (int i = 0; i < M; i++)
			fin >> layers[i];
		for (int i = 0; i < N; i++)
		{
			Balloon b;
			fin >> b.position >> b.origin;
			b.setTime(layers);
			balloons.push(b);
		}
		while (Q > 0) {
			Balloon b = balloons.top();
			balloons.pop();
			Q += b.energy_consume;
			bool flg = true;
			int next_height = b.findNearestReduceHeight(layers, flg, Q);
			if (next_height == INT_MAX)
			{
				fout << "IMPOSSIBLE" << endl;
				break;
			}
			int energy_cons = abs(b.height - next_height);
			
			b.energy_consume = energy_cons;
			b.height = flg ? b.origin + energy_cons : b.origin - energy_cons;
			b.setTime(layers);
			Q -= energy_cons;			
			balloons.push(b);
		}
		Balloon b;
		if (!balloons.empty()) {
			b = balloons.top();
			fout << b.time << endl;
		}
		num++;
	}
	fin.close();
	fout.close();
	return 0;
}
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int main () {
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int start, end;
	cin >> start >> end;
	start--;
	end--;
	queue<int> q;
	q.push(start);
	vector<int> d(n, INF);
	vector<int> p(n);
	p[start] = -1;
	d[start] = 0;
	
		
	while (q.size() > 0) {
		
		int v = q.front();
		q.pop();
		
		if (v == end) {
			cout << d[end] << endl;
		}
		
		for (int i = 0; i < n; i++) {
			if (d[i] == INF && a[v][i] == 1) {
				
				d[i] = d[v] + 1;
				q.push(i);
				p[i] = v;
			}
		}
	}
		
	
	if (d[end] == INF) {
		cout << "-1";
	} else {
		vector<int> path;
		for (int v = end; v != -1; v = p[v]) {
			path.push_back (v);
	}
		reverse (path.begin(), path.end());
		if (path.size() > 1) {
			for (int i = 0; i < path.size(); i++) {
			cout << path[i] + 1 << " ";
			}
		}
		
	}
}

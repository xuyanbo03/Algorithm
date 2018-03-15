#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;

class Move {
	public:
		virtual bool CanMove(char from, char to, int dx, int dy) = 0;
};

class ForwardMove : public Move {
	public:
		virtual bool CanMove(char from, char to, int dx, int dy) {
			if (to == '#') return false;
			switch (from) {
				case '+' :
				case 'S' :
				case 'T' :
					return true;
					break;
				case '-' :
					return dy != 0;
					break;
				case '|' :
					return dx != 0;
					break;
				case '.' :
					return dx == 1;
					break;
			}
			return false;
		}
};

class BackwardMove : public Move {
	public:
		virtual bool CanMove(char from, char to, int dx, int dy) {
			if (to == '#') return false;
			switch (to) {
				case '+' :
				case 'S' :
				case 'T' :
					return true;
					break;
				case '-' :
					return dy != 0;
					break;
				case '|' :
					return dx != 0;
					break;
				case '.' :
					return dx == -1;
					break;
			}
			return false;
		}
};

char s[100][100];
typedef bool ARR[100][100];
ARR bs, bt;
int sx, sy, tx, ty;
int d[4][2] = {{-1, 0},{1, 0},{0, 1},{0, -1}};
void Bfs(ARR b, Move *move, int x, int y) {
	if (b[x][y])
		return;
	b[x][y] = true;
	for (int o = 0; o < 4; o++) {
		int dx = d[o][0];
		int dy = d[o][1];
		int xx = x + dx;
		int yy = y + dy;
		if (move->CanMove(s[x][y], s[xx][yy], dx, dy)) {
			Bfs(b, move, xx, yy);
		}
	}
}

int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			s[i][j] = '#';
	for (int i = 1; i <= n; i++)
		cin >> s[i]+1;
	for (int i = 0; i <= n + 1; i++)
		s[i][m + 1] = '#';
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (s[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if (s[i][j] == 'T') {
				tx = i;
				ty = j;
			}
		}
	}
	Bfs(bs, new ForwardMove(), sx, sy);
	Bfs(bt, new BackwardMove(), tx, ty);
	int ans = 0;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (bs[i][j] && ! bt[i][j])
				ans ++;
		}
	}
	if (bs[tx][ty] == false)
		cout << "I'm stuck!" << endl;
	else
		cout << ans << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

class Solution {
private:
    int hx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int hy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    int N;

    bool validPosition(int x, int y) {
        return (x >= 1 && x <= N && y >= 1 && y <= N);
    }

public:
    int minStepToReachTarget(vector<int>& KnightPos,vector<int>& TargetPos,int N) {
        this->N = N;
        pair<int, int> s = {KnightPos[0], KnightPos[1]}; // s = source
        pair<int, int> d = {TargetPos[0], TargetPos[1]}; // d = destination

        int a[N + 2][N + 2];
        for (int i = 0; i < N + 2; i++)
            for (int j = 0; j < N + 2; j++)
                a[i][j] = -1; // has not visited yet

        queue<pair<int, int>> q;
        q.push(s);
        a[s.first][s.second] = 0; // take 0 step to reach the position s
        if (s.first == d.first && s.second == d.second)
            return a[s.first][s.second];

        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            int x = top.first,
                y = top.second;

            for (int i = 0; i < 8; i++) {
                int xx = x + hx[i],
                    yy = y + hy[i];
                if (validPosition(xx, yy) && a[xx][yy] == -1) {
                    a[xx][yy] = a[x][y] + 1;
                    q.push({xx, yy});
                    if (xx == d.first && yy == d.second)
                        return a[xx][yy];
                }
            }
        }
        return -1;
    }

    vector<pair<int, int> > TraceSourceTarget(const pair<int, int>& source, const pair<int, int>& target) {
        vector<pair<int, int>> path;
        int a[N + 2][N + 2];
        for (int i = 0; i < N + 2; i++)
            for (int j = 0; j < N + 2; j++)
                a[i][j] = -1;

        queue<pair<int, int>> q;
        q.push(source);
        a[source.first][source.second] = 0;

        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            int x = top.first, y = top.second;

            for (int i = 0; i < 8; i++) {
                int xx = x + hx[i], yy = y + hy[i];
                if (validPosition(xx, yy) && a[xx][yy] == -1) {
                    a[xx][yy] = a[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }

        pair<int, int> current = target;
        while (!(current.first == source.first && current.second == source.second)) {
            path.push_back(current);
            for (int i = 0; i < 8; i++) {
                int xx = current.first + hx[i], yy = current.second + hy[i];
                if (validPosition(xx, yy) && a[xx][yy] == a[current.first][current.second] - 1) {
                    current = {xx, yy};
                    break;
                }
            }
        }
        path.push_back(source);

       int start = 0;
       int end = path.size() - 1;
       while (start < end) {
       std::swap(path[start], path[end]);
       start++;
       end--;
       }

        return path;
    }
};

string convert_to_string(const vector<int>& vec) {
    stringstream ss;
    ss << "(";
    for (int i = 0; i < vec.size() - 1; ++i)
        ss << vec[i] << ", ";
    ss << vec[vec.size() - 1] << ")";
    return ss.str();
}

int main() {
    int N = 10;
    vector<int> source_pos(2);
    vector<int> dest_pos(2);

    cout << "Size of the chess board N: ";
    cin >> N;

    source_pos[0] = N / 2;
    source_pos[1] = N / 2;

    cout << "Destination of the knight (2 values x and y): ";
    cin >> dest_pos[0] >> dest_pos[1];

    Solution solution;
    int min_steps = solution.minStepToReachTarget(source_pos, dest_pos, N);
    cout << "Minimal steps from " << convert_to_string(source_pos)
              << " to " << convert_to_string(dest_pos)
              << ": " << min_steps << endl;

    vector<pair<int, int>> path = solution.TraceSourceTarget({source_pos[0], source_pos[1]}, {dest_pos[0], dest_pos[1]});
    cout << "Knight's path: ";
    for (const auto& pos : path) {
        cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    cout << endl;

    return 0;
}

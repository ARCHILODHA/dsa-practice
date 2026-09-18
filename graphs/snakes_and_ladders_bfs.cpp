#include <bits/stdc++.h>
using namespace std;

// Find minimum dice throws to reach the final square.
// board[i] = -1 means normal square.
// Otherwise board[i] gives the destination of a snake/ladder.
int minDiceThrows(vector<int>& board) {
    int N = board.size();

    vector<int> dist(N, -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == N - 1)
            return dist[current];

        for (int dice = 1;
             dice <= 6 && current + dice < N;
             ++dice) {

            int next = current + dice;

            if (board[next] != -1)
                next = board[next];

            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }

    return -1;
}

int main() {
    vector<int> board(30, -1);

    // Example ladders and snakes.
    board[2] = 21;
    board[4] = 7;
    board[10] = 25;
    board[19] = 3;
    board[26] = 0;

    cout << "Minimum dice throws = "
         << minDiceThrows(board) << '\n';

    return 0;
}

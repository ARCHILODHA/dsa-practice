#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
    if (k == word.size())
        return true;

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return false;

    if (board[i][j] != word[k])
        return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool found =
        dfs(board, word, i + 1, j, k + 1) ||
        dfs(board, word, i - 1, j, k + 1) ||
        dfs(board, word, i, j + 1, k + 1) ||
        dfs(board, word, i, j - 1, k + 1);

    board[i][j] = temp;

    return found;
}

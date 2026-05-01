int countLessEqual(vector<vector<int>>& matrix, int mid) {
    int n = matrix.size(), row = n - 1, col = 0, count = 0;

    while (row >= 0 && col < n) {
        if (matrix[row][col] <= mid) {
            count += row + 1;
            col++;
        } else row--;
    }
    return count;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int low = matrix[0][0], high = matrix.back().back();

    while (low < high) {
        int mid = (low + high) / 2;
        if (countLessEqual(matrix, mid) < k) low = mid + 1;
        else high = mid;
    }
    return low;
}

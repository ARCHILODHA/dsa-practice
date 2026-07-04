// LeetCode 374 - Guess Number Higher or Lower

class Solution {
public:
    int guess(int num);

    int guessNumber(int n) {
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);

            if (res == 0)
                return mid;
            else if (res < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};

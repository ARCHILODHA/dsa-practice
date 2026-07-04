class Solution {
public:
    int arrangeCoins(int n) {

        long long l = 0, r = n;

        while (l <= r) {

            long long mid = l + (r - l) / 2;
            long long sum = mid * (mid + 1) / 2;

            if (sum == n)
                return mid;
            else if (sum < n)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return r;
    }
};

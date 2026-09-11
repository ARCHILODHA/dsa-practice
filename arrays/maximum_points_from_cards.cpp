#include <bits/stdc++.h>
using namespace std;

// Pick exactly k cards from either end to maximize score.

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();

    int currentSum = 0;

    // Take first k cards.
    for (int i = 0; i < k; i++) {
        currentSum += cardPoints[i];
    }

    int answer = currentSum;

    // Gradually replace cards from the left with cards
    // from the right.
    for (int i = 0; i < k; i++) {
        currentSum -= cardPoints[k - 1 - i];
        currentSum += cardPoints[n - 1 - i];

        answer = max(answer, currentSum);
    }

    return answer;
}

int main() {
    vector<int> cards = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << "Maximum score: "
         << maxScore(cards, k) << endl;

    return 0;
}

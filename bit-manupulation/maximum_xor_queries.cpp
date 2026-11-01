#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class BinaryTrie {
    TrieNode* root;

public:
    BinaryTrie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;

        for (int bit = 31; bit >= 0; bit--) {
            int b = (num >> bit) & 1;

            if (!node->child[b]) {
                node->child[b] = new TrieNode();
            }

            node = node->child[b];
        }
    }

    int maxXor(int num) {
        TrieNode* node = root;
        unsigned int result = 0;

        for (int bit = 31; bit >= 0; bit--) {
            int b = (num >> bit) & 1;
            int opposite = 1 - b;

            if (node->child[opposite]) {
                result |= (1U << bit);
                node = node->child[opposite];
            }
            else {
                node = node->child[b];
            }
        }

        return static_cast<int>(result);
    }
};

vector<int> maximizeXor(
    vector<int>& nums,
    vector<vector<int>>& queries
) {
    sort(nums.begin(), nums.end());

    vector<array<int, 3>> sortedQueries;

    for (int i = 0; i < queries.size(); i++) {
        sortedQueries.push_back({
            queries[i][1],
            queries[i][0],
            i
        });
    }

    sort(sortedQueries.begin(), sortedQueries.end());

    vector<int> ans(queries.size(), -1);

    BinaryTrie trie;
    int index = 0;

    for (auto q : sortedQueries) {
        int limit = q[0];
        int x = q[1];
        int originalIndex = q[2];

        while (index < nums.size() && nums[index] <= limit) {
            trie.insert(nums[index]);
            index++;
        }

        if (index > 0) {
            ans[originalIndex] = trie.maxXor(x);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> ans = maximizeXor(nums, queries);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}

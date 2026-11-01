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

    void insert(unsigned int num) {
        TrieNode* node = root;

        for (int bit = 31; bit >= 0; bit--) {
            int b = (num >> bit) & 1U;

            if (!node->child[b]) {
                node->child[b] = new TrieNode();
            }

            node = node->child[b];
        }
    }

    unsigned int getMaxXor(unsigned int num) {
        TrieNode* node = root;
        unsigned int result = 0;

        for (int bit = 31; bit >= 0; bit--) {
            int b = (num >> bit) & 1U;
            int opposite = 1 - b;

            if (node->child[opposite]) {
                result |= (1U << bit);
                node = node->child[opposite];
            }
            else {
                node = node->child[b];
            }
        }

        return result;
    }
};

unsigned int maxSubarrayXor(vector<unsigned int>& nums) {
    BinaryTrie trie;

    trie.insert(0);

    unsigned int prefixXor = 0;
    unsigned int ans = 0;

    for (unsigned int num : nums) {
        prefixXor ^= num;

        ans = max(ans, trie.getMaxXor(prefixXor));

        trie.insert(prefixXor);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<unsigned int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxSubarrayXor(nums);

    return 0;
}

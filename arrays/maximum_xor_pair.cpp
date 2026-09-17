#include <bits/stdc++.h>
using namespace std;

// Find the maximum XOR obtainable from any two elements.
//
// Uses a binary trie.
//
// Time: O(n * 32)
// Space: O(n * 32)

struct TrieNode {
    TrieNode* child[2];

    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class BinaryTrie {
private:
    TrieNode* root;

public:
    BinaryTrie() {
        root = new TrieNode();
    }

    void insert(int number) {
        TrieNode* node = root;

        for (int bit = 31; bit >= 0; bit--) {

            int currentBit =
                (number >> bit) & 1;

            if (node->child[currentBit] == nullptr) {
                node->child[currentBit] =
                    new TrieNode();
            }

            node = node->child[currentBit];
        }
    }

    int getMaximumXOR(int number) {
        TrieNode* node = root;
        int answer = 0;

        for (int bit = 31; bit >= 0; bit--) {

            int currentBit =
                (number >> bit) & 1;

            int oppositeBit =
                1 - currentBit;

            if (node->child[oppositeBit] != nullptr) {

                answer |= (1 << bit);

                node =
                    node->child[oppositeBit];
            }
            else {
                node =
                    node->child[currentBit];
            }
        }

        return answer;
    }
};

int findMaximumXOR(vector<int>& nums) {
    BinaryTrie trie;

    for (int x : nums) {
        trie.insert(x);
    }

    int answer = 0;

    for (int x : nums) {
        answer = max(
            answer,
            trie.getMaximumXOR(x)
        );
    }

    return answer;
}

int main() {
    vector<int> nums = {
        3, 10, 5, 25, 2, 8
    };

    cout << "Maximum XOR: "
         << findMaximumXOR(nums)
         << endl;

    return 0;
}

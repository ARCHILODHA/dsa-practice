class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums2.begin(), nums2.end());

        set<int> ans;

        for (int x : nums1) {

            if (binary_search(nums2.begin(), nums2.end(), x))
                ans.insert(x);
        }

        return vector<int>(ans.begin(), ans.end());
    }
};

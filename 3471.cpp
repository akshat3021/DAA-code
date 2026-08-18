class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> count;

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> present;

            for (int j = i; j < i + k; j++) {
                present.insert(nums[j]);
            }

            for (int x : present) {
                count[x]++;
            }
        }

        int ans = -1;

        for (auto &[x, cnt] : count) {
            if (cnt == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};

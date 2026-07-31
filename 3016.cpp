class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {};

        for (char c : word)
            freq[c - 'a']++;

        sort(freq, freq + 26, greater<int>());

        int ans = 0;
        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};

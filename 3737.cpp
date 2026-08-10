class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(); 
         if (find(nums.begin(), nums.end(), target) != nums.end()) {
            vector<int> freq(2 * n + 1, 0);
            
             int current_sum = 0;
             int total_subarrays = 0;
            
             freq[0 + n] = 1;

             int running_count = 0;
        for (int i = 0; i < n; ++i) {
        
        if (nums[i] == target) {

            running_count += freq[current_sum + n];
            current_sum++;
        } else {
            current_sum--;
            running_count -= freq[current_sum + n];
        }

        total_subarrays += running_count;

        freq[current_sum + n]++;
    }

    return total_subarrays;
}

 return 0;
    }
};

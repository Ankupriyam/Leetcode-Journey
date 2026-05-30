class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            string tmp = to_string(nums[i]);
            for (char c : tmp)
                ans.push_back(c - '0');
        }
        return ans;
    }
};
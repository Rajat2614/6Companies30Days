class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int nmax = INT_MIN, nmin = INT_MAX, l = -1, r = -2;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < nmax) r = i;
            nmax = max(nmax, nums[i]);
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] > nmin) l = i;
            nmin = min(nmin, nums[i]);
        }
        return r - l + 1;
    }
};

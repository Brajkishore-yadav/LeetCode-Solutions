class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int left = 0;
        long long sum = 0;
        long long ans = 0;
        set<int> st;

        for(int right = 0; right < nums.size(); right++) {

            while(st.count(nums[right]) || st.size() == k) {
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            st.insert(nums[right]);
            sum += nums[right];

            if(st.size() == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
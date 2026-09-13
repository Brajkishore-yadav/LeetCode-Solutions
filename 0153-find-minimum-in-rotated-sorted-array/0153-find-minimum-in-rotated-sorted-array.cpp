class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            // mid right se bada hai,
            // matlab minimum right side mein hai
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }

            // minimum mid ya left side mein ho sakta hai
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};
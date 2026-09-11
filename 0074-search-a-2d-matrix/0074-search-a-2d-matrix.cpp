class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size(); // no. of rows

        // Agar matrix empty hai
        if(m == 0) {
            return false;
        }

        int n = matrix[0].size(); // no. of columns

        int left = 0;
        int right = (m * n) - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            // 1D index ko 2D index mein convert kar rahe hain
            int element = matrix[mid / n][mid % n];

            if(element == target) {
                return true;
            }
            else if(target < element) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return false;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int n = height.size();
        int right = n-1;
        int area = 0;
        while(left<right){
            if(height[left]<=height[right]){
                area = max(min(height[left],height[right])*((right)-left),area);
                left++;
            }
            else{
                area = max(min(height[left],height[right])*((right)-left),area);
                right--;
            }
        }
        return area;
    }
};
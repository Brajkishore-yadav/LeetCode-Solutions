class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        // Horizontal direction mein overlap check
        bool horizontal = rec1[0] < rec2[2] && rec2[0] < rec1[2];

        // Vertical direction mein overlap check
        bool vertical = rec1[1] < rec2[3] && rec2[1] < rec1[3];

        // Dono direction mein overlap hona chahiye
        return horizontal && vertical;
    }
};
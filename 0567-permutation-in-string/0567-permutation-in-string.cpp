class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>s1hash(26,0);
        vector<int>s2hash(26,0);
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2){
            return false;
        }
        int left=0,right=0;
        while(right<n1){
            s1hash[s1[right]-'a']++;
            s2hash[s2[right]-'a']++;
            right++;
        }
        right--;
        while(right<n2){
            if(s1hash==s2hash){
                return true;
            }
            right++;
            if(right!=n2){
                s2hash[s2[right]-'a']++;
            }
            s2hash[s2[left]-'a']--;
            left++;
        }
        return false;
    }
};
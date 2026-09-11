class Solution {
public:

    int totalNumbers(vector<int>& digits) {

        int ans = 0;

        // Har digit ki frequency
        int freq[10] = {0};

        for(int i = 0; i < digits.size(); i++) {
            freq[digits[i]]++;
        }

        // Last digit even hona chahiye
        for(int i = 0; i <= 8; i += 2) {

            if(freq[i] == 0)
                continue;

            freq[i]--;

            // First digit 0 nahi ho sakta
            for(int j = 1; j <= 9; j++) {

                if(freq[j] == 0)
                    continue;

                freq[j]--;

                // Middle digit kuch bhi ho sakta hai
                for(int k = 0; k <= 9; k++) {

                    if(freq[k] > 0) {
                        ans++;
                    }
                }

                freq[j]++;
            }

            freq[i]++;
        }

        return ans;
    }
};
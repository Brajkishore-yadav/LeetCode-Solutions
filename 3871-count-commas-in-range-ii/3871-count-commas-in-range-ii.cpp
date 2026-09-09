class Solution {
public:
    long long countCommas(long long n) {

        long long ans = 0;

        // Pehla comma 1000 se start hota hai
        long long start = 1000;

        // 1000 se 999999 tak har number mein 1 comma
        long long commas = 1;

        while (start <= n) {

            // Current range ka last number
            long long end = min(n, start * 1000 - 1);

            // Current range mein total numbers
            long long count = end - start + 1;

            // Total commas add karo
            ans += count * commas;

            // Next range par jao
            start *= 1000;
            commas++;
        }

        return ans;
    }
};
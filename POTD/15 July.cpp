class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long x = 0, y = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (i % 2)
                y += i;
            else
                x += i;
        }
        return gcd(x, y);
    }
};
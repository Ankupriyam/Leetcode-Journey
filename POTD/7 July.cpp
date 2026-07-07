class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0;
        string a = to_string(n);
        for (int i = 0; i < a.size(); i++) {
            int curr = a[i] - '0';
            if (curr != 0) {
                x *= 10;
                x += curr;
                sum += curr;
            }
        }

        return x * sum;
    }
};
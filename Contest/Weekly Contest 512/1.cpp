class Solution {
public:
    int largestInteger(int n, int s) {
        int x=0;
        long long ans=0;
        if(9*n<s){
            return -1;
        }
        while(x<n && s>0){
            int next=min(s,9);
            ans=ans*10+next;
            x++;
            s-=next;
        }
        while(x<n){
            ans*=10;
            x++;
        }
        // x=n;
        // while(s>0){
        //     int mul=min(s,8);
        //     ans= ans*mul*pow(10,x);
        //     x--;
        // }
        return ans;
        
    }
};
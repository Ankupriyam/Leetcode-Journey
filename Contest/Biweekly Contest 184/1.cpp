class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count=0;
        for(int i=0;i<31;i++){
            if(((n>>i)&1)&&((n>>(i+1)&1))){
                count++;
            }
        }
        return count==1;
    }
};
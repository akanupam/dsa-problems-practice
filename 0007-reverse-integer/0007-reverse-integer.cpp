class Solution {
public:
    int reverse(int x) {
        long long r=0;
        while (x!=0){
            r= r*10 + x%10;
            x/=10;
            if(abs(r)> INT_MAX){
                return 0;
            }
        }
        return r;
    }
};
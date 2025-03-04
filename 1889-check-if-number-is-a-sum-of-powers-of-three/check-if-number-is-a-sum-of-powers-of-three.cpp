class Solution {
public:
    bool checkPowersOfThree(int n) {
        int temp = n;
        int i = 0;
        int ans = 0;
        while(temp != 0){
            int r = temp%3;
            if(r != 0 )
                ans+=pow(3,i);
            temp/=3;
            i++;
        }
        if(ans == n)
            return true;
        return false;
    }
};
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> cnt(10,0);
        while(n > 0){
            cnt[n%10]++;
            n /= 10;
        }
        for(int i=0;i<32;i++){
            vector<int> twopow(10,0);
            int x = (1<<i);
            while(x > 0){
                twopow[x%10]++;
                x /= 10;
            }
            bool flag = true;
            for(int i=0;i<10;i++){
                if(cnt[i] != twopow[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return true;
        }
        return false;
    }
};
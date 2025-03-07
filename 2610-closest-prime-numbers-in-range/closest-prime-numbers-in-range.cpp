class Solution {
public:
    vector<int> li;
    vector<int> validPrimes;
    void seive(int n){
        vector<bool> f(n+1,true);
        f[0]=false;
        f[1]=false;
        for(int i=2;i*i<=n;i++){
            if(f[i]){
                for(int j=i*i;j<=n;j+=i)
                    f[j] = false;
            }
        }
        for(int i=2;i<=n;i++){
            if(f[i])
                li.push_back(i);
        }
    }

    void extendedSeive(int left,int right){
        vector<bool> f1(right-left+1,true);
        if(left > right)
            return;
        if(left == 1)
            f1[0] = false;
        for(auto x : li){
            int p = left;
            if(left%x != 0)
                p += x-(left%x);
            for(int i=p;i<=right;i+=x){
                if(i != x)
                    f1[i-left] = false;
            }
        }
        for(int i=0;i<right-left+1;i++){
            if(f1[i] && i+left>1)
                validPrimes.push_back(i+left);
        }
    }

    vector<int> closestPrimes(int left, int right) {
        seive(sqrt(right));
        extendedSeive(left,right);
        vector<int> ans(2,-1);
        if(validPrimes.size() < 2)
            return ans;
        int curdiff = INT_MAX;
        for(int i=0;i<validPrimes.size()-1;i++){
            int diff = validPrimes[i+1]-validPrimes[i];
            if(diff < curdiff){
                ans[0] = validPrimes[i];
                ans[1] = validPrimes[i+1];
                curdiff = diff;
            }
        }
        li.clear();
        validPrimes.clear();
        return ans;
    }
};
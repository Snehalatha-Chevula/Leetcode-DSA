class Solution {
public:
    int m = 1e9+7;
    long calculatePower(int n){
        if(n == 1)
            return 2;
        long long p = calculatePower(n/2)%m;
        if(n%2)
            return (((p*p))*2);
        return (p*p);
    }
    int monkeyMove(int n) {
        long ans = calculatePower(n);
        return (ans-2)%m;
    }
};
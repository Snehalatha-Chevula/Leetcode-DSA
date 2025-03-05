class Solution {
public:
    long long coloredCells(int n) {
        if(n == 0)
            return 1;
        return (n-1)*4 + coloredCells(n-1);
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int curSum = 0;
        int ans = 0;
        for(int i=0;i<k;i++)
            curSum += cardPoints[i];
        ans = curSum;
        int p1 = k-1, p2 = n-1;
        while(p1 >= 0){
            curSum -= cardPoints[p1];
            curSum += cardPoints[p2];
            ans = max(ans, curSum);
            p1--;
            p2--;
        }
        return ans;
    }
};
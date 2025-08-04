class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0, j = 0;
        int idx1 = 0, idx2 = -1;
        int ans = INT_MIN;
        while(j < n){
            if(fruits[j] == fruits[idx1])
                idx1 = j;
            else if(idx2 == -1 || fruits[j] == fruits[idx2])
                idx2 = j;
            else{
                i = min(idx1,idx2)+1;
                idx1 = (i == idx1+1 ? idx2 : idx1);
                idx2 = j;
                cout <<idx1 <<" " <<idx2 <<endl;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
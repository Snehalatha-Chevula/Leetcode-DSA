class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n*n;
        int sum = (total*(total+1))/2;
        vector<int> ans;
        vector<int> possible(total,0);
        int temp = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x = grid[i][j];
                if(possible[x-1] != 0)
                    ans.push_back(x);
                else{
                    temp += x;
                    possible[x-1] = 1;
                }
            }
        }
        ans.push_back(sum-temp);
        return ans;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int r = matrix.size();
        int c = matrix[0].size();
        int lo = matrix[0][0];
        int hi = matrix[r-1][c-1];
        while(lo <= hi){
            int mid = (lo+hi)/2;
            int lowEle = findLesser(matrix, mid);
            if(lowEle < k){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return hi;
    }

    int findLesser(vector<vector<int>>& matrix, int mid){
        int r = matrix.size();
        int c = matrix[0].size();
        int cnt = 0;
        for(int i=0;i<r;i++){
            int lo = 0, hi = c-1;
            int temp = 0;
            while(lo <= hi){
                int m = (lo+hi)/2;
                if(matrix[i][m] >= mid)
                    hi = m-1;
                else{
                    temp = m+1;
                    lo = m+1;
                }
            }
            cnt += temp;
        }
        return cnt;
    }
};
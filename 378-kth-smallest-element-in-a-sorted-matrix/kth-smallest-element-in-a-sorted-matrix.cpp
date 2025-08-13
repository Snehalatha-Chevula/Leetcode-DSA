class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pq.size() < k)
                    pq.push(matrix[i][j]);
                else if(pq.size()==k && matrix[i][j] < pq.top()){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};
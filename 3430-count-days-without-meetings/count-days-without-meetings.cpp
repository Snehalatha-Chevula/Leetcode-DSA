class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n = meetings.size();
        int c = 0;
        c += meetings[0][0] - 1;
        int end = meetings[0][1];
        for(int i=1;i<n;i++){
            if(meetings[i][0] > end){
                c += meetings[i][0] - end - 1;
                end = meetings[i][1];
            }
            else if(meetings[i][1] > end)
                end = meetings[i][1];
        }
        c += (days - end);
        return c;
    }
};
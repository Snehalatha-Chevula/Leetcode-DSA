class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int white = 0;
        int ans = INT_MAX;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W')
                white++;
        }
        ans = min(ans,white);
        for(int i=k;i<n;i++){
            if(blocks[i-k] == 'W')
                white--;
            if(blocks[i] == 'W')
                white++;
            ans = min(ans,white);
        }
        return ans;
    }
};
class Solution {
public:
    void sequences(string &tiles, unordered_set<string> &ans, vector<bool> &vis, string cur){
        ans.insert(cur);
        for(int i=0;i<tiles.length();i++){
            if(!vis[i]){
                vis[i] = true;
                sequences(tiles,ans,vis,cur+tiles[i]);
                vis[i] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int len = tiles.length();
        unordered_set<string> ans;
        vector<bool> vis(len,false);
        sequences(tiles,ans,vis,"");
        return ans.size()-1;
    }
};
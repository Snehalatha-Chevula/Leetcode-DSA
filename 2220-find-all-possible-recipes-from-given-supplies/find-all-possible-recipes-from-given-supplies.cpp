class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available;
        for(auto ing : supplies)
            available.insert(ing);
        int n = recipes.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            for(int i=0;i<n;i++){
            if(available.find(recipes[i]) == available.end()){
                bool pos = true;
                for(int j=0;j<ingredients[i].size();j++){
                    if(available.find(ingredients[i][j]) == available.end())
                        pos = false;
                }
                if(pos){
                    ans.push_back(recipes[i]);
                    available.insert(recipes[i]);
                }
            }
        }
        }
        return ans;
    }
};
void solve(vector<int>& candidates, int ind, int target,int s, vector<int>& temp, vector<vector<int>>& ans) {

        if (ind == candidates.size()) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if (candidates[ind] <= target) {

            temp.push_back(candidates[ind]);
            s += candidates[ind];
            solve(candidates, ind, target - candidates[ind], s, temp, ans);
            temp.pop_back();
            s -= candidates[ind];

        }
        solve(candidates, ind+1, target, s, temp, ans);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, 0, target, 0, temp, ans);


        return ans;
        
    }

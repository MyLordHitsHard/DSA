vector<int> topView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;
    queue<pair<TreeNode*, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        TreeNode* node = t.first;
        int ind = t.second;
        if (mp.find(ind) == mp.end()) mp[ind] = node -> data;
        if (node -> left) q.push({node -> left, ind - 1});
        if (node -> right) q.push({node -> right, ind + 1});
    }
    
    for (auto i : mp) {
        ans.push_back(i.second);
    }
    
    return ans;
}

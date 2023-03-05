long long kthLargestLevelSum(TreeNode* root, int k) {
        

        // khud ka code nhi hai ye mera
        // khud hua nhi to kisi aur ka samajh ke kiya hai
        priority_queue<long long> pq;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            long long len = q.size();
            long long levelMax = 0;

            while (len--) {
                TreeNode* curr = q.front();
                levelMax += curr -> val;
                q.pop();

                if (curr -> left) q.push(curr -> left);
                if (curr -> right) q.push(curr -> right);
            }
            pq.push(levelMax);
        }

        if (pq.size() < k) return -1;
        k--;
        while (k--) {
            pq.pop();
        }

        
        return pq.top();
        
    }

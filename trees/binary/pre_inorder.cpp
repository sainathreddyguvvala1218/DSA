
// using rec O(n*2)


class Solution {
public:
    int search(vector<int>& inorder,int val,int left,int right){
        for(int i=left;i<=right;i++){
            if(inorder[i] == val) return i;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& preidx,int left,int right) {
        if(left>right) return NULL;
        TreeNode* root = new TreeNode(preorder[preidx]);     
        int inidx = search(inorder,preorder[preidx],left,right);
        preidx++;
        root->left = helper(preorder,inorder,preidx,left,inidx-1);
         root->right = helper(preorder,inorder,preidx,inidx+1,right);
         return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;
        return helper(preorder,inorder,preidx,0,inorder.size()-1);
    }
};

//O(n) using hashmap for search in inorder


class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& preidx,int left,int right) {
        if(left>right) return NULL;
        TreeNode* root = new TreeNode(preorder[preidx]);     
        int inidx = mp[preorder[preidx]];
        preidx++;
        root->left = helper(preorder,inorder,preidx,left,inidx-1);
         root->right = helper(preorder,inorder,preidx,inidx+1,right);
         return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i; // data -> index map
        }
        int preidx = 0;
        return helper(preorder,inorder,preidx,0,inorder.size()-1);
    }
};
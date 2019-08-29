/*
Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
// Pass previous and head by reference since the changes should be communicated to the successive recursive calls
void convert_to_doubly(TreeNode* root,TreeNode*& previous,TreeNode*& head)
{
    if(root == NULL)
        return;
    
    // Process the left subtree
    convert_to_doubly(root -> left,previous,head);
    
    // DO the operation on the current node
    if(previous == NULL)
        head = root;
    else{
        root -> left = previous;
        previous -> right = root;
    }
    previous = root;
    convert_to_doubly(root -> right,previous,head);
}
TreeNode* solve(TreeNode *A){
    
    if(A == NULL)
        return A;
        
    TreeNode* previous = NULL;
    TreeNode* head = NULL;
    convert_to_doubly(A,previous,head);
    TreeNode* last = head;
    while(last -> right != NULL){
        last = last -> right;
    }
    last -> right = head;
    head -> left = last;
    return head;

}

Node*findMin(Node*root){
    while(root->left!=NULL) root=root->left;
    return root;
}
Node *deleteNode(Node *root,  int x)
{
    // your code goes here
    if(root==NULL) return root;
    else if (root->data>x)  root->left=deleteNode(root->left,x);
    else if (root->data<x)  root->right=deleteNode(root->right,x);
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        else if(root->left==NULL){
            Node*temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node*temp=root;
            root=root->left;
            delete temp;
        }
        else{
            Node*temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}
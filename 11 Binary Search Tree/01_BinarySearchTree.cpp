#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int d){
            this->data = d;
            this->right=this->left=NULL;
        }
};
class BST{
public:
    Node* root;
    BST(){
        root=NULL;}
    
    Node* insert(Node* root,int data);
    void takeinput();
    void levelOrder();
    void preOrder(Node* root);
    void inOrder(Node* root);
    void postOrder(Node* root);
    Node* remove(Node* root , int key);
    Node* minVal(Node* root);
    Node* maxVal(Node* root);
};

//Time Complexity = O(logN)
Node* BST ::insert(Node* root, int d){
    if(root==NULL){
        root= new Node(d);
        return root;
    }
    if(d<root->data)root->left=insert(root->left , d);
    else root->right= insert(root->right , d);
    return root;
}


void BST::takeinput(){
    int data;
    cin>>data;
    while(data!=-1){ //will form a BST according to our entries
        root=insert(root,data);
        cin>>data;
    }
}

void BST::levelOrder(){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp= q.front();
        q.pop();
        //i.e current level is completed
        if(temp==NULL){
            cout<<endl;
            //just push a NULL 
            if(!q.empty())q.push(NULL);
        }else{
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            
        }
    }
}

void BST :: preOrder(Node* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void BST :: inOrder(Node* root){
    if(root==NULL)return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void BST :: postOrder(Node* root){
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
//min value will be always in left 
Node* BST :: minVal(Node* root){
    Node* temp= root;
    while(temp->left !=NULL){
        temp=temp->left;
    }
    return temp;
}
//max value will be always in right
Node* BST :: maxVal(Node* root){
    Node* temp= root;
    while(temp->right !=NULL){
        temp=temp->right;
    }
    return temp;
}

Node* BST:: remove(Node* root , int key){
    if(root==NULL)return root;
    else if (key<root->data){
        root->left=remove(root->left, key);//if the key is less then search the left subtree
        return root;
    } 
    else if (key>root->data){
        root->right=remove(root->right, key);//else right subtree
        return root;
    } 
    else{
        //if the value is find 
        
        //if leaf node ie. 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
            // return NULL;
        }
        //1 child
        else if(root->left == NULL){
            Node* temp=root;
            root=root->right;
            delete temp; 
            return root;
        }
        else if(root->right == NULL){
            Node* temp=root;
            root=root->left;
            delete temp; 
            return root;
        }
        //2 child
        
        else{
            Node* temp= minVal(root->right); //min value in the right subtree
            root->data=temp->data;//updating the value with the min value
            root->right=remove(root->right,temp->data);//removing the duplicate value from the right subtree
                                                       //reducint 2 child to 1-child
        }
    }
    
}


int main(){
    BST t;

    cout << "Enter data to create BST:" << endl;
    t.takeinput();

    cout << "Level Order: " << endl;
    t.levelOrder();
    
    cout << "Preorder: ";
    t.preOrder(t.root);
    cout << endl;

    cout << "Inorder: ";
    t.inOrder(t.root);
    cout << endl;

    cout << "Postorder: ";
    t.postOrder(t.root);
    cout << endl;
    
    // (t.search(t.root,27)) ? cout << "27 is present" << endl : cout << "27 is not present" << endl;
    // (t.search(t.root,20)) ? cout << "20 is present" << endl : cout << "20 is not present" << endl;

    cout << "Min value is " << t.minVal(t.root)->data << endl;
    cout << "Max value is " << t.maxVal(t.root)->data << endl;

    // Deleting Node
    // t.root = t.remove(t.root, 30); // with no child
    // t.root = t.remove(t.root, 90); // with 1 child
    t.root = t.remove(t.root, 4); // with 2 child

    // After deletion
    cout << "After Deletion:" << endl;
    cout << "Level Order: " << endl;
    t.levelOrder();
    
    cout << "Preorder: ";
    t.preOrder(t.root);
    cout << endl;

    cout << "Inorder: ";
    t.inOrder(t.root);
    cout << endl;

    cout << "Postorder: ";
    t.postOrder(t.root);
    cout << endl;

    
}










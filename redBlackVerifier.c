#include <stdio.h>
#include <string.h>

int MAX-DEPTH = -1;
int CURR-DEPTH = 0;
int rootChecked = 0;

typedef struct node {
    char color;
    char *id;   //changed from assginment default of char *data;
    struct node* left;
    struct node* right;
} treenode;

int depthVerify(treenode root){
    if (root->left){
        CURR-DEPTH++;
        depthVerify(root->left);
    }
    else {
        if (MAX-DEPTH == -1){
            MAX-DEPTH = CURR-DEPTH;
            //Need something here
        } else {
            if (MAX-DEPTH == CURR-DEPTH){
                //Need something here
            }
        }        
    }
}

int verify(treenode root){
    if (root){                                                  //The node exists
        if (root->color == 'r' || root->color == 'b') {         //Node has an assigned color
            if (!(root->left) && !(root->right)) {              //All children are leafs
                if (root->color == 'r'){                        //End of tree is a red
                    return 3;                           //RED_END
                } else {                                        //Nothing
                    //Need something here
                }
            } else {                                            //node has atlease one non leaf
                if (!rootChecked){                              //This node is the head of tree
                    rootChecked++;
                    if (root->color != 'b'){                    //Head node is not black
                        return 2;                       //ROOT_RED
                    } else {                                    //Recurse to the next node
                        verify(root->left);
                        verify(root->right);
                    }
                } 
                
                else {                                          //Node is not the head of the tree
                    if (root->color == 'r'){                    //Current node is red
                        if (root->left){                        //Left node Exists
                            if (root->left->color == 'r'){      //Red node has Red left child
                                return 4;               //RED_ON_RED
                            } else {                            //This child node is black
                                //Need something here
                            }
                        } else {                                  //Left node is a leaf, therefore black
                            //Need something here
                        }
            
                        if (root->right){                       //Right node Exists
                            if (root->right->color == 'r'){     //Red node has Red right child
                                return 4;               //RED_ON_RED
                            } else {                            //This child node is black
                                //Need something here
                            }
                        } else {                                //Right node Doesn't Exist
                            //Need something here
                        }
                    } else {                                    //Node is black
                        //Need something here
                    }
                }
            }
        } else {                                                //Node has no assigned color
            return 1;                                   //NODE_UNCOLORED
        }
    } else {
        printf("Passed a bad pointer!\n");
        return 6;                                       // NO_ROOT_NODE
    }
}

int main(){
        //Initializing tree and assigning R/B value
    treenode *a;
    a = malloc(sizeof(struct node));
    a->id = 'a';
    a->color = 'b';

    treenode *b;
    b = malloc(sizeof(struct node));
    b->id = 'b';
    b->color = 'b';
    
    treenode *c;
    c = malloc(sizeof(struct node));
    c->id = 'c';
    c->color = 'r';
    
    treenode *d;
    d = malloc(sizeof(struct node));
    d->id = 'd';
    d->color = 'b';
    
    treenode *e;
    e = malloc(sizeof(struct node));
    e->id = 'e';
    e->color = 'b';
    
    treenode *x;
    x = malloc(sizeof(struct node));
    x->id = 'x';
    x->color = 'r';
    
    treenode *z;
    z = malloc(sizeof(struct node));
    z->id = 'z';
    z->color = 'r';
    
        //Assigning pointers
    a->left = b;
    a->right = c;
    b->left = x;
    b->right = z;
    c->left = d;
    c->right = e;
    d->left = 0;
    d->right = 0;
    e->left = 0;
    e->right = 0;
    z->left = 0;
    z->right = 0;
    x->left = 0;
    x->right = 0;

    //  The above creates the following RB Tree
    //
    //              a
    //             / \
    //            b   c
    //           / \  /\
    //          x   zd   e
    //
    //  With members b, and c being red nodes,
    //  Giving the tree a black-height of 3

    printf("The result of the verify() function is: %d\n", verify(a));

    //Verifies that the tree is RB.
    //If not, it returns a value to determine,
    //error with tree.
    //
    //Return error codes:
    //   1- Uncolored nodes 
    //   2- Root node is red
    //   3- A leaf is red
    //   4- R nodes has <2 B children
    //   5- BHeight is not == for all leaves
    //   6- No root node
}

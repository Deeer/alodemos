//
//  main.c
//  avltree
//
//  Created by apple on 2018/9/28.
//  Copyright © 2018 apple. All rights reserved.
//

#include <stdio.h>

//
typedef int  Type;

#define HEIGHT(p)    ( (p==NULL) ? 0 : (((Node *)(p))->height) )
#define MAX(a, b)    ( (a) > (b) ? (a) : (b) )


typedef struct AVLTreeNode {
    Type key;
    int height;
    struct AVLTreeNode *left; // 左孩子
    struct AVLTreeNode *right; // 右孩子
}Node, *AVLTree;


static Node * avltree_create_node(Type key, Node *left, Node *right) {
    Node *p;
    if ((p=(Node*)malloc(sizeof(Node))) == NULL) {
        return NULL;
    }
    p->key = key;
    p->height = 0;
    p->left = left;
    p->right = right;
    
    return p;
}

int avlTree_height(AVLTree tree) {
    return HEIGHT(tree);
}


// LL
static Node *left_left_rotation(AVLTree k2) {
    AVLTree k1;
    
    // 旋转
    k1 = k2->left;
    
    k2->left = k1->right;
    
    k1->right = k2;
    
    // 重新计算高度
    k2 -> height = MAX(HEIGHT(k2->left), HEIGHT(k1->right)) + 1;
    k1 -> height = MAX(HEIGHT(k1->left), k2->height) + 1;
    
    return k1;
}

// RR
static Node *right_right_rotation(AVLTree k1) {
    AVLTree k2;
    
    k2 = k1 -> right;
    k1->right = k2->left;
    k2->left = k1;
    
    
    k1->height = MAX(HEIGHT(k1->left), HEIGHT(k1->right)) + 1;
    k2->height = MAX(HEIGHT(k2->right), k1->height) + 1;
    
    return k2;
}

//LR
static Node *left_right_rotation(AVLTree k3) {
    k3->left = right_right_rotation(k3->left);
    return left_left_rotation(k3);
}

// RL
static Node *right_left_rotation(AVLTree k1) {
    k1->right = left_left_rotation(k1->right);
    return right_right_rotation(k1);
}



Node *avltree_insert(AVLTree tree, Type key) {
    if (tree == NULL) {
        tree = avltree_create_node(key, NULL, NULL);
        if (tree == NULL) {
            printf("error: creaet altree node failed\n");
            return  NULL;
        }
    } else if(key < tree->key) {
        tree -> left = avltree_insert(tree, key);
        if (HEIGHT(tree->left) - HEIGHT(tree->right) == 2) {
            if (key < tree -> key) {
                tree = left_left_rotation(tree);
            } else {
                tree = left_right_rotation(tree);
            }
        }
    }else if(key > tree->key) {
        tree->right =avltree_insert(tree->right, key);
        
        if (HEIGHT(tree->right) - HEIGHT(tree->left) == 2) {
            if (key > tree ->right -> key) {
                tree = right_right_rotation(tree);
            } else {
                tree = right_left_rotation(tree);
            }
        }
    } else {
        printf("添加失败");
    }
    
    tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    return tree;
}


//static Node *delete_node(AVLTree tree, Node *z) {
//    if (tree == NULL || z == NULL) {
//        return NULL;
//    }
//    
//    if (z->key < tree->key) {
//        tree->left = delete_node(tree->left, z);
//        if (HEIGHT(tree->right) - HEIGHT(tree->left) == 2) {
//            Node *r = tree->right;
//            if (HEIGHT(r->left)> HEIGHT(r->right)) {
//                tree = right_left_rotation(tree);
//            } else {
//                tree = left_right_rotation(tree);
//            }
//        }
//    }else if( z->key > tree->key ){
//        tree->right = delete_node(tree->right, z);
//        if (HEIGHT(tree->left) - HEIGHT(tree->right) == 2) {
//            Node *l = tree->left;
//            if (HEIGHT(l->right) > HEIGHT(l->left)) {
//                tree = left_right_rotation(tree);
//            }else {
//                tree = left_left_rotation(tree);
//            }
//        }
//    }else {
//        if (tree->left && tree->right) {
//            if (HEIGHT(tree->left) > HEIGHT(tree->right)) {
//                
//            }
//        }
//    }
//}







int main(int argc, const char * argv[]) {
    
    return 0;
}

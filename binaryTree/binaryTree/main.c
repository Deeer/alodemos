//
//  main.c
//  binaryTree
//
//  Created by apple on 2018/9/28.
//  Copyright © 2018 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef int  Type ;

typedef struct BSTreeNode{
    Type key; // 节点值信息
    struct BSTreeNode *left; // 左结点
    struct BSTreeNode *right; // 右节点
    struct BSTreeNode *paretnt; // 父节点
    
} Node, *BSTree;


/**
 创建结点
 */
static Node * create_bstree_node(Type key, Node *parent, Node *left, Node *right) {
    Node *p; // 声明变量
    // 开辟控件
    if ((p = (Node *)malloc(sizeof(Node))) == NULL)
        return NULL;
    // 赋值
    p->key = key;
    p->left = left;
    p->right = right;
    p->paretnt = parent;
    return  p;
}


// 前序遍历
void preorder_bstree(BSTree tree) {
    if (tree == NULL) {
        return;
    }
    
    printf("%d", tree -> key);
    preorder_bstree(tree->left);
    preorder_bstree(tree->right);
}

// 中序遍历
void midorder_bstree(BSTree tree) {
    if (tree == NULL) {
        return;
    }
    
    midorder_bstree(tree->left);
    printf("%d", tree->key);
    midorder_bstree(tree->right);
}

// 后序遍历
void postorder_bstree(BSTree tree) {
    if (tree == NULL) {
        return;
    }
    
    postorder_bstree(tree->left);
    postorder_bstree(tree->right);
    printf("%d", tree->key);
}


// 搜索二叉树
// key 决定搜索方向
// 递归方式
Node * bstree_search(BSTree x, Type key) {
    
    if (x == NULL || x->key == key) {
        return x;
    }
    
    if(key < x -> key)  {
        return bstree_search(x->left, key);
    } else {
        return bstree_search(x->right, key);
    }
}

// 非递归方式
Node * bstree_search2(BSTree x, Type key) {
    while ((x != NULL) && (x -> key != key)) {
        if (key < x-> key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

// 最大值
Node * bstree_maxiumx(BSTree tree) {
    if (tree == NULL) {
        return  NULL;
    }
    while (tree -> right != NULL) {
        tree = tree->right;
    }
    return tree;
}

// 最小值
Node * bstrer_minmux(BSTree tree) {
    if (tree == NULL) {
        return NULL;
    }
    
    while (tree -> left != NULL) {
        tree = tree -> left;
    }
    return tree;
}

// 前驱
Node *bstree_predecessor(Node *x) {
    
    //  如果x存在左孩子，则x的前驱结点未 以其左孩子为根的子树的最大结点
    
    if (x -> left != NULL) {
        return bstree_maxiumx(x -> left);
    }
    
    // 如果没有左子树， x 有以下两种可能
    // 1.x 是一个右孩子，则x的前驱结点 为 他的父节点
    // 2.x 是一个左孩子，则查找x的最低的父节点，并且该父节点具有右孩子，找到这个最低的父节点d 就是 x 的前驱结点
    
    Node *y = x->paretnt;
    while ((y != NULL) && (x==y->left)) {
        x = y;
        y = y -> paretnt;
    }
    
    return y;
}

// 后继
Node *bstree_successor(Node *x) {
    // 如果x 存在右孩子，则 x 的后继点为 以其右孩子为根的子树的最小结点
    if (x -> right != NULL ) {
        return bstrer_minmux(x->right);
    }
    
    // 如果x没有右孩子，则x有以下两种可能
    // x 是一个左孩子，则x的后继结点为 他的父节点
    // x 是一个右孩子，则查找x的最低的父节点，并且该父节点要具有左孩子，找到的这个 最低父节点 就是 x的后继结点
    Node *y = x->paretnt  ;
    while ((y!=NULL) && (x==y->right)) {
        x = y;
        y = y->paretnt;
    }
    return y;
}


// 插入结点
static Node * bstree_insert(BSTree tree, Node *z) {
    Node *y = NULL;
    Node *x = NULL;
    // 找到要挂载的结点
    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    // 进行插入操作
    z->paretnt = y;
    
    //
    if (y == NULL) {
        tree = z;
    } else if(z -> key < y -> key ) {
        y->left = z;
    } else {
        y->right = z;
    }
    return tree;
}

// 插入结点
Node *insert_bstree(BSTree tree, Type key) {
    // 构造节点
    Node *z;
    if ((z = create_bstree_node(key, NULL, NULL, NULL))) {
        return tree;
    }
    // 执行插入操作
    return bstree_insert(tree, z);
}

// 删除二叉树中的节点，并返回删除后的根节点
static Node *bstree_delete(BSTree tree, Node *z) {
    Node * x = NULL;
    Node * y = NULL;
    
    // case1: 删除节点没有左右孩子
    if ((z -> left == NULL) || (z->right == NULL)) {
        y = z;
    } else {
        // 有的话，找打他的后继节点
        y = bstree_successor(z);
    }
    
    //
    if (y -> left != NULL) {
        x = y -> left;
    } else {
        x = y -> right;
    }
    
    // case3:没有左节点页
    if (x != NULL) {
        x -> paretnt = y -> paretnt;
    }
    
    if (y -> paretnt == NULL) {
        // 没有父节点 意味着是单单节点
        tree = x;
    } else if (y == y -> paretnt->left ) {
        //
        y -> paretnt -> left = x;
    } else {
        y -> paretnt -> right = x;
    }
    
    if (y != z) {
        z -> key = y -> key;
    }
    
    if (y != NULL) {
        free(y);
    }
    
    return tree;
}

Node *delete_bstree(BSTree tree, Type key) {
    Node* z;
    if ((z = bstree_search(tree, key)) != NULL) {
        tree = bstree_delete(tree, z) ;
    }
    return tree;
}

// 打印二叉树
void print_btree(BSTree tree, Type key, int direction ) {
    if (tree != NULL) {
        if (direction == 0) {
            printf("%2d is root \n",tree -> key);
        } else {
            printf("%2d is %2d's %6s child\n ",tree -> key, key, direction == 1 ? "right":"left" );
        }
        print_btree(tree->left, tree->key, -1);
        print_btree(tree->right, tree->key, 1);
    }
}


// 从根节点递归遍历到子节点，然后递归删除
void destory_bstree(BSTree tree) {
    if (tree== NULL) {
        return;
    }
    if (tree -> left != NULL) {
        destory_bstree(tree -> left);
    } else {
        destory_bstree(tree->right);
    }
    free(tree);
}


int main(int argc, const char * argv[]) {
    
    return 0;
}


#include "binary_tree.h"

void tree_print(struct Node* tree){
    if (tree == NULL)
        return;
    else{
        tree_print(tree->left);
        printf("%d ", tree->data);
        tree_print(tree->right);
    }
}

struct Node* tree_add(struct Node* tree, Data d){
    if (tree == NULL){
        struct Node * new_node = malloc(sizeof(struct Node));
        new_node->data = d;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    else if (d < tree->data){
        tree->left = tree_add(tree->left, d);
    }
    else{
        tree->right = tree_add(tree->right, d);
    }
    return tree;
}


struct Node* search(struct Node* tree, Data k){
    if(tree == NULL || k == tree->data)
        return tree;
    else if(k < tree->data)
        search(tree->left, k);
    else
        search(tree->right, k);
    return tree;
}

struct Node* min(struct Node* tree){
    if (tree->left == NULL)
        return tree;
    return min(tree->left);
}

struct Node* max(struct Node* tree){ 
    if (tree->right == NULL)  
        return tree;
    return max(tree->right); 
}

struct Node* insert(struct Node* tree, Data k){
    if(tree == NULL)
        return tree_add(NULL, k);
    else if(k < tree->data)
        tree->left = insert(tree->left, k);
    else if(k > tree->data)
        tree->right = insert(tree->right, k);
    return tree; 
}

struct Node* delete(struct Node* tree, Data k){
    if(tree == NULL)
        return tree;
    else if(k < tree->data)
        tree->left = delete(tree->left, k);
    else if(k > tree->data)
        tree->right = delete(tree->right, k);
    //далее ситуация, когда мы нашли удаляемый узел
    else if(tree->left != NULL && tree->right != NULL){
        tree->data = min(tree->right)->data;
        tree->right = delete(tree->right, tree->data);  
    }
    else{
        if(tree->left != NULL)
            tree = tree->left;
        else if(tree->right != NULL)
            tree = tree->right;
        //если выше все неверно, то значит искомый узел - лист
        else
            tree = NULL;
    }
    return tree;
}


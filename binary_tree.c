#include "binary_tree.h"


void tree_print(struct Node* tree, ST_ERR *err){
    if (tree == NULL){        
        if(err != NULL){
            fprintf(stderr, "Tree is empty\n");
            *err = ST_ERR_EMPTY; 
        }    
        return;
    }
    else{
        if(tree->left != NULL)
            tree_print(tree->left, err);
        printf("%d ", tree->data);
        if(tree->right != NULL)
            tree_print(tree->right, err);
    }
}

struct Node* tree_add(struct Node* tree, Data d, ST_ERR *err){
    if (tree == NULL){
        struct Node * new_node = malloc(sizeof(struct Node));
        new_node->data = d;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    else if(d < tree->data){
        tree->left = tree_add(tree->left, d, err);
    }
    else{
        tree->right = tree_add(tree->right, d, err);
    }
    return tree;
}


struct Node* search(struct Node* tree, Data k, ST_ERR *err){
    if(tree == NULL){
        if (k == tree->data)
            return tree;
        else{
            if (err != NULL){
                *err = ST_ERR_EMPTY;
                fprintf(stderr, "Tree is empty\n");
            }
            return NULL;
        }
    }
    else if(k < tree->data){
        if(tree->left != NULL)
            search(tree->left, k, err);
        else{
            *err = ST_ERR_EMPTY;
            fprintf(stderr, "Tree is empty\n");
        }
    }
    else{
        if(tree->right != NULL)
            search(tree->right, k, err);
        else{
            *err = ST_ERR_EMPTY;
            fprintf(stderr, "Tree is empty\n");
        }
    }
    return tree;
}

struct Node* min(struct Node* tree, ST_ERR *err){
    if (tree == NULL){
        if (err != NULL){
            fprintf(stderr, "Tree is empty\n");
            *err = ST_ERR_EMPTY;
        }
    }
    if (tree->left == NULL)
        return tree;
    return min(tree->left, err);
}

struct Node* max(struct Node* tree, ST_ERR *err){ 
    if (tree == NULL){
        if (err != NULL){
            *err = ST_ERR_EMPTY;
            fprintf(stderr, "Tree is empty\n");
        }
    }
    if (tree->right == NULL)  
        return tree;
    return max(tree->right, err); 
}

struct Node* insert(struct Node* tree, Data k, ST_ERR *err){
    if(tree == NULL)
        return tree_add(NULL, k, err);
    else if(k < tree->data)
        tree->left = insert(tree->left, k, err);
    else if(k >= tree->data)
        tree->right = insert(tree->right, k, err);
    return tree; 
}

struct Node* delete(struct Node* tree, Data k, ST_ERR *err){
    if(tree == NULL){        
        return tree;
    }
    else if(k < tree->data && tree->left != NULL)
        tree->left = delete(tree->left, k, err);
    else if(k > tree->data && tree->right != NULL)
        tree->right = delete(tree->right, k, err);
    //далее ситуация, когда мы нашли удаляемый узел
    else if(tree->data == k && tree->left != NULL && tree->right != NULL){
        tree->data = min(tree->right, err)->data;
        tree->right = delete(tree->right, tree->data, err);  
    }
    else if(tree->data == k){
        if(tree->left != NULL)
            tree = tree->left;
        else if(tree->right != NULL)
            tree = tree->right;
        //если выше все неверно, то значит искомый узел - лист
        else
            tree = NULL;
    }
    else{ //значит такой вершины нет
        if (err != NULL){
            *err = ST_ERR_INVARG;
            fprintf(stdout, "Node wasn't found\n");
        }        
    }
    return tree;
}

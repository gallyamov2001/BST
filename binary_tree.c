#include "binary_tree.h"


void tree_print(struct Node* tree, ST_ERR *err){
    if (tree == NULL){
        fprintf(stderr, "Tree is empty\n");        
        if(err != NULL){
            *err = ST_ERR_EMPTY; 
        }    
        return;
    }
    if(tree->left != NULL)
        tree_print(tree->left, err);
    printf("%d ", tree->data);
    if(tree->right != NULL)
        tree_print(tree->right, err);
    *err = ST_ERR_SUCCESS;
    return;
}

struct Node* tree_add(struct Node* tree, Data d, ST_ERR *err){
    if (tree == NULL){
        struct Node * new_node = malloc(sizeof(struct Node));
        if (new_node == NULL) {
            fprintf (stderr, "Not enough memory\n");
            if (err != NULL)
                *err = ST_ERR_EMALLOC; 
            return NULL;
        }
        new_node->data = d;
        new_node->left = NULL;
        new_node->right = NULL;
        *err = ST_ERR_SUCCESS;
        return new_node;
    }
    else if(d < tree->data){
        tree->left = tree_add(tree->left, d, err);
    }
    else{
        tree->right = tree_add(tree->right, d, err);
    }
    *err = ST_ERR_SUCCESS;
    return tree;
}


struct Node* search(struct Node* tree, Data k, ST_ERR *err){
    if(tree == NULL){
        fprintf(stderr, "Node wasn't found\n");
        if (err != NULL){
            *err = ST_ERR_INVARG;
        }
        return NULL;
    }
    struct Node* tree_d = NULL;
    if(k < tree->data){
        if(tree->left != NULL)
            tree_d = search(tree->left, k, err);
        else{
            fprintf(stderr, "Node wasn't found\n");
            if(err != NULL){
                *err = ST_ERR_INVARG;
            }
            return NULL;
        }
    }
    else{
        if(tree->data == k){
            return tree;
        }
        if(tree->right != NULL)
            tree_d = search(tree->right, k, err);
        else{
            fprintf(stderr, "Node wasn't found\n");
            if(err != NULL){
                *err = ST_ERR_INVARG;
            }
            return NULL;
        }
    }
    if(tree_d == NULL){
        if (err != NULL){
            *err = ST_ERR_INVARG;
        }
        return NULL;
    }
    *err = ST_ERR_SUCCESS;
    return tree_d;
}

struct Node* min(struct Node* tree, ST_ERR *err){
    if (tree == NULL){
        fprintf(stderr, "Tree is empty\n");
        if (err != NULL){
            *err = ST_ERR_EMPTY;
        }
        return tree;
    }
    if (tree->left == NULL)
        return tree;
    *err = ST_ERR_SUCCESS;
    return min(tree->left, err);
}

struct Node* max(struct Node* tree, ST_ERR *err){ 
    if (tree == NULL){
        fprintf(stderr, "Tree is empty\n");
        if (err != NULL){
            *err = ST_ERR_EMPTY;
        }
        return tree;
    }
    if (tree->right == NULL)  
        return tree;
    *err = ST_ERR_SUCCESS;
    return max(tree->right, err); 
}

struct Node* insert(struct Node* tree, Data k, ST_ERR *err){
    if(tree == NULL)
        return tree_add(tree, k, err);
    else if(k < tree->data)
        tree->left = insert(tree->left, k, err);
    else if(k >= tree->data)
        tree->right = insert(tree->right, k, err);
    *err = ST_ERR_SUCCESS;
    return tree; 
}

struct Node* node_remove(struct Node* tree, Data k, ST_ERR *err){
    if(tree == NULL){
        fprintf(stderr, "Tree is empty\n");
        if(err != NULL){
            *err = ST_ERR_EMPTY;
        }       
        return tree;
    }
    else if(k < tree->data && tree->left != NULL)
        tree->left = node_remove(tree->left, k, err);
    else if(k > tree->data && tree->right != NULL)
        tree->right = node_remove(tree->right, k, err);
    //далее ситуация, когда мы нашли удаляемый узел
    else if(tree->data == k && tree->left != NULL && tree->right != NULL){
        tree->data = min(tree->right, err)->data;
        tree->right = node_remove(tree->right, tree->data, err);  
    }
    else if(tree->data == k){
        if(tree->left != NULL)
            tree = tree->left;
        else if(tree->right != NULL)
            tree = tree->right;
        //если выше все неверно, то значит искомый узел - лист
        else{
            *err = ST_ERR_SUCCESS;
            free(tree);
            tree = NULL;
        }
    }
    else{ //значит такой вершины нет
        fprintf(stderr, "Node wasn't found\n");
        if (err != NULL){
            *err = ST_ERR_INVARG;
        }
        return NULL;
    }
    
    return tree;
}

void tree_del(struct Node* tree, ST_ERR *err){
    if(tree == NULL){
        fprintf(stderr, "Tree wasn't found\n");
        if (err != NULL){
            *err = ST_ERR_INVARG;
        }
        return;
    }
    if(tree->left != NULL){
        tree_del(tree->left, err);
    }
    if(tree->right != NULL){
        tree_del(tree->right, err);
    }
    *err = ST_ERR_SUCCESS;
    free(tree);
    tree = NULL;
    return;
}

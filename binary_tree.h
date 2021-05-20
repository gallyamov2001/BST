#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Data;

typedef enum {
    ST_ERR_SUCCESS = 0,
    ST_ERR_INVARG,
    ST_ERR_EMPTY,
    ST_ERR_OOM,
    ST_ERR_EMALLOC
} ST_ERR;

struct Node{
    Data data;
    struct Node* left;
    struct Node* right;
};

void tree_print(struct Node* tree, ST_ERR *err);

struct Node* tree_add(struct Node* tree, Data d, ST_ERR *err);

struct Node* search(struct Node* tree, Data k, ST_ERR *err);

struct Node* min(struct Node* tree, ST_ERR *err);

struct Node* max(struct Node* tree, ST_ERR *err); 

struct Node* insert(struct Node* tree, Data k, ST_ERR *err);

struct Node* node_remove(struct Node* tree, Data k, ST_ERR *err);

void tree_del(struct Node* tree, ST_ERR *err);

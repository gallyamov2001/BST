#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Data;

struct Node{
    Data data;
    struct Node* left;
    struct Node* right;
};

void tree_print(struct Node* tree);

struct Node* tree_add(struct Node* tree, Data d);

struct Node* search(struct Node* tree, Data k);

struct Node* min(struct Node* tree);

struct Node* max(struct Node* tree); 

struct Node* insert(struct Node* tree, Data k);

struct Node* delete(struct Node* tree, Data k);

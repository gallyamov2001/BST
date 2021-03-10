#include <stdio.h>
#include "binary_tree.h"


int main(){
    struct Node* tree;
    int nums[] = {17, 23, 55, 34, 11, 99, 54, 24, 100, 9};
    for (int i = 0; i < sizeof(nums); i++){
        tree = tree_add(tree, nums[i]);
    }
    tree_print(tree);
    fprintf(stdout, "max is %d\n", max(tree)->data);
    fprintf(stdout, "min is %d\n", min(tree)->data);
    tree = delete(tree, 55);
    tree_print(tree);
}

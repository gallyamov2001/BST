#include <stdio.h>
#include "binary_tree.h"


int main(){
    struct Node* tree = NULL;
    const int n = 10;
    int nums[n] = {17, 23, 55, 34, 11, 99, 54, 24, 100, 9};
    for (int i = 0; i < n; i++){
        tree = tree_add(tree, nums[i]);
    }
    printf("Tree is: ");
    tree_print(tree);
    printf("\n");
    fprintf(stdout, "Max is %d\n", max(tree)->data);
    fprintf(stdout, "Min is %d\n", min(tree)->data);
    tree = delete(tree, 55);
    printf("Tree after deleting 55 is: ");
    tree_print(tree);
}

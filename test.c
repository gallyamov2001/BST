#include <stdio.h>
#include "binary_tree.h"


int main(){
    ST_ERR err;
    struct Node* tree = NULL;
    const int n = 14;
    int nums[n] = {17, 100, 9, 23, 55, 17, 24, 34, 11, 99, 54, 24, 100, 9};
    for (int i = 0; i < n; i++){
        tree = tree_add(tree, nums[i], &err);
    }
    printf("Tree is: ");
    tree_print(tree, &err);
    printf("\n");

    fprintf(stdout, "Max is %d\n", max(tree, &err)->data);
    fprintf(stdout, "Min is %d\n", min(tree, &err)->data);

    fprintf(stdout, "Let's try to delete 54\n");
    tree = delete(tree, 54, &err);
    printf("Tree after deleting 54 is: ");
    tree_print(tree, &err);
    printf("\n");

    fprintf(stdout, "Let's try to delete 53\n");
    tree = delete(tree, 53, &err);
    printf("Tree after deleting 53 is: ");
    tree_print(tree, &err);
    printf("\n");

    fprintf(stdout, "Let's try to insert 53\n");
    tree = insert(tree, 53, &err);
    printf("Tree after inserting 53 is: ");
    tree_print(tree, &err);
    printf("\n");
    
}

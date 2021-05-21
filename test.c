#include <stdio.h>
#include "binary_tree.h"

int main(){
    ST_ERR err;
    struct Node* tree = NULL; //empty tree
    struct Node* tree_n = NULL;
    struct Node* tree_d = NULL; //draft tree
    int nums[14] = {17, 101, 9, 23, 55, 17, 24, 34, 11, 99, 54, 24, 100, 9};
    for (int i = 0; i < 14; i++){
        tree_n = tree_add(tree_n, nums[i], &err);
    }
    
    tree_d = search(tree_n, 1001, &err); //0
    if(err != ST_ERR_INVARG){
        fprintf(stdout, "Test_0\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_0\t->\tPASSED\n");
    }
    
    tree_del(NULL, &err); //1
    if(err != ST_ERR_INVARG){
        fprintf(stdout, "Test_1\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_1\t->\tPASSED\n");
    }


    tree_print(tree, &err); //2
    if(err != ST_ERR_EMPTY){
        fprintf(stdout, "Test_2\t->\tFAILED\n");
    }   
    else{
        fprintf(stdout, "Test_2\t->\tPASSED\n");
    }

    
    tree_d = search(tree, 1, &err); //3
    if(err != ST_ERR_INVARG){
         fprintf(stdout, "Test_3\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_3\t->\tPASSED\n");
    }
    
    
    tree_d = min(tree, &err); //4
    if(err != ST_ERR_EMPTY){
         fprintf(stdout, "Test_4\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_4\t->\tPASSED\n");
    }
    
    
    tree_d = max(tree, &err); //5
    if(err != ST_ERR_EMPTY){
         fprintf(stdout, "Test_5\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_5\t->\tPASSED\n");
    }
    
    
    fprintf(stdout, "Tree is: "); //6
    tree_print(tree, &err);
    printf("\n");
    if(err != ST_ERR_EMPTY){
         fprintf(stdout, "Test_6\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_6\t->\tPASSED\n");
    }
    
    
    tree_d = max(tree_n, &err); //7
    fprintf(stdout, "Max is: ");
    fprintf(stdout, "%d", tree_d->data);
    printf("\n");
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_7\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_7\t->\tPASSED\n");
    }
    
    
    tree_d = min(tree_n, &err); //8
    fprintf(stdout, "Min is: ");
    fprintf(stdout, "%d", tree_d->data);
    printf("\n");
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_8\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_8\t->\tPASSED\n");
    }
    

    tree_d = search(tree_n, 17, &err); //9
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_9\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_9\t->\tPASSED\n");
    }
    
    
    tree_d = search(tree_n, 100, &err); //10
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_10\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_10\t->\tPASSED\n");
    }
    
    
    tree_d = search(tree_n, 23, &err); //11
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_11\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_11\t->\tPASSED\n");
    }
    
    
    tree_d = search(tree_n, 55, &err); //12
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_12\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_12\t->\tPASSED\n");
    }
    
    
    tree_d = search(tree_n, 24, &err); //13
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_13\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_13\t->\tPASSED\n");
    }
    
    
    tree_d = search(tree_n, 99, &err); //14
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_14\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_14\t->\tPASSED\n");
    }
    
    tree_print(tree_n, &err);
    printf("\n");
    tree_d = node_remove(tree_n, 99, &err); //15
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_15\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_15\t->\tPASSED\n");
    }
    
    tree_print(tree_n, &err);
    printf("\n");
    tree_d = node_remove(tree_n, 24, &err); //16
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_16\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_16\t->\tPASSED\n");
    }
    
    tree_print(tree_n, &err);
    printf("\n");
    tree_d = node_remove(tree_n, 55, &err); //16(2)
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_16(2)\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_16(2)\t->\tPASSED\n");
    }
    
    tree_print(tree_n, &err);
    printf("\n");
    tree_d = node_remove(tree_n, 23, &err); //17
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_17\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_17\t->\tPASSED\n");
    }
    
    
    tree_print(tree_n, &err);
    printf("\n");
    tree_d = node_remove(tree_n, 100, &err); //18
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_18(1)\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_18\t->\tPASSED\n");
    }
    
    tree_print(tree_n, &err);
    printf("\n");
    tree_d = node_remove(tree_n, 101, &err); //18_2
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_18(2)\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_18(2)\t->\tPASSED\n");
    }
    
    
    tree_print(tree_n, &err);
    printf("\n");
    tree_n = insert(tree_n, 100, &err); //19
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_19\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_19\t->\tPASSED\n");
    }
    
    
    tree_print(tree_n, &err);
    printf("\n");
    tree_n = insert(tree_n, 101, &err); //19(2)
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_19(2)\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_19(2)\t->\tPASSED\n");
    }
    
    
    tree_print(tree_n, &err);
    printf("\n");
    tree_n = insert(tree_n, 23, &err); //20
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_20\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_20\t->\tPASSED\n");
    }
    
    
    tree_n = insert(tree_n, 55, &err); //21
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_21\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_21\t->\tPASSED\n");
    }
    
    
    tree_n = insert(tree_n, 24, &err); //22
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_22\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_22\t->\tPASSED\n");
    }
    
    
    tree_n = insert(tree_n, 99, &err); //23
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_23\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_23\t->\tPASSED\n");
    }
    
    
    //вернули наше tree_n в исходное состояние
    fprintf(stdout, "Tree is: "); //24
    tree_print(tree_n, &err);
    printf("\n");
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_24\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_24\t->\tPASSED\n");
    }
    
    
    tree_d = tree_add(tree, 1, &err); //25
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_25\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_25\t->\tPASSED\n");
    }
    
    
    tree_d = insert(tree, 1, &err); //26
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_26\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_26\t->\tPASSED\n");
    }
    

    tree_d = search(tree_n, 0, &err); //27
    if(err != ST_ERR_INVARG){
        fprintf(stdout, "Test_27\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_27\t->\tPASSED\n");
    }
    
    
    tree_d = search(tree_n, 51, &err); //28
    if(err != ST_ERR_INVARG){
        fprintf(stdout, "Test_28\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_28\t->\tPASSED\n");
    }
    
    
    tree_d = search(tree_n, 22, &err); //28
    if(err != ST_ERR_INVARG){
        fprintf(stdout, "Test_28\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_28\t->\tPASSED\n");
    }
    
    
    tree_d = node_remove(tree_n, 22, &err); //29
    if(err != ST_ERR_INVARG){
        fprintf(stdout, "Test_29\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_29\t->\tPASSED\n");
    }
    
    
    tree_d = node_remove(tree_n, 51, &err); //30
    if(err != ST_ERR_INVARG){
        fprintf(stdout, "Test_30\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_30\t->\tPASSED\n");
    }
    
    
    tree_d = node_remove(tree_n, 0, &err); //31
    if(err != ST_ERR_INVARG){
        fprintf(stdout, "Test_31\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_31\t->\tPASSED\n");
    }
    
    
    tree_d = node_remove(tree_n, 1, &err); //32
    if(err != ST_ERR_INVARG){
        fprintf(stdout, "Test_32\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_32\t->\tPASSED\n");
    }
    
    
    tree_del(tree_n, &err); //33
    if(err != ST_ERR_SUCCESS){
         fprintf(stdout, "Test_33\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_33\t->\tPASSED\n");
    }
    
    
    tree_del(tree, &err); //34
    if(err != ST_ERR_INVARG){
         fprintf(stdout, "Test_34\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_34\t->\tPASSED\n");
    }
    
    
    tree_d = node_remove(tree, 99, &err); //35
    if(err != ST_ERR_EMPTY){
         fprintf(stdout, "Test_35\t->\tFAILED\n");
    }
    else{
        fprintf(stdout, "Test_35\t->\tPASSED\n");
    }
    
    tree_del(tree_d, &err);
    

    return 0;    
}

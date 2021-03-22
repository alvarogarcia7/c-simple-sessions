#include <stdio.h>

void print_recursive(node *node){

        printf("%d->%d. L_id: %d, R_id: %d\n", node->node_id, node->data, node->left == NULL ? 0 : node->left->node_id, node->right == NULL ? 0 : node->right->node_id);
        if(node->left != NULL){
                print_recursive(node->left);
        }
        if(node->right != NULL){
                print_recursive(node->right);
        }
}

void print_all(){
        node* t=root;

        if(root!=NULL){
                print_recursive(t);
        }
}


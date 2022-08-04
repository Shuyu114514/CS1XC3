#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

struct node {
    char *name;
	char *tea;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

int depth(struct node *root){
    if (root == NULL) {
		return 0;
	}
	else{
		int LeftDepth = depth(root->left);
		int RightDepth = depth(root->right);
        if(LeftDepth > RightDepth){
            return LeftDepth+1;
        }else{
            return RightDepth+1;
        }
	}
}
int count_sub(struct node *root){
    if(root->left != NULL && root->right != NULL){
       return 1+count_sub(root->left)+count_sub(root->right);
    }else if(root->left != NULL && root->right == NULL){
        return 1+count_sub(root->left);
    }else if(root->left == NULL && root->right != NULL){
        return 1+count_sub(root->right);
    }else{
        return 1;
    }
}
int dfs(struct node *root, char *tok){
    int a = -1;
    int b = -1;
    //node *temp = malloc(sizeof(node));
    if (root == NULL){
		return -1;
	}else if(strcmp(root->name, tok) == 0){
        return 1;
    }

    if(root->left != NULL){
       a = dfs(root->left, tok); 
    }
    if(a > 0){
        return 1+a;
    }
    if(root->right != NULL){
        b = dfs(root->right, tok); 
    }
    if(b > 0 && root->left != NULL){
        return 1+b+count_sub(root->left);
    }else if(b > 0){
        return 1+b;
    }
    return -1;
    
}

/******************The binary tree***********************
 * The following is an illustration of the binary tree
 * I *highly* recommend you test your algorithm on.
 ********************************************************
 *                        Nicholas
 *                        /      \
 *                     Mark      Parker
 *                    /          /     \
 *                Swaleh     Soroush   Other Mark
 *                                 \
 *                                 Ana
 *                                 /
 *                             Bassel
 *
 *
 * (where "/" indicates a left branch, 
 *    and "\" indicates a right branch)
 *
 */ 

int main() {
    
    Node *root = malloc(sizeof(Node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(Node));
    root->left->left = malloc(sizeof(Node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(Node));
    root->right->left = malloc(sizeof(Node));
    root->right->right = malloc(sizeof(Node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(Node));
    root->right->left->right->left = malloc(sizeof(Node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";

    printf("The sub tree of Parker: %d\n", count_sub(root->right));
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
    
    printf("Depth First Search for : Nicholas\n");
    printf("result: %d\n", dfs(root, "Nicholas"));
    // expected result is 1
    
    printf("Depth First Search for : Other Mark\n");
    printf("result: %d\n", dfs(root, "Other Mark"));
    // expected result is 8
    
    printf("Depth First Search for : Parker\n");
    printf("result: %d\n", dfs(root, "Parker"));
    
    printf("Depth First Search for : Soroush\n");
    printf("result: %d\n", dfs(root, "Soroush"));
    
    printf("Depth First Search for : Swaleh\n");
    printf("result: %d\n", dfs(root, "Swaleh"));

    printf("Depth First Search for : Mark\n");
    printf("result: %d\n", dfs(root, "Mark"));
    
    printf("Depth First Search for : Ana\n");
    printf("result: %d\n", dfs(root, "Ana"));
    // expected result is 4
    
    printf("Depth First Search for : Julius Ceasar\n");
    printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // expected result is -1
    
    free(root->right->left->right->left);
    free(root->right->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);
}

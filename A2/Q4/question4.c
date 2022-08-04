#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node {
    int value;
    struct node *prev;
    struct node *next;
};

struct node *element(struct node *dll, int i){
    if(i != 0 && dll->next != NULL){
        return element(dll->next, i-1);
    }else if(i != 0 && dll->next == NULL){
        return NULL;
    }
    return dll;
}
struct node *head(struct node *dll){
    if(dll->prev != NULL){
        return head(dll->prev);
    }else{
        return dll;
    }
}
struct node *tail(struct node *dll){
    if(dll->next != NULL){
        return tail(dll->next);
    }else{
        return dll;
    }
}
struct node *add(struct node *dll, int i, int value){
    if((i > 0 && dll->next == NULL) || i < 0){
        struct node *new_node = malloc(sizeof(struct node));
        new_node->value = value;
        new_node->prev = tail(dll);
        tail(dll)->next = new_node;
        return head(dll);
    }else if(i > 0 && dll->next != NULL){
        return add(dll->next, i-1, value);
    }else if(i == 0){
        struct node *new_node = malloc(sizeof(struct node));
        new_node->value = value;
        if(dll->prev != NULL){
            dll->prev->next = new_node;
            new_node->prev = dll->prev;
        }
        dll->prev = new_node;
        new_node->next = dll;
        return head(dll);
    }  
}
struct node *delete(struct node *dll, int i){
    if((i > 0 && dll->next == NULL) || i < 0){
        return head(dll);
    }else if(i > 0 && dll->next != NULL){
        return delete(dll->next, i-1);
    }else if(i == 0 && dll->prev == NULL && dll->next == NULL){
        return NULL;
    }else if(i == 0 && dll->prev == NULL){
        dll->next->prev = NULL;
        return dll->next;
    }else if(i == 0 && dll->prev != NULL){
        dll->next->prev = dll->prev;
        dll->prev->next = dll->next;
        return head(dll);
    }
}

void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}


void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
    struct node *dll = malloc(sizeof(struct node));
    dll->value = 1;
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll);
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
    
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
}

/* Expected Output: 

Obviously the pointers will be different each time, the point is that the previous and next pointers are pointing to the correct node. 

---
< This: 0x1cf8590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf8610 >
< This: 0x1cf8610 - 7 - P : 0x1cf85f0 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8610 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
---

*/ 

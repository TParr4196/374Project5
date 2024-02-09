#include "llist.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void llist_insert_head(struct node **head, struct node *n){

}

struct node *llist_delete_head(struct node **head){
    return NULL;
}

void llist_insert_tail(struct node **head, struct node *n){

}

void llist_print(struct node *head){
    if(head==NULL){
        printf("[empty]\n");
    }else{
        
    }
}

void llist_free(struct node **head){

}

struct node *node_alloc(int value){
    return NULL;
}

void node_free(struct node *n){

}



int main(int argc, char *argv[]){
    struct node *head=NULL;
    if(argc>1){
        int i=1;
        while(argv[i]!=NULL){
            if(strcmp(argv[i],"ih")==0){
                printf("insertHead %d, ", atoi(argv[i+1]));
                i+=2;
            }else if(strcmp(argv[i],"it")==0){
                printf("insertTail %d, ", atoi(argv[i+1]));
                i+=2;
            }else if(strcmp(argv[i],"dh")==0){
                printf("deleteHead, ");
                i++;
            }else if(strcmp(argv[i],"f")==0){
                printf("free, ");
                i++;
            }else if(strcmp(argv[i],"p, ")==0){
                llist_print(head);
                i++;
            }
            else{
                printf("command %d unknown, ", i-1);
                i++;
            }
        }
    }
    llist_free(&head);
}
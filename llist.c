#include "llist.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void llist_insert_head(struct node **head, struct node *n){
    *head=n;
}

struct node *llist_delete_head(struct node **head){
    struct node *n=*head;
    head=NULL;
    return n;
}

void llist_insert_tail(struct node **head, struct node *n){
    *head=n;
}

void llist_print(struct node *head){
    if(head==NULL){
        printf("[empty]\n");
    }else{
        printf("%d", head->value);
    }
}

void llist_free(struct node **head){
    node_free(*head);
}

struct node *node_alloc(int value){
    struct node *n;
    n=malloc(16);//sizeof(struct node is 16)
    n->value=value;
    n->next=NULL;
    return n;
}

void node_free(struct node *n){
    free(n);
}

int main(int argc, char *argv[]){
    struct node *head=NULL;
    
    if(argc>1){
        int i=1;
        while(argv[i]!=NULL){
            if(strcmp(argv[i],"ih")==0){
                //printf("insertHead %d, ", atoi(argv[i+1]));
                struct node *n=node_alloc(atoi(argv[i+1]));
                llist_insert_head(&head,n);
                i+=2;
            }
            else if(strcmp(argv[i],"it")==0){
                //printf("insertTail %d, ", atoi(argv[i+1]));
                struct node *n=node_alloc(atoi(argv[i+1]));
                llist_insert_tail(&head, n);
                i+=2;
            }
            else if(strcmp(argv[i],"dh")==0){
                //printf("deleteHead, ");
                llist_delete_head(&head);
                i++;
            }
            else if(strcmp(argv[i],"f")==0){
                //printf("free, ");
                llist_free(&head);
                i++;
            }
            else if(strcmp(argv[i],"p")==0){
                llist_print(head);
                i++;
            }
            else{
                printf("command %d unknown, ", i-1);
                i++;
            }
        }
    }
    if(head!=NULL){
        llist_free(&head);
    }
}
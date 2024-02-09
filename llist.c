#include "llist.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void llist_insert_head(struct node **head, struct node *n){
    n->next=*head;
    *head=n;
}

struct node *llist_delete_head(struct node **head){
    //llist_print(*head);
    head=&((*head)->next);
    //llist_print(*head);
    return *head;
}
//link logic still untested

void llist_insert_tail(struct node **head, struct node *n){
    struct node *temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp=n;
}
//link logic still untested

void llist_print(struct node *head){
    if(head==NULL){
        printf("[empty]\n");
    }else{
        struct node *n=head->next;
        printf("%d", head->value);
        while(n!=NULL){
            struct node *nn= n->next;
            printf(" -> %d", n->value);
            n=nn;
        }
        printf("\n");
    }
}

void llist_free(struct node **head){
    struct node *n=(*head)->next;
    node_free(*head);
    while(n!=NULL){
        struct node *nn = n->next;
        node_free(n);
        n=nn;
    }
}
//link logic still untested

struct node *node_alloc(int value){
    struct node *n;
    n=malloc(16);//sizeof(struct node is 16)
    n->value=value;
    n->next=NULL;
    return n;
}

void node_free(struct node *n){
    free(n);
    n=NULL;//unsure if needed
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
                head=llist_delete_head(&head);
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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node *right;
    struct Node *left;
}Node;

typedef struct Dequeue{
    Node* head;
    Node* tail;
    int size;
}Dequeue;

Dequeue* CreateDequeue()
{
    Dequeue* dq;
    dq = (Dequeue *)malloc(sizeof(Dequeue));
    dq->head = NULL;
    dq->tail = NULL;
    dq->size = 0;

    return dq;
}

int IsEmpty(Dequeue *dq)
{
    if (dq->head == NULL)
        return 1;
    else return 0;
}

void Push_front(Dequeue *dq, int item)
{
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = item;
    if (dq->head == NULL){
        dq->head = newnode;
        dq->tail = newnode;
        newnode->right = NULL;
        newnode->left = NULL;
        dq->size++;
    }
    else{
        newnode->left = NULL;
        newnode->right = dq->head;
        dq->head->left = newnode;
        dq->head = newnode;
        dq->size++;
    }
}

void Push_back(Dequeue *dq, int item)
{
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = item;
    if (dq->head == NULL){
        dq->head = newnode;
        dq->tail = newnode;
        newnode->right = NULL;
        newnode->left = NULL;
        dq->size++;
    }
    else{
        newnode->right = NULL;
        newnode->left = dq->tail;
        dq->tail->right = newnode;
        dq->tail = newnode;
        dq->size++;
    }
}

void Pop_front(Dequeue *dq)
{
    Node* old;
    old = dq->head;
    if(dq->head == NULL)
        printf("Empty...\n");
    else{
        dq->size--;
        dq->head = dq->head->right; 
        old->right = NULL;
    }
    free(old);
}

void Pop_back(Dequeue *dq)
{
    Node* old;
    old = dq->tail;
    if(dq->head == NULL)
        printf("Empty...\n");
    else{
        dq->size--;
        dq->tail = dq->tail->left;
        old->left = NULL;
    }
    free(old);
}

void PrintDeque(Dequeue *dq)
{
    Node* temp;
    int i = 0;
    temp = dq->head;
    if (dq->head == NULL)
        printf("Empty...\n");
    else{
        while(temp){
            printf("%d index is %d\n",++i,temp->data);
            temp = temp->right;
        }
    }
}

void PrintDequeReverse(Dequeue *dq)
{
    Node* temp;
    temp = dq->tail;
    if (dq->head == NULL)
        printf("Empty...\n");
    else{
        while(temp){
            printf("%d index is %d\n",dq->size--,temp->data);
            temp=temp->left;
        }
    }
}

void All_free(Dequeue *dq)
{
    Node *temp;
    temp = dq->head;
    if (dq->head == NULL)
        printf("Empty...\n");
    else{
        while (temp){
            temp->right = NULL;
            dq->head = dq->head->right;
            free(temp);
            temp = dq->head;
            dq->size--;
        }
    }
}

int First_data(Dequeue *dq)
{
    if(dq->head == NULL)
        return 0;
    else return dq->head->data;
}

int Last_data(Dequeue *dq)
{
    if(dq->head == NULL)
        return 0; 
    else return dq->tail->data;
}

int main(void)
{
    Dequeue *dq1=CreateDequeue();
    Push_back(dq1,10);
    Push_back(dq1,20);
    Push_back(dq1,30);
    Push_back(dq1,40);
    PrintDequeReverse(dq1);

    All_free(dq1);
    printf("%d\n", dq1->size);

    return 0;
}

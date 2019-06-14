#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node *right;
    struct Node *left;
}Node;

typedef struct Linkedlist{
    Node* head;
    Node* tail;
    int size;
}Linkedlist;

Linkedlist* CreateLinkedlist()
{
    Linkedlist* l;
    l = (Linkedlist *)malloc(sizeof(Linkedlist));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

int IsEmpty(Linkedlist *l)
{
    if (l->head == NULL)
        return 1;
    else return 0;
}

void Push_front(Linkedlist *l, int item)
{
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = item;
    if (l->head == NULL){
        l->head = newnode;
        l->tail = newnode;
        newnode->right = NULL;
        newnode->left = NULL;
        l->size++;
    }
    else{
        newnode->left = NULL;
        newnode->right = l->head;
        l->head->left = newnode;
        l->head = newnode;
        l->size++;
    }
}

void Push_back(Linkedlist *l, int item)
{
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = item;
    if (l->head == NULL){
        l->head = newnode;
        l->tail = newnode;
        newnode->right = NULL;
        newnode->left = NULL;
        l->size++;
    }
    else{
        newnode->right = NULL;
        newnode->left = l->tail;
        l->tail->right = newnode;
        l->tail = newnode;
        l->size++;
    }
}

void Pop_front(Linkedlist *l)
{
    Node* old;
    old = l->head;
    if(l->head == NULL)
        printf("Empty...\n");
    else{
        l->size--;
        l->head = l->head->right; 
        old->right = NULL;
    }
    free(old);
}

void Pop_back(Linkedlist *l)
{
    Node* old;
    old = l->tail;
    if(l->head == NULL)
        printf("Empty...\n");
    else{
        l->size--;
        l->tail = l->tail->left;
        old->left = NULL;
    }
    free(old);
}

int Max(Linkedlist *l) 
{
    Node *max;
    Node *temp;
    max = l->head;
    temp = max->right;

    if (l->head == NULL)
        printf("Empty...\n");
    else{
        while(temp){
            if ((max->data) < (temp->data)){
                max = temp;
                temp = max->right;
            }
            else temp = temp->right;
        }
    }
    return max->data;
}

int Min(Linkedlist *l) 
{
    Node *min;
    Node *temp;
    min = l->head;
    temp = min->right;

    if (l->head == NULL)
        printf("Empty...\n");
    else{
        while(temp){
            if ((min->data) > (temp->data)){
                min = temp;
                temp = min->right;
            }
            else temp = temp->right;
        }
    }
    return min->data;
}

void Print(Linkedlist *l)
{
    Node* temp;
    int i = 0;
    temp = l->head;
    if (l->head == NULL)
        printf("Empty...\n");
    else{
        while(temp){
            printf("%d index is %d\n",++i,temp->data);
            temp = temp->right;
        }
    }
}

void PrintReverse(Linkedlist *l)
{
    Node* temp;
    temp = l->tail;
    if (l->head == NULL)
        printf("Empty...\n");
    else{
        while(temp){
            printf("%d index is %d\n",l->size--,temp->data);
            temp=temp->left;
        }
    }
}

void All_free(Linkedlist *l)
{
    Node *temp;
    temp = l->head;
    if (l->head == NULL)
        printf("Empty...\n");
    else{
        while (temp){
            temp->right = NULL;
            l->head = l->head->right;
            free(temp);
            temp = l->head;
            l->size--;
        }
    }
}

int First_data(Linkedlist *l)
{
    if(l->head == NULL)
        return 0;
    else return l->head->data;
}

int Last_data(Linkedlist *l)
{
    if(l->head == NULL)
        return 0; 
    else return l->tail->data;
}

int main(void)
{
    Linkedlist *l1=CreateLinkedlist();
    Push_back(l1,10);
    Push_back(l1,20);
    Push_back(l1,30);
    Push_back(l1,40);
    Push_back(l1,35);
    Push_back(l1,25);
    Print(l1);

    printf("Max is %d\n",Max(l1));

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node *next; //노드를 가리키는 링크 포인터
}Node;

typedef struct Queue{
    Node* head;
    Node* tail;
    int size;
}Queue;

Queue* CreateQueue()
{
    Queue* q;
    q = (Queue *)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

int IsEmpty(Queue *q)
{
    if (q->head == NULL)
        return 1;
    else return 0;
}

void Push(Queue *q, int item)
{
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = item;
    if (q->head == NULL){ // 공백이라면
        q->head = newnode; // 헤드는 새 노드를 가리킴
        q->tail = newnode; 
        newnode->next = NULL;
        q->size++;
    }
    else{
        q->tail->next = newnode; // 맨 끝 노드는 새노드가리킴
        q->tail = newnode; // 꼬리도 새 노드 가리킴
        newnode->next = NULL;
        q->size++;
    }
}

void Pop(Queue *q)
{
    Node* old;
    old = q->head;
    if(q->head == NULL)
        printf("Empty...\n");
    else{
        q->size--; 
        q->head=q->head->next; // 헤드는 삭제할 노드의 다음 노드를 가리킴 즉 2번째 노드
        old->next = NULL;
    }
    free(old);
}

void PrintQueue(Queue *q)
{
    Node* temp;
    int i = 0;
    temp = q->head;
    if (q->head == NULL)
        printf("Empty...\n");
    else{
        while(temp){
            printf("%d index is %d\n",++i,temp->data);
            temp = temp->next;
        }
    }
}

int main(void)
{
    Queue* q1=CreateQueue();
    Push(q1,10);
    Push(q1,20);
    Push(q1,30);
    Push(q1,40);
    Pop(q1);

    PrintQueue(q1);

    return 0;
}

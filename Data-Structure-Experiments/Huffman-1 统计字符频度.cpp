#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode            //���ṹ������������Ƶ��������
{
    char     c;                    //�����ַ�
    int      frequency;            // �ַ���Ƶ��
    struct ListNode *next;  
}ListNode;

void insert(ListNode**, char);
void sort(ListNode*);
void swap(ListNode*,ListNode*);
void output(ListNode*);

ListNode* tail = NULL;
// ����һ���½�㣬�ַ�Ϊc��Ƶ��Ϊ1
void insert(ListNode** head_ref, char c){
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->c = c;
    new_node->frequency = 1;
    new_node->next = NULL;
    
    if(*head_ref == NULL){ //����Ϊ��
        *head_ref = new_node;
        tail = *head_ref;
        return;
    }
    ListNode* curr = *head_ref;
    while(curr != NULL){
        if(curr->c == c){ //����ǰ�ַ��Ѵ����������У���Ƶ�ȼ�1
            curr->frequency++;
            free(new_node); //�ͷ��½��
            return;
        }
        curr = curr->next;
    }
    // ����ǰ�ַ��������������У���β��
    new_node->next = NULL;
    tail->next = new_node;
    tail = tail->next;
}

void swap(ListNode *a, ListNode *b)
{
    int temp_frequency = a->frequency;
    char temp_c = a->c;
    a->frequency = b->frequency;
    a->c = b->c;
    b->frequency = temp_frequency;
    b->c = temp_c;
}

// �����������frequency�����򣬴Ӵ�С
void sort(ListNode* head)
{
    int swapped, i;
    ListNode *ptr1;
    ListNode *lptr = NULL;
  
    if (head == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = head;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->frequency < ptr1->next->frequency)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// ���������ÿ�������ַ���Ƶ��
void output(ListNode* head){
    ListNode* curr = head;
    while(curr != NULL){
        if(curr->c!='\n')   printf("'%c' %d\n", curr->c, curr->frequency);
        else    			printf("'\\n' %d\n", curr->frequency);
        curr = curr->next;
    }
}

int main()
{
    ListNode* head = NULL;
    char tmp;
    int i=0;
    while((tmp=getchar())!=EOF){
        insert(&head,tmp);
    }
    sort(head);
    output(head);
    return 0;
}

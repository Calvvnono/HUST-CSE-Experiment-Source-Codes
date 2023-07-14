#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode 
{
    char c;                  
    int frequency;           
    char *code;              
    struct ListNode *parent;
    struct ListNode *left;   
    struct ListNode *right;  
    struct ListNode *next;  
} ListNode, HuffmanTree;

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

// �����������frequency�����򣬴�С����
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
            if (ptr1->frequency > ptr1->next->frequency)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void buildHuffmanTree(ListNode** head) {
    ListNode* left, * right, * parent;

    while ((*head)->next != NULL) {
        left = *head;
        right = left->next;
        parent = (ListNode*)malloc(sizeof(ListNode));
        parent->c = '\0';
        parent->frequency = left->frequency + right->frequency;
        parent->code = NULL;
        parent->left = left;
        parent->right = right;
        parent->parent = NULL;
        left->parent = parent;
        right->parent = parent;
        *head = right->next;

        // �½���������
        ListNode* current = *head;
        ListNode* previous = NULL;
        while (current != NULL && parent->frequency > current->frequency) {
            previous = current;
            current = current->next;
        }
        if (previous == NULL) {
            parent->next = *head;
            *head = parent;
        } else {
            parent->next = previous->next;
            previous->next = parent;
        }
    }
}

// �������������ĺ���
void computeHuffmanCodes(HuffmanTree* root) {
    // ������ڵ�Ϊ�գ�ֱ�ӷ���
    if (root == NULL) {
        return;
    }
    
    // �����Ҷ�ӽڵ㣬�����ɹ���������
    if (root->left == NULL && root->right == NULL) {
        // ������������λ��
        int codeLength = 0;
        ListNode* node = root;
        while (node->parent != NULL) {
            codeLength++;
            node = node->parent;
        }
        
        // ����ռ䲢��ʼ�������ַ���
        root->code = (char*)malloc((codeLength + 1) * sizeof(char));
        root->code[codeLength] = '\0';
        
        // ��Ҷ�ӽڵ����ϱ��������ɹ���������
        node = root;
        for (int i = codeLength - 1; i >= 0; i--) {
            if (node == node->parent->left) {
                root->code[i] = '0';
            } else {
                root->code[i] = '1';
            }
            node = node->parent;
        }
    }
    
    // �ݹ鴦����������������
    computeHuffmanCodes(root->left);
    computeHuffmanCodes(root->right);
}

void printCodes(ListNode *nodeT) {
    ListNode *node = nodeT;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    while (node != NULL) {
        next = node->next; // ��¼��һ���ڵ�
        node->next = prev; // ����ǰ�ڵ��ָ�뷴��
        prev = node; // ����ǰһ���ڵ�Ϊ��ǰ�ڵ�
        node = next; // ������һ���ڵ�
    }
    node = prev; // �����һ���ڵ㸳ֵ��node
    while (node != NULL) { // ��β��ͷ��������
        if (node->c == '\n') {
            printf("'\\n' %d %s\n", node->frequency, node->code);
        } else {
            printf("'%c' %d %s\n", node->c, node->frequency, node->code);
        }
        node = node->next; // ������һ���ڵ�
    }
}

// �ݹ����ĳ���ڵ�Ĵ�Ȩ·������
int WPL(HuffmanTree *root, int depth) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) { // �����Ҷ�ӽڵ�
        return root->frequency * depth; // ���ظýڵ��Ȩ�س������
    } else {
        // ���򣬵ݹ�������������������Ĵ�Ȩ·�����ȣ����������ǵĺ�
        return WPL(root->left, depth + 1) + WPL(root->right, depth + 1);
    }
}

// �����������������Ĵ�Ȩ·������
int getWPL(HuffmanTree *root) {
    if (root == NULL) {
        return 0; // �����Ϊ�գ��򷵻� 0
    } else {
        return WPL(root, 0); // ���򣬵��� WPL ���������������Ĵ�Ȩ·������
    }
}

int main() {
    ListNode *head = NULL;
    ListNode *HEAD = NULL;
    char c;
    while ((c = getchar()) != EOF) {
        insert(&head, c);
    }

    sort(head);
    HEAD = head;
    // ������,head����Ϊ����root,��nextҲ�����ܱ���ԭ������Ϣ,����Ҫstartָ���ݴ�

    buildHuffmanTree(&head);
    computeHuffmanCodes(head);

    printCodes(HEAD);
    printf("%d", getWPL(head));
    return 0;
}

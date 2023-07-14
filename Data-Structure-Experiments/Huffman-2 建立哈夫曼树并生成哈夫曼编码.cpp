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
// 插入一个新结点，字符为c，频度为1
void insert(ListNode** head_ref, char c){
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->c = c;
    new_node->frequency = 1;
    new_node->next = NULL;
    
    if(*head_ref == NULL){ //链表为空
        *head_ref = new_node;
        tail = *head_ref;
        return;
    }
    ListNode* curr = *head_ref;
    while(curr != NULL){
        if(curr->c == c){ //若当前字符已存在于链表中，则频度加1
            curr->frequency++;
            free(new_node); //释放新结点
            return;
        }
        curr = curr->next;
    }
    // 若当前字符不存在于链表中，则尾插
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

// 根据链表结点的frequency域排序，从小到大
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

        // 新结点插入链表
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

// 计算哈夫曼编码的函数
void computeHuffmanCodes(HuffmanTree* root) {
    // 如果根节点为空，直接返回
    if (root == NULL) {
        return;
    }
    
    // 如果是叶子节点，则生成哈夫曼编码
    if (root->left == NULL && root->right == NULL) {
        // 计算编码所需的位数
        int codeLength = 0;
        ListNode* node = root;
        while (node->parent != NULL) {
            codeLength++;
            node = node->parent;
        }
        
        // 分配空间并初始化编码字符串
        root->code = (char*)malloc((codeLength + 1) * sizeof(char));
        root->code[codeLength] = '\0';
        
        // 从叶子节点向上遍历，生成哈夫曼编码
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
    
    // 递归处理左子树和右子树
    computeHuffmanCodes(root->left);
    computeHuffmanCodes(root->right);
}

void printCodes(ListNode *nodeT) {
    ListNode *node = nodeT;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    while (node != NULL) {
        next = node->next; // 记录下一个节点
        node->next = prev; // 将当前节点的指针反向
        prev = node; // 更新前一个节点为当前节点
        node = next; // 处理下一个节点
    }
    node = prev; // 将最后一个节点赋值给node
    while (node != NULL) { // 从尾到头遍历链表
        if (node->c == '\n') {
            printf("'\\n' %d %s\n", node->frequency, node->code);
        } else {
            printf("'%c' %d %s\n", node->c, node->frequency, node->code);
        }
        node = node->next; // 处理下一个节点
    }
}

// 递归计算某个节点的带权路径长度
int WPL(HuffmanTree *root, int depth) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) { // 如果是叶子节点
        return root->frequency * depth; // 返回该节点的权重乘以深度
    } else {
        // 否则，递归计算左子树和右子树的带权路径长度，并返回它们的和
        return WPL(root->left, depth + 1) + WPL(root->right, depth + 1);
    }
}

// 计算整个哈夫曼树的带权路径长度
int getWPL(HuffmanTree *root) {
    if (root == NULL) {
        return 0; // 如果树为空，则返回 0
    } else {
        return WPL(root, 0); // 否则，调用 WPL 函数计算整个树的带权路径长度
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
    // 建树后,head将成为树的root,其next也不再能保存原链表信息,故需要start指针暂存

    buildHuffmanTree(&head);
    computeHuffmanCodes(head);

    printCodes(HEAD);
    printf("%d", getWPL(head));
    return 0;
}

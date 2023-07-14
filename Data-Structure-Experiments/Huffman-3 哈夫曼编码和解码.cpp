#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 10000
#define MAX_CHARACTERS 256

typedef struct ListNode {
    char c;
    int frequency;
    char *code;
    struct ListNode *parent;
    struct ListNode *left;
    struct ListNode *right;
    struct ListNode *next;
} ListNode, HuffmanTree;

// �����ı���ÿ���ַ����ֵ�Ƶ��
void calculateFrequencies(char *text, int *frequencies) {
    int i = 0;
    while (text[i] != '\0') { // �����ı�
        frequencies[(unsigned char)text[i]]++; // ����Ӧ�ַ���Ƶ�ʼ�һ
        i++;
    }
}

// ���½ڵ���뵽�������ʵ���λ��
void insertListNode(ListNode **list, ListNode *node) {
    ListNode *prev = NULL;
    ListNode *current = *list;

    // ���������ҵ�һ���ڵ㣬�ýڵ��Ƶ�ʴ��ڻ�����½ڵ��Ƶ�ʣ����ߵ��������ĩβ
    while (current != NULL && current->frequency < node->frequency) {
        prev = current;
        current = current->next;
    }

    // ����½ڵ��Ƶ����С��������������ͷ��
    if (prev == NULL) {
        *list = node;
    } else { // ���򣬽������뵽�����м�
        prev->next = node;
    }

    // ���½ڵ��nextָ��ָ��current�ڵ�
    node->next = current;
}

// �����ַ�Ƶ�ʹ���Huffman��
void buildHuffmanTree(HuffmanTree **root, int *frequencies) {
    ListNode *list = NULL;

    // �����г��ֵ��ַ���Ϊ�ڵ���뵽������
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (frequencies[i] > 0) {
            ListNode *node = (ListNode *)malloc(sizeof(ListNode));
            node->c = (char)i;
            node->frequency = frequencies[i];
            node->code = NULL;
            node->parent = NULL;
            node->left = NULL;
            node->right = NULL;
            node->next = NULL;

            insertListNode(&list, node); // ���ڵ���뵽������
        }
    }
	ListNode* p = list;

    // �������й���Huffman��
    while (list != NULL && list->next != NULL) {
        ListNode *node1 = list;
        ListNode *node2 = list->next;
        list = list->next->next;

        // ����һ���µ�Huffman���ڵ㣬�������������ֱ�Ϊnode1��node2
        HuffmanTree *tree = (HuffmanTree *)malloc(sizeof(HuffmanTree));
        tree->c = '\0';
        tree->frequency = node1->frequency + node2->frequency;
        tree->code = NULL;
        tree->parent = NULL;
        tree->left = node1;
        tree->right = node2;

        // ��node1��node2�ĸ��ڵ�ָ������Ϊ�½ڵ�
        node1->parent = tree;
        node2->parent = tree;

        insertListNode(&list, (ListNode *)tree); // ���½ڵ���뵽������
    }
    *root = (HuffmanTree *)list; // ����Huffman���ĸ��ڵ�
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

// �����ַ�c�ڹ�������root�еĽڵ�
void search(HuffmanTree* root, char c, HuffmanTree** Node) {
    // �����ǰ�ڵ�ΪҶ�ӽڵ�
    if(root->left == NULL && root->right == NULL){
        // ����ýڵ��Ӧ���ַ���c�����ҵ���Ŀ��ڵ�
        if(root->c == c){
            *Node = root;
            return;
        }   
        // �����������
        else    return;
    }   
    // �����ǰ�ڵ㲻��Ҷ�ӽڵ㣬������ݹ�������������
    search(root->left, c, Node);    search(root->right, c, Node);
}

// ���ı����й���������
void encodeText(char *text, HuffmanTree *root, char **encodedText, int *encodedTextLength) {
    int i = 0;
    int j = 0;
    // Ϊ�������ı������ڴ�ռ�
    *encodedText = (char *)malloc(MAX_TEXT_LENGTH * sizeof(char));

    // ����������ı�
    while (text[i] != '\0') {
        char *code = NULL;
        // ���ҵ�ǰ�ַ��ڹ��������еĽڵ㣬����ȡ�����������
        ListNode* Node = NULL;
        search(root,text[i],&Node);
        code = Node->code;
        
        if (code != NULL) {
            // �����ַ��Ĺ�����������뵽�������ı���
            strcat(*encodedText, code);
            j += strlen(code);
        }
        i++;
    }
    // ��¼�������ı�����
    *encodedTextLength = j;
}

// �Թ�����������н���
void decodeText(char *encodedText, HuffmanTree *root, char **decodedText) {
    int i = 0;
    int j = 0;
    // Ϊ�������ı������ڴ�ռ�
    *decodedText = (char *)malloc(MAX_TEXT_LENGTH * sizeof(char));
    // �Ӹ��ڵ㿪ʼ������������
    HuffmanTree *currentNode = root;
    while (encodedText[i] != '\0') {
        // �����ǰ����Ϊ0�����������������
        if (encodedText[i] == '0') {
            currentNode = (HuffmanTree *)currentNode->left;
        } else if (encodedText[i] == '1') {
            // �����ǰ����Ϊ1�����������������
            currentNode = (HuffmanTree *)currentNode->right;
        }
    
        // �����������Ҷ�ӽڵ㣬�򽫸ýڵ��Ӧ���ַ����뵽�������ı���
        if (currentNode->left == NULL && currentNode->right == NULL) {
            (*decodedText)[j] = currentNode->c;
            j++;
            currentNode = root;
        }

        i++;
    }
    (*decodedText)[j] = '\0';
}

int main() {
	char *text = (char *)malloc(MAX_TEXT_LENGTH * sizeof(char));
	int c;
	int i = 0;
	while ((c = getchar()) != EOF && i < MAX_TEXT_LENGTH - 1) {
	    text[i] = c;
	    i++;
	}
	text[i] = '\0';
	
	int frequencies[MAX_CHARACTERS] = {0};
	calculateFrequencies(text, frequencies);
	
	HuffmanTree *root = NULL;
	buildHuffmanTree(&root, frequencies);
	
	computeHuffmanCodes(root);
	
	char *encodedText = NULL;
	int encodedTextLength = 0;
	encodeText(text, root, &encodedText, &encodedTextLength);
	
	char *decodedText = NULL;
	decodeText(encodedText, root, &decodedText);
	
	printf("%s\n", encodedText);
	printf("%s\n", decodedText);
    printf("%d", encodedTextLength);
	
	return 0;
}

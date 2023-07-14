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

// 计算文本中每个字符出现的频率
void calculateFrequencies(char *text, int *frequencies) {
    int i = 0;
    while (text[i] != '\0') { // 遍历文本
        frequencies[(unsigned char)text[i]]++; // 将对应字符的频率加一
        i++;
    }
}

// 将新节点插入到链表中适当的位置
void insertListNode(ListNode **list, ListNode *node) {
    ListNode *prev = NULL;
    ListNode *current = *list;

    // 在链表中找到一个节点，该节点的频率大于或等于新节点的频率，或者到达链表的末尾
    while (current != NULL && current->frequency < node->frequency) {
        prev = current;
        current = current->next;
    }

    // 如果新节点的频率最小，则将它放在链表头部
    if (prev == NULL) {
        *list = node;
    } else { // 否则，将它插入到链表中间
        prev->next = node;
    }

    // 将新节点的next指针指向current节点
    node->next = current;
}

// 根据字符频率构建Huffman树
void buildHuffmanTree(HuffmanTree **root, int *frequencies) {
    ListNode *list = NULL;

    // 将所有出现的字符作为节点插入到链表中
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

            insertListNode(&list, node); // 将节点插入到链表中
        }
    }
	ListNode* p = list;

    // 从链表中构建Huffman树
    while (list != NULL && list->next != NULL) {
        ListNode *node1 = list;
        ListNode *node2 = list->next;
        list = list->next->next;

        // 创建一个新的Huffman树节点，其中左右子树分别为node1和node2
        HuffmanTree *tree = (HuffmanTree *)malloc(sizeof(HuffmanTree));
        tree->c = '\0';
        tree->frequency = node1->frequency + node2->frequency;
        tree->code = NULL;
        tree->parent = NULL;
        tree->left = node1;
        tree->right = node2;

        // 将node1和node2的父节点指针设置为新节点
        node1->parent = tree;
        node2->parent = tree;

        insertListNode(&list, (ListNode *)tree); // 将新节点插入到链表中
    }
    *root = (HuffmanTree *)list; // 返回Huffman树的根节点
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

// 查找字符c在哈夫曼树root中的节点
void search(HuffmanTree* root, char c, HuffmanTree** Node) {
    // 如果当前节点为叶子节点
    if(root->left == NULL && root->right == NULL){
        // 如果该节点对应的字符是c，则找到了目标节点
        if(root->c == c){
            *Node = root;
            return;
        }   
        // 否则继续搜索
        else    return;
    }   
    // 如果当前节点不是叶子节点，则继续递归搜索左右子树
    search(root->left, c, Node);    search(root->right, c, Node);
}

// 对文本进行哈夫曼编码
void encodeText(char *text, HuffmanTree *root, char **encodedText, int *encodedTextLength) {
    int i = 0;
    int j = 0;
    // 为编码后的文本分配内存空间
    *encodedText = (char *)malloc(MAX_TEXT_LENGTH * sizeof(char));

    // 遍历输入的文本
    while (text[i] != '\0') {
        char *code = NULL;
        // 查找当前字符在哈夫曼树中的节点，并获取其哈夫曼编码
        ListNode* Node = NULL;
        search(root,text[i],&Node);
        code = Node->code;
        
        if (code != NULL) {
            // 将该字符的哈夫曼编码加入到编码后的文本中
            strcat(*encodedText, code);
            j += strlen(code);
        }
        i++;
    }
    // 记录编码后的文本长度
    *encodedTextLength = j;
}

// 对哈夫曼编码进行解码
void decodeText(char *encodedText, HuffmanTree *root, char **decodedText) {
    int i = 0;
    int j = 0;
    // 为解码后的文本分配内存空间
    *decodedText = (char *)malloc(MAX_TEXT_LENGTH * sizeof(char));
    // 从根节点开始遍历哈夫曼树
    HuffmanTree *currentNode = root;
    while (encodedText[i] != '\0') {
        // 如果当前编码为0，则继续遍历左子树
        if (encodedText[i] == '0') {
            currentNode = (HuffmanTree *)currentNode->left;
        } else if (encodedText[i] == '1') {
            // 如果当前编码为1，则继续遍历右子树
            currentNode = (HuffmanTree *)currentNode->right;
        }
    
        // 如果遍历到了叶子节点，则将该节点对应的字符加入到解码后的文本中
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

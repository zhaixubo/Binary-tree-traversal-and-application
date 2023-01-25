#include <stdio.h>
#include <stdlib.h>
 
//二叉树结构体的建立包括：数据域、左孩子指针、右孩子指针
typedef struct BiTNode {
    char data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode, * BiNodeTree;
 
//先序建立二叉树
BiNodeTree CreateBiTree() {
    char ch;
    scanf("%c", &ch);
    BiNodeTree root;
    if (ch == '#') {
        root = NULL;
    } else {
        root = (BiNodeTree)malloc(sizeof(BiTNode));
        root->data = ch;
        root->lchild = CreateBiTree();
        root->rchild = CreateBiTree();
    }
    return root;//返回根节点
}
 
//先序遍历二叉树
void  PreOrderTraverse(BiNodeTree root) {
    if (root) {
        printf("%c",root->data);
        PreOrderTraverse(root->lchild);
        PreOrderTraverse(root->rchild);
    }
}
 
//中序遍历
void InOrderTraverse(BiNodeTree root) {
    if (root) {
        InOrderTraverse(root->lchild);
        printf("%c",root->data);
        InOrderTraverse(root->rchild);
    }
}

//后序遍历
void PostOrderTraverse(BiNodeTree root) {
    if (root) {
        PostOrderTraverse(root->lchild);
        PostOrderTraverse(root->rchild);
        printf("%c",root->data);
    }
}

//按树状打印二叉树
void PrintTree(BiNodeTree root, int t) {
    if (root == NULL) {
        return;
    }
    PrintTree(root->rchild, t + 1);
    for (int i = 0; i < t; i++) {
        printf(" ");
    }
    printf("%c\n", root->data);
    PrintTree(root->lchild, t + 1);
}

//分治法统计叶子节点数目
int LeafCount(BiNodeTree root)
{
    int count;
    if (root == NULL) {
        count = 0;
    } else if (root->lchild == NULL && root->rchild == NULL) {
        count = 1;
    } else {
        count = LeafCount(root->lchild) + LeafCount(root->rchild);
    }
    return count;
}

int main() {
    printf("输入一个二叉树:\n");
    BiNodeTree root;
    root = CreateBiTree();//建立
    printf("先序遍历:");
    PreOrderTraverse(root);
    printf("\n");
    printf("中序遍历:");
    InOrderTraverse(root);//输出
    printf("\n");
    printf("后序遍历:");
    PostOrderTraverse(root);
    printf("\n");
    printf("按树状输出二叉树：\n");
    PrintTree(root, 0);
    printf("叶子结点个数：\n");
    printf("%d",LeafCount(root));
}


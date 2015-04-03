#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 100

struct Node
{
        char item[MAX_LEN];
        int count;
        int string_lenth;
        struct Node *pLeft;
        struct Node *pRight;
};

struct LinkedList
{
        struct LinkedList *pnext;
        int string_lenth;
        char string[MAX_LEN];
};

struct Node *createnode (char string[MAX_LEN], int string_lenth);
struct Node *addnode (char string[], struct Node *pNode, int string_lenth);
void freenodes (struct Node *pNode);
void listnodes (struct Node *pNode);
static struct LinkedList *first = NULL;
void freelinked (struct LinkedList *first);

int main (void)
{
        int tmpstring_lenth;
        struct Node *pRoot = NULL;
        bool needfree = false;
        printf ("Type some sentences:\n");

        while (true)
        {
                tmpstring_lenth = 0;
                char tmpstring[MAX_LEN] = {0};
                fgets (tmpstring, MAX_LEN, stdin);
                if (tmpstring[0] == '\n')
                        break;
                tmpstring_lenth = static_cast<int>(strlen (tmpstring));
                if (pRoot == NULL) {
                        pRoot = createnode (tmpstring, tmpstring_lenth);
                } else {
                        if (addnode (tmpstring, pRoot, tmpstring_lenth) == NULL)
                        {
                                needfree = true;
                                static struct LinkedList *current = NULL;
                                static struct LinkedList *previous = NULL;
                                current = reinterpret_cast<LinkedList *>(malloc (sizeof (LinkedList)));
                                if (first == NULL)
                                        first = current;
                                if (previous != NULL)
                                        previous->pnext = current;
                                current->string_lenth = tmpstring_lenth;
                                for (int i = 0; i < tmpstring_lenth; ++i) {
                                        current->string[i] = tmpstring[i];
                                }
                                current->pnext = NULL;
                                previous = current;
                        }
                }
                fflush (stdin);
        }
        printf ("All the sentences are:\n");
        listnodes (pRoot);
        freenodes (pRoot);
        if (needfree)
                freelinked (first);
        return 0;
}

struct Node *createnode (char string[MAX_LEN], int string_lenth)
{
        struct Node *pNode = reinterpret_cast<Node *>(malloc (sizeof (struct Node)));
        if (pNode == NULL) {
                printf ("malloc faild\n");
                exit (1);
        }
        for (int i = 0; i < static_cast<int>(strlen (string)); ++i) {
                pNode->item[i] = string[i];
        }
        pNode->count = 1;
        pNode->pLeft = pNode->pRight = NULL;
        pNode->string_lenth = string_lenth;
        return pNode;
}

struct Node *addnode (char string[], struct Node *pNode, int string_lenth)
{
        if (pNode == NULL)
                return createnode (string, string_lenth);
        if (string_lenth == pNode->string_lenth) {
                ++pNode->count;
                return NULL;
        }
        if (string_lenth < pNode->string_lenth) {
                if (pNode->pLeft == NULL) {
                        pNode->pLeft = createnode (string, string_lenth);
                        return pNode->pLeft;
                } else {
                        return addnode (string, pNode->pLeft, string_lenth);
                }
        } else {
                if (pNode->pRight == NULL) {
                        pNode->pRight = createnode (string, string_lenth);
                        return pNode->pRight;
                } else {
                        return addnode (string, pNode->pRight, string_lenth);
                }
        }
}

void listnodes (struct Node *pNode)
{
        if (pNode->pLeft != NULL)
                listnodes (pNode->pLeft);
        if (pNode->count != 1) {
                struct LinkedList *tmp = NULL;
                tmp = first;
                while (tmp != NULL) {
                        if (tmp->string_lenth == pNode->string_lenth)
                                printf ("%s", tmp->string);
                        tmp = tmp->pnext;
                }
        }
        printf ("%s", pNode->item);
        if (pNode->pRight != NULL)
                listnodes (pNode->pRight);
}

void freenodes (struct Node *pNode)
{
        if (pNode == NULL)
                return;
        if (pNode->pLeft != NULL)
                freenodes (pNode->pLeft);
        if (pNode->pRight != NULL)
                freenodes (pNode->pRight);
        free (pNode);
}

void freelinked (struct LinkedList *current)
{
        struct LinkedList *previous = NULL;
        while (current == NULL){
                previous = current;
                current = current->pnext;
                free (previous);
        }
}

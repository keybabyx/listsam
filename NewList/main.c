/** Practice by Samuel Toh Good luck! **/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
} Node;

Node *addItem(Node *list, int number);
Node *removeItem(Node *list, int pos);
Node *insertItem(Node *list, int pos, int number);
Node *changeValue(Node *list, int pos, int number);
Node *sort(Node *list);
Node *reverseSort(Node *list);
int getLength(Node *list);
void displayList(Node *list);
void swap(Node *node1, Node *node2);
Node *fileRead(char *fileName);

Node *addItem(Node *list, int number){

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = number;
    newNode->next = NULL;

    if (list == NULL){
        list = newNode;
    } else {
        Node *tempNode = list;
        while (tempNode->next != NULL){
            tempNode = tempNode->next;
        }

        tempNode->next = newNode;
    }
    return list;
}

int getLength(Node *list){
    int count = 0;

    if (list == NULL){
        return 0;
    } else {
        Node *tempNode = list;
        while (tempNode != NULL){
            tempNode = tempNode->next;
            count += 1;
        }
    }
    return count;
}

Node *removeItem(Node *list, int pos){
    if (list == NULL){
        printf("Nothing to delete");
    } else if (pos == 0){
        Node *tempNode = list;
        list = list->next;

        tempNode->number = NULL;
        free(tempNode);

        return list;

    } else {
        if (pos < getLength(list)){
            Node *tempNode = list;

            for (int i = 0; i < pos - 1; i++) {
                tempNode = tempNode->next;
            }

            Node *deleteNode = tempNode->next;
            deleteNode->number = NULL;

            if (deleteNode->next == NULL){
                tempNode->next = NULL;
            } else {
                tempNode->next = deleteNode->next;
            }
        } else {
            printf("The number is too far.");
        }


        return list;
    }
}

void displayList(Node *head){
    printf("Current List Items\n");
    if (head == NULL){
        printf("The list is empty.");
    } else {
        Node *tempNode = head;
        while (tempNode != NULL){
            printf("%d\n", tempNode->number);
            tempNode = tempNode->next;
        }
    }
    printf("\n");
}

Node *insertItem(Node *list, int pos, int number){

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = number;
    newNode->next = NULL;

    if (list == NULL){
        list = newNode;
    } else {
        if (pos < getLength(list)){

            Node *tempNode = list;
            for (int i = 0; i < pos - 1; i++) {
                tempNode = tempNode->next;
            }

            newNode->next = tempNode->next;
            tempNode->next = newNode;
        } else {
            printf("Position out of range");
        }
    }

    return list;
}

Node *changeValue(Node *list, int pos, int number){
    if (list == NULL){
        printf("The list is not being instantiated");
    } else {
        if (pos < getLength(list)){

            Node *tempNode = list;
            for (int i = 0; i < pos; i++) {
                tempNode = tempNode->next;
            }
            tempNode->number = number;

            return list;
        } else {
            printf("Position out of range");
        }
    }
}

Node *sort(Node *list){
    if (list == NULL){
        printf("This is an empty list");
    } else {
        for (int i = 0; i < getLength(list); i++) {
            Node *temp = list;
            for (int j = 0; j < getLength(list); j++) {
                if (temp->next != NULL){
                    if (temp->number > temp->next->number){
                        swap(temp, temp->next);
                    }
                    temp = temp->next;
                }
            }
        }
    }

    return list;
}

Node *reverseSort(Node *list){
    if (list == NULL){
        printf("This is an empty list");
    } else {
        for (int i = 0; i < getLength(list); i++) {
            Node *temp = list;
            for (int j = 0; j < getLength(list); j++) {
                if (temp->next != NULL){
                    if (temp->number < temp->next->number){
                        swap(temp, temp->next);
                    }
                    temp = temp->next;
                }
            }
        }
    }

    return list;
}

void swap(Node *node1, Node *node2){
    int number = node1->number;
    node1->number = node2->number;
    node2->number = number;
}

Node *fileRead(char *fileName){
    Node *newList = NULL;
    FILE *file = fopen(fileName, "r");

    if (file == NULL){
        printf("Can't read the file\n");
    } else {
        while (!feof(file)){
            int number;
            fscanf(file, "%d", &number);
            newList = addItem(newList, number);
        }
    }

    return newList;
}


int main() {
    printf("****WELCOME TO THE LINKED LIST!****\n\n");
    Node *head = NULL;

    printf("1) Showing an empty list\n");
    displayList(head);

    head = addItem(head, 2);
    head = addItem(head, 3);
    head = addItem(head, 1);
    head = addItem(head, 2);
    head = addItem(head, 8);
    head = addItem(head, 7);
    head = addItem(head, 5);

    printf("\n2) Showing list with 7 items (2, 3, 1, 2, 8, 7, 5)\n");
    displayList(head);

    printf("\n3) Length of the list should be 7\n");
    printf("Length of the list: %d\n", getLength(head));

    printf("\n4) Removing the positon 6 of array\n");
    head = removeItem(head, 6);

    printf("\n5) Showing 6 digits (2, 3, 1, 2, 8, 7)\n");
    displayList(head);

    printf("\n6) Length of the list should be 6\n");
    printf("Length of the list: %d\n", getLength(head));

    printf("\n7) Removing the positon 0 of array\n");
    head = removeItem(head, 0);

    printf("\n8) Showing 5 digits (3, 1, 2, 8, 7)\n");
    displayList(head);

    printf("\n9) Length of the list should be 5\n");
    printf("Length of the list: %d\n", getLength(head));

    printf("\n10) Inserting into position 3 of value 10 (3, 1, 2, 10, 8, 7)\n");
    head = insertItem(head, 3, 10);
    displayList(head);

    printf("\n11) Changing value of 3 of position 0 to 12\n");
    head = changeValue(head, 0, 12);
    displayList(head);

    printf("\n12) Changing value of 2 of position 2 to 55\n");
    head = changeValue(head, 2, 55);
    displayList(head);

    printf("\n13) Sorted List (1, 7, 8, 10, 12, 55)\n");
    head = sort(head);
    displayList(head);

    printf("\n14) Reverse Sorted List (55, 12, 10, 8, 7, 1)\n");
    head = reverseSort(head);
    displayList(head);

    printf("\n15) File Read (20, 30, 40, 5, 10, 80, 20, 50)\n");
    Node *newList = NULL;
    newList = fileRead("numbers.txt");
    displayList(newList);

    printf("\n16) Sorted File Read (5, 10, 20, 20, 30, 40, 50, 80)\n");
    newList = sort(newList);
    displayList(newList);

    return 0;
}
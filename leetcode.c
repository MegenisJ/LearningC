#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* create(char data){
    struct Node *newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = create(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFromFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

bool containsChar(struct Node* head, char c){
    if (head == NULL){
        return 0;
    }
    if(head -> data == c){
        return true;
    }
    struct Node* temp = head;
    while(temp != NULL){
        if(temp->data == c){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int length(struct Node* head){
    struct Node* temp = head;
    int res =0;
    while(temp != NULL){
        ++res;
        temp = temp->next;
    }
    return res;
}

int lengthOfLongestSubstring(char* s){
    struct Node* head = NULL;
    int res = 0;
    int currentLength =0;
    for(int r = 0; r < strlen(s);++r){
        while (containsChar(head,s[r])){  
           deleteFromFirst(&head);
            --currentLength;
        }
        insertAtEnd(&head,s[r]);//Can only add right when ll does not contain
        ++currentLength;
        if (currentLength > res){
           res = currentLength; 
        }
    }
    return res;
}


int main(){
    int c;
    
    char* input;
    char a = 'a';
    int asciiValue = (int)a;
    while( (c=getchar()) != asciiValue) {
        input += c;
    }
    printf("%d", legthOfLongestSubstring(input));
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int a;
    scanf("%d", &a);

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* current = NULL;

    for (int i = 0; i < a; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            current->next = temp;
        }
        current = temp;
    }

    int position;
    scanf("%d", &position);

    if (position < 1 || position > a) {
        printf("Invalid position\n");
        return 0;
    }

    if (position == 1) {
        temp = head;
        head = head->next;
        free(temp);
    } else {
        current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

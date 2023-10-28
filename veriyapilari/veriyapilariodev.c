#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

void insertNode(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    struct Node *head = NULL;
    int value;

    printf("Çıkış için -1 tuşlayınız.\tListeye eklenicek elemanları girin:\n");

    while (1) {
        scanf("%d", &value);
        if (value == -1)
            break;
        insertNode(&head, value);
    }

    struct Node *current = head;
    printf("Liste:");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("Listenin sonu\n");

    // Belleği temizle
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

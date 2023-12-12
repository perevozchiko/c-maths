/*
 * Order before even and then odd nubmer in list from file stream
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *next;
  int data;
} Node;

void print_list(const Node *top) {
  const Node *it = NULL;
  if (NULL == top)
    return;

  for (it = top; it != NULL; it = it->next) {
    printf("%d ", it->data);
  }
  printf("\n");
}

Node *reverse_list(Node *top);

Node *read_list(FILE *input) {
  int n;
  Node *el = NULL, *ol = NULL, *result = NULL, *tail = NULL;

  while (fscanf(input, "%d", &n) == 1) {
    Node *node = calloc(1, sizeof(Node));
    node->data = n;

    if ((n & 0x1) == 0) {
      /* printf("evenNumber: %d", node->data); */
      if (tail == NULL) {
        tail = node;
      }
      node->next = el;
      el = node;
    } else {
      node->next = ol;
      ol = node;
    }
  }
  if (ol == NULL)
    return el;
  if (el == NULL)
    return ol;

  tail->next = ol;
  return el;
}

void delete_list(Node *top) {
    while (top != NULL)
    {
        Node* tmp = top;
        top = tmp->next;
        free(tmp);
    }
}

Node* reverse_list(Node *top) {
  Node *cur, *next = NULL, *prev = NULL;

  if (top == NULL)
    return NULL;
  if (top->next == NULL)
    return top;

  for (cur = top; cur != NULL;) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

int main() {
  Node *top, *result;
  FILE *f = fopen("input.txt", "r");
  if (!f) {
    perror("Failed to open file");
    abort();
  }

  top = read_list(f);

  print_list(top);

  result = reverse_list(top);

  print_list(result);

  delete_list(top);

  fclose(f);
  return 0;
}

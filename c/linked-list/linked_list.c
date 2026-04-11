#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct list_node {
  struct list_node *prev, *next;
  ll_data_t data;
};

struct list {
  struct list_node *first, *last;
};

struct list *list_create(void) { return calloc(1, sizeof(struct list)); }

size_t list_count(const struct list *list) {
  size_t count = 0;

  struct list_node *current = list->first;
  while (current != NULL) {
    current = current->next;
    count++;
  }

  return count;
}

void list_push(struct list *list, ll_data_t item_data) {
  struct list_node *new_node = calloc(1, sizeof(struct list_node));
  new_node->data = item_data;

  if (list->last == NULL) {
    list->first = new_node;
    list->last = new_node;
    return;
  }

  new_node->prev = list->last;
  list->last->next = new_node;
  list->last = new_node;
}

ll_data_t list_pop(struct list *list) {
  struct list_node *last_node = list->last;
  struct list_node *before_last_node = last_node->prev;

  list->last = before_last_node;

  if (before_last_node == NULL) {
    list->first = NULL;
  } else {
    before_last_node->next = NULL;
  }

  ll_data_t data = last_node->data;

  free(last_node);

  return data;
}

void list_unshift(struct list *list, ll_data_t item_data) {
  struct list_node *new_node = calloc(1, sizeof(struct list_node));
  new_node->data = item_data;

  if (list->first == NULL) {
    list->first = new_node;
    list->last = new_node;
    return;
  }

  new_node->next = list->first;
  list->first->prev = new_node;
  list->first = new_node;
}

ll_data_t list_shift(struct list *list) {
  struct list_node *first_node = list->first;
  struct list_node *second_node = first_node->next;

  list->first = second_node;

  if (second_node == NULL) {
    list->last = NULL;
  } else {
    second_node->prev = NULL;
  }

  ll_data_t data = first_node->data;

  free(first_node);

  return data;
}

void list_delete(struct list *list, ll_data_t data) {
  struct list_node *current = list->first;

  while (current != NULL) {
    if (current->data == data) {
      struct list_node *prev = current->prev;
      struct list_node *next = current->next;

      if (prev != NULL) {
        prev->next = current->next;
      }

      if (next != NULL) {
        next->prev = current->prev;
      }

      if (list->first == current) {
        list->first = current->next;
      }

      if (list->last == current) {
        list->last = current->prev;
      }
      return;
    }

    current = current->next;
  }
}

void list_destroy(struct list *list) {
  while (list->first != NULL) {
    struct list_node *head = list->first;
    list->first = head->next;
    free(head);
  }

  free(list);
}

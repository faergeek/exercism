#include "list_ops.h"
#include <string.h>

list_t *new_list(size_t length, list_element_t elements[]) {
  list_t *result = malloc(sizeof(list_t) + length * sizeof(list_element_t));

  *result = (list_t){.length = length};

  if (length != 0) {
    memcpy(result->elements, elements, length * sizeof(list_element_t));
  }

  return result;
}

list_t *append_list(list_t *list1, list_t *list2) {
  list_element_t *elements =
      malloc((list1->length + list2->length) * sizeof(list_element_t));

  memcpy(elements, list1->elements, list1->length * sizeof(list_element_t));
  memcpy(elements + list1->length, list2->elements,
         list2->length * sizeof(list_element_t));

  list_t *result = new_list(list1->length + list2->length, elements);
  free(elements);

  return result;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
  list_element_t *elements = malloc((list->length) * sizeof(list_element_t));
  size_t length = 0;

  for (size_t i = 0; i < list->length; i++) {
    if (filter(list->elements[i])) {
      elements[length] = list->elements[i];
      length++;
    }
  }

  list_t *result = new_list(length, elements);
  free(elements);

  return result;
}

size_t length_list(list_t *list) { return list->length; }

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
  list_t *result = new_list(list->length, list->elements);

  for (size_t i = 0; i < list->length; i++) {
    result->elements[i] = map(list->elements[i]);
  }

  return result;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
  list_element_t result = initial;

  for (size_t i = 0; i < list->length; i++) {
    result = foldl(result, list->elements[i]);
  }

  return result;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
  list_element_t result = initial;

  size_t last_index = list->length - 1;
  for (size_t i = 0; i < list->length; i++) {
    result = foldr(list->elements[last_index - i], result);
  }

  return result;
}

list_t *reverse_list(list_t *list) {
  list_t *result = new_list(list->length, list->elements);
  size_t last_index = list->length - 1;
  for (size_t i = 0; i < list->length; i++) {
    result->elements[i] = list->elements[last_index - i];
  }

  return result;
}

void delete_list(list_t *list) { free(list); }

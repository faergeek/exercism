#include "circular_buffer.h"
#include <errno.h>
#include <stdlib.h>

struct circular_buffer {
  size_t capacity;
  size_t count;
  size_t start_index;
  buffer_value_t values[];
};

circular_buffer_t *new_circular_buffer(size_t capacity) {
  circular_buffer_t *result =
      malloc(sizeof(circular_buffer_t) + sizeof(buffer_value_t) * capacity);

  *result = (circular_buffer_t){
      .capacity = capacity,
  };

  return result;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
  if (buffer->count >= buffer->capacity) {
    errno = ENOBUFS;
    return EXIT_FAILURE;
  }

  size_t index = (buffer->start_index + buffer->count) % buffer->capacity;
  buffer_value_t *new_item = buffer->values + index;
  buffer->count++;

  *new_item = value;

  return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t value[static 1]) {
  if (buffer->count == 0) {
    errno = ENODATA;
    return EXIT_FAILURE;
  }

  value[0] = *(buffer->values + buffer->start_index);
  buffer->count--;
  buffer->start_index = (buffer->start_index + 1) % buffer->capacity;

  return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
  if (buffer->count >= buffer->capacity) {
    buffer_value_t v;
    read(buffer, &v);
  }

  return write(buffer, value);
}

void delete_buffer(circular_buffer_t *buffer) { free(buffer); }
void clear_buffer(circular_buffer_t *buffer) { buffer->count = 0; }

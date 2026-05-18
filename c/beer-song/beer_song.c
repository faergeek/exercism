#include "beer_song.h"
#include <stdio.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
  for (uint8_t i = 0; i < take_down; i++) {
    uint8_t bottles = start_bottles - i;
    int start_index = i * 3;

    if (bottles == 0) {
      snprintf(song[start_index], 1024,
               "No more bottles of beer on the wall, no more bottles of beer.");
      snprintf(
          song[start_index + 1], 1024,
          "Go to the store and buy some more, 99 bottles of beer on the wall.");
    } else if (bottles == 1) {
      snprintf(song[start_index], 1024,
               "1 bottle of beer on the wall, 1 bottle of beer.");
      snprintf(song[start_index + 1], 1024,
               "Take it down and pass it around, no more bottles of beer on "
               "the wall.");
    } else if (bottles == 2) {
      snprintf(song[start_index], 1024,
               "%d bottles of beer on the wall, %d bottles of beer.", bottles,
               bottles);
      snprintf(
          song[start_index + 1], 1024,
          "Take one down and pass it around, 1 bottle of beer on the wall.");
    } else {
      snprintf(song[start_index], 1024,
               "%d bottles of beer on the wall, %d bottles of beer.", bottles,
               bottles);
      snprintf(
          song[start_index + 1], 1024,
          "Take one down and pass it around, %d bottles of beer on the wall.",
          bottles - 1);
    }
  }
}

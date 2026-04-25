#include "dnd_character.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int ability(void) {
  int rolls[4] = {0};
  for (size_t i = 0; i < 4; i++) {
    rolls[i] = (double)rand() / (double)RAND_MAX * 5.0 + 1.0;
  }

  size_t min_index = 0;
  for (size_t i = 0; i < 4; i++) {
    if (rolls[i] < rolls[min_index]) {
      min_index = i;
    }
  }

  int score = 0;
  for (size_t i = 0; i < 4; i++) {
    if (i != min_index) {
      score += rolls[i];
    }
  }

  printf("score: %d\n", score);

  return score;
}

int modifier(int score) { return floor(((double)score - 10) / 2); }

dnd_character_t make_dnd_character(void) {
  dnd_character_t character = {0};
  character.strength = ability();
  character.dexterity = ability();
  character.constitution = ability();
  character.intelligence = ability();
  character.wisdom = ability();
  character.charisma = ability();
  character.hitpoints = 10 + modifier(character.constitution);

  return character;
}

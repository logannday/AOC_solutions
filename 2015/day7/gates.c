#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int signal;
} Wire_t;

typedef struct {
  Wire_t **wires;
  int index;
} Circuit_t;

#define CIRCUIT_SIZE 1000

void circuit_init(Circuit_t *circuit);
bool circuit_contains(Circuit_t *circuit, char *name);
void circuit_add(Circuit_t *circuit, char *name, int signal);
void circuit_set(Circuit_t *circuit, char *name, int signal);
int circuit_get(Circuit_t *circuit, char *name);

int main(int argc, char *argv[]) {
  Circuit_t circuit;
  circuit_init(&circuit);
  circuit_add(&circuit, "ab", 210);
  circuit_add(&circuit, "cd", 210);
  circuit_add(&circuit, "ef", 210);
  circuit_set(&circuit, "ef", 420);
  circuit_set(&circuit, "ef", 420);
  printf("%d\n", circuit_get(&circuit, "ef"));
  printf("%d\n", circuit_contains(&circuit, "ab"));
  printf("%d\n", circuit_contains(&circuit, "cd"));
  printf("%d\n", circuit_contains(&circuit, ""));
  return 0;
}

void circuit_init(Circuit_t *circuit) {
  circuit->wires = (Wire_t **)calloc(CIRCUIT_SIZE, sizeof(Wire_t *));
  circuit->index = 0;
}

bool circuit_contains(Circuit_t *circuit, char *name) {
  for (int i = 0; i < circuit->index; i++) {
    if (strcmp(circuit->wires[i]->name, name) == 0) {
      return true;
    }
  }

  return false;
}

void circuit_add(Circuit_t *circuit, char *name, int signal) {
  Wire_t *wire = malloc(sizeof(Wire_t *));
  wire->name = strdup(name);
  wire->signal = signal;
  circuit->wires[circuit->index++] = wire;
}

void circuit_set(Circuit_t *circuit, char *name, int signal) {
  if (!circuit_contains(circuit, name)) {
    circuit_add(circuit, name, signal);
    return;
  }

  for (int i = 0; i < circuit->index; i++) {
    if (strcmp(circuit->wires[i]->name, name) == 0) {
      circuit->wires[i]->signal = signal;
      return;
    }
  }
}

int circuit_get(Circuit_t *circuit, char *name) {
  if (!circuit_contains(circuit, name)) {
    printf("get failed\n");
    exit(2);
  }
  for (int i = 0; i < circuit->index; i++) {
    if (strcmp(circuit->wires[i]->name, name) == 0) {
      return circuit->wires[i]->signal;
    }
  }
  return -1;
}

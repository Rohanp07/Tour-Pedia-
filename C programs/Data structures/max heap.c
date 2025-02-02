#include <stdio.h>

#include <stdlib.h>

struct HEAP {
  int * items, size, capacity;
}* heap;

void swap(int * a, int * b) {
  int temp = * b;
  * b = * a;
  * a = temp;
}

void init(struct HEAP ** heap) {
  * heap = (struct HEAP * ) malloc(sizeof(struct HEAP));
  ( * heap) -> capacity = 2;
  ( * heap) -> size = 0;
  ( * heap) -> items = (int * ) malloc(sizeof(int) * ( * heap) -> capacity + 1);
}

void allocate(struct HEAP ** heap) {
  ( * heap) -> capacity *= 2;
  ( * heap) -> items = (int * ) realloc(( * heap) -> items, sizeof(int) * ( * heap) -> capacity + 1);
}

void heapify_up(struct HEAP ** heap, int size) {
  if (size > 1) {
    if (( * heap) -> items[size / 2] < ( * heap) -> items[size]) {
      swap( & ( * heap) -> items[size / 2], & ( * heap) -> items[size]);
      heapify_up(heap, size / 2);
    }
  }
}

void insert(struct HEAP ** heap, int val) {
  if (( * heap) -> size == ( * heap) -> capacity) {
    allocate(heap);
  }
  ( * heap) -> items[++( * heap) -> size] = val;
  heapify_up(heap, ( * heap) -> size);
}

int child(struct HEAP * heap, int index) {
  int left = index * 2;
  int right = index * 2 + 1;

  if (right > heap -> size) {
    return left;
  } else if (heap -> items[left] >= heap -> items[right]) {
    return left;
  }
  return right;
}

void heapify_down(struct HEAP ** heap, int index) {
  int childindex = child( * heap, index);
  if (index * 2 <= ( * heap) -> size) {
    if (( * heap) -> items[index] < ( * heap) -> items[childindex]) {
      swap( & ( * heap) -> items[index], & ( * heap) -> items[childindex]);
      heapify_down(heap, childindex);
    }
  }
}

void removemax(struct HEAP ** heap) {
  swap( & ( * heap) -> items[1], & ( * heap) -> items[( * heap) -> size--]);
  heapify_down(heap, 1);
}

void print(struct HEAP * heap) {
  for (int i = 1; i <= heap -> size; i++) {
    printf("%i ", heap -> items[i]);
  }
  printf("\n");
}

void deallocate(struct HEAP ** heap) {
  free(( * heap) -> items);
  free( * heap);
}

int main(void) {
  init( & heap);

  insert( & heap, 4);
  insert( & heap, 10);
  insert( & heap, 2);
  insert( & heap, 22);
  insert( & heap, 45);
  insert( & heap, 18);

  // Before removemax
  print(heap);

  removemax( & heap);

  // After removemax
  print(heap);
  /*
  	(before removemax)Output: 45 22 18 4 10 2
  	(after removemax)Output: 22 10 18 4 2
  */

  deallocate( & heap);

  return 0;
}
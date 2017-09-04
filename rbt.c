#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rbt.h"
#include "mylib.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

typedef enum { RED, BLACK } rbt_colour;

struct rbt_node {
  char *key;
  rbt_colour colour;
  rbt left;
  rbt right;
};

rbt rbt_new() {
  return NULL;
  /*rbt r = malloc(sizeof *r);
    return r;*/
}

int rbt_search(rbt r, char *str) {
  int result;
  printf("Search called\n");
  printf("key size is %d\n", sizeof(r->key));
  if (r->key == NULL) {
    printf("R is null\n");
    return 0;
  }
  
  printf("Searching for: %s\n", str);
  result = strcmp(r->key, str);

  if (result > 0) {
    rbt_search(r->left, str);
  } else if (result < 0) {
    rbt_search(r->right, str);
  }
  return 1;
}

rbt rbt_insert(rbt r, char *str) {
  int result;
  if (r == NULL) {
    r = emalloc(sizeof *r);
    printf("new() done\n");
    r->key = emalloc((strlen(str) + 1) * sizeof(char));
    printf("Key malloc done\n");
    strcpy(r->key, str);
    printf("Copy done\n");
    return r;
    
  } else {
    result = strcmp(str, r->key);
    if (result < 0) {
      r->left = rbt_insert(r->left, str);
    } else if (result > 0) {
      r->right = rbt_insert(r->right, str);
    } 
  }
  return r;
}

int main(void) {
  rbt tree = rbt_new();
  char *temp = NULL;
  if (tree == NULL) {
    printf("Tree is null\n");
  }
  printf("Tree made\n");
  tree = rbt_insert(tree, "hi\0");
  printf("Insert done\n");
  printf("%d\n", rbt_search(tree, "hii\0"));
  return EXIT_SUCCESS;
}
  

  

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
  /*printf("key size is %d\n", sizeof(r->key));*/
  if (r == NULL) {
    /*printf("R is null\n");*/
    return 0;
  } else {
  
    printf("Searching for: %s\n", str);
    result = strcmp(r->key, str);

    if (result == 0) {
      printf("%s found!\n", str);
      return 1;
    } else if (result > 0) {
      return rbt_search(r->left, str);
    } else  {
      return rbt_search(r->right, str);
    }
  }
}

rbt rbt_insert(rbt r, char *str) {
  int result;
  if (r == NULL) {
    r = emalloc(sizeof *r);
    printf("R malloc\n");
    r->key = emalloc((strlen(str) + 1) * sizeof(char));
    r->left = NULL;
    r->right = NULL;
    printf("Key malloc done\n");
    strcpy(r->key, str);
    printf("Copy done\n");
    /*return r;*/
    
  } else {
    result = strcmp(str, r->key);
    printf("R->key is %s. Result of compare is %d\n", r->key, result);
    if (result < 0) {
      printf("Call insert on left\n");
      r->left = rbt_insert(r->left, str);
      
    } else if (result > 0) {
      printf("Call insert on right\n");
      r->right = rbt_insert(r->right, str);
      
    } 
  }
  printf("Insert done\n");
  return r;
}

int main(void) {
  rbt tree = rbt_new();

  tree = rbt_insert(tree, "hi\0");
  tree = rbt_insert(tree, "bee\0");
  tree = rbt_insert(tree, "hello\0");
  tree = rbt_insert(tree, "world\0");
  tree = rbt_insert(tree, "test\0");
  tree = rbt_insert(tree, "code\0");
  tree = rbt_insert(tree, "c\0");
  printf("%d\n", rbt_search(tree, "worlddd\0"));
  return EXIT_SUCCESS;
}
  

  

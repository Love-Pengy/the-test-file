#include <stdarg.h>
#include <locale.h>
#include <execinfo.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uchar.h>
#include <unistd.h>
#define LOG(s, data...) argFunc("%s (%d): %s", __FILE__, __LINE__, s, ##data)   
void argFunc(char *formatString, ...) {
  va_list list;
  int d;
  char c;
  /*char *s;*/
  /*long l;*/
  /*long long ll;*/
  /*float f; */
  va_start(list, formatString);
  char test;
  char buff[8192];
  vsnprintf(buff, 8192, formatString, list);
  /*printf("WRITTEN: %d\n",d); */
  printf("%s\n", buff);
  /*printf("%p\n", __builtin_return_address(0));*/
  va_end(list);
}
char *extractUnicode(const char *input) {
  char *buff = malloc(sizeof(char) * (strlen(input) + 1));
  buff[0] = '\0';
  char *test = malloc(sizeof(char) * (strlen(input) + 2));
  test[0] = '\0';
  strncpy(test, input, strlen(input) + 1);
  char32_t specChar;
  mbstate_t mbs;
  char *locale = setlocale(LC_ALL, "");

  if (!locale) {
    free(buff);
    return (NULL);
  }
  memset(&mbs, 0, sizeof(mbs));

  size_t size = mbrtoc32(&specChar, test, 16, &mbs);
  if (size == (size_t)-1 || size == (size_t)-2) {
    return (NULL);
  }
  int cpy = c32rtomb(buff, specChar, &mbs);
  if (cpy < 0) {
    return (NULL);
  }
  free(test);
  return (buff);
}

void test(char **input) {
  free(*input);
  *input = malloc(sizeof(char) * (strlen("test") + 1));
  strcpy(*input, "test");
}

void *aFunc(void *a) {
  int *aVal = (int *)a;
  while (1) {
    (*aVal)++;
    printf("A: %d\n", *aVal);
    sleep(1);
  }
  return (NULL);
}

void *bFunc(int *b) {
  while (1) {
    (*b)++;
    printf("B: %d\n", *b);
    sleep(1);
  }
  return (NULL);
}

#define MAP(name) (SPEC_##name)
#define SPEC_TEST 0x1
#define MAPPING (MAP(TEST))

union test {
  char *string;
  int intyWinty;
};

int main(void) {
  /*int a = 10;*/
  /*int b = 11;*/
  /*printf("a: %d, b: %d\n", a, b);*/
  /*a = a ^ b;*/
  /*b = a ^ b;*/
  /*a = a ^ b;*/
  /*printf("a: %d, b: %d\n", a, b);*/
  /*int a = 20000;*/
  /*int b = 9999;*/
  /*printf("OG: %d\n", a / b);*/
  /*printf("FLOOR: %d\n", (a / b + (a % b != 0 && (a ^ b) < 0)));*/
  /*bool t = false;*/
  // 0 |= 1 == 1
  // 1 |= 1 == 1

  // double u spec
  /*char *test = "󱨸";*/
  // single u spec
  /*char *test = "";*/
  // non U spec
  /*
  char* test = "@";
printf("ORIGINAL: %s\n", test);
  char* buff = malloc(sizeof(char) * (strlen(test) + 1));
      buff[0] = '\0';
char32_t specChar;

mbstate_t mbs;
setlocale(LC_ALL, "");
memset(&mbs, 0, sizeof(mbs));
size_t size = mbrtoc32(&specChar, test, 16, &mbs);
printf("SIZE: %ld\n", size);
c32rtomb(buff, specChar, &mbs);

printf("%s\n", buff);
  */
  /*const char* test = "󰆍";*/
  /*printf("%s\n", extractUnicode(test));*/
  /*printf("%ld\n", sizeof(char32_t));*/
  /*char* testString = malloc(sizeof(char) * 100);*/
  /*testString[0] = '\0';*/
  /*strcpy(testString, "original");*/
  /*printf("INPUT: %s\n", testString);*/
  /*test(&testString);*/
  /*printf("OUTPUT: %s\n", testString);*/

  /*char* something = malloc(sizeof(char) * 5);*/
  /*printf("INIT: %ld\n", sizeof(somehting));*/
  /*realloc(something, 10);*/
  /*printf("\u2764");*/
  /*
int a = 0, b = 0;
pthread_t thread1, thread2;
printf("BEFORE START: %d, %d\n", a, b);
pthread_create(&thread1, NULL, aFunc, &a);
pthread_join(thread1, NULL);
printf("CAN YOU GO PAST THIS?\n");
*/
  /*printf("%d\n", MAPPING);    */
  /*bool a = true;*/
  /*bool b = false;*/
  /*printf("%d\n", a^b);*/
  /*int foo = 2;*/
  /*switch (foo) {*/
  /*case 1:*/
  /*  printf("one\n");*/
  /*  goto DEFAULTLABEL;*/
  /*case 2:*/
  /*  printf("two\n");*/
  /*DEFAULTLABEL: */
  /*default:*/
  /*  printf("I'm playing default\n");*/
  /*}*/
  /*printf("we got out \n");*/
  // printf("%s\n", get_utf8_input());
  /*for(;;){*/
  /*    printf("hi");*/
  /*    }*/
  /*union test structure = {NULL};*/
  /*structure.string = "something";*/
  /*printf("%s\n", structure.string);*/
  /*structure.string = malloc(sizeof(char) * 100);*/
  /*strncpy(structure.string, "lkasdhjflkdlkasfjd", 19);*/
  /*printf("%s\n", structure.string);*/
  /*bool one = false;*/
  /*bool two = false;*/
  /*  switch((one << 1) | (two)){*/
  /*      case 0b10:*/
  /*          printf("WORKED\n");*/
  /*          break;*/
  /*      default: */
  /*          printf("DIDN'T WORK\n");*/
  /*  }*/
  //---------------------------------------
  LOG("%c|%d\n", 'l', 10);
}

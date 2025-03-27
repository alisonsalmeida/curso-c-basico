/*
* Crie um programa que solicite ao usario que insira uma string ,
* e em seguida, conte quantos caracteres existem nela (sem considerar)
* o caracter \0
 * */

#include <stdio.h>

int main(){
  char string[100];
  int count = 0;

  printf("Digite uma string: ");
  fgets(string, sizeof(string), stdin);

  for (int i = 0; i < sizeof(string); i++) {
    char c = string[i];
    if(c == '\0') {
      // remove o \n
      string[i - 1] = '\0';
      count--;
      break;
    };

    count++;
  }

  printf("A string %s possui %d caracteres.\n", string, count);

  return 0;
}
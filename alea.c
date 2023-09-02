#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define debug 0

int main() {
    unsigned short num_esc[10], nums[10], asertou_cont = 0, armazenar[10];
    
    // Define a semente com base no tempo atual
    srand(time(NULL));
    puts("Escreva 10 números entre 1 e 100");
    for (unsigned short i = 0; i < 10; i++) {
        num_esc[i] = rand() % 100 + 1;
    }
    
    for (unsigned short i = 0; i < 10; i++) {
        printf("Escreva o %huº número: ", i + 1);
        scanf("%hu", &nums[i]);
        if (nums[i] > 100 || nums[i] <= 0) {
        puts("Número invalido");
        i--;
        }
        if (i) {
        for (unsigned short check = 0; check < i; check++) {
        if (check != i)
        if (nums[i] == nums[check]) {
        puts("Número repetido, escreva outro número");
        i--;
        break;
        }
        }
        }
    }
    
#if debug
    for (int i = 0; i < 10; i++) {
      printf("\n%hd\n", num_esc[i]);
    }
#endif
    
    puts("começou");
    
    for (unsigned short i = 1; i <= 100; i++) {
      bool aserto = false;
      for (unsigned short j = 0; j < 10; j ++) {
          for (unsigned short k = 0; k < 10; k++)
          if (i == num_esc[j] && num_esc[j] == nums[k]) {
          printf(" X");
          aserto = true;
          armazenar[asertou_cont] = nums[k];
          asertou_cont++;
          break;
          }
          }
    if (!aserto)
      printf(" %hu", i);
    if (i % 10 == 0)
      printf("\n");
    }
    
    if (!asertou_cont)
    printf("Não acertou nenhum número");
    else if (asertou_cont == 1)
    printf("Acertou apenas 1 número, %hu", armazenar[0]);
    else {
    printf("Acertou %hu vezes\nForam os números ", asertou_cont);
    for (unsigned short mostrar = 0; mostrar < asertou_cont; mostrar++)
    printf("%hu ", armazenar[mostrar]);
    }
    
    printf("\n");

    return 0;
}

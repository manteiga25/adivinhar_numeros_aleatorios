#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define debug 0

int main() {
    unsigned short num_esc[10], nums[10], asertou_cont = 0, armazenar[10];
    
    // Define a semente com base no tempo atual
    srand(time(0));
    cout << "Escreva 10 números entre 1 e 100" << endl;
    for (unsigned short i = 0; i < 10; i++) {
        num_esc[i] = rand() % 100 + 1;
     //   scanf("%hu", &nums[i]);
    //    printf("%hd\n", num_esc[i]);
    }
    
    for (unsigned short i = 0; i < 10; i++) {
        cout << "Escreva o " << i + 1 <<"º número: ";
        cin >> nums[i];
        if (nums[i] > 100 || nums[i] <= 0) {
        cout << "Número invalido" << endl;
        i--;
        }
        if (i) {
        for (unsigned short check = 0; check < i; check++) {
        if (check != i)
        if (nums[i] == nums[check]) {
        cout << "Número repetido, escreva outro número" << endl;
        i--;
        break;
        }
        }
        }
    //    printf("%hd\n", num_esc[i]);
    }
    
#if debug
    for (int i = 0; i < 10; i++) {
      cout << "\n" << num_esc[i] << endl;
    }
#endif
    
    cout << "começou" << endl;
    
    for (unsigned short i = 1; i <= 100; i++) {
      bool aserto = false;
      for (unsigned short j = 0; j < 10; j ++) {
        /*if (i == num_esc[j]) {
          printf(" X");
          aserto = true; */
          for (unsigned short k = 0; k < 10; k++)
          if (i == num_esc[j] && num_esc[j] == nums[k]) {
          cout << " X";
          aserto = true;
          armazenar[asertou_cont] = nums[k];
          asertou_cont++;
          break;
          }
          }
    if (!aserto)
      cout << " " << i;
    if (i % 10 == 0)
      cout << "\n";
    }
    
    if (!asertou_cont)
    cout << "Não acertou nenhum número";
    else if (asertou_cont == 1)
    cout << "Acertou apenas 1 número, " << armazenar[0];
    else {
    cout << "Acertou " << asertou_cont << " vezes\nForam os números ";
    for (unsigned short mostrar = 0; mostrar < asertou_cont; mostrar++)
    cout << armazenar[mostrar];
    }
    
    cout << endl;

    return 0;
}

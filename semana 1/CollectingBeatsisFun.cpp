#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    // ele pode pressionar k luzes com uma mão ao mesmo tempo

    // seu objetivo é pressionar cada luz no tempo exato

    // se ele não conseguir pressionar as luzes com suas duas mãos no tempo exato ele falha

    // quando o número próximo do array é menor que todos os outros anteriores ele da errado se o numero de k não estiver disponível

    char vetor[16];

    char digito[5];

    int contador = 0;

    int k = 0;

    cin >> k;

    int pain = k*2;

    for(int i = 0; i < 4; i++) {
        scanf("%s", digito);

        vetor[contador++] = digito[0];
        vetor[contador++] = digito[1];
        vetor[contador++] = digito[2];
        vetor[contador++] = digito[3];
        
    }

    contador = 1;

    for(int i = 0; i < 16; i++) {
        for(int k = i+1; k < 16; k++) {
            if(vetor[i] == '.') {
                break;
            }
            else{
                if(vetor[i] == vetor[k]) {
                    contador++;
                    vetor[k] = '.';
                }
            }
        }
        if(vetor[i] != '.') {
            vetor[i] = '.';
            if(contador > pain) {
                cout << "NO" << "\n";
                return 0;
            }
        }
        contador = 1;
    }

    cout << "YES" << "\n";

    return 0;
}

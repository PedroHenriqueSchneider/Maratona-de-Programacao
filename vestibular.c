#include <stdio.h>
#include <stdlib.h>

int main(){
    int N = 0;
    int contador = 0;
    scanf("%d", &N);

    char question;
    char questoes_marcadas[N];
    char questoes_certas[N];

    for(int i = 0; i < N; i++) {
        scanf(" %c", &question);
        questoes_certas[i] = question; 
    }
     for(int i = 0; i < N; i++) {
        scanf(" %c", &question);
        questoes_marcadas[i] = question; 
    }

    for(int i = 0; i < N; i++) {
        if(questoes_certas[i] == questoes_marcadas[i]) {
            contador++;
        }
    }
    printf("%d\n", contador);
    return 0;
}

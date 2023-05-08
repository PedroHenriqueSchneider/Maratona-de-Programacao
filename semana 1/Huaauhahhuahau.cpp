#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char palavra[51];

    scanf("%s", palavra);

    int i = 0, j = strlen(palavra) - 1;

    while (i < j) {
        while (palavra[i] != 'a' && palavra[i] != 'e' && palavra[i] != 'i' && palavra[i] != 'o' && palavra[i] != 'u') {
            i++;
        }
        while (palavra[j] != 'a' && palavra[j] != 'e' && palavra[j] != 'i' && palavra[j] != 'o' && palavra[j] != 'u') {
            j--;
        }
        if (palavra[i] != palavra[j]) {
            printf("N\n");
            return 0;
        }
        i++;
        j--;
    }

    printf("S\n");

    return 0;
}

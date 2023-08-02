#include <bits/stdc++.h>


using namespace std;


int n, hi, hf, counter = 0;


typedef struct horarioss
{
    int init;
    int fim;
} horarios;


int sortInitStruct(horarios h1, horarios h2)
{
    return h1.init < h2.init;
}


int sortFimStruct(horarios h1, horarios h2)
{
    return h1.fim < h2.fim;
}


int main()
{

    cin >> n;

    int fim;

    vector<horarios> ho;

    horarios h;

    for (int i = 0; i < n; i++)
    {
        cin >> hi >> hf;
        h.init = hi;
        h.fim = hf;

        ho.push_back(h);
    }


    sort(ho.begin(), ho.end(), sortInitStruct);
    sort(ho.begin(), ho.end(), sortFimStruct);


    fim = ho.front().fim;
    counter++;

    for (int i = 1; i < n; i++)
    {
        if (fim <= ho[i].init)
        {
            counter++;
            fim = ho[i].fim;
        }
    }

    cout << counter << "\n";

    return 0;
}

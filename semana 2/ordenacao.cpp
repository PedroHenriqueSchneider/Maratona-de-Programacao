#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Seu código vai aqui
    int N = 0;
    int num;

    cin >> N;

    vector<int> numbers;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}

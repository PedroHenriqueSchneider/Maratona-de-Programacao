#include <bits/stdc++.h>

using namespace std;
vector<int> bolas;

bool check(int pos){
}

bool solve(){
    sort(bolas.begin(), bolas.end() );
    int quatro = 0;
    for(int i = 0 ;i < bolas.size() - 1; i++){
        if(bolas[i + 1]== bolas[i])
            quatro++;
        else
            quatro = 0;        
        if(quatro >= 4){
            return false;
        }
    }
    return true;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0 ; i < 8; i++){
        int b;
        cin >> b;
        bolas.push_back(b);
    }    

    if(solve())
        cout << "S\n";
    else
        cout << "N\n";

    return 0;


}
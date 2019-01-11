#include <iostream>
using namespace std;

int main(){
    string s = "abc";
    bool answer = true;
    int n = sizeof(s);
    char symbol;
    int maxAlph = 140;
    int charcount[maxAlph];
    charcount[0] = 0;

    for(int i = 0; i <= maxAlph; i++){
        charcount[i] = 0;
    }

    for(int i = 0; i < n; ++i){
        symbol = s[i];
        charcount[symbol] += 1;
        //cout << symbol << " - " << charcount[symbol] << endl;
    }

    cout << "here" << endl;
    
    for(int i = 0; i <= maxAlph; i++){
        cout << charcount[i];
        if(i == 0){charcount[i] = 0;}  //reinforced concrete crutch (all by technologies)
        //cout << charcount[i];    
        
        if(charcount[i] >= 1){
            answer = false;
            cout << i << " " << charcount[i];
        }
    }

    cout << "\nans = " << answer;
    
    return 0;
} 
#include<iostream>
#include<fstream>

using namespace std;


void recFBC(int amount, int alph[], ofstream fout){
    

   for(int charNumber = 1; charNumber <= amount; charNumber++){
            fout << "amount = " << amount << "   charNumber = " << charNumber << endl;
    }
    fout << "----------\n"; 
}


void foutBrtCombinations(int minAmount, int maxAmount, int alph[], string filename){
    //ofstream fout;
    //fout.open("./" + filename);
    ofstream fout("./" + filename);

    for(int amount = minAmount; amount <= maxAmount; amount++){
        
        recFBC(amount, alph, fout);

        /*for(int charNumber = 1; charNumber <= amount; charNumber++){
            fout << "amount = " << amount << "   charNumber = " << charNumber << endl;
        }
        fout << "----------\n";*/
    }
    fout.close();
}





int main(){
    int alph[] = {1, 2, 3, 4};
    foutBrtCombinations(3, 5, alph, "file.txt");

    return 0;
}
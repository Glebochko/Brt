#include<iostream>
#include<fstream>

using namespace std;



class PBRTexception{
    public: PBRTexception(){}
    void oversizedFile(ofstream *fout){
        *fout << "File too big\nExit\nEOF"; 
        //*fout.close();
        exit;
    } 
};
    

class PBRT{
 
    public: 
    PBRT(){}

    PBRTexception exception;
    int linecount = 0;

    private: void foutdash(int dashcount, ofstream *fout){
        for(int j = 0; j < dashcount; j++){
            *fout << '-';
            if (j == dashcount - 1){
                *fout << endl;
            }
        }
    }

    private: void recFBC(int amount, int alph[], ofstream *fout, string paspart){
        string newpaspart;

        for(int charNumber = 1; charNumber <= amount; charNumber++){
            newpaspart = paspart + (char)alph[charNumber];

            *fout << "amount = " << amount;
            *fout << "   charNumber = " << charNumber;
            *fout << "   paspart = " << paspart << endl;

            linecount++;
            if (linecount * 3 > 1000){
                exception.oversizedFile(fout);
            }
            recFBC(amount, alph, fout, newpaspart);
        }
        
        
        foutdash(2, fout);
    }

    public: void foutBrtCombinations(int minAmount, int maxAmount, int alph[], string filename){
        ofstream fout;
        fout.open("./" + filename);
        string paspart;
        PBRTexception exception();
        for(int amount = minAmount; amount <= maxAmount; amount++){
            
            recFBC(amount, alph, &fout, paspart);


        }
        fout << "EOF";
        fout.close();
    }


};




int main(){
    int alph[] = {1, 2, 3, 4};

    PBRT brt;
    brt.foutBrtCombinations(3, 5, alph, "file.txt");

    return 0;
}
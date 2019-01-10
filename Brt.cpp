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

    int alph[], linecount;
    PBRTexception exception;
    string outputFileName;

    PBRT(int alph[], string filename){
        alph = this->alph;
        outputFileName = filename;
        linecount = 0;
    }

    private: void foutdash(int dashcount, ofstream *fout){
        for(int j = 0; j < dashcount; j++){
            *fout << '-';
            if (j == dashcount - 1){
                *fout << endl;
            }
        }
    }

    private: void recFBC(int amount, ofstream *fout, string paspart){
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
            recFBC(amount, fout, newpaspart);
        }
        
        
        foutdash(2, fout);
    }

    public: void foutBrtCombinations(int minAmount, int maxAmount){
        ofstream fout;
        fout.open("./" + outputFileName);
        string paspart;
        PBRTexception exception();
        for(int amount = minAmount; amount <= maxAmount; amount++){
            
            recFBC(amount, &fout, paspart);


        }
        fout << "EOF";
        fout.close();
    }


};




int main(){
    int alph[] = {1, 2, 3, 4};

    PBRT brt(alph, "file.txt");
    brt.foutBrtCombinations(3, 5);

    return 0;
}
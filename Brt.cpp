#include<iostream>
#include<fstream>

using namespace std;



class PBRTexception{
    public: PBRTexception(){}

    void oversizedFile(ofstream *fout){
        *fout << "File too big\nExit"; 
        //*fout.close();
        
    } 

    bool sizeCheck(int linecount){
        bool answer = false;
        if (linecount * 3 > 1000){
            answer = true;
        } 
        return answer;   
    }
};
    

class PBRTF{

    public: 

    char alph[4];
    int linecount;
    PBRTexception exception;
    string outputFileName;

    PBRTF(char alph[], string filename){
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

            if (exception.sizeCheck(++linecount)){
                //exception.oversizedFile(fout);
                exit;
            }

            recFBC(amount - 1, fout, newpaspart);
        }
        
        
        foutdash(20, fout);
    }

    public: void foutBrtfCombinations(int minAmount, int maxAmount){
        ofstream fout;
        fout.open("./" + outputFileName);
        string paspart;

        for(int amount = minAmount; amount <= maxAmount; amount++){
            
            recFBC(amount, &fout, paspart);


        }

        fout << "EOF";
        fout.close();
    }

    public: void foutBrtfCombinations(int amount){
        ofstream fout;
        fout.open("./" + outputFileName);
        string paspart;

        //for(int i = 0; i < 3; i++){ fout << i + 1 << endl;}
        recFBC(amount, &fout, paspart);

        fout << "EOF";
        fout.close();
    }


};






int main(){
    char alph[] = {'1', '2', '3', '4'};

    PBRTF brtf(alph, "file.txt");
    brtf.foutBrtfCombinations(3);

    return 0;
}
#include<iostream>
#include<fstream>

using namespace std;



class PBRTException{
    public: PBRTException(){}

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
    private:

    char alph[4];
    int linecount, alphLength;
    string inputStrAlph, outputFileName;
    PBRTException exception;

    public: PBRTF(string inputStrAlph, string outputFileName){
        this->inputStrAlph = inputStrAlph;
        this->outputFileName = outputFileName;
        alphLength = this->inputStrAlph.size();
        setAlphArray(alph, this->inputStrAlph, alphLength);
        linecount = 0;
    }

    private: void setAlphArray(char alph[], string stralph, int n){
        for(int i = 0; i < n; i++){
            alph[i] = stralph[i];
        }
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

        






        /*for(int charNumber = 1; charNumber <= amount; charNumber++){
            newpaspart = paspart + (char)alph[charNumber - 1];

            *fout << "amount = " << amount;
            *fout << "   charNumber = " << charNumber;
            *fout << "   paspart = " << paspart << endl;

            if (exception.sizeCheck(linecount)){
                //exception.oversizedFile(fout);
                *fout << "File too big\nExit"; 
                exit;
            }

            recFBC(amount - 1, fout, newpaspart);
        }*/
        
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
        string paspart = "";

        //for(int i = 0; i < 3; i++){ fout << i + 1 << endl;}
        recFBC(amount, &fout, paspart);

        fout << "EOF";
        fout.close();
    }

    public: void showInformation(){
        cout << "----------------------------------\n";
        cout << "PBRTF object information :" << endl;
        cout << "----------------------------------\n";
        cout << "Input alphabet = ";
        for(int i = 0; i < alphLength; i++){
            cout << alph[i] << " ";
            if (i == alphLength - 1){
                cout << endl;
            }
        }
        cout << "Length of alphabet = " << alphLength << endl;
        cout << "Output file name = " << outputFileName << endl;
        cout << "Estimated number of combinations = " << "-?-" << endl;
        //cout << " = " <<  << endl;
        cout << "----------------------------------\n";
        
    }

};






int main(){
    string alph = "1234";

    PBRTF brtf(alph, "OutputFile.txt");
    //brtf.showInformation();
    brtf.foutBrtfCombinations(3);

    return 0;
}
#include<iostream>
#include<fstream>

using namespace std;



/*class PBRTException{
    public: PBRTException(){}

    void oversizedFile(ofstream *fout){
        *fout << "File too big\nExit"; 
        
    } 

    bool sizeCheck(int linecount){
        bool answer = false;
        if (linecount * 3 > 1000){
            answer = true;
        } 
        return answer;   
    }
};*/
    

class PBRTF{
    private:

    char alph[4];
    int linecount, alphLength;
    string inputStrAlph, outputFileName;
    //PBRTException exception;

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

    private: void foutShowInformation(ofstream *fout, int amount){
        *fout << "PBRTF object information :" << endl;
        *fout << "Input alphabet = ";
        for(int i = 0; i < alphLength; i++){
            *fout << alph[i] << " ";
            if (i == alphLength - 1){
                *fout << endl;
            }
        }
        *fout << "Length of alphabet = " << alphLength << endl;
        *fout << "Amount character in password = " << amount << endl;
        *fout << "Output file name = " << outputFileName << endl;
        foutdash(35, fout);
        
    }

    private: void foutShowInformationMulti(ofstream *fout, int minAmount, int maxAmount){
        *fout << "PBRTF object information :" << endl;
        *fout << "Input alphabet = ";
        for(int i = 0; i < alphLength; i++){
            *fout << alph[i] << " ";
            if (i == alphLength - 1){
                *fout << endl;
            }
        }
        *fout << "Length of alphabet = " << alphLength << endl;
        *fout << "Amount character in password = ";
        for(int amount = minAmount; amount <= maxAmount; amount++){
            *fout << amount;
            if (amount == maxAmount){
                *fout << endl;
            }
            else{
                *fout << "; ";
            }
        }
        *fout << "Output file name = " << outputFileName << endl;
        foutdash(35, fout);
        
    }

    private: bool checkOptimality(string s){
        bool answer = true;



        return answer;
    }

    private: void recFBC(int amount, ofstream *fout, string passpart){
        if (amount >= 1){

            string newpasspart;

            for(int charNumb = 0; charNumb < alphLength; charNumb++){
                newpasspart = passpart + alph[charNumb];
                if (amount == 1){
                    *fout << "password = ";
                    *fout << newpasspart;
                    if (checkOptimality(newpasspart) == false){
                        *fout << " - not optimaze";
                    }
                    *fout << endl;
                }

                if (amount > 1){
                    recFBC(amount - 1, fout, newpasspart);
                }
            }
        }
    }

    public: void foutBrtfCombinations(int minAmount, int maxAmount){
        ofstream fout;
        fout.open("./" + outputFileName);
        foutShowInformationMulti(&fout, minAmount, maxAmount);

        for(int amount = minAmount; amount <= maxAmount; amount++){
            string passpart = "";
            recFBC(amount, &fout, passpart);
        }

        fout << "EOF";
        fout.close();
    }

    public: void foutBrtfCombinations(int amount){
        ofstream fout;
        fout.open("./" + outputFileName);
        foutShowInformation(&fout, amount);

        string passpart = "";
        recFBC(amount, &fout, passpart);

        fout << "EOF";
        fout.close();
    }

    public: void coutShowInformation(){
        cout << "------------------------------------\n";
        cout << "PBRTF object information :" << endl;
        cout << "------------------------------------\n";
        cout << "Input alphabet = ";
        for(int i = 0; i < alphLength; i++){
            cout << alph[i] << " ";
            if (i == alphLength - 1){
                cout << endl;
            }
        }
        cout << "Length of alphabet = " << alphLength << endl;
        cout << "Output file name = " << outputFileName << endl;
        cout << "Estimated number of combinations = " << alphLength << "^Amount = <?>" << endl;
        //cout << " = " <<  << endl;
        cout << "------------------------------------\n";
        
    }

};






int main(){
    string alph = "ab";

    PBRTF brtf(alph, "OutputFile.txt");
    brtf.coutShowInformation();
    brtf.foutBrtfCombinations(5, 6);

    return 0;
}
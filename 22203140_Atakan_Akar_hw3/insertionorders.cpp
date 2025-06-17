#include <iostream>
#include <fstream>
using namespace std;
const long long mod_inv_2 = 500000005;
const long long mod_inv_3 = 666666673;
const long long mod_inv_6 = 833333341;
const long long mod = 1000000009;
int main(int argc, char* argv[]) {
    
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_filename> <output_filename>" << endl;
        return 1;
    }

   
    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error: Could not open the input file!" << endl;
        return 1;
    }

    
    ofstream outputFile(argv[2]);
    if (!outputFile) {
        cerr << "Error: Could not open the output file!" << endl;
        return 1;
    }

    int N; 

    
    inputFile >> N;

    
    int* table = new int[N];

    
    for (int i = 0; i < N; ++i) {
        inputFile >> table[i];
    }

    inputFile.close();

    
   
    
    
    
    int* differenceHolder = new int[N+2];

    for(int i = 0; i < N;i++){
        if(table[i] != -1){
            int actual = table[i] % N;
            int difference = i - actual;
            if(difference < 0){
                difference = N + difference;
            }
            differenceHolder[i] = difference;
        }
        else{
            differenceHolder[i] = -1;
        }
    }
    differenceHolder[N] = differenceHolder[0];
    differenceHolder[N+1] = differenceHolder[1];
    
    long long maxPossibility = 1;
    int temp = 1;
    for(int i = 1; i <= N;i++){
        if(table[i-1] != -1){
            maxPossibility = (maxPossibility*temp)%mod;
            temp++;
        }  
    }

   
    int checker = 0;
    while(checker < N){
        if(differenceHolder[checker] == 0){
            if(differenceHolder[checker+1] == 1 && (differenceHolder[checker+2] == 0 || differenceHolder[checker+2] == -1 )){
                checker += 2;
                maxPossibility = ((maxPossibility*mod_inv_2)%mod);
                
            }
            else if(differenceHolder[checker+1] == 1 && differenceHolder[checker+2] == 2){
                checker += 3;
                maxPossibility = ((maxPossibility*mod_inv_6)%mod);
                
            }
            else if(differenceHolder[checker+1] == 0 && differenceHolder[checker+2] == 2){
                checker += 3;
                
                maxPossibility = ((maxPossibility*mod_inv_3)%mod);
                
            }
            else if(differenceHolder[checker+1] == 1 && differenceHolder[checker+2] == 1){
                checker += 3;
                maxPossibility = ((maxPossibility*mod_inv_6)%mod);
                
            }
            else{
                checker++;
            }
            
        }
        else{
                checker++;
            }
    }
    outputFile << maxPossibility;

    
    delete[] table;
    delete[] differenceHolder;

    outputFile.close();

    return 0;
}
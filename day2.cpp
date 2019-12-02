#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//code moved to this method for part 2
int runComputer(vector<int> computer){ //pass by value so that the vector is reset each time
    int i = 0;
    while(computer[i] != 99){
        int num;
        if(computer[i] == 1){                
            num = computer[computer[i+1]] + computer[computer[i+2]];
            computer[computer[i+3]] = num;
        }
        else if(computer[i] == 2){
            num = computer[computer[i+1]] * computer[computer[i+2]];
            computer[computer[i+3]] = num;
        }
        else{
            cout << "something went wrong" << endl;
            return -1;
        }  
        i+=4;        
    }
    //cout << "final: " << computer[0] << endl; //this line commented out for part2
    return computer[0];
}

int main(){
    ifstream myfile;
    vector<int> computer;
    myfile.open ("input2.txt");
    if (myfile.is_open())
    {
        string line;
        while (getline(myfile,line))
        {            
            stringstream ss(line);
            string val;
            while(getline(ss,val,',')){
                computer.push_back(stoi(val));
            }           
        }
        
        //nested for loop added for part 2 to try each combination of noun and verb
        for(int i = 0; i <= 99; i++){
            for(int j = 0; j <= 99; j++){
                computer[1] = i;
                computer[2] = j;
                //if the target is found, print the answer and exit
                if(runComputer(computer) == 19690720){
                    cout << "answer: " << 100 * i + j << endl;
                    myfile.close();
                    return 0;
                }
            }
        }  
    }
    else cout << "Unable to open file" << endl;
    
    myfile.close();
    return 0;
}

#include <iostream>
#include <fstream> 
using namespace std;

int main(){
    ifstream myfile;
    int total = 0;
    myfile.open ("input1.txt");
    if (myfile.is_open())
    {
        string line;
        while (getline(myfile,line))
        {            
            int subtotal = 0;
            int num = stoi(line);            
            while(num > 0){
                num = num/3;
                num -= 2;                  
                if(num > 0){
                    cout << num << " + ";
                    subtotal += num;  
                }                
            }
            cout << " = " << subtotal << endl;
            total += subtotal;
        }
    }
    else cout << "Unable to open file"; 
    cout << "final: " << total << endl;

    myfile.close();
    return 0;
}
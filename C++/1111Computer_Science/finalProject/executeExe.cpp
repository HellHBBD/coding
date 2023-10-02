#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
using namespace std;

int main(){
    string userInput;
    time_t start,end;
    time(&start);
    system("start timer.exe");
    while (1){
        cin >> userInput;
        if (userInput == "quit")
            break;
        cout << "result report" << endl;
    }
    time(&end);
    system("taskkill /F /T /IM timer.exe");
    cout << endl << "you spent " << difftime(end,start)-1 << " sec(s).";
    return 0;
}
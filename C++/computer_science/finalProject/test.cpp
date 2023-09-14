#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    system("start timer.exe");
    while(1){
        cin >> input;
        if (input == "quit")
            break;
        if (input == "pause")
            system("timer.exe & pause");
    }
    system("taskkill /F /T /IM timer.exe");
    return 0;
}
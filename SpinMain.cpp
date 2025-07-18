#include "spin.h"

int main(){
    srand(time(NULL));
    vector<string> *games = new vector<string>;
    string name;
    bool exit = false;
    while(true){
        int option;
        cout<<"1) See list\n";
        cout<<"2) Remove Game\n";
        cout<<"3) Add Game\n";
        cout<<"4) Spin!\n";
        cout<<"5) Exit.\n";
        cout<<"6) Load\n";
        cout<<"Pick an option: ";
        cin >> option;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(option){
            case 1: List(*games); break;
            case 2: Remove(*games) ;break;
            case 3: Add(*games); break;
            case 4: Spin(*games); break;
            case 5: cout<< "Exitting...\n";break;
            case 6: Load(*games);break;
            default: cout<< "Invalid!\n"; break;
        }
        if(option == 5) {
            Save(*games);
            break;
        }
    }
    delete games;
    return 0;
}
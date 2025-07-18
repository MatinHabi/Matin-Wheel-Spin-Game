#include "spin.h"

void List(vector<string>& games){
    cout<<"Games\n" << endl;
    for(const string &i : games){
        cout<< i << endl;
    }
    cout << "\n";
}

void Remove(vector<string>& games){
    system("clear");
    string name;
    cout<< "Enter game name: "; //<-- future update: make this hash map and ask "Enter game name or number"
    getline(cin, name);
    auto it = find(games.begin(), games.end(), name);
    if(it != games.end()){
        games.erase(it);
        cout<< name << " is removed\n";
    }else{
        cout << name << " not found.\n";
    }

}

void Add(vector<string>& games){
    system("clear");
    string name;
    cout<< "Enter game name: ";
    getline(cin, name);
    auto it = find(games.begin(), games.end(), name);
    if(it == games.end()){
        games.push_back(name);
        cout<< name << " is added!\n";
    }else{
        cout << name << " is already added.\n";
    }

}


void Spin(vector<string>& games){
    if(games.size() < 2 ){
        cout<<"You cannot spin until you add at least 2 games!\n";
        return;
    }
    int milliseconds = 30;
    int random = rand()%games.size();
    for(int i = 0 ; i < games.size() + 50 ; i++){
        random = rand()%games.size();
        cout << games[random] << endl;
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
        system("clear");
        milliseconds += 5;
    }
    cout<< games[random] << endl;
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << "Game picked " << games[random] << "!!!!\n";
}

void Save(vector<string> &games){
    string name;
    cout<<"What is your name: " << endl;
    getline(cin, name);
    name.erase(remove(name.begin(), name.end(), ' '), name.end());
    string filename = name + ".txt";

    ofstream userFile(filename);
    if(!userFile){
        cout<<"Unable to access file!\n";
        return;
    }

    for(const string &i : games){
        userFile << i << "\n";
    }

    cout << "Saved successful to " << filename << endl;
}

void Load(vector<string> &games){
    string name;
    cout<<"What is your name: " << endl;
    getline(cin, name);
    name.erase(remove(name.begin(), name.end(), ' '), name.end());
    string filename = name + ".txt";
    
    ifstream user(filename);
    if(!user){ cout<< "Unable to access file or file doesn't exist.\n" << endl; return;}

    games.clear();

    string line;

    while(getline(user, line)){
        if(!line.empty())
            games.push_back(line);
    }

    cout<<"Successfully Loaded" << endl;

    user.close();


}

//srand(time(NULL)); <-- need this for random number
//cout << rand()%10 << endl;
///this_thread::sleep_for(chrono::milliseconds(50)); <-- for wheel spin effect
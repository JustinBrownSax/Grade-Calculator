//
//  main.cpp
//  Csis223 12.2 aka 8.6
//
//  Created by Justin Brown on 3/19/23.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int QUESTIONS = 20;

char gradecalc(int score);

char gradecalc(int score) {
    switch (int (score/40.0 * 10)) {
        case 10:
        case 9:
            return 'A';
        case 8:
            return 'B';
        case 7:
            return 'C';
        case 6:
            return 'D';
        default:
            return 'F';
    }
}

int main() {
    
    ifstream File;
    char *key = new char[QUESTIONS];
    string id;
    char *answers = new char[QUESTIONS];
    int score;
    char ch;
    
    File.open("ch8_Ex6Data.txt");
    
    //cant do File >> key, needs to be stepped through the array unlike in 8.6
    for (int i = 0; i < 20; i++) {
        File >> key[i];
    }
    cout << "Key ";
    for (int i = 0; i < QUESTIONS; i++) {
        cout << key[i];
    }
    cout << endl;
    //stuans
    
    File >> id;
    File.get(ch);
    File.get(answers, 21);
    
    while (File) {
        score = 0;
        for (int i=0; i<QUESTIONS; i++){
            if (key[i]==answers[i]) {
                score = score + 2;
            }
            else if (answers[i] == ' ') {
                score = score;
            }
            else {
                score = score - 1;
            }
        }
        
        cout << id << " " << answers << " " << score << " " << gradecalc(score) << endl;
        
        File >> id;
        File.get(ch);
        File.get(answers, 22);
    }
    
    
    return 0;
}


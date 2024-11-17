#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#ifdef __linux__
    #include <vector>
#endif
// test 
using std::cout;
using std::cin;
using std::endl;
using std::string;
/* 
    +---+---+\n
    | a | b |\n  
    +---+---+
*/
void DrawLine(int n){
    for(int i = 0; i<n;++i){
        cout << "+---";
    }
    cout << "+";
}
void ShowTable(string table){
    DrawLine(table.size());
    cout << "\n";
    for(int i = 0; i< table.size();++i){
        cout << "| " << table[i] << " ";
    }
    cout << "|\n"; 
    DrawLine(table.size());
}

char input(){
    char c;
    cout << "\n enter letter" << endl;
    cin >> c;

    return c;
}
bool OpenLetter(string &table,string word,char c){
    bool found = false;
    for(int i =0; i < word.size();i++){
        if(word[i] == c){
            table[i] = c;

            found = true;
        }
    }
    return found;
}
void drawHangman(int attemptsLeft) 
    { 
        if (attemptsLeft == 0) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |      " << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 1) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 2) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 3) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |    /|" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 4) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |    /|\\" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 5) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |    /|\\" << endl; 
            cout << "  |    /" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 6) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     " << endl; 
            cout << "  |    /|\\" << endl; 
            cout << "  |    / \\" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
    } 
std::string RandomWord() {
#ifdef __APPLE__
    string str[] = {"hello","word"};
    int size = sizeof(str) / sizeof(*str);
    int r = rand() % size;
#elif __linux__ 
        std::vector<std::string> str = {"hello", "world"};
        int r = rand() % str.size();
#endif
    return str[r];
}




int main(void)
{
    srand(time(0));
    string word = RandomWord();
    string table(word.size(), ' ');
    char c;
    int error = 0;
    
  while(table != word && error < 6){
        system("clear");
        drawHangman(error);
        ShowTable(table);
        c = input();
        if(!OpenLetter(table,word,c)){
            error++;
            drawHangman(error);
        }
    }
        ShowTable(table);
    if(table == word){
        cout << "\nyou won" << endl;
    } else {
        cout << "\nyou lose" << endl;
    }
    return 0;
}
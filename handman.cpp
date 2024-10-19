#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void ShowTable(string table){
    cout << table << endl;
}
char input()
{
    char c;
    cout << "enter letter" << endl;
    cin >> c;

    return c;
}
bool ShowLetter(string &table,string word,char c)
{
    bool found = false;
    for(int i = 0;i<word.size();i++){
        if(word[i] == c){
            table[i] = c;

            found = true;
        }
    }

    return found;
}
void drawHangman(int attemptsLeft) 
    { 
        // Add your hangman drawing logic here 
        // For simplicity, you can print a static hangman 
        // ASCII art Modify this function to display the 
        // hangman as you like 
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
            cout << "  |     O" << endl; 
            cout << "  |    /|\\" << endl; 
            cout << "  |    / \\" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
    } 
int main(void)
{
    string word = "headmap";
    string table = "-------";
    char c;
    int error = 0;

    while(table != word && error < 6){
        drawHangman(error);
        ShowTable(table);
        c = input();
        if(!ShowLetter(table,word,c)){
            error++;
            drawHangman(error);

        }
    }
    if(table == word){
        cout << "you won" << endl;
    } else {
        cout << "you lose" << endl;
    }
    return 0;
}
#include <algorithm> 
#include<iostream>
#include<string>

using namespace std;

int main()
{
    int count = 0;
    string word,updatedWord;
    cin >> word;
    updatedWord = word;
    
    for(int i=0;i<word.length();i++){
        char letter = word[i];
        int posInOtherSide = (word.length()-1)-i;
        char letterInOtherSide = word[posInOtherSide];
        if(letter != letterInOtherSide){
            count += 1;
            string backupWord;
            for(int y=0;y<(updatedWord.length()+1);y++){
                if(y == posInOtherSide){
                    backupWord = backupWord + updatedWord[y];
                    backupWord = backupWord + letter;
                    
                    string reverseStr = backupWord;
                    reverse(reverseStr.begin(), reverseStr.end());
                    if(reverseStr == backupWord){
                        updatedWord = backupWord;
                        cout << "Step " << count << " - " << backupWord << endl;
                        cout << count << endl;
                        cout << "Palindrome Word - " << updatedWord << endl;
                        exit(0);
                    }
                }else{
                    backupWord = backupWord + updatedWord[y];
                    string reverseStr = backupWord;
                    reverse(reverseStr.begin(), reverseStr.end());
                    if(reverseStr == backupWord && y > 1){
                        updatedWord = backupWord;
                        cout << "Step " << count << " - " << backupWord << endl;
                        cout << count << endl;
                        cout << "Palindrome Word - " << updatedWord << endl;
                        exit(0);
                    }
                }
            }
            updatedWord = backupWord;
            cout << "Step " << count << " - " << backupWord << endl;
        }
    }
    cout << count << endl;
    cout << "Palindrome Word - " << updatedWord << endl;

    return 0;
}
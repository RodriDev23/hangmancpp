#include <iostream>
#include <vector>
#include "hangmanv2_funtions.h"
using namespace std;

int main(){
  greet();
  string codeword = "obfuscating";
  string answer = "___________";
  int misses = 0;
  vector<char> incorrecGuesses;
  bool guess = false;
  char letter;
  while(answer != codeword && misses < 7){
    display_misses(misses);
    display_status(incorrecGuesses, answer);
    cout << "\nEnter your guess\n";
    cin >> letter;
   for(int i = 0; i < codeword.length(); i++){
      if(letter == codeword[i]){
          answer[i] = letter;
          guess = true;
      }
   }
      if (guess) {
            cout << "\nGood, your letter is correct!\n";
        } else {
            cout << "\nNope, the letter is wrong!\n";
            incorrecGuesses.push_back(letter);
            misses++;
        }
   guess = false; 
  }
  
  end_game(answer, codeword);
  return 0;
}

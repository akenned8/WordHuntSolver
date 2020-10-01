#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "wordhunt.h"

using namespace std;

/*
At each location on the board we call for a search on the given word
*/
bool exist(char board[BOARD_HEIGHT][BOARD_WIDTH], string word) {
  int i;
  int j;
  for(i=0; i < BOARD_HEIGHT; i++) {
    for(j=0; j < BOARD_WIDTH; j++ ) {
      if(searchw(board, word, i, j, 0)){
        return true;
      }
    }
  }
  return false;
}

/*
Return false if word[pos] is not at position i,j on the board, otherwise recursively search the board for the next char of the word.
*/
bool searchw(char board[BOARD_HEIGHT][BOARD_WIDTH], string word, int i, int j, int pos) {
  if(pos == word.length()){
    return true;
  }
  if( board[i][j] != word.at(pos) || i<0 || i>= BOARD_HEIGHT || j<0 || j >= BOARD_WIDTH) {
    return false;
  }
  //Ensuring we don't accidentally count a char twice in the word
  char tmp = board[i][j];
  board[i][j] = '#';

  //checking all bordering places on the board for the next character (recursively)
  bool res = searchw(board, word, i+1, j, pos+1) ||
            searchw(board, word, i-1, j, pos+1) ||
            searchw(board, word, i, j+1, pos+1) ||
            searchw(board, word, i, j-1, pos+1) ||
            searchw(board, word, i+1, j+1, pos+1) ||
            searchw(board, word, i-1, j-1, pos+1) ||
            searchw(board, word, i+1, j-1, pos+1) ||
            searchw(board, word, i-1, j+1, pos+1);

  //replacing the '#' so that it won't affect the search for the next word
  board[i][j] = tmp;

  return res;
}

/*
Get input from the user, build a 2d matrix from the input, and search the board for our words
*/
int main(){
  string input;
  char board[BOARD_HEIGHT][BOARD_WIDTH];

  //getting input from the user
  cout<< "enter " << BOARD_HEIGHT * BOARD_WIDTH <<" characters without spaces: ";
  cin >> input;
  while (input.length() != BOARD_HEIGHT * BOARD_WIDTH){
    cerr << "input length is not " << BOARD_HEIGHT * BOARD_WIDTH <<" Please try again: ";
    cin >> input;
  }
  cout << "\n\n";
  //building the board from the input
  int i;
  int j;
  int pos=0;
  for(i=0; i < BOARD_HEIGHT; i++) {
    for(j=0; j < BOARD_WIDTH; j++) {
      board[i][j] = input[pos];
      pos++;
    }
  }

  //opening the dictionary and searching for each word on the board
  ifstream wordfile("currdict.txt");
  string word;
  while(getline(wordfile, word)){
    if(exist(board, word)) {
      cout<< word <<endl;
    }
  }

  wordfile.close();
  return 0;
}
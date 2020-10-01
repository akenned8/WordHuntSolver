import numpy as np
from typing import List
import sys

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board:
            return False

        for x in range(0, len(board)):
            for y in range(0, len(board[0])):
                if self.searchw(board, word, x, y, 0):
                    return True
        return False


    def searchw(self, board: List[List[str]], word: str, i: int, j: int, pos: int) -> bool:

        if pos == len(word):
            return True

        if i<0 or i>=len(board) or j<0 or j>=len(board[0]) or word[pos] != board[i][j]:
            return False

        tmp = board[i][j]
        board[i][j] = '#'

        res = self.searchw(board,word,i+1,j, pos+1) \
        or self.searchw(board,word,i-1,j, pos+1) \
        or self.searchw(board,word,i,j+1, pos+1) \
        or self.searchw(board,word,i,j-1, pos+1) \
        or self.searchw(board,word,i-1,j-1, pos+1) \
        or self.searchw(board,word,i-1,j+1, pos+1) \
        or self.searchw(board,word,i+1,j-1, pos+1) \
        or self.searchw(board,word,i+1,j+1, pos+1)
        board[i][j] = tmp
        return res

def main():
    print('enter 16 characters without spaces: ')
    x = input()
    if(len(x) != 16):
        print("input not 16 chars, please run again")
        sys.exit()
    arr = []
    board = [[]]
    for i in range(0,len(x)):
        if(i%4 == 0 and i != 0):
            board.append(arr)
            arr = []
        arr.append(x[i])
    board.append(arr)
    board = board[1:]

    sol = Solution()
    file1 = open('currdict.txt', 'r')
    while True:

        # Get next line from file
        line = file1.readline()
        if(sol.exist(board,line.strip())):
            print(line.strip(),flush=True)
        if not line:
            break


    file1.close()


if __name__ == "__main__":
    main()

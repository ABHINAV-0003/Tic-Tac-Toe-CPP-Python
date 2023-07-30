
import sys

def display_board(board):
    print(f" {board[1]} | {board[2]} | {board[3]} ")
    print("-----------")
    print(f" {board[4]} | {board[5]} | {board[6]} ")
    print("-----------")
    print(f" {board[7]} | {board[8]} | {board[9]} ")


def player1_input(board):
    
    x=0
    while x not in [1,2,3,4,5,6,7,8,9]:
         x=int(input("Enter your move (1-9)-"))
    board[x]='X'
    
def player2_input(board):
    
    o=0
    while o not in [1,2,3,4,5,6,7,8,9]:
         o=int(input("Enter your move (1-9)-"))
    board[o]='O'
    
def game_logic1(board,Player1):
    
    if(board[1]==board[2]==board[3]=='X')or(board[4]==board[5]==board[6]=='X')or(board[7]==board[8]==board[9]=='X')or(board[1]==board[5]==board[9]=='X')or(board[3]==board[5]==board[7]=='X'):
        print(f"{Player1} wins")
      
        sys.exit()
        
def game_logic2(board,Player1):
    
    if(board[1]==board[2]==board[3]=='O')or(board[4]==board[5]==board[6]=='O')or(board[7]==board[8]==board[9]=='O')or(board[1]==board[5]==board[9]=='O')or(board[3]==board[5]==board[7]=='O'):
        print(f"{Player2} wins")
      
        sys.exit()
        

def draw():
    print("Game ends in a draw as it should")

while True:   
    board = [' ',' ',' ',' ',' ',' ',' ',' ',' ',' ']
    print('Welcome to Tic Tac Toe by APEACE ')
    Player1=input(" Enter Player1 name-")
    Player2=input(" Enter Player2 name-")

    display_board(board)
    player1_input(board)
    
    display_board(board)

    player2_input(board)
    display_board(board)


    player1_input(board)
    display_board(board)


    player2_input(board)
    display_board(board)


    player1_input(board)
    display_board(board)
    game_logic1(board,Player1)

    player2_input(board)
    display_board(board)
    game_logic2(board,Player2)


    player1_input(board)
    display_board(board)
    game_logic1(board,Player1)

    player2_input(board)
    display_board(board)
    game_logic2(board,Player2)

    player1_input(board)
    display_board(board)
    game_logic1(board,Player1)
 draw()


#include <iostream>
#include <random>
#include <string>

using namespace std;


void disp(char array[3][3], int &a, int &i, int &j) {
  if (a == 1) {
    i = 0;
    j = 0;
  } else if (a == 2) {
    i = 0;
    j = 1;
  } else if (a == 3) {
    i = 0;
    j = 2;
  } else if (a == 4) {
    i = 1;
    j = 0;
  } else if (a == 5) {
    i = 1;
    j = 1;
  } else if (a == 6) {
    i = 1;
    j = 2;
  } else if (a == 7) {
    i = 2;
    j = 0;
  } else if (a == 8) {
    i = 2;
    j = 1;
  } else if (a == 9) {
    i = 2;
    j = 2;
  }
}

void print(char array[3][3]) {
  for (int i = 0; i < 3; i++) {
    if (i > 0) {
      cout << "---|---|---\n";
    }
    for (int j = 0; j < 3; j++) {
      if (j < 3 && j > 0) {
        cout << "|";
      }
      cout << " " << array[i][j] << " ";
    }
    cout << endl;
  }
}

void board() {
  cout << "\n 1 | 2 | 3 \n---|---|---\n 4 | 5 | 6 \n---|---|---\n 7 | 8 | 9 \n";
}

void check1(char array[3][3], string Player1) {
  if (((array[0][0] == 'X') && (array[0][1] == 'X') && (array[0][2] == 'X')) ||
      ((array[1][0] == 'X') && (array[1][1] == 'X') && (array[1][2] == 'X')) ||
      ((array[2][0] == 'X') && (array[2][1] == 'X') && (array[2][2] == 'X')) ||
      ((array[0][0] == 'X') && (array[1][0] == 'X') && (array[2][0] == 'X')) ||
      ((array[0][1] == 'X') && (array[1][1] == 'X') && (array[2][1] == 'X')) ||
      ((array[0][2] == 'X') && (array[1][2] == 'X') && (array[2][2] == 'X')) ||
      ((array[0][0] == 'X') && (array[1][1] == 'X') && (array[2][2] == 'X')) ||
      ((array[0][2] == 'X') && (array[1][1] == 'X') && (array[2][0] == 'X')))

  {
    cout << Player1 << " wins";
    exit(0);
  }
}

void check2(char array[3][3], string Player2) {
  if (((array[0][0] == 'O') && (array[0][1] == 'O') && (array[0][2] == 'O')) ||
      ((array[1][0] == 'O') && (array[1][1] == 'O') && (array[1][2] == 'O')) ||
      ((array[2][0] == 'O') && (array[2][1] == 'O') && (array[2][2] == 'O')) ||
      ((array[0][0] == 'O') && (array[1][0] == 'O') && (array[2][0] == 'O')) ||
      ((array[0][1] == 'O') && (array[1][1] == 'O') && (array[2][1] == 'O')) ||
      ((array[0][2] == 'O') && (array[1][2] == 'O') && (array[2][2] == 'O')) ||
      ((array[0][0] == 'O') && (array[1][1] == 'O') && (array[2][2] == 'O')) ||
      ((array[0][2] == 'O') && (array[1][1] == 'O') && (array[2][0] == 'O')))

  {
    cout << Player2 << " wins";
    exit(0);
  }
}

void comp1(int &a, int x1, int x2, int x3, int x4, int x5, int o1, int o2,
           int o3, int o4) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(1, 9);
  a = dist(gen);

  while (a == x1 || a == x2 || a == x3 || a == x4 || a == x5 || a == o1 ||
         a == o2 || a == o3 || a == o4) {
    a = dist(gen);
  }
}

int main() {
  int a, i, j, x, y, z;
  char array[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  string Player1;
  string Player2;
  int wx = 0;
  int wo = 1;
  int tie = 0;
  string Player;
  int x1, x2, x3, x4, x5, o1, o2, o3, o4;
  cout << "Welcome to TicTacToe by APEACE\n";
  cout << "To Play with a Friend Press 0\nTo Play with the Computer Press 1\n";
  cin >> x;
  if (x == 1) // Playing First vs Computer//Computer is dumb
  {
    cout << "Game with Computer\n";
    cout << "Enter your Name: ";
    cin >> Player;
    Player1 = Player;
    Player2 = "Computer";
    cout << "Do you want to play first (press 0) or second (press 1) \n";
    cin >> y;
    if (y == 0) {
      // Move 1
      system("clear");
      board();
      cout << Player << ", enter your move (1-9): ";
      cin >> a;
      x1 = a;
      disp(array, a, i, j);
      array[i][j] = 'X';

      comp1(a, x1, x2, x3, x4, x5, o1, o2, o3, o4);
      disp(array, a, i, j);
      array[i][j] = 'O';
      o1 = a;
      print(array);
      // Move 2
      cout << Player << ", enter your move (1-9): ";

      cin >> a;
      x2 = a;
      disp(array, a, i, j);
      array[i][j] = 'X';

      comp1(a, x1, x2, x3, x4, x5, o1, o2, o3, o4);
      o2 = a;
      disp(array, a, i, j);
      array[i][j] = 'O';
      print(array);
      // Move 3
      cout << Player << ", enter your move (1-9): ";

      cin >> a;
      x3 = a;
      disp(array, a, i, j);
      array[i][j] = 'X';
      print(array);
      check1(array, Player1);
       system("clear");
      comp1(a, x1, x2, x3, x4, x5, o1, o2, o3, o4);
      o3 = a;
      disp(array, a, i, j);
      array[i][j] = 'O';
      print(array);
      check2(array, Player2);
      // Move 4
      cout << Player << ", enter your move (1-9): ";

      cin >> a;
      x4 = a;
      disp(array, a, i, j);
      array[i][j] = 'X';
      print(array);
      check1(array, Player1);
       system("clear");
      comp1(a, x1, x2, x3, x4, x5, o1, o2, o3, o4);
      o4 = a;
      disp(array, a, i, j);
      array[i][j] = 'O';
      print(array);
      check2(array, Player2);

      // Move 5
      cout << Player << ", enter your move (1-9): ";

      cin >> a;
      x5 = a;
      disp(array, a, i, j);
      array[i][j] = 'X';
      print(array);
      check1(array, Player1);
      cout << "Game ends in a Draw\n";
      return 0;

    } else if (y == 1) // Playing Second against Computer
    {
      system("clear");
      Player1 = "Computer";
      Player2 = Player;
      cout << "Game Starts\n";
      // Move 1
      comp1(a, x1, x2, x3, x4, x5, o1, o2, o3, o4);
      x1 = a;
      disp(array, a, i, j);
      array[i][j] = 'X';
      print(array);
      cout << Player << ", enter your move (1-9): ";

      cin >> a;
      o1 = a;
      disp(array, a, i, j);
      array[i][j] = 'O';

      // Move 2
      comp1(a, x1, x2, x3, x4, x5, o1, o2, o3, o4);
      disp(array, a, i, j);
      x2 = a;
      array[i][j] = 'X';
      print(array);

      cout << Player << ", enter your move (1-9): ";
      cin >> a;
      o2 = a;
      disp(array, a, i, j);
      array[i][j] = 'O';

      // Move 3
      comp1(a, x1, x2, x3, x4, x5, o1, o2, o3, o4);
      disp(array, a, i, j);
      x3 = a;
      array[i][j] = 'X';
      print(array);
      check1(array, Player1);

      cout << Player << ", enter your move (1-9): ";

      cin >> a;
      o3 = a;
      disp(array, a, i, j);
      array[i][j] = 'O';
 print(array);
      check2(array, Player2);
      system("clear");

      // Move 4
      comp1(a, x1, x2, x3, x4, x5, o1, o2, o3, o4);
      disp(array, a, i, j);
      x4 = a;
      array[i][j] = 'X';
      print(array);
      check1(array, Player1);
      cout << Player << ", enter your move (1-9): ";

      cin >> a;
      o4 = a;
      disp(array, a, i, j);
      array[i][j] = 'O';
 print(array);
      check2(array, Player2);
      system("clear");

      // Move5
      comp1(a, x1, x2, x3, x4, x5, o1, o2, o3, o4);
      disp(array, a, i, j);
      x5 = a;
      array[i][j] = 'X';
      print(array);
      check1(array, Player1);
      cout << "Game ends in a Draw\n";
      return 0;
    }
  }

  // Not now :(

  else if (x == 0) {
    cout << "Game with Friend\n";
    cout << "Enter Player 1 Name: ";
    cin >> Player1;
    cout << "\nEnter Player 2 Name: ";
    cin >> Player2;
    system("clear");
    board();
    cout << Player1 << ", enter your move (1-9): ";
    cin >> a;
    disp(array, a, i, j);
    array[i][j] = 'X';
    print(array);

    board();
    cout << Player2 << ", enter your move (1-9): ";
    cin >> a;
    system("clear");
    disp(array, a, i, j);
    array[i][j] = 'O';
    print(array);

    board();
    cout << Player1 << ", enter your move (1-9): ";
    cin >> a;
    system("clear");
    disp(array, a, i, j);
    array[i][j] = 'X';
    print(array);

    board();
    cout << Player2 << ", enter your move (1-9): ";
    cin >> a;
    system("clear");
    disp(array, a, i, j);
    array[i][j] = 'O';
    print(array);

    board();
    cout << Player1 << ", enter your move (1-9): ";
    cin >> a;
    system("clear");
    disp(array, a, i, j);
    array[i][j] = 'X';
    print(array);
    check1(array, Player1);

    board();
    cout << Player2 << ", enter your move (1-9): ";
    cin >> a;
    system("clear");
    disp(array, a, i, j);
    array[i][j] = 'O';
    print(array);
    check2(array, Player2);

    board();
    cout << Player1 << ", enter your move (1-9): ";
    cin >> a;
    system("clear");
    disp(array, a, i, j);
    array[i][j] = 'X';
    print(array);
    check1(array, Player1);

    board();
    cout << Player2 << ", enter your move (1-9): ";
    cin >> a;
    system("clear");
    disp(array, a, i, j);
    array[i][j] = 'O';
    print(array);
    check2(array, Player2);

    board();
    cout << Player1 << ", enter your move (1-9): ";
    cin >> a;
    system("clear");
    disp(array, a, i, j);
    array[i][j] = 'X';
    print(array);
    check1(array, Player1);
  }
  cout << "Game ends in a Draw\n";
  cout << "Do you want to play a new game\nPress 1 for Yes\nPress 0 for No ";

  cin >> z;
  system("clear");

  return 0;
}
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum ENPLAY {Stone = 1, Paper, Scissors};

struct STPLAY{
int YouWinner;
int ComputerWinner;
int Draw;
};

void Game();
void RoundGame(int n, STPLAY &Play);
int ReadNumber(string S, int FROM, int TO);
ENPLAY ReadYou(string S, int FROM, int TO);
ENPLAY GetRand(int FROM, int TO);
int RandNumber(int FROM, int TO);
string Choise(int n);
string CHECKRound(int nn, int cnn, STPLAY &Play);
void PRINTFRound(int nn, int cnn, int i, string Winner);
void GameOver(int n, STPLAY Play);
void PRINTFGameOver();
string TabsT(int n);
string TabsU(int n);
string CHECKGameOver(STPLAY Play);
char PlayAgain(string S);
void ClearGame(STPLAY &Play);

int main(void){
srand((unsigned)time(NULL));
Game();

return 0;
}

void Game(){
STPLAY Play;
char C;
do{
ClearGame(Play);
int n = ReadNumber("Count Game: ", 1, 10);
RoundGame(n, Play);
GameOver(n, Play);
C = PlayAgain("Play Again Y / N: ");
}while(C == 'Y' || C == 'y');
}

void RoundGame(int n, STPLAY &Play){
Play.YouWinner = 0, Play.ComputerWinner = 0, Play.Draw = 0;
for(int i = 0; i < n; i++){
int nn, cnn, CHE;
nn = ReadYou("[1]Stone, [2]Paper, [3]Scissors: ", 1, 3);
cnn = GetRand(1, 3);

//string StringYou, StringComputer;
//StringYou = Choise(nn);
//StringComputer = Choise(cnn);

//CHECKRound(nn, cnn, Play);

PRINTFRound(nn, cnn, i, CHECKRound(nn, cnn, Play));

}
}

int ReadNumber(string S, int FROM, int TO){
int n;
do{
cout << S;
cin >> n;
}while(n < FROM || n > TO);
return n;
}

ENPLAY ReadYou(string S, int FROM, int TO){
int n;
do{
cout << S;
cin >> n;
}while(n < FROM || n > TO);
return (ENPLAY)n;
}

ENPLAY GetRand(int FROM, int TO){
//int n = (ENPLAY)RandNumber(FROM, TO); 
return (ENPLAY)RandNumber(FROM, TO);
}

int RandNumber(int FROM, int TO){
return rand() % (TO - FROM + 1) + FROM;
}

string Choise(int n){
string S[3] = {"Stone", "Paper", "scissors"};
return S[n - 1];
}

string CHECKRound(int nn, int cnn, STPLAY &Play){ 
if(nn == cnn){
system("color 6F");
++Play.Draw;
return "Drow";
}

else if(nn == ENPLAY::Stone && cnn == ENPLAY::Scissors){
system("color 2F");
++Play.YouWinner;
return "You Winner";}
else if(nn == ENPLAY::Paper && cnn == ENPLAY::Stone){
system("color 2F");
++Play.YouWinner;
return "You Winner";}
else if(nn == ENPLAY::Scissors && cnn == ENPLAY::Paper){
system("color 2F");
++Play.YouWinner;
return "You Winner";}

else {
system("color 4F");
cout << "\a";
++Play.ComputerWinner;
return "computer Winner";}
}

void PRINTFRound(int nn, int cnn, int i, string Winner){
cout << "_____________ROUND[" << i + 1 << "]______________\n";
cout << "You: " << Choise(nn) << endl;
cout << "Computer: " << Choise(cnn) << endl;
cout << "winner: " << Winner << endl;
cout << "_____________________________________________________\n";
}

void GameOver(int n, STPLAY Play){
//cout << "_________________________________________________\n\n";
//cout << "+++G a m e   O v e r\n\n";
//cout << "________________________________________________________\n\n";
PRINTFGameOver();
cout << TabsT(2) << TabsU(20) << "[Game]" << TabsU(20) << endl;
cout << TabsT(2) << "You Winner: " << Play.YouWinner << endl;
cout << TabsT(2) << "Computer Winner: " << Play.ComputerWinner << endl;
cout << TabsT(2) << "Drow: " << Play.Draw << endl;
cout << TabsT(2) << CHECKGameOver(Play) << endl;
cout << TabsT(2) << TabsU(50) << "\n\n";
}

string CHECKGameOver(STPLAY Play){
if(Play.YouWinner > Play.ComputerWinner){return "You Winner (-:";}
else if(Play.ComputerWinner > Play.YouWinner){return "Computer Winner )-:";}
//else if(Play.Draw > Play.YouWinner && Play.Draw  > Play.ComputerWinner){return "Draw ()-:";}
else {return "Draw ()-:";}
}

char PlayAgain(string S){
char C;
do{
cout << S;
cin >> C;
}while(C != 'Y' && C != 'y' && C != 'N' && C != 'n');
return C;
}

void ClearGame(STPLAY &Play){
//Play.YouWinner = 0, Play.ComputerWinner = 0, Play.Draw = 0;
system("color 0F");
system("cls");
}

void PRINTFGameOver(){
cout << "\n\n";
cout << TabsT(2) << TabsU(50) << endl;
cout << TabsT(2) << "     +++ G a m e   O v e r +++" << endl;
cout << TabsT(2) << TabsU(50) << endl;
}

string TabsT(int n){
//string C = "\t";
string S = "";
for(int i = 0; i < n; i++){
S = S + "\t";
}
return S;
}
string TabsU(int n){
//char C = '_';
string S = "";
for(int i = 0; i < n; i++){
S = S + '_';
}
return S;
}
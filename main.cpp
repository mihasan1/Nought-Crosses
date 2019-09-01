#include <iostream>
#include <string>
using namespace std;

char winner='-';
char arr[9]={'1','2','3','4','5','6','7','8','9'};

void output()
{
cout <<" |-"<<arr[0]<<"-|-" << arr[1] << "-|-"<<arr[2]<<"-| \n";
cout <<" |-"<<arr[3]<<"-|-" << arr[4] << "-|-"<<arr[5]<<"-| \n";
cout <<" |-"<<arr[6]<<"-|-" << arr[7] << "-|-"<<arr[8]<<"-| \n";
}

char move_checker(int choice)
{
    switch(choice){
            case 1:return arr[0];break;
            case 2:return arr[1];break;
            case 3:return arr[2];break;
            case 4:return arr[3];break;
            case 5:return arr[4];break;
            case 6:return arr[5];break;
            case 7:return arr[6];break;
            case 8:return arr[7];break;
            case 9:return arr[8];break;
            default: cout << "Error!\n";break;}
}

void movement(int player){
int choice;
cin >>choice;
while (move_checker(choice)== 'X' || move_checker(choice)== '0')
cout <<"This cell is occupy!\n";
        switch(choice){
        case 1:if(player==1)arr[0]='X';else arr[0]='0';break;
        case 2:if(player==1)arr[1]='X';else arr[1]='0';break;
        case 3:if(player==1)arr[2]='X';else arr[2]='0';break;
        case 4:if(player==1)arr[3]='X';else arr[3]='0';break;
        case 5:if(player==1)arr[4]='X';else arr[4]='0';break;
        case 6:if(player==1)arr[5]='X';else arr[5]='0';break;
        case 7:if(player==1)arr[6]='X';else arr[6]='0';break;
        case 8:if(player==1)arr[7]='X';else arr[7]='0';break;
        case 9:if(player==1)arr[8]='X';else arr[8]='0';break;
        default:cout << "Error!\n";break;
    }
}

char checkher()
{
    for(int i = 0; i < 3; i++)
      if (arr[i*3] == arr[i*3+1] && arr[i*3+1] == arr[i*3+2])
         return arr[i]; // 1-2-3 / 4-5-6 / 7-8-9
      else if (arr[i] == arr[i+3] && arr[i+3] == arr[i+6])
         return arr[i]; //1-4-7, 2-5-8 / 3-6-9
      else if ((arr[2] == arr[4] && arr[4] == arr[6]) || (arr[0] == arr[4] && arr[4] == arr[8]))
         return arr[i]; // 1-5-9 / 3-5-7
      return '-'; // no winner
}

void win(){
if(winner=='X')cout << "Crosses win!";
else if(winner=='0')cout << "Noughts win!";
else cout << "Standoff!";
}

int main()
{
cout << " --- Noughts and crosses ---\n\n";
cout << "Below is the playing field:\n";
output();
cout << "Enter the cell number to make a move:\n";
for(int mov=1; mov<=9; mov++){
    if(mov%2!=0){cout << "Crosses go: ";
    movement(1);
    }
    else{ cout << "Noughts go: ";
    movement(2);
    }
    output();
    if(mov>=5){
        winner=checkher();
        if(winner!='-')break;
    }
}
win();
return 0;
}

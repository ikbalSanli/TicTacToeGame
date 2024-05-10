#include <iostream>

using namespace std;
 char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

 char current_marker;
 int current_player;

 void draw (){
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board [0][2]<<endl;
    cout<<"------------ \n";
    cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board [1][2]<<endl;
    cout<<"------------\n";
    cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board [2][2]<<endl;
    }

    bool placeMarker(int slot){
    int row ;
    if(slot %3 ==0){
        row = (slot/3)-1;
    }
    else{
        row=slot/3;
    }

    int col;
    if(slot%3==0){
        col=2;
    }
    else {
        col=slot%3 -1;
    }

    if(board[row][col]!='X' && board[row][col]!='O'){
            board[row][col]=current_marker;
    return true;
    }else{
    return false;
    }
    }
    int winner() {
    for(int i=0;i<3;i++){

        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){//satır
            return current_player;
        }
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){//sütun
            return current_player;
        }
        }
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){//soldan sağa
            return current_player;
        }
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){//sağdan sola
            return current_player;
        }

        return 0;//kazanan yok demek

    }
     void swap_player_and_marker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

    void game(){
    cout<<"player 1 ,choose your marker:";
    char marker_p1;
    cin>>marker_p1;

    current_player=1;
    current_marker=marker_p1;

    draw();

    int player_won;
    for(int i=0;i<9;i++){//beraberlik durumunda max 9 kez donecek bu yuzden 9 kere 
        cout<<"its player"<<current_player<<"s turn .enter your slot:";
       int slot;
        cin>>slot;


         if (slot<1 || slot>9){
            cout<<"that slot invalid! try another slot!";
            i--;// aynı kişiye bir hak daha veriyorum
            continue;
         }
        if(!placeMarker(slot)){
            cout<<"that slot occupied! try another slot!";
            i--;// aynı kişiye bir hak daha veriyorum
            continue;
        }
        draw();


        player_won=winner();
        if(player_won==1){
            cout<<"player one won! Congratulations!";break;
        }
        if(player_won==2){
            cout<<"player two won! Congratulations!";break;
        }
        swap_player_and_marker();
    }
    if(player_won==0){// 9 hamle sonunda berabere
        cout<<"that is a tie game!";
    }
    }



int main()
{
    game();
   draw();
   cout<<"\n";
   current_marker='X';
   current_player=1;

   placeMarker(1);
   placeMarker(5);
   placeMarker(9);
   swap_player_and_marker();

   draw();
   cout<<winner();
    return 0;
}

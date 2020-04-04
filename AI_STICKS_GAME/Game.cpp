####################AI GAME #########################
1.random player
2.AI vs player
3.AI vs AI

------------------------------

#include<bits/stdc++.h>
#include "Game.h"

using namespace std;


typedef struct root{
    struct root* left;
    struct root* mid;
    struct root* right;

}root;



void two_player(int n){
             int player_1,player_2;
             int t,rest_sticks=n,sticks;
             printf("\n---------------GAME RULE--------------");
             printf("\nA PLAYER CAN CHOOSE ATLEAST 1 STICK OR CAN CHOOSE ATMOST 3 STICKS");
             printf("\nLETS BEGIN THE GAME.WE ARE DOING THE TOSS");
             player_1=0,player_2=1;
             t=rand()%2;
            
             if(t==player_1){
                 printf("\n PLAYER_1 WON THE TOSS\n");
                while(1){
                 
               e:  printf("\n PLAYER_1:");
                 scanf("%d",&sticks);
                 if(sticks<1 || sticks>3 || sticks>rest_sticks){
                     printf("\n NOT PERMITED.TRY AGAIN");
                     goto e;
                 }
                 rest_sticks-=sticks;
                 if(rest_sticks==1){
                      printf("\n PLAYER_1 HAS WON THE GAME");
                      break;
                 }
                 else if(rest_sticks==0){
                      printf("\n PLAYER_2 HAS WON THE GAME");
                      break;
                 
                 }
              f:   printf("\n PLAYER_2:");
                 scanf("%d",&sticks);
                 if(sticks<1 || sticks>3 || sticks>rest_sticks){
                     printf("\n NOT PERMITED.TRY AGAIN");
                     goto f;
                 }
                 rest_sticks=rest_sticks-sticks;
                 if(rest_sticks==1){
                      printf("\n PLAYER_2 HAS WON THE GAME");
                      break;
                 }
                 else if(rest_sticks==0){
                      printf("\n PLAYER_1 HAS WON THE GAME");
                      break;
                 
                 }
            }
            }
            else if(t==player_2){
                printf("\n PLAYER_2 WON THE TOSS\n");
                while(1){
               
               e1:  printf("\n PLAYER_2:");
                 scanf("%d",&sticks);
                 if(sticks<1 || sticks>3 || sticks>rest_sticks){
                     printf("\n NOT PERMITED.TRY AGAIN");
                     goto e1;
                 }
                 rest_sticks-=sticks;
                 if(rest_sticks==1){
                      printf("\n PLAYER_2 HAS WON THE GAME");
                      break;
                 }
                 else if(rest_sticks==0){
                      printf("\n PLAYER_1 HAS WON THE GAME");
                      break;
                 
                 }
                 printf("\n PLAYER_1:");
               f1:  scanf("%d",&sticks);
                  if(sticks<1 || sticks>3 || sticks>rest_sticks){
                     printf("\n NOT PERMITED.TRY AGAIN");
                     goto f1;
                 }
                 rest_sticks=rest_sticks-sticks;
                 if(rest_sticks==1){
                      printf("\n PLAYER_1 HAS WON THE GAME");
                      break;
                 }
                 else if(rest_sticks==0){
                      printf("\n PLAYER_2 HAS WON THE GAME");
                      break;
                 
                 }
            }
            }
}
int main(){
          int n,ch;
          root* start=NULL;
         
         while(1){
                   printf("\n\n####################################");
                   printf("\n-----------STICK GAME-------------");
                   printf("\n----------------------------------");
                   printf("\n HOW MUCH STICK WITH YOU WANT TO PLAY:\n");
                   scanf("%d",&n);
                   printf("\n1. PLAY WITH FRIEND");
                   printf("\n2. PLAY WITH COMPUTER");
                   printf("\n3. PLAY COMPUTER VS COMPUTER");
                   printf("\n4. EXIT");
                   printf("\n5. ENTER YOUR CHOICE:\n");
                   scanf("%d",&ch);

                   switch(ch){

                       case 1:
                                two_player(n);

                       break;
                       case 2:

                       break;
                       case 3:

                       break;
                       case 4:
                       exit(0);
                       break;
                       default:
                       printf("\n ENTER THE RIGHT CHOICE");
                       break;

                   }
 
         }

return 0;
}


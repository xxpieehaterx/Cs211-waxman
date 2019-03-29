#include <iostream>
using namespace std;

int main() {
   //chessboard
   int q[8][8] = {};
   int r = 0, c = 0;
   q[r][c] = 1;

nextCol:
   // Moves to the next column
   c++;
   if (c==8){
      goto print;
   }
   r = -1;

nextRow:
   // Moves to the next row
   r++;
   if (r==8){
      goto backtrack;
   }

   // If there is a queen in the same row (to the left), goto nextRow
   for (int i=0;i<=c-1;i++){
      if (q[r][i] ==1){ goto nextRow;
      }
   }
   // If there is a queen in the upper-left diagonal  
   for (int i = 1; (r-i>=0) && (c-i>=0); i++){
      if (q[r-i][c-i] ==1){
         goto nextRow;
      }
   }

   // If there is a queen in the lower-left diagonal, 
   for (int i = 1; (r+i<8) && (c-i>=0); i++) {
      if (q[r+i][c-i] ==1){
         goto nextRow;
      }
   }

   // Places a queen in the current square 
   q[r][c] =1;
   goto nextCol;

backtrack:
   c-=1; // Moves to the previous column
   if (c<0){
      return 0;
   }
   for(int i=0;i<8;i++){
      if(q[i][c] ==1){
         q[i][c] =0; 
         r=i; 
         goto nextRow;
      }
   }



print:
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions<< ":\n";
	//print out queens
   for(int i=0;i<8;i++){
      cout<<endl;
      for(int j=0; j<8;j++){
         cout<< q[i][j];
      }
   }
   cout<<endl;
   goto backtrack;
}
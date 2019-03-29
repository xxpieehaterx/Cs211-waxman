#include <iostream>
#include <cmath>
using namespace std;

// test if previous queens conflict with current colum
bool ok(int q[], int c) {
   for(int i = 1;i <= c; i ++){ 
      if(q[c] == q[i-1] || q[c-i] == q[c]-i || q[c-i] == q[c]+i) 
         return false;
   }
   return true;
}
void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
   // Print the array
   for(int i = 0; i < 8; i++)
      cout << q[i];

   cout << "\n";
}

int main() {
    //start array
   int q[8]={0};   
   int r = 0, c = 0;
   
    //next colum then print if its the last colum
   while (c >= 0){
      c++;                    
      if(c == 8){
         print(q);
         c--;
         r = q[c]; 
      }
      else
         r = -1;
         
    //next row
      while (c >= 0) {
         r++;
         q[c] = r;

         if(r == 8){
            c --;
            r = q[c];
         }
        //test queen
         else if(ok(q,c)){
            break;
         }

      }
   }
   return 0;
}
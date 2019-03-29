#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int q[8] = {0};
	int r = 0, c = 0;
    
    q[0] = 0;
	
nextCol:
	//next colum
	c++;
	if (c==8){
      goto print;
   }
   q[c] = -1;
   
 nextRow:
	//next row
	q[c]++;
	if (q[c]==8){
      goto backtrack;
   }
   
   //row test
   for(int i = 0; i < c; i++)
        if((q[i] == q[c]) || (abs(q[c] - q[i])== c-1))) goto nextRow;
	
	goto nextCol;

backtrack:
	c--;
    if(c == -1) return 0;
    
    goto nextRow;
	
print:
	static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions<< ":\n";
	//print out queens
   for(int i=0;i<8;i++){
       cout<<endl;
      for(int j=0; j<8;j++){
         if(q[i]==j){
			 cout<<"1";
		 }
		 else{
			 cout<<"0";
		 }
      }
   }
   cout<<endl;
   goto backtrack;
}
	
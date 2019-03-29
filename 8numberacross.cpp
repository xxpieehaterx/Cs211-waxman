#include<iostream>
#include<cmath>
using namespace std;
bool test( int q[8], int c ){
    int checkList[][5] = {
        { -1 },
        { 0, -1 },
        { 0, -1 },
        { 0, 1, 2, -1 },
        { 0, 1, 3, -1 },
        { 1, 4, -1 },
        { 2, 3, 4, -1 },
        { 3, 4, 5, 6, -1 }};
    
	//row test
	for ( int i = 0 ; i < c ; ++i )
		if ( q[i] == q[c] )
			return false;
	//adjacent test
	for ( int i = 0 ; checkList[c][i] != -1 ; ++i )
	{
		if (abs( q[c] - q[ checkList[c][i] ] ) == 1 )
			return false;
	}
	return true;
}

void backtrack(int &c){
    c--;
    
    if(c == -1){
        exit(1);
    }
}

void print(int q[]){    
    cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << " ";
    cout << endl << endl << endl;
}

int main(){
    int q[8], c = 0;
    bool n=false;
    
    while(true){
		//back tracking
        while(c<8){
            if(!n)
                q[c] = -1;
            n = false;
            
        while(q[c]<8){
            q[c]++;
            //print solution     
            if(q[c] == 8){
                backtrack(c);
                continue;
                } 
                if(test(q,c) ) 
				break;
            } 
            c++;
        } 
        
        print(q);
        backtrack(c);
        n = true;
    }
    return 0;
}
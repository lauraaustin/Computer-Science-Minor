#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int seed = 0;
    int guess = 0;
    int guess2= 0;
    const int ten = 10;
    
    //ask for seed
    cout << "Enter Seed: ";
    cin >> seed;
    //randomize the numbers
    srand(seed);
    int a = rand()%10;
    int b = rand()%10;
    int c = rand()%10;
    int d = rand()%10;
    char again = 'y';
    // make sure none of the numbers repeat
    while (a==b || a==c || a==d || b==c || b==d || c==d){
        seed = seed + 1;
        srand(seed);
        a = rand()%10;
        b = rand()%10;
        c = rand()%10;
        d = rand()%10;
    }
    //create vector for target number
    vector <int> index;
    index.push_back(a);
    index.push_back(b);
    index.push_back(c);
    index.push_back(d);
    
    
    cout << "Number to guess: " <<a<<b<<c<<d << endl;
    //FIXME  run game again
    while (again =='y'){
        
        //ask for input
        cout << "Enter your guess: ";
        int bulls=0;
        while (bulls !=4){
            
        while(cin >> guess){
            
            guess2 = guess;
            
            //break integer into digits
            int aa = guess /1000;
            guess = guess % 1000;
            int bb = guess/100;
            guess = guess % 100;
            int cc = guess/10;
            guess = guess %10;
            int dd = guess;
           
            //check if the copy has four numbers
            for(int i=0; i<4;i++){
                guess2 = guess2/ten;
            }
            if(guess2 !=0){
                cout << "You can only enter four digits." << endl;
                cout << "Enter your guess: ";
            }
            //check if all inputs are different
            if(aa==bb|| aa==cc || aa==dd || bb==cc || bb==dd || cc==dd){
                cout << "Each number must be diffent." << endl;
                cout << "Enter your guess: ";
            }
            else if (guess2==0 && (aa!=bb|| aa!=cc || aa!=dd || bb!=cc || bb!=dd || cc!=dd)){
          
            //create a vector for the valid inputs
            vector <int> guessV;
            guessV.push_back(aa);
            guessV.push_back(bb);
            guessV.push_back(cc);
            guessV.push_back(dd);
            unsigned int bulls = 0;
            unsigned int cows =0;
            if (aa==a){ //check if they are bulls
                bulls+=1;
            }
            else if (aa==b || aa==c || aa == d){
                cows +=1;
            }
            if (bb==b){
                bulls+=1;
            }
            else if (bb==a|| bb==c || bb==d){
                cows +=1;
            }
            if (cc==c){
                bulls+=1;
            }
            else if (cc==a|| cc==b || cc==d){
                cows +=1;
            }
            if (dd==d){
                bulls+=1;
            }
            else if (dd==a|| dd==c || dd==b){
                cows +=1;
            }
            
            
            if (bulls == 4 ){
                cout << bulls << " bulls - " << a<< b << c << d << " is Correct!" << endl;
                break;
            }
            else {
                
                cout << bulls << " bulls"<< endl;
                cout << cows << " cows" << endl;
            }
        }
            cout << "Enter your guess: ";
        }
            break;
        }
        cout << "Enter 'y' to play again: ";
        cin >> again;
        
    }
    cout << "Goodbye"<< endl;
    return 0;
}

//DISPLAY 2.15 A do-while Loop
#include <iostream>
using namespace std;
int main( )
{
    char ans;

    // Write your code here using do-while loop
    //
    do {
        cout << "Do you want to repeat? (y/n) ";
        cin >> ans;
        cout << "Hello" << endl;
    } while(ans == 'y');

    return 0;
}

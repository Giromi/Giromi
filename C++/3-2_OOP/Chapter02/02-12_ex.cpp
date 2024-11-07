//DISPLAY 2.12 A while Loop
#include <iostream>
using namespace std;
int main( )
{
    int countDown;
    cout << "How many greetings do you want? ";
    cin >> countDown;

    // Write your code here using While loop
    while (countDown--) {
        cout << "Hello ";
    }

    cout << endl;
    cout << "That's all!\n";

    return 0;
}

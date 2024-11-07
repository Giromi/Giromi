#include <iostream>

int main(void) {
    const int N = 10;
    const int target = 5;

    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    bool found = false;
    while((i < N) && !found)
        if (a[i] == target)
            found = true;
        else
            i++;
    std::cout << i << std::endl;
  
}

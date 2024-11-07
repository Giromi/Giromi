#include <stdio.h>

struct Position {
    int x;
    int y;
    int z;
} typedef Position;

struct Orientation {
    int roll;
    int pitch;
    int yaw;
} typedef Orientation;

struct Drone {
    Position position;
    Orientation orientation;
} typedef Drone;

void my_first_level(void) {
    Drone drone1;
    Drone drone[10];
    printf("Size of Drone: %ld\n", sizeof(Drone));
    printf("Size of Drone: %ld\n", sizeof(drone));
   for (int i = 0; i < 10; i++) {
        drone[i].position.x = i;
        drone[i].position.y = i;
        drone[i].position.z = i;
        drone[i].orientation.roll = i;
        drone[i].orientation.pitch = i;
        drone[i].orientation.yaw = i;
    }

    for (int i = 0; i < 10; i++) {
        printf("Drone %d\n", i);
        printf("Position: x=%d, y=%d, z=%d\n", drone[i].position.x, drone[i].position.y, drone[i].position.z);
        printf("Orientation: roll=%d, pitch=%d, yaw=%d\n", drone[i].orientation.roll, drone[i].orientation.pitch, drone[i].orientation.yaw);
    }
}

int main() {
    my_first_level();
    return 0;
}

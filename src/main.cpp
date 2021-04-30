#include <iostream>
#include "pid.h"
#include <cstdlib>
#include <unistd.h>

int main() {

    PidController pid(.1, .05, .05, 5);
    float processValue = 0;
    const float ROUNDS = 1000;
    unsigned int microseconds = 100000;

    for (size_t i = 0; i < ROUNDS; i++) {
        printf("Process: %.3f\t", processValue);
        processValue += pid.update(processValue);
        printf("%.3f\n", processValue);
        usleep(microseconds);
    }
    

    return 0;

    while (1) {
        printf("Process: %.3f\t", processValue);
        //processValue += pid.update(processValue);
        printf("%.3f\n", processValue);
        usleep(1000);
        std::system("clear");
    }
    
}
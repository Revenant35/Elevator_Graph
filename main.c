#include <stdio.h>
#include "Elevator.h"

int main() {
//    solve(1, 1, 1, 0, 0);
    for(short f = 1; f <= 100; f++){
        for(short s = 1; s <= f; s++){
            for(short g = 1; g <= f; g++){
                for(short u = 0; u <= 100; u++){
                    for(short d = 0; d <= 100; d++){
                        solve(f, s, g, u, d);
                    }
                }
            }
        }
    }
    return 0;
}

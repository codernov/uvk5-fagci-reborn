#ifndef FASTSCAN_H
#define FASTSCAN_H

#include "../driver/keyboard.h"
#include <stdbool.h>
#include <stdint.h>

void FASTSCAN_init();
void FASTSCAN_update();
bool FASTSCAN_key(KEY_Code_t key, bool bKeyPressed, bool bKeyHeld);
void FASTSCAN_render();
void FASTSCAN_deinit();


#endif /* end of include guard: FASTSCAN_H */

#ifndef MESSENGER_H
#define MESSENGER_H

#include "../driver/keyboard.h"
#include <stdbool.h>
#include <stdint.h>

void MESSENGER_init();
void MESSENGER_update();
bool MESSENGER_key(KEY_Code_t key, bool bKeyPressed, bool bKeyHeld);
void MESSENGER_render();
void MESSENGER_deinit();
void MSG_EnableRX(const bool enable);

#endif /* end of include guard: MESSENGER_H */

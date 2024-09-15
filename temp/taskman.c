#include "taskman.h"
#include "../misc.h"
#include "../scheduler.h"
#include "../ui/graphics.h"
#include "apps.h"

void TASKMAN_Init(void) { }

void TASKMAN_Render(void) {
  UI_ClearScreen();
  for (uint8_t i = 0; i < ARRAY_SIZE(tasks); ++i) {
    Task *t = &tasks[i];
    if (t->handler) {
      PrintSmall(0, 8 + 5 + 6 * i, "%s: %u", t->name, t->priority);
    }
  }
}

bool TASKMAN_Key(KEY_Code_t key, bool bKeyPressed, bool bKeyHeld) {
  if (bKeyPressed && !bKeyHeld) {
    switch (key) {
    case KEY_EXIT:
      APPS_exit();
      return true;
    default:
      break;
    }
  }
  return false;
}

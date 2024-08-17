#include "settings.h"
#include "driver/eeprom.h"
#include "scheduler.h"

Settings gSettings;

uint8_t BL_TIME_VALUES[7] = {0, 5, 10, 20, 60, 120, 255};
const char *BL_TIME_NAMES[7] = {"Off",  "5s",   "10s", "20s",
                                "1min", "2min", "On"};

const char *BL_SQL_MODE_NAMES[3] = {"Off", "On", "Open"};
const char *TX_POWER_NAMES[3] = {"Low", "Mid", "High"};
const char *TX_OFFSET_NAMES[3] = {"Unset", "+", "-"};
const char *TX_CODE_TYPES[4] = {"None", "CT", "DCS", "-DCS"};
const char *rogerNames[4] = {"None", "Moto", "Tiny", "Call"};
const char *dwNames[3] = {"Off", "TX Stay", "TX Switch"};
const char *EEPROM_TYPE_NAMES[8] = {
    "none 1",          // 000
    "none 2",          // 001
    "BL24C64 (stock)", // 010
    "BL24C128",        // 011
    "BL24C256",        // 100
    "BL24C512",        // 101
    "BL24C1024",       // 110
    "M24M02 (x1)",     // 111
};

const uint32_t EEPROM_SIZES[8] = {
    8192,   // 000
    8192,   // 001
    8192,   // 010
    16384,  // 011
    32768,  // 100
    65536,  // 101
    131072, // 110
    262144, // 111
};

const uint16_t PAGE_SIZES[8] = {
    32,  // 000
    32,  // 001
    32,  // 010
    64,  // 011
    64,  // 100
    128, // 101
    128, // 110
    128, // 111
};

void SETTINGS_Save(void) {
  EEPROM_WriteBuffer(SETTINGS_OFFSET, &gSettings, SETTINGS_SIZE);
}

void SETTINGS_Load(void) {
  EEPROM_ReadBuffer(SETTINGS_OFFSET, &gSettings, SETTINGS_SIZE);
}

void SETTINGS_DelayedSave(void) {
  TaskRemove(SETTINGS_Save);
  TaskAdd("Settings save", SETTINGS_Save, 5000, false, 0);
}

uint32_t SETTINGS_GetFilterBound(void) {
  return gSettings.bound_240_280 ? VHF_UHF_BOUND2 : VHF_UHF_BOUND1;
}

uint32_t SETTINGS_GetEEPROMSize(void) {
  return EEPROM_SIZES[gSettings.eepromType];
}

uint16_t SETTINGS_GetPageSize(void) { return PAGE_SIZES[gSettings.eepromType]; }

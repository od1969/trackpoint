#ifndef CONFIG_H
    #define CONFIG_H

    #include "config_common.h"

    #define VENDOR_ID       0x04D8
    #define PRODUCT_ID      0xEE59
    #define DEVICE_VER      0x0001
    #define MANUFACTURER    QMK
    #define PRODUCT         TRACKPOINT-DEMO
    #define DESCRIPTION     Simple demonstration for IBM Trackpoint integration

    #define MATRIX_ROWS 1
    #define MATRIX_COLS 3

    #ifdef PS2_USE_INT
        #define PS2_CLOCK_PORT  PORTB
        #define PS2_CLOCK_PIN   PINB
        #define PS2_CLOCK_DDR   DDRB
        #define PS2_CLOCK_BIT   5
        #define PS2_DATA_PORT   PORTB
        #define PS2_DATA_PIN    PINB
        #define PS2_DATA_DDR    DDRB
        #define PS2_DATA_BIT    6
    
		#define PS2_INT_INIT()  do {    \
		    PCICR |= (1<<PCIE0);        \
		} while (0)
		#define PS2_INT_ON()  do {      \
		    PCMSK0 |= (1<<PCINT5);      \
		} while (0)
		#define PS2_INT_OFF() do {      \
		    PCMSK0 &= ~(1<<PCINT5);     \
		} while (0)
		#define PS2_INT_VECT   PCINT0_vect
    #endif

    #define MATRIX_COL_PINS { F1, F4, F5 }
    #define MATRIX_ROW_PINS { F0 }
    #define UNUSED_PINS

    /* COL2ROW or ROW2COL */
    #define DIODE_DIRECTION COL2ROW

    #define DEBOUNCING_DELAY 5

    #define LOCKING_SUPPORT_ENABLE
    #define LOCKING_RESYNC_ENABLE

    /* key combination for command */
    #define IS_COMMAND() ( \
        keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
    )

#endif

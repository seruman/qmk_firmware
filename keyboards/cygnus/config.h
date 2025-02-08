// Copyright 2023 seruman (@seruman)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// NOTE(selman): See: https://github.com/GEIGEIGEIST/qmk-config-totem/blob/main/totem/config.h

/* Serial settings */
#define USE_SERIAL
/* serial.c configuration for split keyboard */
/* #define SOFT_SERIAL_PIN GP0 */
# define SERIAL_USART_TX_PIN GP0
//#define SPLIT_LAYER_STATE_ENABLE
//#define SPLIT_USB_DETECT
#define SERIAL_USE_MULTI_TRANSACTION
/* communication between sides */
#define SERIAL_PIO_USE_PIO1


#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define TAPPING_TERM 150
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY

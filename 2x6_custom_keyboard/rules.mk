# This file intentionally left blank
MCU = RP2040
QMK_BIN = $(KEYBOARD).uf2
LTO_ENABLE = yes	# Enable link time optimization
BOARD = GENERIC_RP_RP2040

# Bootloader selection
BOOTLOADER = rp2040

# Quantum Painter for SSD1306 128x160
QUANTUM_PAINTER_ENABLE  = yes
QUANTUM_PAINTER_DRIVERS += sh1106_i2c
QUANTUM_LIB_SRC         += i2c_master.c





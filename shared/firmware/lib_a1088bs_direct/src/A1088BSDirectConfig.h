#pragma once

/**
 * @brief Custom Pin Mapping Configuration
 * * Edit this table if your physical wiring or PCB layout differs from the default.
 * Each entry follows the format: { Anode_Pin (Row), Cathode_Pin (Column) }
 * * Orientation:
 * - The first index [8] represents the Rows (0-7).
 * - The second index [8] represents the Columns (0-7).
 * - The third index [2] represents the physical Arduino pins: [0] = Anode, [1] = Cathode.
 */

static const uint8_t CONFIGURABLE_LEDMATRIX_PINOUT[8][8][2] = {
  // Row 0: {Anode, Cathode} for each of the 8 columns
  {{ 2,  3},{ 2,  5},{ 2,  7},{ 2,  9},{ 2, 11},{ 2, 13},{ 2, 15},{ 2, 17}},
  // Row 1
  {{ 4,  3},{ 4,  5},{ 4,  7},{ 4,  9},{ 4, 11},{ 4, 13},{ 4, 15},{ 4, 17}},
  // Row 2
  {{ 6,  3},{ 6,  5},{ 6,  7},{ 6,  9},{ 6, 11},{ 6, 13},{ 6, 15},{ 6, 17}},
  // Row 3
  {{ 8,  3},{ 8,  5},{ 8,  7},{ 8,  9},{ 8, 11},{ 8, 13},{ 8, 15},{ 8, 17}},
  // Row 4
  {{10,  3},{10,  5},{10,  7},{10,  9},{10, 11},{10, 13},{10, 15},{10, 17}},
  // Row 5
  {{12,  3},{12,  5},{12,  7},{12,  9},{12, 11},{12, 13},{12, 15},{12, 17}},
  // Row 6
  {{14,  3},{14,  5},{14,  7},{14,  9},{14, 11},{14, 13},{14, 15},{14, 17}},
  // Row 7
  {{16,  3},{16,  5},{16,  7},{16,  9},{16, 11},{16, 13},{16, 15},{16, 17}}
};

// Override the default library pinout with this configuration
#define LEDMATRIX_PINOUT CONFIGURABLE_LEDMATRIX_PINOUT
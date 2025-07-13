# Connections

## Led matrix 1088B8

### Rows

| Row | Led matrix 1088B8 pins | Arduino pins |
|:---:|:----------------------:|:------------:|
|  1  |           9            |      2       |
|  2  |          14            |      3       |
|  3  |           8            |      4       |
|  4  |          12            |      5       |
|  5  |           1            |      6       |
|  6  |           7            |      7       |
|  7  |           2            |      8       |
|  8  |           5            |      9       |

### Columns

| Column | Led matrix 1088B8 pins | 74HC595 pins |
|:------:|:----------------------:|:------------:|
|   1    |          13            |      15      |
|   2    |           3            |       1      |
|   3    |           4            |       2      |
|   4    |          10            |       3      |
|   5    |           6            |       4      |
|   6    |          11            |       5      |
|   7    |          15            |       6      |
|   8    |          16            |       7      |


## Shift register 74HC595

| 74HC595 pins names                  | 74HC595 pins numbers   | Led matrix 1088B8 pins|  Arduino pins |
|:-----------------------------------:|:----------------------:|:---------------------:|:-------------:|
|   QA                                |          15            |      13      |      -      |
|   QB                                |           1            |       3      |      -      |
|   QC                                |           2            |       4      |      -      |
|   QD                                |           3            |      10      |      -      |
|   QE                                |           4            |       6      |      -      |
|   QF                                |           5            |      11      |      -      |
|   QG                                |           6            |      15      |      -      |
|   QH                                |           7            |      16      |      -      |
|   GND                               |           8            |       -      |      6      |
|   VCC                               |          16            |       -      |      5      |
|   SER(Data)                         |          14            |       -      |     10      |
|   $\overline{ OE}$(Output enable)   |          13            |       -      |      6      |
|   RCLK(Latch)                       |          12            |       -      |     11      |
|   SRCLK(Clock)                      |          11            |       -      |     12      |
|   $\overline{ SRCLR}$(Reset)        |          10            |       -      |      5      |
|   QH'                               |           9            |       -      |      -      |

[Back to README](../README.md)
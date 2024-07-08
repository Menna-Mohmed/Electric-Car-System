#ifndef _DISPLAY_SEG_H
#define _DISPLAY_SEG_H

/* section: INCLUDES*/
#include "Arduino.h"

/* section: functions declarations */
void segment_setup(int seg);
void number_0(int seg_index);
void number_1(int seg_index);
void number_2(int seg_index);
void number_3(int seg_index);
void number_4(int seg_index);
void number_5(int seg_index);
void number_6(int seg_index);
void number_7(int seg_index);
void number_8(int seg_index);
void number_9(int seg_index);
void first_segment(int number);
void second_segment(int number);
void print_ampere_dot(void);
void print_volt_dot(void);
void print_volt(void);

#endif
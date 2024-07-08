#include "display_seg.h"

void segment_setup(int seg)
{
  unsigned int i;
  for(i=seg ;  ((seg-i) != 8) ; i--)
  {
    pinMode(i,OUTPUT);
    
  }
  pinMode(A1,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(3,OUTPUT);
}

void number_0(int seg_index)
{
  digitalWrite(seg_index,0);
  digitalWrite(seg_index-1,0);
  digitalWrite(seg_index-2,0);
  digitalWrite(seg_index-3,0);
}
void number_1(int seg_index)
{
  digitalWrite(seg_index,1);
  digitalWrite(seg_index-1,0);
  digitalWrite(seg_index-2,0);
  digitalWrite(seg_index-3,0);
}
void number_2(int seg_index)
{
  digitalWrite(seg_index,0);
  digitalWrite(seg_index-1,1);
  digitalWrite(seg_index-2,0);
  digitalWrite(seg_index-3,0);
}
void number_3(int seg_index)
{
  digitalWrite(seg_index,1);
  digitalWrite(seg_index-1,1);
  digitalWrite(seg_index-2,0);
  digitalWrite(seg_index-3,0);
}
void number_4(int seg_index)
{
  digitalWrite(seg_index,0);
  digitalWrite(seg_index-1,0);
  digitalWrite(seg_index-2,1);
  digitalWrite(seg_index-3,0);
}
void number_5(int seg_index)
{
  digitalWrite(seg_index,1);
  digitalWrite(seg_index-1,0);
  digitalWrite(seg_index-2,1);
  digitalWrite(seg_index-3,0);
}
void number_6(int seg_index)
{
  digitalWrite(seg_index,0);
  digitalWrite(seg_index-1,1);
  digitalWrite(seg_index-2,1);
  digitalWrite(seg_index-3,0);
}
void number_7(int seg_index)
{
  digitalWrite(seg_index,1);
  digitalWrite(seg_index-1,1);
  digitalWrite(seg_index-2,1);
  digitalWrite(seg_index-3,0);
}
void number_8(int seg_index)
{
  digitalWrite(seg_index,0);
  digitalWrite(seg_index-1,0);
  digitalWrite(seg_index-2,0);
  digitalWrite(seg_index-3,1);
}
void number_9(int seg_index)
{
  digitalWrite(seg_index,1);
  digitalWrite(seg_index-1,0);
  digitalWrite(seg_index-2,0);
  digitalWrite(seg_index-3,1);
}


void first_segment(int number)
{
  if(number==0)
  {
    number_0(13);
  }
  else if(number==1)
  {
    number_1(13);
  }
  else if(number==2)
  {
    number_2(13);
  }
  else if(number==3)
  {
    number_3(13);
  }
  else if(number==4)
  {
    number_4(13);
  }
  else if(number==5)
  {
    number_5(13);
  }
  else if(number==6)
  {
    number_6(13);
  }
  else if(number==7)
  {
    number_7(13);
  }
  else if(number==8)
  {
    number_8(13);
  }
  else if(number==9)
  {
    number_9(13);
  }
  
}
void second_segment(int number)
{
  if(number==0)
  {
    number_0(9);
  }
  else if(number==1)
  {
    number_1(9);
  }
  else if(number==2)
  {
    number_2(9);
  }
  else if(number==3)
  {
    number_3(9);
  }
  else if(number==4)
  {
    number_4(9);
  }
  else if(number==5)
  {
    number_5(9);
  }
  else if(number==6)
  {
    number_6(9);
  }
  else if(number==7)
  {
    number_7(9);
  }
  else if(number==8)
  {
    number_8(9);
  }
  else if(number==9)
  {
    number_9(9);
  }
  
}

void print_ampere_dot(void)
{
  digitalWrite(A1,0);
  digitalWrite(A3,1);
  digitalWrite(A4,0);
  digitalWrite(3,0);
}
void print_volt(void)
{
  digitalWrite(A1,1);
  digitalWrite(A3,0);
  digitalWrite(A4,1);
  digitalWrite(3,1);
}
void print_volt_dot(void)
{
  digitalWrite(A1,1);
  digitalWrite(A3,0);
  digitalWrite(A4,1);
  digitalWrite(3,0);
}


#include "stm32f4xx.h"
void printSigmoid(const int a)
{
	 char Msg[100];
	 char *ptr;
	
		 
		 sprintf(Msg, " Y = %x\n ", a);
	 ptr = Msg ;
   while(*ptr != '\0')
	 {
      ITM_SendChar(*ptr);
      ++ptr;
   }
	
	 
}

void printMsg_nor(const int a)
{
	 char Msg[100];
	 char *ptr;
	 sprintf(Msg,"\n  NOR \n");
	 ptr = Msg ;
   while(*ptr != '\0')
	 {
      ITM_SendChar(*ptr);
      ++ptr;
   }
	 sprintf(Msg, "%x", a);
	 ptr = Msg ;
   }	 

void printMsg_and(const int a)
{
	 char Msg[100];
	 char *ptr;
	 sprintf(Msg,"\n  AND \n ");
	 ptr = Msg ;
   while(*ptr != '\0')
	 {
      ITM_SendChar(*ptr);
      ++ptr;
   }
	 sprintf(Msg, "%x", a);
	 ptr = Msg ;
   }	 

void printMsg_or(const int a)
{
	 char Msg[100];
	 char *ptr;
	 sprintf(Msg,"\n  OR \n");
	 ptr = Msg ;
   while(*ptr != '\0')
	 {
      ITM_SendChar(*ptr);
      ++ptr;
   }
	 sprintf(Msg, "%x", a);
	 ptr = Msg ;
   }	 

void printMsg_xor(const int a)
{
	 char Msg[100];
	 char *ptr;
	 sprintf(Msg,"\n  XOR \n");
	 ptr = Msg ;
   while(*ptr != '\0')
	 {
      ITM_SendChar(*ptr);
      ++ptr;
   }
	 sprintf(Msg, "%x", a);
	 ptr = Msg ;
   }	

void printMsg_xnor(const int a)
{
	 char Msg[100];
	 char *ptr;
	 sprintf(Msg,"\n  XNOR \n");
	 ptr = Msg ;
   while(*ptr != '\0')
	 {
      ITM_SendChar(*ptr);
      ++ptr;
   }
	 sprintf(Msg, "%x", a);
	 ptr = Msg ;
   }	

void printMsg_nand(const int a)
{
	 char Msg[100];
	 char *ptr;
	 sprintf(Msg,"\n  NAND \n");
	 ptr = Msg ;
   while(*ptr != '\0')
	 {
      ITM_SendChar(*ptr);
      ++ptr;
   }
	 sprintf(Msg, "%x", a);
	 ptr = Msg ;
   }	

void printMsg_not(const int a)
{
	 char Msg[100];
	 char *ptr;
	 sprintf(Msg,"\n  NOT \n");
	 ptr = Msg ;
   while(*ptr != '\0')
	 {
      ITM_SendChar(*ptr);
      ++ptr;
   }
	 sprintf(Msg, "%x", a);
	 ptr = Msg ;
   }
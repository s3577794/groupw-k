#include "printf.h"
#include "uart.h"

#define MAX_PRINTF_SIZE 256


void printf(char *string,...) {

	va_list ap;
	va_start(ap, string);
    char myNumbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'E', 'F'};


	char buffer[MAX_PRINTF_SIZE];
	int buffer_index = 0;
	char temp_buffer[MAX_PRINTF_SIZE];
	int limiter;
	int multiplier;
	while(1) {
		if (*string == 0)
			break;
		
		if (*string == '%') {
			string++;
			if (*string > 47 && *string < 58) {
				int susi = MAX_PRINTF_SIZE - 1;
				int numreg[MAX_PRINTF_SIZE];
				char neater;
				int numfind = 0;
				multiplier = 1;
				if (*string == '0') {
					neater = '0';
					string++;
				}
				else {
					neater = ' ';
				}
				int reg1 = 0;
				while (!((*string > 96 && *string < 123) || *string == '.')) {
					numreg[reg1] = *string - '0';
					string++;
					reg1++;
				}
				
				while (reg1 >= 0){
					numfind = numfind + (numreg[reg1] * multiplier);
					multiplier = multiplier * 10;
					reg1 = reg1 - 1;
				}
			 	int x = numfind/10;

			 	do {
					temp_buffer[susi] = neater;
					susi--;
                    x = x - 1;
				} while(x > 0);
				if (numfind > 0){
					for(int i = susi + 1; i < MAX_PRINTF_SIZE; i++) {
						buffer[buffer_index] = temp_buffer[i];
						buffer_index++;
					}
			 	}
			}
			limiter = -1;
			if (*string == '.') {
				int numreg[MAX_PRINTF_SIZE];
				int reg1 = 0;
				limiter ++;
				string++;
				while (!(*string > 96 && *string < 123)) {
				 	numreg[reg1] = *string - '0';
				 	string++;
				 	reg1++;
				}
				
				multiplier = 1;
				while (reg1 >= 0){
					limiter = limiter + (numreg[reg1] * multiplier);
					multiplier = multiplier * 10;
					reg1 = reg1 - 1;
				}
				limiter = limiter / 10;
			}

			if (*string == 'd') {
				string++;
				int x = va_arg(ap, int);
				int susi = MAX_PRINTF_SIZE - 1;

				do {
					temp_buffer[susi] = (x % 10) + '0';
					susi--;
                    x /= 10;
				} while(x != 0);

				for(int i = susi + 1; i < MAX_PRINTF_SIZE; i++) {
					buffer[buffer_index] = temp_buffer[i];
					buffer_index++;
				}
			}
			else if (*string == 'x') {
				string++;
				int x = va_arg(ap, int);
				int susi = MAX_PRINTF_SIZE - 1;
				do {
                    temp_buffer[susi] = myNumbers[(x % 16)];
					susi--;
					x /= 16;
				} while(x != 0);

				for(int i = susi + 1; i < MAX_PRINTF_SIZE; i++) {
					buffer[buffer_index] = temp_buffer[i];
					buffer_index++;
				}
			}
            else if (*string == 'c') {
                string++;
				int x = va_arg(ap, int);
				int susi = MAX_PRINTF_SIZE - 1;
                temp_buffer[susi] = x;
				susi--;
                    


				for(int i = susi + 1; i < MAX_PRINTF_SIZE; i++) {
					buffer[buffer_index] = temp_buffer[i];
					buffer_index++;
				}
            }
            else if (*string == 'f') {
				string++;
                double x1;
                x1 = va_arg(ap, double);
				if (x1 == 0){
					x1 = va_arg(ap, int);
				}
				int x, x2;
				int susi = MAX_PRINTF_SIZE - 1;
                int reg[8];
				int reg0[8];
				int reg2;
				int reg3 = 0;
				int rege3;
				
				if (limiter < 0){
					limiter = 6;
				}
				double xy = x1;
				x2 = xy;
				while (x2 != 0) {
					rege3 ++;
					xy /= 10;
					x2 = xy;
				}
				int coutup = limiter;
				xy = x1;
				x2 = xy;
				int coureco = 0;
				if ((limiter) > 7){
					while (coutup > 0){
						if ((reg3 > 0 && coureco == 0)){
							coureco = coutup;
						}
						if (coutup > 6){
							xy = xy * 10000000;
							coutup = coutup - 7;
							reg0[reg3] = 7;
						}
						else{
							reg0[reg3] = coutup;
							while(coutup > 0){
								xy = xy * 10;
								coutup --;
							}
						}
						x2 = xy;
						xy = xy - x2;
						reg[reg3] = x2;
						if (coutup > 0){
							reg3 ++;
						}
					}
					while (reg3 > 0){
						if (reg[reg3] == 0){
							
							do {
								temp_buffer[susi] = (x % 10) + '0';
								susi--;
								x /= 10;
							} while(x != 0);
						}
						else{
							x = reg0[reg3];
							x2 = reg[reg3];
							do {
								temp_buffer[susi] = (x2 % 10) + '0';
								susi--;
								x --;
								x2 /= 10;
							} while(x > 0);
						}
						reg3 --;
					}
				}
				else{
					while(coutup > 0){
						xy = xy * 10;
						coutup --;
					}
					x2 = xy;
					reg[0] = x2;
				}
				x = reg[0];
				int chek = 0;
				reg3 = 0;
                do {
					if (limiter - coureco == reg3 && limiter != 0){
						temp_buffer[susi] = '.';
						chek = 1;
					}
					else{
						temp_buffer[susi] = (x % 10) + '0';
						x /= 10;
						chek = 0;
					}
					susi--;
					reg3 ++;
				} while(x != 0 || chek == 1);


				for(int i = susi + 1; i < MAX_PRINTF_SIZE; i++) {
					buffer[buffer_index] = temp_buffer[i];
					buffer_index++;
				}
			}
			else if (*((string + 1) - 1) == 'o') {
				string++;
				int x = va_arg(ap, int);
				int susi = MAX_PRINTF_SIZE - 1;

				do {
					temp_buffer[susi] = (x % 8) + '0';
					susi--;
                    x /= 8;
				} while(x != 0);

				for(int i = susi + 1; i < MAX_PRINTF_SIZE; i++) {
					buffer[buffer_index] = temp_buffer[i];
					buffer_index++;
				}
			}
			else if (*string == 's') {
				string++;
				char * xchar = va_arg(ap, char*);
				int susi = MAX_PRINTF_SIZE - 1;
				int x = 0;
				while (xchar[x + 1] != '\0'){
					x ++;
				}
				do {
					temp_buffer[susi] = xchar[x];
					susi--;
                    x --;
				} while(x >= 0);

				for(int i = susi + 1; i < MAX_PRINTF_SIZE; i++) {
					buffer[buffer_index] = temp_buffer[i];
					buffer_index++;
				}
			}
		}
		else {
			buffer[buffer_index] = *string;
			buffer_index++;
			string++;
		}

		if (buffer_index == MAX_PRINTF_SIZE - 1)
			break;
	}

	va_end(ap);
    buffer[buffer_index] = '\0';
    

	//Print out formated string
	uart_puts(buffer);
}

#include "printf.h"
#include "uart.h"
#include "mbox.h"
#include "framebf.h"




int pw = 1024, ph = 768, vw = 1024, vh = 768;
int Compare_Strings(char *Str1, char *Str2, int num){
	//shift characters by 'num' letter.
	int i = 0;
	i = 0;
	if(Str1[i] == '\0') {
		return 1;
	}
  	while(Str1[i+num] == Str2[i])
  	{
  		if(Str1[i+num] == '\0' || Str2[i] == '\0') {
			break;
		}
		i++;
	}

	//Check space (allow space by-pass)
	if(Str1[i+num] == 0xA0 || Str1[i] == 0x20 ){
		Str1[i+num] = '\0';
	}

	return Str1[i+num] - Str2[i];
}














int Color(char* Str1, int second, int cli5){
	//ex: setcolor[first commnad] -b[second command] black[third input]
	int i = 0;
	char z[15];
	char o[15];
	int a = 0;
	int x = 9;
	int y = 9;
	int j = 0;
	//skip the first command
	while (Str1[i] != 0xA0 && Str1[i] != 0x20 && Str1[i] != '\0' ){
		i++;
	}
	i++;

	//get and skip the second command
	
	while (Str1[i] != 0xA0 && Str1[i] != 0x20 && Str1[i] != '\0' ){
		z[a] = Str1[i]; 
		i++;
		a++;
	}

	int stop = 0;
	char z1[3] = "-t", z2[3] = "-b", z3[3] ="-p", z4[3] = "-v", z5[3] = "-c", z6[3] ="-s", z7[3] = "-w";
	for(a=0; a<15; a++){
		if(z[a] == '\0'){
			break;
		}
		if(z[a] != z1[a]){
			x = 10;
			stop = 0;
			break;
			
		}
		x=0;
		stop = 1;
	}
	if (stop == 0){
		for(a=0; a<15; a++){
			if(z[a] =='\0'){
				break;
			}
			if(z[a] != z2[a]){
				x = 10;
				stop = 0;
				break;
			}
			x=1;
			stop = 1;
		}
	}
	if (stop == 0){
		for(a=0; a<15; a++){
			if(z[a] =='\0'){
				break;
			}
			if(z[a] != z3[a]){
				x = 10;
				stop = 0;
				break;
			}
			x=2;
			stop = 1;
		}
	}
	if (stop == 0){
		for(a=0; a<15; a++){
			if(z[a] =='\0'){
				break;
			}
			if(z[a] != z4[a]){
				x = 10;
				stop = 0;
				break;
			}
			x=3;
			stop = 1;
		}
	}
		if (stop == 0){
		for(a=0; a<15; a++){
			if(z[a] =='\0'){
				break;
			}
			if(z[a] != z5[a]){
				x = 10;
				stop = 0;
				break;
			}
			x=4;
			stop = 1;
		}
	}
	if (stop == 0){
		for(a=0; a<15; a++){
			if(z[a] =='\0'){
				break;
			}
			if(z[a] != z6[a]){
				x = 10;
				stop = 0;
				break;
			}
			x=5;
			stop = 1;
		}
	}
	if (stop == 0){
		for(a=0; a<15; a++){
			if(z[a] =='\0'){
				break;
			}
			if(z[a] != z7[a]){
				x = 10;
				stop = 0;
				break;
			}
			x=6;
			stop = 1;
		}
	}

	
	i++;
	//get and skip the third input
	a = 0;
	while (Str1[i] != 0xA0 && Str1[i] != 0x20 && Str1[i] != '\0' ){
		o[a] = Str1[i]; 
		i++;
		a++;
	}
	i++;
	

	if (x==1||x==0||x==6){
		stop = 0;
		char o1[6] = "black", o2[4] = "red", o3[6] = "green", o4[7] = "yellow", o5[5] = "blue", o6[7] = "purple", o7[5] = "cyan", o8[6] = "white";
		for(a=0; a<15; a++){
			if(o[a] == '\0'){
				break;
			}
			if(o[a] != o1[a]){
				y = 9;
				stop = 0;
				break;
				
			}
			y=0;
			stop = 1;
		}
		if (stop == 0){
			for(a=0; a<15; a++){
				if(o[a] =='\0'){
					break;
				}
				if(o[a] != o2[a]){
					y = 9;
					stop = 0;
					break;
				}
				y=1;
				stop = 1;
			}
		}
		if (stop == 0){
			for(a=0; a<15; a++){
				if(o[a] =='\0'){
					break;
				}
				if(o[a] != o3[a]){
					y = 9;
					stop = 0;
					break;
				}
				y=2;
				stop = 1;
			}
		}
		if (stop == 0){
			for(a=0; a<15; a++){
				if(o[a] =='\0'){
					break;
				}
				if(o[a] != o4[a]){
					y = 9;
					stop = 0;
					break;
				}
				y=3;
				stop = 1;
			}
		}
		if(stop == 0){
			for(a=0; a<15; a++){
				if(o[a] == '\0'){
					break;
				}
				if(o[a] != o5[a]){
					y = 9;
					stop = 0;
					break;
					
				}
				y=4;
				stop = 1;
			}	
		}
		if (stop == 0){
			for(a=0; a<15; a++){
				if(o[a] =='\0'){
					break;
				}
				if(o[a] != o6[a]){
					y = 9;
					stop = 0;
					break;
				}
				y=5;
				stop = 1;
			}
		}
		if (stop == 0){
			for(a=0; a<15; a++){
				if(o[a] =='\0'){
					break;
				}
				if(o[a] != o7[a]){
					y = 9;
					stop = 0;
					break;
				}
				y=6;
				stop = 1;
			}
		}
		if (stop == 0){
			for(a=0; a<15; a++){
				if(o[a] =='\0'){
					break;
				}
				if(o[a] != o8[a]){
					y = 9;
					stop = 0;
					break;
				}
				y=7;
				stop = 1;
			}
		}
	}
	j = x*10 + y;
	if((x == 2 || x == 3 || x == 4) && cli5 == 1){
		//get the second number
		
		if (second == 1){
			a=0;
			while (Str1[i] != 0xA0 && Str1[i] != 0x20 && Str1[i] != '\0' ){
				o[a] = Str1[i]; 
				i++;
				a++;
			}
		}
		j = 0;
		for (int i = 0; o[i] != '\0'; ++i) {
			if (o[i]> '9' || o[i]<'0')
				return 10;
			j = j*10 + o[i] - '0';
		}
	}
	return j;
} 













int TAB (char* Str1){
	int i, a, j;
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0, x9 = 0, x10 = 0;
	char CLI1[5] = "help", CLI2[9] = "setcolor", CLI3[4] = "cls", CLI4[7] = "brdrev", CLI5[8] = "scrsize", CLI6[8] = "movcsor", CLI7[7] = "quit", CLI8[7] = "clrscr", CLI9[4] = "res", CLI10[4] = "atk";
	char Str[10];

	for(a=0; a<10; a++){
		Str[a] = CLI1[a];
	}
	for (a = 0; Str[a] != '\0' && Str[a] == Str1[a]; a++){
		x1++;
	}


	for(a=0; a<10; a++){
		Str[a] = CLI2[a];
	}
	for (a = 0; Str[a] != '\0' && Str[a] == Str1[a]; a++){
		x2++;
		}


	for(a=0; a<10; a++){
		Str[a] = CLI3[a];
	}
	for (a = 0; Str[a] != '\0' && Str[a] == Str1[a]; a++){
		x3++;
	}


	for(a=0; a<10; a++){
		Str[a] = CLI4[a];
	}
	for (a = 0; Str[a] != '\0' && Str[a] == Str1[a]; a++){
		x4++;
	}


	for(a=0; a<10; a++){
		Str[a] = CLI5[a];
	}
	for (a = 0; Str[a] != '\0' && Str[a] == Str1[a]; a++){
		x5++;
	}


	for(a=0; a<10; a++){
		Str[a] = CLI6[a];
	}
	for (a = 0; Str[a] != '\0' && Str[a] == Str1[a]; a++){
		x6++;
	}


	for(a=0; a<10; a++){
		Str[a] = CLI7[a];
	}
	for (a = 0; Str[a] != '\0' && Str[a] == Str1[a]; a++){
		x7++;
	}


	for(a=0; a<10; a++){
		Str[a] = CLI8[a];
	}
	for (a = 0; Str[a] != '\0' && Str[a] == Str1[a]; a++){
		x8++;
	}


	for(a=0; a<10; a++){
		Str[a] = CLI9[a];
	}
	for (a = 0; Str[a] != '\0' && Str[a] == Str1[a]; a++){
		x9++;
	}


	for(a=0; a<10; a++){
		Str[a] = CLI10[a];
	}
	for (a = 0; Str[a] != '\0'&& Str[a] == Str1[a]; a++){
		x10++;
	}

	j=x1;
	int check = 1;
	if(j < x2){
		j=x2;
		check = 2;
	}
	if(j < x3){
		j=x3;
		check = 3;
	}
	if(j < x4){
		j=x4;
		check = 4;
	}
	if(j < x5){
		j=x5;
		check = 5;
	}
	if(j < x6){
		j=x6;
		check = 6;
	}
	if(j < x7){
		j=x7;
		check = 7;
	}
	if(j < x8){
		j=x8;
		check = 8;
	}
	if(j < x9){
		j=x9;
		check = 9;
	}
	if(j < x10){
		j=x10;
		check = 10;
	}
	if(j < x1){
		j=x1;
		check = 1;
	}
	printf("%d",j);

	int jar;
	if(check == 2){
		jar = 2;
	}
	if(check == 3){
		jar = 3;
	}
	if(check == 4){
		jar = 4;
	}
	if(check == 5){
		jar = 5;
	}
	if(check == 6){
		jar = 6;
	}
	if(check == 7){
		jar = 7;
	}
	if(check == 8){
		jar = 8;
	}
	if(check == 9){
		jar = 9;
	}
	if(check == 10){
		jar = 10;
	}
	if(check == 1){
		jar = 1;
	}
	j = jar;
	if(x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0 && x5 == 0 && x6 == 0 && x7 == 0 && x8 == 0 && x9 == 0 && x10 == 0){
		j = 0;
	}
	return j;
}
















void main()
{
	int enter_activated;
	
	
	// set up serial console
	uart_init();
	
	mBuf[0] = 8*4; // Message Buffer Size in bytes (8 elements * 4 bytes (32 bit) each)
    mBuf[1] = MBOX_REQUEST; // Message Request Code (this is a request message)
    mBuf[2] = 0x00030002; // TAG Identifier: Get clock rate
    mBuf[3] = 8; // Value buffer size in bytes (max of request and response lengths)
    mBuf[4] = 0; // REQUEST CODE = 0
    mBuf[5] = 3; // clock id: ARM system clock
    mBuf[6] = 0; // clear output buffer (response data are mbox[5] & mbox[6])
    mBuf[7] = MBOX_TAG_LAST;

	uart_puts("#     # ####### #        #####  ####### #     # #######    ####### ####### \n#  #  # #       #       #     # #     # ##   ## #             #    #     # \n#  #  # #       #       #       #     # # # # # #             #    #     # \n#  #  # #####   #       #       #     # #  #  # #####         #    #     # \n#  #  # #       #       #       #     # #     # #             #    #     # \n#  #  # #       #       #     # #     # #     # #             #    #     # \n ## ##  ####### #######  #####  ####### #     # #######       #    ####### \n																			\n				#     # #     #          #######  #####                  \n				##   ##  #   #           #     # #     #                 \n				# # # #   # #            #     # #                       \n				#  #  #    #             #     #  #####                  \n				#     #    #             #     #       #                 \n				#     #    #             #     # #     #                 \n				#     #    #             #######  #####                  \n");
                                                                            	
	// Initialize frame buffer
	framebf_init(pw, ph, vw, vh);

	// Draw something on the screen
	drawRectARGB32(0,0,1024,768,0x00AA0000,1); //RED
	
	// echo everything back
	char z[40];
	int i = 0;
	while(1) {
		char lamb[40];
		
		//read each char
		enter_activated = 0;
		char c = uart_getc();

		//detect enter and clear memory
		if (c == 0x0A){
			int pw = 1024, ph = 768, vw = 1024, vh = 768;
			//CLI commands
			char CLI1[5] = "help", CLI2[9] = "setcolor", CLI3[4] = "cls", CLI4[7] = "brdrev", CLI5[8] = "scrsize", CLI6[8] = "movcsor", CLI7[7] = "quit", CLI8[7] = "clrscr", CLI9[4] = "res", CLI10[4] = "atk";
			if (Compare_Strings(z, CLI10, 0) == 0 ) {
				i=0;
				while(i<=40) {
					if (z[i != lamb[i]]){
						z[i] = lamb[i];
					}
					if (z[i] == '\0' && lamb[i] == '\0'){
						break;
					}
					i++;
				}

			}
			if (Compare_Strings(z, CLI1, 0) == 0 ) {
				if (Compare_Strings(z, CLI1, 5) == 0 ) {
					uart_puts("\nShow brief information of all commands\nhelp <command_name>: Show full information of the command\nExample: help setcolor\n");
				};

				if (Compare_Strings(z, CLI2, 5) == 0 ) {
					uart_puts("\nSet text color, and/or background color of the console to one of the following color: BLACK, RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, WHITE.\nExample: setcolor -b yellow\n");
				};
				
				if (Compare_Strings(z, CLI3, 5) == 0 ) {
					uart_puts("\nClear screen\n");
				};
				
				if (Compare_Strings(z, CLI4, 5) == 0 ) {
					uart_puts("\nShow board revision\n");
				};
				
				if (Compare_Strings(z, CLI5, 5) == 0 ) {
					uart_puts("\nSet Screen Size\nMust have options to set physical screen size (-p) or virtual screen size (-v), or both (by default)\nExample: scrsize -p 1024 768\n");
				};
				
				if (Compare_Strings(z, CLI6, 5) == 0 ) {
					uart_puts("\nmove cursor to another location\nExample: movcsor -c 10 10\n");
				};

				if (Compare_Strings(z, CLI7, 5) == 0 ) {
					uart_puts("\nquit the program\n");
				};
				
				if (Compare_Strings(z, CLI8, 5) == 0 ) {
					uart_puts("\nclear up the display\n");
				};
				
				if (Compare_Strings(z, CLI9, 5) == 0 ) {
					uart_puts("\nresist\n");
				};
				
				if (Compare_Strings(z, CLI10, 5) == 0 ) {
					uart_puts("\nexecute the last command\n");
				};
				
				if (Compare_Strings(z, "", 5) == 0 ) {
					uart_puts("\nCLI available:\n1.help\n2.setcolor\n3.cls\n4.brdrev\n5.scrsize\n6.movcsor\n7.tnsize\n8.clrscr\n9.res\n10.atk\n");
				};
				
			}
			if (Compare_Strings(z, CLI2, 0) == 0 ) {
				int c1 = Color(z, 0, 0);
				if (c1 == 0){
					uart_puts("\n\e[30mblack text");
				}
				if (c1 == 1){
					uart_puts("\n\e[31mred text");
				}
				if (c1 == 2){
					uart_puts("\n\e[32mgreen text");
				}
				if (c1 == 3){
					uart_puts("\n\e[33myellow text");
				}
				if (c1 == 4){
					uart_puts("\n\e[34mblue text");
				}
				if (c1 == 5){
					uart_puts("\n\e[35mpurple text");
				}
				if (c1 == 6){
					uart_puts("\n\e[36mcyan text");
				}
				if (c1 == 7){
					uart_puts("\n\e[37mwhite text");
				}
				if (c1 == 10){
					uart_puts("\n\033[40mblack background");
				}
				if (c1 == 11){
					uart_puts("\n\033[41mred background");
				}
				if (c1 == 12){
					uart_puts("\n\033[42mgreen background");
				}
				if (c1 == 13){
					uart_puts("\n\e[33;3myellow background");
				}
				if (c1 == 14){
					uart_puts("\n\033[44mblue background");
				}
				if (c1 == 15){
					uart_puts("\n\033[45mpurple background");
				}
				if (c1 == 16){
					uart_puts("\n\033[46mcyan background");
				}
				if (c1 == 17){
					uart_puts("\n\033[47mwhite background");
				}
			}
			if (Compare_Strings(z, CLI3, 0) == 0 ) {
				//Clear Screen
				uart_puts("\x1B[2J");
			}
			if (Compare_Strings(z, CLI4, 0) == 0 ) {
				uart_puts("\n\n");
				if (mbox_call(ADDR(mBuf), MBOX_CH_PROP)) {
					uart_puts("Response Code for whole message: ");
					uart_hex(mBuf[1]);
					uart_puts("\n");
					uart_puts("Response Code in Message TAG: ");
					uart_hex(mBuf[4]);
					uart_puts("\n");
					uart_puts("DATA: ARM clock rate = ");
					uart_dec(mBuf[6]);
					uart_puts("\n");
				}
			}
			if (Compare_Strings(z, CLI5, 0) == 0 ) {
				
				int s1 = Color(z, 0, 0);
				if(s1 == 29){
					pw = Color(z, 0, 1);
					ph = Color(z, 1, 1);
					vw = pw;
					vh = ph;
					framebf_init(pw, ph, vw, vh);
					drawRectARGB32(0,0,pw,ph,0x00AA0000,1);
				}
				if(s1 == 39){
					vw = Color(z, 0, 1);
					vh = Color(z, 1, 1);
					framebf_init(pw, ph, vw, vh);
					drawRectARGB32(0,0,pw,ph,0x00AA0000,1);
				}
				printf("\nphysical screen size: %d x %d ", pw,ph);
				printf("\nvirtual screen size: %d x %d ", pw,ph);

			}
			if (Compare_Strings(z, CLI6, 0) == 0 ) {
				int b1 = Color(z, 0, 0);
				if(b1 == 49){
					int xx = Color(z, 0, 1);
					int yy = Color(z, 1, 1);
					printf("\n\n\033[%d;%dHHello World", yy, xx);
				}
			}
			if (Compare_Strings(z, CLI7, 0) == 0 ) {
				uart_puts("\nGood Bye");

				break;
			}
			if (Compare_Strings(z, CLI8, 0) == 0 ) {
				pw = 1024, ph = 768, vw = 1024, vh = 768;
				framebf_init(pw, ph, vw, vh);
				drawRectARGB32(0,0,pw,ph,0x00000000,1);
				uart_puts("\nclrscr");
				uart_puts("\n");
			}
			if (Compare_Strings(z, CLI9, 0) == 0 ) {
				framebf_init(pw, ph, vw, vh);
				int clr = Color(z, 0, 0);
				if (clr == 60){
					drawRectARGB32(0,0,pw,ph,0x00000000,1);
				}
				if (clr == 61){
					drawRectARGB32(0,0,pw,ph,0x00AA0000,1);
				}
				if (clr == 62){
					drawRectARGB32(0,0,pw,ph,0x0000BB00,1);
				}
				if (clr == 63){
					drawRectARGB32(0,0,pw,ph,0x00FFFF00,1);
				}
				if (clr == 64){
					drawRectARGB32(0,0,pw,ph,0x000000CC,1);
				}
				if (clr == 65){
					drawRectARGB32(0,0,pw,ph,0x00800080,1);
				}
				if (clr == 66){
					drawRectARGB32(0,0,pw,ph,0x0000FFFF,1);

				}
				if (clr == 67){
					drawRectARGB32(0,0,pw,ph,0x00FFFFFF,1);
				}
			}

			
			
			//clear the string memory
			i = 0;
			while(i<=40) {
				lamb[i] = z[i];
				z[i] = '\0';
				i++;
			}
			i = 0;
			enter_activated = 1;

		}

		//handle tab
		if (c == 0x09){
			char CLI1[5] = "help", CLI2[9] = "setcolor", CLI3[4] = "cls", CLI4[7] = "brdrev", CLI5[8] = "scrsize", CLI6[8] = "movcsor", CLI7[7] = "quit", CLI8[7] = "clrscr", CLI9[4] = "res", CLI10[4] = "atk";
			int tabtab = TAB(z);
			int a;
			if (tabtab == 1){
				for(a=0; CLI1[a] != '\0'; a++ ){
					z[a] = CLI1[a];
					i = a;
				}
			}
			if (tabtab == 2){
				for(a=0; CLI2[a] != '\0'; a++ ){
					z[a] = CLI2[a];
					i = a;
				}
			}
			if (tabtab == 3){
				for(a=0; CLI3[a] != '\0'; a++ ){
					z[a] = CLI3[a];
					i = a;
				}
			}
			if (tabtab == 4){
				for(a=0; CLI4[a] != '\0'; a++ ){
					z[a] = CLI4[a];
					i = a;
				}
			}
			if (tabtab == 5){
				for(a=0; CLI5[a] != '\0'; a++ ){
					z[a] = CLI5[a];
					i = a;
				}
			}
			if (tabtab == 6){
				for(a=0; CLI6[a] != '\0'; a++ ){
					z[a] = CLI6[a];
					i = a;
				}
			}
			if (tabtab == 7){
				for(a=0; CLI7[a] != '\0'; a++ ){
					z[a] = CLI7[a];
					i = a;
				}
			}
			if (tabtab == 8){
				for(a=0; CLI8[8] != '\0'; a++ ){
					z[a] = CLI1[a];
					i = a;
				}
			}
			if (tabtab == 9){
				for(a=0; CLI9[a] != '\0'; a++ ){
					z[a] = CLI9[a];
					i = a;
				}
			}
			if (tabtab == 10){
				for(a=0; CLI10[a] != '\0'; a++ ){
					z[a] = CLI10[a];
					i = a;
				}
			}
			i++;
			uart_puts("\n");
			uart_puts(z);
			enter_activated = 1;

		};
		
		//write character into string
		if(enter_activated == 0){
			z[i] = c;
			i = i+1;
			if (i == 39){
				i = 0;
			}	
		}
		
		//write character into terminal
		uart_sendc(c);
		

	};
	return;
}

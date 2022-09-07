#include "uart.h"
#include "mbox.h"
#include "framebf.h"

void main()
{
    // set up serial console
	uart_init();

	// Initialize frame buffer
	framebf_init();

	drawStringARGB32(200,300,"Le Minh Hoang",0x00AA0000);
	drawStringARGB32(200,320,"Nguyen Truong Thinh",0x0000BB00);
	drawStringARGB32(200,340,"Ta Hien Thuan",0x000000CC);
	drawStringARGB32(200,360,"Vo Hieu Thuan",0x00FFFF00);


	while(1) {

	}
}

#include <stdio.h>
#include "pico/stdlib.h"
#include "jxglib/LABOPlatform.h"

int main()
{
	stdio_init_all();
	jxglib_labo_init(false);
	while (true) {
		printf("Hello, world!\n");
		jxglib_sleep(1000);
	}
}

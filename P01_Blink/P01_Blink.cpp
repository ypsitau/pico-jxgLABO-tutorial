#include <stdio.h>
#include "pico/stdlib.h"
#include "jxglib/LABOPlatform.h"

int msecBlink = 500;

int main()
{
	bool value = true;
	stdio_init_all();
	jxglib_labo_init(false);
	gpio_init(15);
	gpio_set_dir(15, GPIO_OUT);
	while (true) {
		gpio_put(15, value);
		value = !value;
		jxglib_sleep(msecBlink);
	}
}

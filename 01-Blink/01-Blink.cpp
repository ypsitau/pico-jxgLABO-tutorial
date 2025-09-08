#include <stdio.h>
#include "pico/stdlib.h"
#include "jxglib/LABOPlatform.h"

int main()
{
	stdio_init_all();
	jxglib_labo_init(false);
	gpio_init(15);
	gpio_set_dir(15, GPIO_OUT);
	bool value = false;
	while (true) {
		gpio_put(15, value);
		jxglib_sleep(100);
		value = !value;
	}
}

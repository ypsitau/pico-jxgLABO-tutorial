#include <stdio.h>
#include "pico/stdlib.h"
#include "jxglib/LABOPlatform.h"

using namespace jxglib;

bool value = false;

TickableEntry(blink, 100)
{
	gpio_put(15, value);
	value = !value;
}

int main()
{
	stdio_init_all();
	jxglib_labo_init(false);
	gpio_init(15);
	gpio_set_dir(15, GPIO_OUT);
	while (true) {
		jxglib_tick();
	}
}

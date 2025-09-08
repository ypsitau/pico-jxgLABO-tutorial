#include <stdio.h>
#include "pico/stdlib.h"
#include "jxglib/LABOPlatform.h"

using namespace jxglib;

int main()
{
	::stdio_init_all();
	LABOPlatform::Instance.Initialize();
	while (true) {
		Tickable::Tick();
	}
}

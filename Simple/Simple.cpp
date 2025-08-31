#include <stdio.h>
#include "pico/stdlib.h"
#include "jxglib/LABOPlatform.h"

using namespace jxglib;

int main()
{
	LABOPlatform::Instance.Initialize();
    stdio_init_all();

    while (true) {
        Tickable::Tick();
    }
}

#include <stdio.h>
#include "pico/stdlib.h"
#include "jxglib/LABOPlatform.h"

using namespace jxglib;

ShellCmd(test_arg, "show command line arguments")
{
	for (int i = 0; i < argc; i++) {
		tout.Printf("argv[%d]: %s\n", i, argv[i]);
	}
	return Result::Success;
}

ShellCmd(test_tout_terr, "test tout and ter")
{
	tout.Println("This is standard output (tout).");
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			tout.Printf("%3d", i * j);
		}
		tout.Println();
	}
	terr.Println("This is standard error (terr).");
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			terr.Printf("%3d", i * j);
		}
		terr.Println();
	}
	return Result::Success;
}

ShellCmd(test_tin, "test tin")
{
	char buff[128];
	while (true) {
		int len = tin.Read(buff, sizeof(buff) - 1);
		if (len > 0) {
			buff[len - 1] = '\0';
			tout.Printf("You entered: %s\n", buff);
			if (strcmp(buff, "exit") == 0) break;
		}
	}
	return Result::Success;
}

int main()
{
	stdio_init_all();
	jxglib_labo_init(false);
	while (true) {
		jxglib_tick();
	}
}

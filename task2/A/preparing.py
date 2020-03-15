with open('index.h', 'w') as f:
	f.write( "int FirstFunction();")
with open("index.cpp", "w") as f:
    f.write("""
#include "index.h"

int FirstFunction() {
    return 1;
}""")

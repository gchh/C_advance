SRC = ..\test\acllib.c
INCLUDE_DIR = ..\test
LIB = gdi32 ole32 oleaut32 uuid winmm msimg32

all : main 

main :
	gcc $(SRC) $@.c -I$(INCLUDE_DIR) $(LIB:%=-l%) -DWINVER=0x0501 -o $@
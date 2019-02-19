all:
	gcc lua.c -o Clua -llua -lm -ldl -lrt
clean:
	rm -rf Clua

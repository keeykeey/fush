all: ./src/core/fush.c
	gcc -c ./src/core/fush.c
	gcc -c ./src/core/fush_echo.c
	gcc -c ./src/core/fush_touch.c
	mv *.o ./bin/
	gcc -o fush ./bin/fush.o ./bin/fush_echo.o ./bin/fush_touch.o

fush_echo: ./src/core/fush_echo.c
	gcc -c ./src/core/fush_echo.c

fush_touch: ./src/core/fush_touch.c
	gcc -c ./src/core/fush_touch.c

clean:
	rm -f ./*.o ./bin/*.o
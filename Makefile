all: ./src/core/fush.c
	gcc -c ./src/core/fush.c
	gcc -c ./src/core/fush_echo.c
	gcc -c ./src/core/fush_touch.c
	gcc -c ./src/core/fush_cat.c
	mv *.o ./bin/
	gcc -o fush ./bin/fush.o ./bin/fush_echo.o ./bin/fush_touch.o ./bin/fush_cat.o

fush_echo: ./src/core/fush_echo.c
	gcc -c ./src/core/fush_echo.c

fush_touch: ./src/core/fush_touch.c
	gcc -c ./src/core/fush_touch.c

fush_cat: ./src/core/fush_cat.c
	gcc -c ./src/core/fush_cat.c

clean:
	rm -f ./*.o ./bin/*.o
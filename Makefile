all: ./src/core/fush.c
	gcc -c ./src/core/fush.c
	gcc -c ./src/core/fush_echo.c
	mv *.o ./bin/
	gcc -o fush ./bin/fush.o ./bin/fush_echo.o

fush_echo: ./src/core/fush_echo.c
	gcc -c ./src/core/fush_echo.c

clean:
	rm -f ./*.o ./bin/*.o
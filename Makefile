all: ./src/core/fush.c
	gcc -c ./src/core/fush.c
	gcc -c ./src/core/fush_echo.c
	gcc -c ./src/core/fush_string.c
	mv *.o ./bin/
	gcc -o fush ./bin/fush.o ./bin/fush_echo.o ./bin/fush_string.o

fush_echo: ./src/core/fush_echo.c
	gcc -c ./src/core/fush_echo.c

fush_string: ./src/core/fush_string.c
	gcc -c ./src/core/fush_string.c

fush_string_test: ./test/fush_string_test.c
	gcc -c ./test/fush_string_test.c
	gcc -c ./src/core/fush_string.c
	mv *.o ./test/
	gcc -o fush_string_test ./test/fush_string_test.o ./test/fush_string.o

clean:
	rm -f ./*.o ./bin/*.o ./test/*.o
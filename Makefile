all: ./src/core/fush.c
	gcc -c ./src/core/fush.c
	gcc -c ./src/core/fush_echo.c
	gcc -c ./src/core/fush_touch.c
	gcc -c ./src/core/fush_cat.c
	gcc -c ./src/core/fush_rm.c
	gcc -c ./src/util/fush_file.c
	mv *.o ./bin/
	gcc -o fush ./bin/fush.o ./bin/fush_echo.o ./bin/fush_touch.o ./bin/fush_cat.o ./bin/fush_rm.o ./bin/fush_file.o

fush_echo: ./src/core/fush_echo.c
	gcc -c ./src/core/fush_echo.c

fush_touch: ./src/core/fush_touch.c
	gcc -c ./src/core/fush_touch.c

fush_cat: ./src/core/fush_cat.c
	gcc -c ./src/core/fush_cat.c

fush_rm: ./src/core/fush_rm.c
	gcc -c ./src/core/fush_rm.c

fush_file: ./src/util/fush_file.c
	gcc -c ./src/core/fush_file.c

clean:
	rm -f ./*.o ./bin/*.o
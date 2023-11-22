connectn.out: connectn.o board.o move.o win.o
	gcc -g -Wall -Werror -o connectn.out connectn.o board.o move.o win.o

connectn.o: connectn.c connectn.h board.h move.h win.h
	gcc -g -Wall -Werror -c connectn.c

board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c

move.o: move.c move.h
	gcc -g -Wall -Werror -c move.c

win.o: win.c win.h
	gcc -g -Wall -Werror -c win.c

clean:
	rm -fr *.o *.out
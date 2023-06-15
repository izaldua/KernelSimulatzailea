seso: seso.o clock.o scheduler.o loader.o timer.o 
	gcc seso.o clock.o scheduler.o loader.o timer.o -o seso

seso.o: seso.c config.h clock.h scheduler.h loader.h timer.h
	gcc -c seso.c

clock.o: clock.c clock.h config.h
	gcc -c clock.c

scheduler.o: scheduler.c scheduler.h config.h
	gcc -c scheduler.c

timer.o: timer.c timer.h config.h
	gcc -c timer.c

loader.o: loader.c loader.h config.h
	gcc -c loader.c

clean:
	rm *.o seso
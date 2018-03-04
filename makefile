ledshow: main.o menu.o config.o itoa.o all.o none.o show.o choice.o thread_controller.o
	gcc $^ -o $@ -lwiringPi -lpthread
	rm -f *.o

main.o: main.c
	gcc -c $^ -o $@

menu.o: menu.c
	gcc -c $^ -o $@
	
config.o: config/config.c
	gcc -c $^ -o $@

itoa.o: lib/itoa.c
	gcc -c $^ -o $@
	
all.o: tlc/all.c
	gcc -c $^ -o $@
	
none.o: tlc/none.c
	gcc -c $^ -o $@
	
show.o: tlc/show.c
	gcc -c $^ -o $@
	
choice.o: tlc/choice.c
	gcc -c $^ -o $@

thread_controller.o: thread_controller.c
	gcc -c $^ -o $@

clean:
	rm -f *.o ledshow
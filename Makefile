all: sema.o
	gcc -o control sema.o

clean:
	-rm -f *.o
	-rm -f *~
	-rm build
	-rm control
	-rm control.out

run: all
	./control -c 4
	./control -v
	./control -r
	./control -c 3
	./control -v
	./control -r
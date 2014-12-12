CC = clang
CFLAGS = -Wall -O0 -g 
LFLAGS = -O0 -g
LIBS = -lm

q3: q3.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)
	
clean:
	rm -f *~
	rm -f *.o
	
veryclean: clean
	rm -f q3


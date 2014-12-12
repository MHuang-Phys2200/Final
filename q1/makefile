
GRAPH = gnuplot

CC = clang
CFLAGS = -Wall -O3 
LFLAGS = -O3
LIBS = -lgsl -lm 

all: mc-se

mc-se: main.o mc_se.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

res: mc-se
	./mc-se > res

mc-se.png: mc_se.gpl res
	$(GRAPH) mc_se.gpl

clean:
	rm -f *.o *~ mc-se

veryclean: clean
	rm -f res mc-se1.png

GRAPH = gnuplot

CC = clang
CFLAGS = -Wall -O0 -g 
LFLAGS = -O0 -g
LIBS = -lgsl -lm

all: pend.png

pend: pend.o pend_func.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

pends: pend_stable.o pend_func.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)
	
pendu: pend_unstable.o pend_func.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

res1: pend
	./pend > res1
	
res2: pends
	./pends > res2
	
res3: pendu
	./pendu > res3
	
pend.png: pend.gpl res1
	$(GRAPH) pend.gpl
	
pend-stable.png: pend_stable.gpl res2
	$(GRAPH) pend_stable.gpl
	
pend-unstable.png: pend_unstable.gpl res3
	$(GRAPH) pend_unstable.gpl


clean : 
	rm -f *~
	rm -f *.o

veryclean : clean
	rm -f res1 res2 res3 pend pends pendu pend.png


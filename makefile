CC = g++
CCFLAGS = -Wall
SRC = rendering.cc
PROGRAM = Particle
 

build:
	$(CC) -o $(PROGRAM) $(SRC) point.cc liniar.cc global.cc mouse.cc $(CCFLAGS) -lGL -lGLU -lglut -lm
 
run:
	./$(PROGRAM)

clean :
	rm -f $(PROGRAM) core *~

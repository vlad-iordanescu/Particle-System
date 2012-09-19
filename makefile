CC = g++
CCFLAGS = -Wall
SRC = rendering.cc
PROGRAM = Particle
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	LDFLAGS = -framework OpenGL -framework GLUT -lm `libpng-config --ldflags` 
	CCFLAGS := `libpng-config --I_opts`
else
	LDFLAGS = -lGL -lGLU -lglut -lm `libpng-config --ldflags`
	CCFLAGS := `libpng-config --I_opts`
endif

build:
	$(CC) -o $(PROGRAM) $(SRC) point.cc liniar.cc global.cc mouse.cc $(CCFLAGS) $(LDFLAGS)
 
run:
	./$(PROGRAM)

clean :
	rm -f $(PROGRAM) core *~

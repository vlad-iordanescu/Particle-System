CC = g++
CCFLAGS = -Wall
SRC = rendering.cc
PROGRAM = Particle
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	LDFLAGS = -framework OpenGL -framework GLUT -lm `libpng-config --ldflags` 
	CCFLAGS := `libpng-config --I_opts`
else
ifeq ($(UNAME), Linux)
	LDFLAGS = -lGL -lGLU -lglut -lm `libpng-config --ldflags`
	CCFLAGS := `libpng-config --I_opts`
else
	LDFLAGS = -L/usr/lib -lglut32 -lglu32 -lopengl32 -lm `libpng-config --ldflags`
	CCFLAGS := -I/usr/include/opengl `libpng-config --I_opts`
endif
endif


build:
	$(CC) -o $(PROGRAM) $(SRC) point.cc liniar.cc global.cc mouse.cc $(CCFLAGS) $(LDFLAGS)
 
run:
	./$(PROGRAM)

clean :
	rm -f $(PROGRAM) core *~

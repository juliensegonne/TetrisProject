CFLAGS   = -g `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lSDL2_gfx -lSDL2_ttf -lm
PROG = tetris_toy
CXX = gcc

OBJS   = init.o input.o graphics.o tetris.o sds.o utility.o main.o

# top-level rule to create the program.
all: $(PROG)

# compiling other source files.
%.o: src/%.c src/%.h src/defs.h
	$(CXX) $(CFLAGS) -c -lSDL2_mixer $<

# linking the program
$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $(PROG) $(LDFLAGS) -lSDL2_mixer

# cleaning everything that can be automatically recreated with "make"
clean:
	rm $(PROG) *.o

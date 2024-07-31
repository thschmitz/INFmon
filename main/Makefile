# Compiler and flags
CC = gcc
CFLAGS = -I$(IDIR) -I$(INTERFACE_DIR)

# Directories
IDIR = main/config
INTERFACE_DIR = main/interfaces
SDIR = main
ODIR = .
LDIR = ..\lib

# Libraries
LIBS = -lraylib -lwinmm -lgdi32

# Header files
_DEPS = config.h mapa.h menu.h movimentacaoPersonagem.h structs.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
DEPS += $(wildcard $(INTERFACE_DIR)/*.h)

# Source files
_SRC = main.c config/config.c mapa/mapa.c menus/menu.c modules/movimentacaoPersonagem.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

# Object files
_OBJ = main.o config/config.o mapa/mapa.o menus/menu.o modules/movimentacaoPersonagem.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Executable name
EXECUTABLE = infmon.exe

# Rule to compile each source file into an object file
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rule to link object files to create the executable
$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Phony targets
.PHONY: clean rebuild

# Rule to clean up build files
clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ $(INTERFACE_DIR)/*~

# Rule to force rebuild
rebuild: clean $(EXECUTABLE)

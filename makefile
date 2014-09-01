GCC = gcc
GPP = g++

BIN = "./bin/Debug/functionstools_C_terminal"

# MAIN -->  Contiene las instrucciones para compilar un programa
# que genera un archivo con N números aleatorios

MAIN = main.c
#MAIN = TEST_uintegerExchangeValues.c
#MAIN = TEST_randomNumbers.c
#MAIN = "TEST_generateNumberBetween0And1.c"
#MAIN = "TEST_conversionBinary2Integer.c" 

SRC = "./src/functionstools.c"

INC = "./include/"

OP_EXE = -o
OP_WALL = -Wall
OP_G = -g

GL_LIB = -lglu -lGL
MATH_LIB = -lm

EXE_FLAGS = $(OP_EXE) $(BIN)

INC_FLAGS = -I$(INC)

SRC_FILES = $(OP_G) $(MAIN) $(SRC)

SRC_FLAGS = $(OP_WALL) $(SRC_FILES) 

compilacion:
	clear
	@echo
	@echo COMPILACION DEL PROGRAMA idividual_C_terminal
	@echo
	$(GCC) $(SRC_FLAGS) $(INC_FLAGS) $(EXE_FLAGS) $(MATH_LIB)
	@echo
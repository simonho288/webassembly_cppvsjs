CXX=clang++
EMCXX=emcc
CXXFLAGS=-O3 -std=c++14
CXXFLAGS_DBG=-g -Wall -pedantic
EMCXXFLAGS=-O3 -s WASM=1 -s EXPORTED_FUNCTIONS="['_ProcessMillionTimes']" -std=c++14
BIN=app
WASM_BIN=app.js

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

# Default build for production local executable
all: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $^

# Build debug version
debug: $(OBJ)
	$(CXX) $(CXXFLAGS_DBG) -o $(BIN) $^

# Build for production WASM format.
wasm: *.cpp
	$(EMCXX) $(EMCXXFLAGS) -o $(WASM_BIN) $^

# Cleanup
clean:
	rm -f *.o
	rm $(BIN)

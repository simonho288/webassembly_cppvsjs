CXX=clang++
# CXX=g++
EMCXX=emcc
CXXFLAGS=-O3 -std=c++14
CXXFLAGS_DBG=-g -std=c++14
EMCXXFLAGS=-std=c++14 -O3 -s WASM=1 -s EXPORTED_FUNCTIONS="['_ProcessMillionTimes']"
BIN=app
WASM_BIN=app.js

SRC=$(wildcard *.cpp)

# Build debug version
debug: $(SRC)
	$(CXX) $(CXXFLAGS_DBG) -o $(BIN) $^

# Build for production WASM format.
wasm: *.cpp
	$(EMCXX) $(EMCXXFLAGS) -o $(WASM_BIN) $^

# Cleanup
clean:
	rm -f *.o
	rm $(BIN)

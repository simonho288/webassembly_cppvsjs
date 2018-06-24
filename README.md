# Web Assembly experiment: C++ vs JS

## Introduction

This is an experiment webapp to demonstrate how to call the external C++ module from Javascript. In addition, here also compares the performance for manipulating a list of products in C++ (with STL) versus Javascript (with Lodash).

Below contents will mention:
1. Development environment setup
2. Develop C++ module
3. Develop the web interface
4. Develop Javascript module
5. Performance comparsion result

## 1. Development Environment Setup

In my development environment, I'm using MacOSX 10.11 EI Capitan. The programming language versions installed as below:

```bash
$ node -v
# v8.9.1
$ python -V
# Python 2.7.13
$ java -version
# java version "1.8.0_171"
$ clang++ -v
# clang version 6.0.1  (emscripten 1.38.6 : 1.38.6)
```

### Install Visual Studio Code

Visual Studio Code (VSCode) is a light-weight and cross platforms editor. You can download it free from [here](https://code.visualstudio.com/).

After installed the VSCode, you'll need to install C/C++ language extension like this screenshot:

01_vscode.png

### Install Emscripten

You'll need the Emscripten to compile C++ programs into webassembly (WASM). Follow [this instructions](http://kripken.github.io/emscripten-site/docs/getting_started/downloads.html) to install the Emscripten and its prerequisites.

When I installed the Emscripten. I need to run below commands before using it:
```bash
# Make sure it is at Emscripten installation directory
$ source ./emsdk_env.sh
```

Below command is to verify the installation:
```bash
$ emcc -v
# emcc (Emscripten gcc/clang-like replacement + linker emulating GNU ld) 1.38.6
```

## 2. Develop C++ Module

### Create the project

### C++ Main program

### Product Source Codes

### VSCode settings for build and debug

### Makefile

## 3. Develop Web Interface

### Index.html

### External Dependencies

### Frontend programming with Semantic UI

## 4. Develop Javascript Module

### Product JS Source Codes

### Array operation using Lodash

## 5. Performance Comparsion Result

### C++ execution result

### JS execution result

## 6. Conclusion


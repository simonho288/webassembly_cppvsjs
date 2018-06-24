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
$ cmake -version
# cmake version 3.11.4
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

Before create the project, make sure you have run the `source ./emsdk_env.sh` in Emscripten directory. Then type this commands:

```bash
$ cd ~/code # suppose your codebase in ~/Code
$ mkdir wasm_exp && cd wasm_exp
```

Create the module files as below:
1. [main.cpp](https://github.com/simonho288/webassembly_cppvsjs/main.cpp)
  - This is the main program file.
  - Create the products array.
  - Operate the products array (two filtering and one sorting).
  - Perform one million times operations on the product array.
2. [headers.h](https://github.com/simonho288/webassembly_cppvsjs/headers.h)
  - Include all STL headers. The products array operations are using STL vector.
3. [product.h](https://github.com/simonho288/webassembly_cppvsjs/product.h)
  - Declare a product object
4. [product.cpp](https://github.com/simonho288/webassembly_cppvsjs/product.cpp)
  - Operator overloaded function for dumping the product to ostream such as cout.
5. [Makefile](https://github.com/simonho288/webassembly_cppvsjs/Makefile)


### VSCode settings for build and debug

Now you can run the C++ module inside the VSCode. To do that, create two files: `tasks.json` & `launch.json`. VSCode can help you to create the `tasks.json`. In VScode editor, click menu "Tasks"->"Configure Default Build Task..."->"Create tasks.json file from template"->"Others". Like the screenshot below:

[02_tasks_json.png]

Replace the tasks.json with below contents:

```json
{
"version": "2.0.0",
  "tasks": [
    {
      "label": "build",
      "type": "shell",
      "command": "make debug",
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": {
        "owner": "cpp",
        "fileLocation": ["relative", "${workspaceFolder}"],
        "pattern": {
          "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
          "file": 1,
          "line": 2,
          "column": 3,
          "severity": 4,
          "message": 5
        }
      }
    }
  ]
}
```

Next one is to create launch.json for debug. In VSCode, click "Debug" tab, then select 'Configure or fix launch.json' as below screenshot:

[03_launch_json.png]

Modify the two settings in `launch.json':
```json
...
      "preLaunchTask": "build",
      "program": "${workspaceFolder}/app",
...
```


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


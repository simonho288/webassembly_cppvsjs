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
      "command": "make",
      "args": [ "debug" ],
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

Now you can set a breakpoint in VSCode and start the debugger (press F5). See below screenshot:

[04_debug.png]

### Compile the C++ into WASM

Emscripten can compile the C++ module into a single Javascript file which is WASM format. I've already created the build script in the Makefile. To build it, type:
```bash
$ make wasm
```
*Note: If the build failed, you may forget to run `source ./emsdk_env.sh` insdie the emsdk directory.*

If the build successful, it generates an `app.js` and `app.wasm` files respectively. Actually we'll need only the `app.js` file in next section.

## 3. Develop Web Interface

In this section we'll develop a simple website to incorporate the `app.js` which generated by Emscripten. I'm fan of Semantic UI, so I build the frontend in Semantic UI. All the external dependencies (include frameworks, libraries) retrieve from the CDN.

Click [here](https://github.com/simonho288/webassembly_cppvsjs/index.html) to view the contents of index.html. Notice that it loads the `app.js` using async syntax as below:
```html
...
</body>

<script async type="text/javascript" src="app.js"></script>
...
```

## 4. Develop Javascript Module

To make the comparsion between Webassembly and Javascript. I developed a Javascript module which performs same operations as what the C++ module does. I used [Lodash](https://lodash.com/) to process the products array. You can view the contents of [product.js](https://github.com/simonho288/webassembly_cppvsjs/product.js) file. Below is the main operations:
```javascript
...
function ProcessProducts() {
  let products = CreateProducts();
  let products1 = _.filter(products, (product) => {
    return product._price >= 20.0 && product._price <= 200.0;
  });
  let products2 = _.filter(products1, (product) => {
    return product._description.includes('pretium');
  });
  let products3 = _.sortBy(products2, '_price');
  return products3;
}
...
```

## 5. Performance Comparsion Result

At this time, we can run a webserver to browse the website to start the comparsion. At the project root directory, start the http-server as below commands (if you haven't installed the http-server, you can install it via `npm install -g http-server`):

```bash
$ http-server
# Starting up http-server, serving ./
# Available on:
#   http://127.0.0.1:8080
```

Open the Chrome browser (version 57 or above) to browse `http://localhost:8080`. Below is the website screenshot:

[05_website.png]

### Result of my PC

You can click C++ and JS execute buttons one by one. Below is the result of my Macbook 2016:

[06_execute_result.png]

## 6. Conclusion

As you can see, Javascript out-performs C++ nearly 3 times. This surprised me. It represents Google's V8 engine is really very fast even faster than C++ STL.

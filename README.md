# Web Assembly experiment: C++ vs JS

## Introduction

This repo hosts the source codes for the [blog](https://blog.simonho.net/2018/06/webassembly-experiment-c-vs-js.html) which demonstrates how to call the external C++ module from Javascript. In addition, it also compares the performance for manipulating a list of products in C++ (with STL) versus Javascript (with Lodash).

## Installation

### Prerequisites

In brief, to run this project, you'll need:

- Emscripten installed
- Visual Studio Code with C++ Extension
- Node.JS and http-server

For the detail prerequisites and installation, please refer to the [blog](https://blog.simonho.net/webassembly_cppvsjs/).

### Download the codes

```bash
$ git clone https://github.com/simonho288/webassembly_cppvsjs
```

### Compile C++ to WASM

```bash
$ make wasm
$ http-server
```

### Open Chrome and browse the website

Browse `http://localhost:8080`. You'll see the website as below screenshot:

[website_screenshot](https://blog.simonho.net/content/images/2018/06/05_website.png#screenshot)

Then you can click [Execute C++ module] and [Execute JS module] to see the result.

Enjoy!

## License

The MIT License (MIT)

Copyright (c) 2018 Simon Ho

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)


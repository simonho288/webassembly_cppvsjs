# Web Assembly experiment: C++ vs JS

## Introduction

This repo hosts the source codes for the [blog]((https://blog.simonho.net/webassembly_cppvsjs/)) which demonstrates how to call the external C++ module from Javascript. In addition, it also compares the performance for manipulating a list of products in C++ (with STL) versus Javascript (with Lodash).

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

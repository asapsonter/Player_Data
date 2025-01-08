name: C/C++ CI

on:
  push:
    branches: [ "main" ]
  pull_request:
    branches: [ "main" ]

jobs:
  build:

    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v4
    - name: Install Dependencies
      run: sudo apt-get update && sudo apt-get install -y autoconf automake libtool
    - name: Generate configure script
      run: autoreconf --install
    - name: Configure
      run: ./configure
    - name: Build
      run: make
    - name: Test
      run: make check
    - name: Distcheck
      run: make distcheck

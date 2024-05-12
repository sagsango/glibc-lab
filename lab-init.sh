#!/bin/bash

# Create directories for installation and build
mkdir -p glibc-install
mkdir -p glibc-build

root=$(pwd)

# Navigate to the build directory
pushd glibc-build

# Configure glibc with specific options
${root}/glibc-2.39/configure --prefix=${root}/glibc-install  CFLAGS="-O0" CXXFLAGS="-O0"

# Build glibc with 16 parallel jobs
make -j 16

# Install glibc
make install

# Return to the previous directory
popd


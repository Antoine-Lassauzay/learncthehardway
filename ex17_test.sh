#!/bin/bash

set -o verbose
set -e

# Creating DB
./ex17 db c

# Adding entries
./ex17 db s 1 Antoine alassauzy@socialludia.com
./ex17 db s 2 Hadrien hdavid@socialludia.com
./ex17 db s 3 Sylvain sboichoin@socialludia.com

# List entries
./ex17 db l

# Lookup
./ex17 db f Antoine
./ex17 db f socialludia.com
./ex17 db f google.com

# Remove some entries
./ex17 db d 1
./ex17 db d 2

# List entries
./ex17 db l

# Delete db
rm db



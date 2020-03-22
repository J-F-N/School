#!/bin/sh
g++ driver.cpp -o ~/a.out
valgrind --track-origins=yes --read-inline-info=yes ~/a.out
rm ~/a.out

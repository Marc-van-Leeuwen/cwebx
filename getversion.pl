#!/usr/bin/perl

# extract version from line containing "@d version_string " in argument file
# that argument file should be 'intro.inc', as used in 'update' Makefile
while(<>) {  print $1 if /^\@d +version_string +"(.+)"/; }

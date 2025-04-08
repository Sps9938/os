#!/bin/bash
# Common shell commands demo

echo "Navigating and listing files"
cd ~
ls -l

echo "Creating and removing directories"
mkdir test_dir
rmdir test_dir

echo "File operations"
touch sample.txt
cat sample.txt
rm sample.txt

echo "Other commands"
whoami
pwd

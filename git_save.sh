#!/bin/bash

git config commit.gpgsign true
git pull;git add .;git commit -a -S -m  master;git push -u origin master

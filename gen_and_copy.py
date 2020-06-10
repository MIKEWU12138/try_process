#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os
import shutil

fname="new"+".txt"
dir="C:/try/workspace/submodule/"
file=open(dir+fname,"w")
file.write("new")
file.close()
dir1=dir+fname
shutil.copy(dir1,"C:/try/workspace/representation/")

from ctypes import *

so_file  = "Arthur/build/functions.so"
functions = CDLL(so_file)

if "__name__" == "__main__":
  functions.parse()



import sys

for line in sys.stdin.readlines():
    print (line % {sys.argv[1] : sys.argv[2]}),

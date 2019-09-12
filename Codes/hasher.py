# export PYTHONHASHSEED=0
import sys
ls = open(sys.argv[1], "r")
ac = ""
for l in ls:
    ac += "".join(l.split()).split('//')[0]
    print("{0:0=3d}".format(hash(ac)%1000), l[:-1])
print(hash(ac))

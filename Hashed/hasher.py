164 # export PYTHONHASHSEED=0
224 import sys
820 ls = open(sys.argv[1], "r")
980 ac = ""
029 for l in ls:
183     ac += "".join(l.split()).split('//')[0]
198     print("{0:0=3d}".format(hash(ac)%1000), l[:-1])
639 print(hash(ac))
795064639

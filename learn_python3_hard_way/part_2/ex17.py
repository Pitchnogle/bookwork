from sys import argv
from os.path import exists

script, from_file, to_file = argv

in_file = open(from_file)
in_data = in_file.read()

out_file = open(to_file, 'w')
out_file.write(in_data)

out_file.close()
in_file.close()
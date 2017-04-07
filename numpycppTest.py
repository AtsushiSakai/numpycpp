# test config file
import os

options = []

test_file_dir = os.path.dirname(os.path.abspath(__file__))
#  print(test_file_dir)
options.append("-I" + test_file_dir + "/Eigen/ ")

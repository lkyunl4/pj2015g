#import Image
from PIL import Image
import numpy
import numpy as np

im = Image.open("monkey.jpg")
im.show()

"""
row, col = im.size
print("{0}\t{1}".format(row, col))
data = np.zeros([row, col])
pixels = im.load()
for i in xrange(row):
	for j in xrange(col):
		r, g, b = pixels[i, j]
		print("{0}\t{1}\t{2}".format(r, g, b))
"""

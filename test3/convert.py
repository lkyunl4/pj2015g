#import Image
from PIL import Image
import numpy
import numpy as np

f = open("denoise.txt")
line = f.readline()
rc = line.split()
row = int(rc[0])
col = int(rc[1])

a = numpy.zeros([row, col, 3], dtype=numpy.int)

for i in xrange(row):
	for j in xrange(col):
		line = f.readline()
		rgb = line.split() 
		a[j][i][0] = int(rgb[0])
		a[j][i][1] = int(rgb[1])
		a[j][i][2] = int(rgb[2])

im_out = Image.fromarray(a.astype('uint8')).convert('RGBA')
im_out.save('denoise.jpg')

im = Image.open("denoise.jpg")
im.show()

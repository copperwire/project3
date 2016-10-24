import matplotlib.pyplot as plt
import numpy as np

planetname = ['Sun', 'Earth', 'Jupiter']
filename = []

for filname in filnames:
	A = np.loadtxt(filename)
	x = A[:,0]
	y = A[:,1]
	z = A[:,2]
	plt.plot(x,y, label = filname)
	plt.hold('on')

plt.show()






import matplotlib.pyplot as plt
import numpy as np

planetname = ['Sun', 'Earth']
filenames = ["positions_earth_sun_euler.xyz", "positions_earth_sun_verlet.xyz"]

for filename in filenames:
	A = np.loadtxt(filename)
	list_of_matrices = []

	for j in range(len(planetname)):
		list_of_matrices.append( np.empty(( np.shape(A)[0]/len(planetname), 3) ))

	i = 0
	n = 0
	for j in range(int(np.shape(A)[0]) - 1):

		list_of_matrices[i][n] = A[j]
		
		if i < (len(planetname) - 1):
			i += 1
		else :
			i = 0
			n += 1

	for B, name in zip(list_of_matrices, planetname):
		x = B[:,0]
		y = B[:,1]
		z = B[:,2]
		
		"""
		print("------------------------{}---------------------".format(name))
		print(x[0], y[0])
		print(x[1], y[1])
		print(x[2], y[2])
		print(x[3], y[3])
		"""
		plt.title(filename)
		plt.plot(x[:-1],y[:-1], label = name)
		plt.axis("equal")
		plt.legend()
		plt.hold('on')

	plt.show()






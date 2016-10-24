import matplotlib.pyplot as plt
import numpy as np
from images2gif import writeGif
from tqdm import tqdm

import PIL

 
def fig2data ( fig ):
    """
    @brief Convert a Matplotlib figure to a 4D numpy array with RGBA channels and return it
    @param fig a matplotlib figure
    @return a numpy 3D array of RGBA values
    """
    # draw the renderer
    fig.canvas.draw ( )
 
    # Get the RGBA buffer from the figure
    w,h = fig.canvas.get_width_height()
    buf = np.fromstring ( fig.canvas.tostring_argb(), dtype=np.uint8 )
    buf.shape = ( w, h,4 )
 
    # canvas.tostring_argb give pixmap in ARGB mode. Roll the ALPHA channel to have it in RGBA mode
    buf = np.roll ( buf, 3, axis = 2 )
    return buf
    

 
def fig2img ( fig ):
    """
    @brief Convert a Matplotlib figure to a PIL Image in RGBA format and return it
    @param fig a matplotlib figure
    @return a Python Imaging Library ( PIL ) image
    """
    # put the figure pixmap into a numpy array
    buf = fig2data ( fig )
    w, h, d = buf.shape
    im=PIL.Image.frombytes( "RGBA", ( w ,h ), buf.tostring())
    return im.convert(mode="RGB")

planetname = ['Sun', 'Earth']
filenames = ["positions_earth_sun_verlet.xyz", "positions_earth_sun_euler.xyz"]

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
		plt.xlabel("x [AU]")
		plt.ylabel("y [AU]")
		plt.plot(x[:-1],y[:-1], label = name)
		plt.axis("equal")
		plt.legend()
		plt.hold('on')

	#make gif 

	x_list = []
	y_list = []

	for B, name in zip(list_of_matrices, planetname):
		x = B[:,0]
		y = B[:,1]
		z = B[:,2]

		x_list.append(x)
		y_list.append(y)


	plt.show()

	figure = plt.figure()
	thing = figure.add_subplot(111)	
	thing.hold(False)
	images = []

	
	"""
	for i in tqdm(range(len(x))):
		for x, y, name in zip(x_list, y_list, planetname):
			thing.plot(x[i], y[i], "o", label = name)
		
		thing.title.set_text("day number: {}".format(365 * 2*(float(i+0.001)/len(x)) ))
		thing.legend()
		thing.set_xlabel("x [AU]")
		thing.set_ylabel("y [AU]")
		thing.set_ylim([-1.2, 1.2])
		thing.set_xlim([-1.2, 1.2])
		im = fig2img(figure)
		images.append(im)

	writeGif(filename + ".gif", images)
	"""
	





import numpy as np
# Define the vector
n1= np.array([2 , 3 , -1])
n2= np.array([1,-2,1])
vector=n1+n2
magnitude=np.linalg.norm(vector)
unit_vector = vector / magnitude
resultant_vector=5*unit_vector
print(magnitude)
print("Unit vector:", unit_vector)
print(resultant_vector)

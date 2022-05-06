import numpy as np
import seaborn as sn
import matplotlib.pyplot as plt

#input data
Age = [30,40,50,60,40]
Income = [200,300,800,600,300]
Yrsworked = [10,20,20,20,20]
Vacation = [4,4,1,2,5]

data = np.array([Age,Income,Yrsworked,Vacation])
#population covariance matrix(N)
covMatrix = np.cov(data,bias=True)
print(covMatrix)

sn.heatmap(covMatrix, annot=True,fmt='g')
plt.show()

#sample covariance matrix(N-1)
covMatrix = np.cov(data, bias=False)print(covMatrix)

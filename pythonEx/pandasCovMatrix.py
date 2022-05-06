import pandas as pd
import seaborn as sn
import matplotlib.pyplot as plt

data = {'Age':[30,40,50,60,40],
        'Income':[200,300,800,600,300],
        'Yrsworked':[10,20,20,20,20],
        'Vacation':[4,4,1,2,5]
        }

df = pd.DataFrame(data,columns=['Age','Income','Yrsworked','Vacation'])
#sample covariance matrix
covMatrix = pd.DataFrame.cov(df)
print(covMatrix)

sn.heatmap(covMatrix, annot=True,fmt='g')
plt.show()

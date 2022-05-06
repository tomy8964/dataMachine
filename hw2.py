# Import packages
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn import linear_model
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import KFold

# Indedependent variable - number of chimpanzees in hunting party
x = np.array([2400,2650,2350,4950,3100,2500,5106,3100,2900,1750])
# Dependent Variable - percent of successful hunts
y = np.array([41200,50100,52000,66000,44500,37700,73500,37500,56700,35600])

df = pd.DataFrame({'spends':x,'income':y})

X = pd.DataFrame(df['spends'])
y = pd.DataFrame(df['income'])

plt.plot(X,y,'o')
plt.show()

model = LinearRegression()
model.fit(X,y)
#coef = m, intercept = b , y = mx + b
print(model.coef_)
print(model.intercept_)

plt.plot(X,y,'o')
plt.plot(X,model.predict(X))
plt.show()

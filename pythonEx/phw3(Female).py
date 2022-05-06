# pandas and numpy for data manipulation
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn import preprocessing
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import RobustScaler
from sklearn import linear_model

#read csv and print
df = pd.read_excel("./bmi_data_phw3.xlsx")
# Select Male
dffm = df[df['Sex'] == 'Female']
dffm.describe()
dffm.columns.values
dffm.dtypes

x = dffm['Height (Inches)']
y = dffm['Weight (Pounds)']

#dataframe to numpy array
x = x.to_numpy()
y = y.to_numpy()

#linear regression
reg = linear_model.LinearRegression()

#fit linear model
reg.fit(x[:, np.newaxis], y)
px = np.array([x.min()-1,x.max()+1])
py = reg.predict(px[:, np.newaxis])
plt.scatter(x,y)
plt.plot(px,py,color='r')
plt.show()

dfr = np.empty_like(x)
#make array that predicted y by liner regression
pred_y = (reg.intercept_) + x * (reg.coef_)

# input difference between y and pred_y
for i in range(0,dfr.size):
    dfr[i] = pred_y[i] - y[i]

# Nomalize e    
normal = preprocessing.scale(dfr)

#plot a histogram showing the distribution of Ze
plt.hist(normal,bins=10)
plt.title("distribution of Ze Female")
plt.xlabel('e')
plt.show()

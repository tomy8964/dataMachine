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
df.describe()
df.columns.values
df.dtypes

#plot histogram
for i in range(0,5):
    bmi = df[df.BMI==i]
    x = bmi['Height (Inches)']
    y = bmi['Weight (Pounds)']
    plt.hist(x,bins=range(60,100,10))
    plt.xticks(range(60,100,10))
    plt.title(str(i) + " group BMI")
    plt.xlabel('Height (Inches)')
    plt.show()
    plt.hist(y,bins=range(90,160,10))
    plt.xticks(range(90,160,10))
    plt.title(str(i) + " group BMI")
    plt.xlabel('Weight (Pounds)')
    plt.show()


#StandardScaling
for i in range(0,5):
    bmi = df[df.BMI==i]
    scdf = bmi.loc[:,['Height (Inches)','Weight (Pounds)']]
    std = preprocessing.StandardScaler()
    std_data = std.fit_transform(scdf)
    x_df = std_data[:,0]
    y_df = std_data[:,1]
    plt.hist(x,bins=10)
    plt.title(str(i) + " group BMI Standard")
    plt.xlabel('Height (Inches)')
    plt.show()
    plt.hist(y,bins=10)
    plt.title(str(i) + " group BMI Standard")
    plt.xlabel('Weight (Pounds)')
    plt.show()

#MinMaxScaling
for i in range(0,5):
    bmi = df[df.BMI==i]
    scdf = bmi.loc[:,['Height (Inches)','Weight (Pounds)']]
    mm = preprocessing.MinMaxScaler()
    mm_data = mm.fit_transform(scdf)
    x = mm_data[:,0]
    y = mm_data[:,1]
    plt.hist(x,bins=10)
    plt.title(str(i) + " group BMI MinMax")
    plt.xlabel('Height (Inches)')
    plt.show()
    plt.hist(y,bins=10)
    plt.title(str(i) + " group BMI MinMax")
    plt.xlabel('Weight (Pounds)')
    plt.show()


#RobustScaling
for i in range(0,5):
    bmi = df[df.BMI==i]
    scdf = bmi.loc[:,['Height (Inches)','Weight (Pounds)']]
    rob = preprocessing.RobustScaler()
    rob_data = rob.fit_transform(scdf)
    x = rob_data[:,0]
    y = rob_data[:,1]
    plt.hist(x,bins=10)
    plt.title(str(i) + " group BMI Robust")
    plt.xlabel('Height (Inches)')
    plt.show()
    plt.hist(y,bins=10)
    plt.title(str(i) + " group BMI Robust")
    plt.xlabel('Weight (Pounds)')
    plt.show()

#read excel file
df = pd.read_excel("./bmi_data_phw3.xlsx")
x = df['Height (Inches)']
y = df['Weight (Pounds)']

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
plt.title("distribution of Ze")
plt.xlabel('e')
plt.show()



# pandas and numpy for data manipulation
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn import preprocessing
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import RobustScaler


#read csv and print
df = pd.read_csv("./bmi_data_lab3.csv")
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
for i in range(1,4):
    bmi = df[df.BMI==i]
    scdf = bmi.loc[:,['Height (Inches)','Weight (Pounds)']]
    std = StandardScaler()
    std_data = std.fit_transform(scdf)
    x = std_data[:,0]
    y = std_data[:,1]
    plt.hist(x,bins=10)
    plt.title(str(i) + " group BMI Standard")
    plt.xlabel('Height (Inches)')
    plt.show()
    plt.hist(y,bins=10)
    plt.title(str(i) + " group BMI Standard")
    plt.xlabel('Weight (Pounds)')
    plt.show()

#MinMaxScaling
for i in range(1,4):
    bmi = df[df.BMI==i]
    scdf = bmi.loc[:,['Height (Inches)','Weight (Pounds)']]
    mm = MinMaxScaler()
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
for i in range(1,4):
    bmi = df[df.BMI==i]
    scdf = bmi.loc[:,['Height (Inches)','Weight (Pounds)']]
    rob = RobustScaler()
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






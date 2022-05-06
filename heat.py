import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.datasets import fetch_california_housing

data =fetch_california_housing( 
data_home=None, download_if_missing=True, 
return_X_y=False, as_frame=False)

#make dataframe
df = pd.DataFrame(data.data,columns=data.feature_names)
df['target'] = data.target

#slicing
X=df.iloc[:,0:8]
y = df.iloc[:,-1]

#get correlations of pairs of features in the dataset
corrmat = df.corr()
#corr() computes pairwise correlations of features in a Data Frame
top_corr_features = corrmat.index
plt.figure(figsize=(8,8))

#plot the heat map
g=sns.heatmap(df[top_corr_features].corr(),annot= True,cmap="RdYlGn")
plt.show()

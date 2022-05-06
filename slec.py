import pandas as pd
import numpy as np
from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import chi2
from sklearn.datasets import fetch_california_housing

data =fetch_california_housing( 
data_home=None, download_if_missing=True, 
return_X_y=False, as_frame=False)

df = pd.DataFrame(data.data,columns=data.feature_names)
df['target'] = data.target

columns_drop = ["Longitude", "Latitude"]
df = df.drop(columns=columns_drop)

X=df.iloc[:,0:6]
y = df.iloc[:,-1]

y=y.astype('int')

#apply SelectKBest class to extract top 10 best features
bestfeatures = SelectKBest(score_func=chi2, k=6)
fit = bestfeatures.fit(X,y)
dfcolumns = pd.DataFrame(X.columns)
dfscores = pd.DataFrame(fit.scores_)

#concatenate two dataframes for better visualization 
featureScores = pd.concat([dfcolumns, dfscores],axis=1)
featureScores.columns = ['Specs','Score'] #name the dataframe columns
print(featureScores.nlargest(10,'Score')) #print 10 bestfeatures

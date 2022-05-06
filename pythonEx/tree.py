import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.ensemble import ExtraTreesClassifier
from sklearn.datasets import fetch_california_housing

data =fetch_california_housing( 
data_home=None, download_if_missing=True, 
return_X_y=False, as_frame=False)

df = pd.DataFrame(data.data,columns=data.feature_names)
df['target'] = data.target


X=df.iloc[:,0:8]
y = df.iloc[:,-1]

y=y.astype('int')

model = ExtraTreesClassifier()
model.fit(X,y)

#use built-in class feature_importances of tree-based classifiers
print(model.feature_importances_)

#plot graph of feature importances for better visualization
feat_importances = pd.Series(model.feature_importances_, index=X.columns)
feat_importances.nlargest(10).plot(kind='barh')
plt.show()

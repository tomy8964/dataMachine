import pandas as pd
import numpy as np

# loading data file into the program. give the location of your csv file
dataset = pd.read_excel("./Tshirt.xlsx")
print(dataset.head()) # prints first five tuples of your data.

# making function for calculating euclidean distance
def E_Distance(x1, x2, length):
    distance = 0
    for x in range(length):
        distance += np.square(x1[x] - x2[x])
    return np.sqrt(distance)

# making function for defining K-NN model

def knn(trainingSet, testInstance, k):
    distances = {}
    length = testInstance.shape[1]
    # calculate distance with testset by loop
    for x in range(len(trainingSet)):
        dist = E_Distance(testInstance, trainingSet.iloc[x], length)
        distances[x] = dist[0]
    #sort distance to find K-nearest points
    sortdist = sorted(distances.items(), key=lambda fileds:fileds[1])
    neighbors = []
    for x in range(k):
        neighbors.append(sortdist[x][0])
    Count = {}  # to get most frequent class of rows
    for x in range(len(neighbors)):
        response = trainingSet.iloc[neighbors[x]][-1]
        if response in Count:
            Count[response] += 1
        else:
            Count[response] = 1
    sortcount = sorted(Count.items(), key=lambda fileds:fileds[1], reverse=True)
    return (sortcount[0][0], neighbors)

# making test data set
testSet = [[161,61]]
test = pd.DataFrame(testSet)

# assigning different values to k
k = 3

# supplying test data to the model
result, neigh = knn(dataset, test, k)

# printing output prediction
print("Test set")
print(testSet)
print("Predict T shirt size is "+result)
print("neighbor point idx is ")
print(neigh)

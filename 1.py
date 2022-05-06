# pandas and numpy for data manipulation
import pandas as pd
import numpy as np

# featuretools for automated feature engineering
import featuretools as ft


# Read in the data
clients = pd.read_csv('./clients.csv', parse_dates = ['joined'])
loans = pd.read_csv('./loans.csv', parse_dates = ['loan_start', 'loan_end'])
payments = pd.read_csv('./payments.csv', parse_dates = ['payment_date'])

clients.head()

# Create new entityset
es = ft.EntitySet(id = 'clients')

# Create an entity from the client dataframe
# This dataframe already has an index and a time index
# index=RDB primary key
# time index= date_time feature
es = es.entity_from_dataframe(entity_id = 'clients', 
dataframe = clients, index = 'client_id', time_index = 'joined')

# Create an entity from the loans dataframe
# This dataframe already has an index and a time index
es = es.entity_from_dataframe(entity_id = 'loans', dataframe = loans, 
                              variable_types = {'repaid': ft.variable_types.Categorical},
                              index = 'loan_id', 
                              time_index = 'loan_start')

# Create an entity from the payments dataframe
# This does not have an index
es = es.entity_from_dataframe(entity_id = 'payments', 
dataframe = payments,
variable_types = {'missed':
ft.variable_types.Categorical},
make_index = True,
index = 'payment_id',
time_index = 'payment_date')

# Group loans by client id and calculate sum of loans
stats = loans.groupby('client_id')['loan_amount'].agg(['sum'])
stats.columns = ['total_loan_amount']

# Merge with the clients dataframe
stats = clients.merge(stats, left_on = 'client_id', right_index=True, how = 'left')
stats.head(10)

# Create a relationship between clients and loans
r_client_previous = ft.Relationship(es['clients']['client_id'],
es['loans']['client_id'])

# Add the relationship to the entity set
es = es.add_relationship(r_client_previous)

# Relationship between previous loans and previous payments
r_payments = ft.Relationship(es['loans']['loan_id'],
es['payments']['loan_id'])

# Add the relationship to the entity set
es = es.add_relationship(r_payments)
es

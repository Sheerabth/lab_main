# Sheerabth O S (19PW33)
# Python Final Lab Examination
# Program to read a data file and analyse it

import pandas as pd

# reading the file
df = pd.read_excel('Train.xlsx')

# Qn 1
# Printing the details of customer who have warehouse block as F
print('\nDetails of customer who have warehouse block as F:\n')
print(df[(df.Warehouse_block == 'F')])

# Qn 2
# Printing the number of customers whose customer-rating is highest(Best)
max_rating_count = len(df[df.Customer_rating == 5].index)
print('\nThe number of customers whose customer-rating is highest(Best) is', max_rating_count)

# Qn 3
# Printing the percentage of male and female customers
male_customer_count = df["Gender"].value_counts().to_dict()["M"]
total_customer_count = df["Gender"].shape[0]
percentage_of_male = (male_customer_count/total_customer_count) * 100
print('The percentage of male customers is {0:.2f}'.format(percentage_of_male), '%')
percentage_of_female = 100 - ((male_customer_count/total_customer_count) * 100)
print('The percentage of female customers is {0:.2f}'.format(percentage_of_female), '%')

# Qn 4
# Printing the ratio of customers whose products have reached on time
reached_ontime_dict = df["Reached.on.Time_Y.N"].value_counts().to_dict()

if 0 not in reached_ontime_dict:
    reached_ontime = 0
else:
    reached_ontime = reached_ontime_dict[0]

total_count = df["Reached.on.Time_Y.N"].shape[0]
ratio_of_reached_ontime = reached_ontime/total_count
percentage_of_reached_ontime = ratio_of_reached_ontime * 100
print('The ratio of customers whose products have reached on time is', ratio_of_reached_ontime)
print('The percentage of customers whose products have reached on time is {0:.2f}'.format(percentage_of_reached_ontime), '%')

# Qn 5
# Printing details of Cost of product and discounted price for each customer
df['Discounted_price'] = df['Cost_of_the_Product'] - df['Discount_offered']
print('\nDetails of Costs:\n')
print(df[["Cost_of_the_Product", "Discounted_price"]])
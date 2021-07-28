i = 1
valid_users = list()
while True:
    url = 'https://jsonmock.hackerrank.com/api/article_users?page=' + str(i)
    response = re
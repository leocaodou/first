import string,random
password=[]
resource=string.digits+string.ascii_letters
for x in range(10):
    password=[]
    for number in range(8):
        i=random.randint(0,len(resource)-1)
        password.append(resource[i])
    else:
        print("".join(password))
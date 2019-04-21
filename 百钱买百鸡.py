for i in range(1,20):
    for j in range(1,33):
        for k in range(3,98,3):
            if i+j+k==100 and 5*i + 3*j + k//3 ==100:
                print(i,j,k)
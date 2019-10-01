#Modify the previous program such that only multiples of three or five are considered in the sum, e.g. 3, 5, 6, 9, 10, 12, 15 for n=17

number = input("Pick a number")

#convert to a number
number = int(number)
add = 0


for i in range(number+1):
    # checking if they are multiples of 3 or 5
    if((i%3 ==0)or(i%5 ==0)):
        add = add + i
        
print("SUM of first ", number, "numbers is: ", add )

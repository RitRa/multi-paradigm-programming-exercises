#Write a program that asks the user for a number n and gives them the possibility to choose between computing the sum and computing the product of 1,…,n.

number = input("Pick a number")

#convert to a number
number = int(number)

decision = input("would you like to: + or * ?")

if(decision == "+"):
    number = number + number
elif(decision == "*"):
    number = number * number

print(number)
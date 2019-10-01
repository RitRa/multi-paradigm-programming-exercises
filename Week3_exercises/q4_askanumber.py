#Write a program that asks the user for a number n and prints the sum of the numbers 1 to n

number = input("Pick a number")

#convert to a number
number = int(number)
sum = 0

for i in range(1, number+1):
    sum = sum+i

print("SUM of first ", number, "numbers is: ", sum )

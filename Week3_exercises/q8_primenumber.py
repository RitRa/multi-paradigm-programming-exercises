# Write a program that prints all prime numbers. (Note: if your programming language does not support arbitrary size numbers, printing all primes up to the largest number you can easily represent is fine too.)
number = input("Pick a number")

#convert to a number
number = int(number)

for i in range(number):
    if (number%i) == 0:  
        print(i)
    else:
        print("heelo")
 

print("Prime number", i)
        


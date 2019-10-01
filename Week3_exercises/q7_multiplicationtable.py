# Write a program that prints a multiplication table for numbers up to 12.

def multiplication_table(n):
    for i in range(n+1):
        if(i ==0):
            continue
        for s in range(13):
            product = i * s
            print(i, "*", s, "=", product)
            

multiplication_table(12)
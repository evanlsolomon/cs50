print("Hello world! \nWelcome to mario.")
height = int(input("How many levels do you want the mountain to be? "))
print(f"you entered: {height}")
for level in range(height):
    print(" "*(height-(level+1))  +   (level+1)*"#"   + " " + (level+1)*"#" )


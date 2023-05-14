#Nicely printing the grades

def CoolDisplay(listarr):
	print("################")
	print("     GRADES      ")
	print("################")
	for i in range(len(listarr)-1):
		print(i+1,"=>",listarr[i])

#Going through the list and grading it
def grading(stdList):
	gradedList = []
	for std in stdList:
		try:
			num = int(std)
			#Grading conditionals
			if num > 90:
				gradedList.append("A+")
			elif num > 80:
				gradedList.append("A")
			elif num > 60:
				gradedList.append("B")
			elif num > 40:
				gradedList.append("C")
			elif num > 0:
				gradedList.append("F")
			else:
				gradedList.append("N/A")
		#Avoiding errors
		except Exception as e:
			gradedList.append("N/A")

	CoolDisplay(gradedList)

#Defining main head
def main():
	try:
		studentList = input("(-) Enter the numbers of all students(integer) in a single line : ").split()
		grading(studentList)
	except Exception as e:
		print("Something went wrong !!")
	
#Invoking main
if __name__ == '__main__':
	main()
  

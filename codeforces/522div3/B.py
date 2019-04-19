# Program in python 2.x to find an element X
# that can be used to operate on an array and
# get equal elements

# Prints "YES" and an element x if we can
# equalize array using x. Else prints "NO"
def canEqualise(array):

	# We all the unique elements (using set
	# function). Then we sort unique elements.
	uniques = sorted(set(array))

	# if there are only 1 or 2 unique elements,
	# then we can add or subtract x from one of them
	# to get the other element
	if len(uniques) == 1:
		print(0)
	elif len(uniques) == 2:
		if (uniques[1] - uniques[0])%2 == 0:
			print(int((uniques[1] - uniques[0])/2))
		else:
			print(uniques[1] - uniques[0])

	# If count of unique elements is three, then
	# difference between the middle and minimum
	# should be same as difference between maximum
	# and middle
	elif len(uniques) == 3:
		if uniques[2] - uniques[1] == uniques[1] - uniques[0]:
			X = uniques[2] - uniques[1]
			print(X)
		else:
			print(-1)

	# if there are more than three unique elements, then
	# we cannot add or subtract the same value from all
	# the elements.
	else:
		print(-1)

# Driver code
#array = [55, 52, 52, 49, 52]
#array = []
n = int(input())
str = input().split(' ')
array = [int(x) for x in str]
#print(array)
canEqualise(array)

print ("Enter number of elements")
n = int(input())
print ("Enter array")
l=list(map(int,input().split()))
print ("Enter element to be searched")
k = int(input())

flag = 0
for i in range(n):
	if l[i] == k:
		flag = 1
		pos = i
		break 

if flag == 0:
	print("Element not present")
else:
	print("Element is present at index", str(pos))

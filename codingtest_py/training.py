#initialize 'a', number of n
n = 100
a = [0] * n
print(a)

#index slicing
a = [1, 2, 3, 4, 5]
print(a[2:4])

#list comprehension
a = [i * 2 for i in range(20) if i % 2 == 1]
print(a)
n = 3
m = 4
arr = [[0] * m for _ in range(n)]
print(arr)

#remove element(for time complex)
a = [1, 2, 3, 4, 5, 5, 5]
remove_set = [3, 5]
result = [i for i in a if i not in remove_set]
print(result)


#function test
def add(a, b):
  print(a, ", ", b)


add(b=7, a=1)

#input
n = int(input())
data = list(map(int, input().split()))
data.sort(reverse=True)
print(data)
n, m, k = map(int, input().split())

#redline
import sys

data = sys.stdin.readline().rstrip()

#print
age = 22
#print("I'm "+22+"olds.") -> error
print("I'm " + str(age) + " olds.")
print("I'm", age, "olds.")  # "," make space
print("I'm {age} olds.")
import matplotlib.pyplot as plt

file = open("histogram", "r")
a = []
for line in file:
    a.append(float(line))
b = []
for i in range(0, 100):
    b.append(i * 1.8 - 90)
plt.bar(b, a * 1,2)
plt.show()

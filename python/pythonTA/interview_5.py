class Car:
    def __init__(self):
        self.capacity = 10
    def unload(self):
        if self.capacity == 10:
            print('車上沒有東西啦')
        else:
            self.capacity += 1
    def add_luggage(self):
        if self.capacity == 0:
            print('已經裝不下了，不然買一台卡車如何')
        else:
            self.capacity -= 1
    def isFull(self):
        return self.capacity == 0

myCar = Car()
print(myCar.capacity)
myCar.unload()
while not myCar.isFull():
    myCar.add_luggage()
myCar.add_luggage()
print(myCar.capacity)
print(myCar.isFull())
myCar.unload()
myCar.unload()
print(myCar.capacity)
print(myCar.isFull())

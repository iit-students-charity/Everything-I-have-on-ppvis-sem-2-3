import random
class Animal(object):
    def __init__(self):
        self.lifeClock=100
        self.nutrions=20
        self.travelDistance=1
        self.dieFlag=0
        self.sex=random.randint(0,1)
        self.id='animal'
    
    def multiply(self):
        self.nutrions-=30
        newLife=self()
        newLife.setNutrions(10)
        return newLife

    def setNutrions(self, x):
        self.nutrions=x

    def tick(self):
        self.lifeClock-=5
        self.nutrions-=2
        if(lifeClock<=0):
            self.die()

    def consume(self, x):
        self.nutrions+=x.nutrions
        if self.nutrions>100:
            self.nutrions=100

    def die(self):
        self.dieFlag=1

    def Priority(self):
        if(self.nutrions>50):
            return "mult"
        else:
            return "feed"

    def __str__(self):
        return self.id
    def __repr__(self):
        return self.id


class Elk(Animal):
    def __init__(self):
        self.id="elk"
        self.travelDistance=3
        self.food="plant"

class Rabbit(Animal):
    def __init__(self):
        self.id="rabbit"
        self.travelDistance=1
        self.food="plant"

class Wolf(Animal):
    def __init__(self):
        self.id="wolf"
        self.travelDistance=2
        self.food="rabbit", "Elk"
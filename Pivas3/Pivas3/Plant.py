class plant(object):
    def __init__(self):
        self.lifeClock=100
        self.nutrions=20
        self.dieFlag=0
        self.id="plant"

    def collectNutrions(self):
        self.nutrions+=4

    def multiply(self):
        self.nutrions-=30
        newLife=self()
        newLife.setNutrions(10)
        return newLife

    def setNutrions(self, x):
        self.nutrions=x

    def tick(self):
        self.lifeClock-=5
        if(lifeClock<=0):
            self.die()

    def die(self):
        self.dieFlag=1

    def turn(self):
        self.collectNutrions()
        self.tick()
        sap=None
        if self.nutrions>=35:
            sap=self.multiply()
        return sap

    def __str__(self):
        return self.id
    def __repr__(self):
        return self.id



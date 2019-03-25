from Animal import Elk, Rabbit, Wolf
from Plant import plant
import random
class PlayingField(object):
    
    def __init__(self, *args, **kwargs):
        self.fieldfItself=[[None for _ in range(0,21)] for _ in range(0,21)]
        self.plantPos={}
        self.elkPos={}
        self.wolfPos={}
        self.rabbitPos={}


    def clearField(self):
        self.fieldfItself=[None for _ in range(0,21)]

    def rollcoords(self):
        x,y=random.randint(0,20),random.randint(0,20)
        return x,y

    def place(self, obj, field, positions, num):
        x,y=self.rollcoords()
        if(field[x][y]==None):
            field[x][y]=obj
            temp=x,y
            obj.id=obj.id+str(num)
            positions[obj.id]=temp
            return True
        else:
            return False

        def move(self)

    def populate(self):
        totalstuff=0
        while(totalstuff<7):
            if self.place(plant(), self.fieldfItself, self.plantPos, totalstuff)==True:
                totalstuff+=1
        totalstuff=0
        while(totalstuff<3):
            if self.place(Elk(), self.fieldfItself, self.elkPos, totalstuff)==True:
                totalstuff+=1
        totalstuff=0
        while(totalstuff<3):
            if self.place(Rabbit(), self.fieldfItself, self.rabbitPos, totalstuff)==True:
                totalstuff+=1
        totalstuff=0
        while(totalstuff<6):
            if self.place(Wolf(), self.fieldfItself, self.wolfPos, totalstuff)==True:
                totalstuff+=1

    def locateTarget(entList, entity):

        pass

    def turn(self):
        pass

    def seek(self):
        pass

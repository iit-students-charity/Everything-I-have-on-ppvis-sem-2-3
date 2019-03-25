from PlayingField import PlayingField
import kivy

x=PlayingField()
x.populate()
for i in x.fieldfItself: print(str(i))
print(x.plantPos)
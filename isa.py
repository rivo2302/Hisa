# -*- coding: utf-8 -*-

"""
    Isa : Python module that translates a number
    into Malagasy letters 

    Author : rivo2302 | www.rivo.iteam-s.mg
"""

import sys

class Isa :
    """
       The class that contains each method of the model.
    """
    def __init__(self,item) :
        self.tokana = ["aotra","ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"]
        if str(item).isdigit() == False :
            print(f"Error  : The argument must Isa(args) be an integer")
            sys.exit()
        self.item = int(item)
    def __str__(self) :
        return self.__main(self.item)


    def __length(self, integer : int ) -> int:
        """
            Method that calculates the length of the number.
        Args:
            integer (_integer_): _description_

        Returns:
            _integer_: _len of the number in args_
        """
        if integer < 10 : res = 1
        elif integer < 100 : res = 2
        elif integer < 1000 : res = 3 
        elif integer < 10000 : res = 4
        elif integer < 100000 : res = 5
        elif integer < 1000000 : res = 6
        elif integer < 1000000000 : res = 7
        elif integer < 1000000000000 : res = 8
        return res

    def __iray(self , nb : int) -> str:
        return (self.tokana[int])

    
    def main (self , integer : int) -> str :
        if self.__length(integer) == 0 : return self.__iray(integer)

            

rivo = Isa("75")
print(rivo)

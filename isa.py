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
        self.tokana = ["aotra","ray","roa","telo","efatra","dimy","enina","fito","valo","sivy","folo"]
        self.folo = ["","folo","roapolo","telopolo","efapolo","dimampolo","enimpolo","fitopolo","valopolo","sivy folo"]

        if str(item).isdigit() == False :
            print(f"Error  : The argument must Isa(args) be an integer")
            sys.exit()
        self.item = int(item)
    def __str__(self) :
        return self.main(self.item)


    def __length(self, nb : int ) -> int:
        """
            Method that calculates the length of the number.
        Args:
            nb (_integer_): _description_

        Returns:
            _integer_: _len of the number in args_
        """
        if nb < 10 : res = 1
        elif nb < 100 : res = 2
        elif nb < 1000 : res = 3 
        elif nb < 10000 : res = 4
        elif nb < 100000 : res = 5
        elif nb < 1000000 : res = 6
        elif nb < 1000000000 : res = 7
        elif nb < 1000000000000 : res = 8
        return res

    def __iray(self , nb : int) -> str:
        return (self.tokana[nb])
    
    def __roa (self , nb : int) -> str :
        if (nb%10) == 0 : return self.tokana[nb]
    
    def main (self , nb : int) -> str :
        if self.__length(nb) == 1 : res = self.__iray(nb)
        elif self.__length(nb) == 2 : res = self.__roa(nb)
        return res.capitalize()

            

rivo = Isa("10")
print(rivo)

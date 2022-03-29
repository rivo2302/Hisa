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
        self.tokana = ["","ray","roa","telo","efatra","dimy","enina","fito","valo","sivy","folo"]
        self.folo = ["","folo","roapolo","telopolo","efapolo","dimampolo","enimpolo","fitopolo","valopolo","sivifolo"]
        self.zato = ["","zato","roanjato","telonjato","efajato","dimanjato","eninjato","fitonjato","valonjato","sivanjato"]
        
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
        elif nb < 10000000 : res = 6
        elif nb < 10000000000: res = 7
        elif nb < 1000000000000000000 : res = 8
        else : res = 10
        return res

    def __iray(self , nb : int) -> str:
        if nb == 0 : return "aotra"
        return (self.tokana[nb])
    
    def __roa (self , nb : int) -> str :
        if (nb%10) == 0 : return self.folo[nb//10]
        elif (int(nb//10) == 1) : 
            if nb%10 == 1 : return "iraika ambiny folo"
            return f"{self.tokana[nb%10]} ambiny folo"
        return f"{self.tokana[nb%10]} amby {self.folo[nb//10]}"
    
    def __telo (self , nb : int) -> str :
        if nb%100 ==  0 : return self.zato[nb//100]
        elif nb%100 ==  1 : return "iraika amby zato"
        elif nb // 100 == 1 :
            return (f"{Isa(nb%100)} amby zato")
        return (f"{Isa(nb%100)} sy {self.zato[nb//100]}")
        
    def __efatra (self , nb : int) -> str : 
        if nb%1000 == 0 :
            if nb//1000 == 1 : return "arivo"
            else : return f"{self.tokana[nb//1000]} arivo"
        x = Isa(nb%1000)
        if nb//1000 == 1 : return f"{x} sy arivo"
        return f"{x} sy {self.tokana[nb//1000]} arivo"

    def __dimy (self , nb : int) -> str : 
        if nb%10000 == 0 : return f"{self.tokana[nb//10000]} alina"
        return f"{Isa(nb%10000)} sy {self.tokana[nb//10000]} alina"

    def __enina (self , nb : int) -> str : 
        if nb%100000 == 0 : return f"{self.tokana[nb//100000]} hetsy"
        return f"{Isa(nb%100000)} sy {self.tokana[nb//100000]} hetsy"

    def __fito (self , nb : int) -> str : 
        if nb%1000000 == 0 : return f"{Isa(nb//1000000)} tapitrisa"
        return f"{Isa(nb%1000000)} sy {Isa(nb//1000000)} tapitrisa"

    def __valo (self , nb : int) -> str : 
        if nb%1000000000 == 0 : return f"{Isa(nb//1000000000)} lavitrisa"
        return f"{Isa(nb%1000000000)} sy {Isa(nb//1000000000)} lavitrisa"

    def main (self , nb : int) -> str :
        if self.__length(nb) == 1 : res = self.__iray(nb)
        elif self.__length(nb) == 2 : res = self.__roa(nb)
        elif self.__length(nb) == 3 : res = self.__telo(nb)
        elif self.__length(nb) == 4 : res = self.__efatra(nb)
        elif self.__length(nb) == 5 : res = self.__dimy(nb)
        elif self.__length(nb) == 6 : res = self.__enina(nb)
        elif self.__length(nb) == 7 : res = self.__fito(nb)
        elif self.__length(nb) == 8 : res = self.__valo(nb)
        else : return "Be loatra kosa zany eeeee "
        return res

    
rivo = Isa("2000000000")
print(rivo)
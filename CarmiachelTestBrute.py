# -*- coding: utf-8 -*-
"""
Created on Thu Sep  8 09:15:00 2022

@author: Anirudh Sathish
"""

# Defining Packages
import math 

class carmiachelNumbers(object):
    # Initilizing values 
    def __init__(self,inputNumber):
        self.NumberToBeTested = inputNumber
    def isOdd(self):
        #Function checks if given number is odd 
        if(self.NumberToBeTested %2) == 0:
            return False
        else:
            return True
    def isCompositeMethod1(self):
        #Function to check if the number is composite or prime 
        rootOfNumber = math.sqrt(self.NumberToBeTested)
        i = 2
        while( i <= rootOfNumber):
            if(self.NumberToBeTested%i == 0):
                return True
            i+=1
        return False
    def FindGCD(self,numberForTest ,iteratingNumber):
        #Finds gcd of two numbers 
        if(iteratingNumber == 0):
            return numberForTest
        else:
            return self.FindGCD(iteratingNumber,numberForTest%iteratingNumber)
    def appropriateGCD(self,HCF_test):
        #Function checks if the HCF of two numbers is 1
        #Which is a criterion in fermat's test 
        if(HCF_test == 1):
            return True
        return False
    def FermatTestResult(self , iteratingNumber , raisedPower , modvalue):
        #Performing Fermat's test 
        if(raisedPower == 0):
            return 1
        #Keep on reducing the number 
        RHS = self.FermatTestResult(iteratingNumber,raisedPower//2,modvalue)%modvalue
        RHS = (RHS*RHS) % modvalue
        if(raisedPower %2 == 1):
            RHS = (RHS*iteratingNumber) % modvalue
        return RHS
        
    def isPassedFermatTest(self,iteratingNumber , raisedPower ,modvalue):
        RHS = self.FermatTestResult(iteratingNumber,raisedPower,modvalue)
        if(RHS ==1):
            return True
        return False
    
    def FinalTest(self):
        number = self.NumberToBeTested
        for i in range(2,number):
            HCF = self.FindGCD(number,i)
            TheResult = self.appropriateGCD(HCF)
            fermatResult = self.isPassedFermatTest(i,number-1, number)
            if(TheResult == True):
                if(fermatResult == False):
                    return False
        return True
    #Printing on basis -> 
    def Print(self,status):
        if(status == 1):
            print("The number ",self.NumberToBeTested," is a carmiachel number ")
        elif(status == 0):
            print("The number ",self.NumberToBeTested," is not a carmiachel number")

#Running the body

#Taking input 
inputNumber = int(input("Enter the number "))

#Initalizing the object
numberSystem = carmiachelNumbers(inputNumber)

level1Test = numberSystem.isOdd()
if(level1Test == False):
    numberSystem.Print(0)
else:
    level2Test = numberSystem.isCompositeMethod1()
    if(level2Test == False):
        numberSystem.Print(0)
    else:
        final = numberSystem.FinalTest()
        if(final == False):
            numberSystem.Print(0)
        else:
            numberSystem.Print(1)
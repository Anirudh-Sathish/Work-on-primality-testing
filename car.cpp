//@ Author : Anirudh Sathish
//To find if a given number , less than 10^5 , is a carmiachel number 


#include<iostream>
#include<math.h>
using namespace std ;

/*----------------------------------------------------------------------------*/
class carmiachelNumbers
{
    private:
        long long int number;
        long long int hcf;
    public:
           carmiachelNumbers() // Constructor
           {

           }
           // Paramterised constructor 
           carmiachelNumbers(long long int inputForCarmiachel)
           {
               number = inputForCarmiachel;
           }
           //Function to check if a given number is Odd
           bool isOdd()
           {
               if(number%2 == 0)
                  return false;
               else
                  return true;
           }
           //Function to check if a given number is composite 
           bool isCompositeMethod1()
           {
               long long int rootOfNumber = sqrt(number);

               for(int i = 2 ; i <= rootOfNumber; i++)
               {
                   if(number%i==0)
                   {
                       return true;
                   }
               }
               return false; 
           }
           //Function to find the Greatest Common divisior , 
           //between two numbers
           int gcd(int numberForCarmiachel ,int iteratingNumber )
           {
               if(iteratingNumber==0)
               {
                   return numberForCarmiachel;
               }
               else
               {
                   return gcd(iteratingNumber,numberForCarmiachel%iteratingNumber);
               }
           }
           //Function to check if the Greatest common divisor of two numbers 
           //is 1 
           bool appropriateGCD(int hcf)
           {
               if(hcf == 1)
               {
                   return true;
               }
               return false;
           }
           //Function to check for part of fermat's test
           int FermatTest(int iteratingNumber , int raisedpower , int modvalue)
           {
               if(raisedpower==0)
               {
                   return 1;
               }
               int RHS = FermatTest(iteratingNumber,raisedpower/2,modvalue)%modvalue;
               
               RHS= (RHS*RHS)%modvalue;
               if(raisedpower % 2 ==1) 
               {
                   RHS = (RHS*iteratingNumber) % modvalue;
               }
               return RHS;
           }
           //Function to check if number passes part of fermat's test 
           bool passFermatTest(int iteratingNumber , int raisedpower , int modvalue)
           {
               int RHS = FermatTest(iteratingNumber,raisedpower,modvalue);

               if(RHS==1)
               {
                   return true;
               }
               return false;

           }
           //Function to check if the number is carmiachel number , given 
           //that it is odd and composite 
           bool FinalTest()
           {
               int i;
               for(i = 2 ; i <number ;i++)
               {
                   hcf = gcd(number,i);
                   bool TheResult = appropriateGCD(hcf);
                   bool fermatResult = passFermatTest(i,number-1,number);
                   cout<<"I here is "<<i<<endl;
                   if(TheResult == true && fermatResult==false)
                   {
                       cout<<"I here is "<<i<<endl;
                       return false;
                   }
               }
               return true;
           }

           /*---------------------------------------------------------------*/
           //For printing

           void notCarmiachelNumber()
           {
               cout<<"The number "<<number<<" is not a Carmiachel number"<<endl;
           }
           void isCarmiachelNumber()
           {
               cout<<"The number  "<<number<<" is a Carmiachel Number"<<endl;
           }
};


/*----------------------------------------------------------------------------*/
int main()
{
    long long int numberForCarmiachel;

    cout<<"Enter the number"<<endl;
    cin>>numberForCarmiachel;

    carmiachelNumbers numberToCheck(numberForCarmiachel);
    bool level1Test= numberToCheck.isOdd();
    
    // Checking if the given number is odd
    //If not odd , then it can't be carmiachel number 
    //So we can stop looking in case the number is even 

    if(level1Test==false) // number is even , so we can stop for those numbers over here 
    {
        numberToCheck.notCarmiachelNumber();
        return 0;
    }

    bool level2Test = numberToCheck.isCompositeMethod1();
    //Checking if the given number is composite 
    //If number is not composite , then it would be a prime and we would 
    // no longer need to classify it as carmiachel number 
    //
    if(level2Test == false)// number is prime , so we can stop checking for carmiachel
    {
        numberToCheck.notCarmiachelNumber();
        return 0;
    }

    //Now , we further check if the number is carmiachel number 
    // By checking if it can pass the fermat's primality test 
    // For this we need to find an a , such that 
    //gcd(a,n)= 1 and 
    bool final = numberToCheck.FinalTest();

    if(final == false)
    {
        numberToCheck.notCarmiachelNumber();
    }
    else
    {
        numberToCheck.isCarmiachelNumber();
    }

    return 0;


}

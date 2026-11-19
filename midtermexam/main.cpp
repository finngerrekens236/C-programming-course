#include <iostream>
#include <string>
#include <cmath>

    // int main() {

    //     //step 1

    //     double realValues [7] {};
    //     double imaginaryValues [7] {};

    //     //step 2

    //     double imaginary;
    //     for(int i{0} ; i < 7 ;++i){
    //         imaginary=0;
    //         std::cout << "Please type in realValue:" << i+1 << std::endl;
    //         std::cin >> realValues[i];

    //         std::cout << "Please type in imaginary value:" << i+1 << std::endl;

    //         std::cin >> imaginary;
    //         while (imaginary < 0){

    //             std::cout << "imaginary value cant be negative" <<std::endl;

    //             std::cout << "Please type in in imaginary value:" << i+1 << std::endl;
    
    //             std::cin >> imaginary;
    //         }

    //         imaginaryValues[i]=imaginary;
    //     }
    // }










    // // step 3


    // int main(){

    //     int arraySize;

    //     std::cout << "Please type your desired number of complex numbers:" << std::endl;
    //     std::cin >> arraySize;
    //     while (arraySize <=0){

    //         std::cout << "array size must be greater than 0. please enter your desired number of complex numbers" << std::endl;
    //         std::cin >> arraySize;
    //     }




    //     double *realValues { new double  [arraySize] {}};
    //     double *imaginaryValues { new double [arraySize] {}};


    //     double imaginary;
    //     for(int i = 0 ; i < arraySize ;++i){
    //         imaginary=0;
    //         std::cout << "Please type in real value of coplex number:" << i+1 << std::endl;
    //         std::cin >> realValues[i];

    //         std::cout << "Please type in imaginary value of coplex number:" << i+1 << std::endl;

    //         std::cin >> imaginary;
    //         while (imaginary < 0){

    //             std::cout << "imaginary value cant less than 0" <<std::endl;
    //             std::cout << "Please type in imaginary value of coplex number:" << i+1 << std::endl;
    
    //             std::cin >> imaginary;
    //         }

    //         imaginaryValues[i]=imaginary;
    //     }
        
    //     delete [] realValues;
    //     realValues = nullptr;

    //     delete [] imaginaryValues;
    //     imaginaryValues = nullptr;

    // }














    // // step 4


    // int main(){

    //     int arraySize;

    //     std::cout << "Please type your desired number of complex numbers:" << std::endl;
    //     std::cin >> arraySize;
    //     while (arraySize <=0){

    //         std::cout << "array size must be greater than 0. please enter your desired number of complex numbers" << std::endl;
    //         std::cin >> arraySize;
    //     }




    //     double *realValues { new double  [arraySize] {}};
    //     double *imaginaryValues { new double [arraySize] {}};


    //     double imaginary;
    //     for(int i = 0 ; i < arraySize ;++i){
    //         imaginary=0;
    //         std::cout << "Please type in real value of coplex number:" << i+1 << std::endl;
    //         std::cin >> realValues[i];

    //         std::cout << "Please type in imaginary value of coplex number:" << i+1 << std::endl;

    //         std::cin >> imaginary;
    //         while (imaginary < 0){

    //             std::cout << "imaginary value cant less than 0" <<std::endl;
    //             std::cout << "Please type in imaginary value of coplex number:" << i+1 << std::endl;
    
    //             std::cin >> imaginary;
    //         }

    //         imaginaryValues[i]=imaginary;
    //     }



    //     for(int i = 0 ; i < arraySize ;++i){

    //         double imaginary = imaginaryValues[i];
    //         double real = realValues[i];


    //         double absolut = sqrt(imaginary * imaginary + real * real);


    //         std::string absoluteValue = "the absolute value of complex number " +std:: to_string(i) + " is: " + std::to_string(absolut);

    //         std::cout << absoluteValue << std::endl;



    //     }
        
    //     delete [] realValues;
    //     realValues = nullptr;

    //     delete [] imaginaryValues;
    //     imaginaryValues = nullptr;

    // }















    // // step 5


    // int main(){




    //     // initialize and read array size
    //     int arraySize;

    //     std::cout << "Please type your desired number of complex numbers:" << std::endl;
    //     std::cin >> arraySize;
    //     while (arraySize <=0){

    //         std::cout << "array size must be greater than 0. please enter your desired number of complex numbers" << std::endl;
    //         std::cin >> arraySize;
    //     }



    //     // declare arrays with dynamic size
    //     double *realValues { new double  [arraySize] {}};
    //     double *imaginaryValues { new double [arraySize] {}};




    //     // ask user for values of complex nummbers
    //     double imaginary;
    //     for(int i = 0 ; i < arraySize ;++i){
    //         imaginary=0;
    //         std::cout << "Please type in real value of coplex number:" << i+1 << std::endl;
    //         std::cin >> realValues[i];

    //         std::cout << "Please type in imaginary value of coplex number:" << i+1 << std::endl;

    //         std::cin >> imaginary;
    //         while (imaginary < 0){

    //             std::cout << "imaginary value cant less than 0" <<std::endl;
    //             std::cout << "Please type in imaginary value of coplex number:" << i+1 << std::endl;
    
    //             std::cin >> imaginary;
    //         }

    //         imaginaryValues[i]=imaginary;
    //     }


    //     // make object in class string out of each imaginary number and print the string
    //     for(int i = 0 ; i < arraySize ;++i){

    //         double imaginary = imaginaryValues[i];
    //         double real = realValues[i];


    //         double absolut = sqrt(imaginary * imaginary + real * real);


    //         std::string absoluteValue = "the absolute value of complex number " +std:: to_string(i) + " is: " + std::to_string(absolut);

    //         std::cout << absoluteValue << std::endl;



    //     }
        

    //     // give the dynamicly assigned memory back
    //     delete [] realValues;
    //     realValues = nullptr;

    //     delete [] imaginaryValues;
    //     imaginaryValues = nullptr;

    // }


























    
    // // step 6




    // void readInComplexNumber(double& real, double& imagin);
    // double calcAbsoluteValue(double real, double imagin);


    // int main(){


    //     // initialize and read array size
    //     int arraySize;

    //     std::cout << "Please type your desired number of complex numbers:" << std::endl;
    //     std::cin >> arraySize;
    //     while (arraySize <=0){

    //         std::cout << "array size must be greater than 0. please enter your desired number of complex numbers" << std::endl;
    //         std::cin >> arraySize;
    //     }



    //     // declare arrays with dynamic size
    //     double *realValues { new double  [arraySize] {}};
    //     double *imaginaryValues { new double [arraySize] {}};




    //     // ask user for values of complex nummbers
    //     for(int i = 0 ; i < arraySize ;++i){

    //         std::cout << "complex number " << i + 1 << ":" << std::endl;
    //         readInComplexNumber(realValues[i], imaginaryValues[i]);
    //     }


    //     // make object in class string out of each imaginary number and print the string
    //     for(int i = 0 ; i < arraySize ;++i){

    //         double absolut = calcAbsoluteValue(realValues[i], imaginaryValues[i]);

    //         std::string absoluteValue = "the absolute value of complex number " +std:: to_string(i) + " is: " + std::to_string(absolut);

    //         std::cout << absoluteValue << std::endl;

    //     }
        

    //     // give the dynamicly assigned memory back
    //     delete [] realValues;
    //     realValues = nullptr;

    //     delete [] imaginaryValues;
    //     imaginaryValues = nullptr;

    // }

    // // function for reading in a complex number
    // void readInComplexNumber(double& real, double& imagin){

        
    //     std::cout << "Please type in real value:" << std::endl;
    //     std::cin >> real;

    //     std::cout << "Please type in inmaginary value:" << std::endl;

    //     std::cin >> imagin;

    //     while (imagin < 0){

    //         std::cout << "inmaginary value cant be less than 0" <<std::endl;

    //         std::cout << "Please type in inmaginary value:" << std::endl;

    //         std::cin >> imagin;

    //     }

    // }

    // // function for calcculating absolute value of a complex number
    // double calcAbsoluteValue(double real, double imagin){

    //     return sqrt(imagin * imagin + real * real);

    // }









































    // step 7







    class Complex {

        private:

        double realValue;
        double imaginaryValue;

        public:
       
        double GetAbsolute(){
           return sqrt(imaginaryValue * imaginaryValue + realValue * realValue);
        }

        void setImaginary(double im){

            if (im < 0){
                std::cout << "setting imaginary value Faild imaginary value cant be less than 0" << std::endl;
                
            }else{
            imaginaryValue = im;
            }
        }

        void setReal(double real){
            realValue=real;
        }

    

    };





    void readInComplexNumber(Complex& number);


    int main(){


        // initialize and read array size
        int arraySize;

        std::cout << "Please type your desired number of complex numbers:" << std::endl;
        std::cin >> arraySize;
        while (arraySize <=0){

            std::cout << "array size must be greater than 0. please enter your desired number of complex numbers" << std::endl;
            std::cin >> arraySize;
        }



        // declare arrays with dynamic size
        // double *realValues { new double  [arraySize] {}};
        // double *imaginaryValues { new double [arraySize] {}};
        Complex *complexNumbers {new Complex[arraySize]{}};




        // ask user for values of complex nummbers
        for(int i = 0 ; i < arraySize ;++i){

            std::cout << "complex number " << i + 1 << ":" << std::endl;
            readInComplexNumber(complexNumbers[i]);
        }


        // make object in class string out of each imaginary number and print the string
        for(int i = 0 ; i < arraySize ;++i){

            double absolut = complexNumbers[i].GetAbsolute();

            std::string absoluteValue = "the absolute value of complex number " +std:: to_string(i) + " is: " + std::to_string(absolut);

            std::cout << absoluteValue << std::endl;

        }
        

        // give the dynamicly assigned memory back

        delete [] complexNumbers;
        complexNumbers = nullptr;



    }

    // function for reading in a complex number
    void readInComplexNumber(Complex& number){

        double real;
        std::cout << "Please type in real value:" << std::endl;
        std::cin >> real;
        number.setReal(real);

        std::cout << "Please type in inmaginary value:" << std::endl;
        double imagin;
        std::cin >> imagin;

        while (imagin < 0){

            std::cout << "inmaginary value cant be less than 0" <<std::endl;

            std::cout << "Please type in inmaginary value:" << std::endl;

            std::cin >> imagin;

        }
        number.setImaginary(imagin);

    }













    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
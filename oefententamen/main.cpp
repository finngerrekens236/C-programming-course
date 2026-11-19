    #include <iostream>

    // int main() {

        // //step 1

        // double numerators [5] {};
        // double denominators [5] {};

        // //step 2

        // double denominator;
        // for(int i{0} ; i < 5 ;++i){
        //     denominator=0;
        //     std::cout << "Please type in numerator:" << i+1 << std::endl;
        //     std::cin >> numerators[i];

        //     std::cout << "Please type in denominator:" << i+1 << std::endl;

        //     std::cin >> denominator;
        //     while (denominator==0){

        //         std::cout << "denominator cant be 0" <<std::endl;

        //         std::cout << "Please type in denominator:" << i+1 << std::endl;
    
        //         std::cin >> denominator;
        //     }

        //     denominators[i]=denominator;
        // }







        // // step 3

        // int arraySize;

        // std::cout << "Please type your desired array size:" << std::endl;
        // std::cin >> arraySize;
        // while (arraySize <=0){

        //     std::cout << "array size must be greater than 0. please enter desired array size" << std::endl;
        //     std::cin >> arraySize;
        // }




        // double *numerators { new double  [arraySize] {}};
        // double *denominators { new double [arraySize] {}};


        // double denominator;
        // for(int i{0} ; i < arraySize ;++i){
        //     denominator=0;
        //     std::cout << "Please type in numerator:" << i+1 << std::endl;
        //     std::cin >> numerators[i];

        //     std::cout << "Please type in denominator:" << i+1 << std::endl;

        //     std::cin >> denominator;
        //     while (denominator==0){

        //         std::cout << "denominator cant be 0" <<std::endl;

        //         std::cout << "Please type in denominator:" << i+1 << std::endl;
    
        //         std::cin >> denominator;
        //     }

        //     denominators[i]=denominator;
        // }
        
        // delete [] numerators;
        // numerators = nullptr;

        // delete [] denominators;
        // denominators = nullptr;







    //     // step 4

    // int main() {


    //     int arraySize;

    //     std::cout << "Please type your desired array size:" << std::endl;
    //     std::cin >> arraySize;
    //     while (arraySize <=0){

    //         std::cout << "array size must be greater than 0. please enter desired array size" << std::endl;
    //         std::cin >> arraySize;
    //     }




    //     double *numerators { new double  [arraySize] {}};
    //     double *denominators { new double [arraySize] {}};

    //     double denominator;
    //     for(int i{0} ; i < arraySize ;++i){
    //         denominator=0;
    //         std::cout << "Please type in numerator:" << i+1 << std::endl;
    //         std::cin >> numerators[i];

    //         std::cout << "Please type in denominator:" << i+1 << std::endl;

    //         std::cin >> denominator;
    //         while (denominator==0){

    //             std::cout << "denominator cant be 0" <<std::endl;

    //             std::cout << "Please type in denominator:" << i+1 << std::endl;
    
    //             std::cin >> denominator;
    //         }

    //         denominators[i]=denominator;


            

    //     }

    //     for(int i{0} ; i < arraySize ;++i){

    //         std::cout << "decimal value:" << i+1 << "=" << numerators[i] / denominators[i] << std::endl;

    //     }


        
    //     delete [] numerators;
    //     numerators = nullptr;

    //     delete [] denominators;
    //     denominators = nullptr;

       
    // }





    // // step 6



    // //function reading of one fraction number 
    // void readFraction(double& numerator, double& denominator);

    // double calcFraction(double num, double den);

        

    // int main() {


    //     int arraySize;

    //     std::cout << "Please type your desired array size:" << std::endl;
    //     std::cin >> arraySize;
    //     while (arraySize <=0){

    //         std::cout << "array size must be greater than 0. please enter desired array size" << std::endl;
    //         std::cin >> arraySize;
    //     }


    //     double *numerators { new double  [arraySize] {}};
    //     double *denominators { new double [arraySize] {}};

    //     for(int i{0} ; i < arraySize ;++i){

    //         std::cout << "Fraction " << i + 1 << ":" << std::endl;
    //         readFraction(numerators[i], denominators[i]);           

    //     }

    //     for(int i{0} ; i < arraySize ;++i){

    //         double decimalValue = calcFraction(numerators[i], denominators[i]);

    //         std::cout << "decimal value:" << i+1 << "=" << decimalValue << std::endl;

    //     }

        
    //     delete [] numerators;
    //     numerators = nullptr;

    //     delete [] denominators;
    //     denominators = nullptr;

        
    // }

    // void readFraction(double& numerator, double& denominator){

    //     denominator=0;
    //     std::cout << "Please type in numerator:" << std::endl;
    //     std::cin >> numerator;

    //     std::cout << "Please type in denominator:" << std::endl;

    //     std::cin >> denominator;

    //     while (denominator==0){

    //         std::cout << "denominator cant be 0" <<std::endl;

    //         std::cout << "Please type in denominator:" << std::endl;

    //         std::cin >> denominator;
    //     }

    // }

    // double calcFraction(double num, double den){

    //     return num / den;

    // }






    
    // step 7


    class fraction {

        public:
       
        double fractionValue(){
           return numerator / denominator; 
        }

        void setDenominator(double den){
            if(den != 0){
            denominator = den;
            }
        }
        double getDenominator(){
            return denominator;
        }
        double numerator = 0;


        private:
        
        double denominator = 1;
    

    };



    //function reading of one fraction number 
    void readFraction(fraction& frac);



        

    int main() {


        int arraySize;

        std::cout << "Please type your desired array size:" << std::endl;
        std::cin >> arraySize;
        while (arraySize <=0){

            std::cout << "array size must be greater than 0. please enter desired array size" << std::endl;
            std::cin >> arraySize;
        }


        fraction *fractions { new fraction  [arraySize] {}};

        for(int i{0} ; i < arraySize ;++i){

            std::cout << "Fraction " << i + 1 << ":" << std::endl;
            readFraction(fractions[i]);           

        }

        for(int i{0} ; i < arraySize ;++i){

            double decimalValue = fractions[i].fractionValue();

            std::cout << "decimal value:" << i+1 << "=" << decimalValue << std::endl;

        }

        
        delete [] fractions;
        fractions = nullptr;


       
    }

    void readFraction(fraction& frac){

        
        std::cout << "Please type in numerator:" << std::endl;
        std::cin >> frac.numerator;

        std::cout << "Please type in denominator:" << std::endl;
        double denominator;
        std::cin >> denominator;

        while (denominator==0){

            std::cout << "denominator cant be 0" <<std::endl;

            std::cout << "Please type in denominator:" << std::endl;

            std::cin >> denominator;
        }
        frac.setDenominator(denominator);

    }

 
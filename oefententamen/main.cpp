    #include <iostream>




    // int main() {

    //     //step 1

    //     double numerators [5] {};
    //     double denominators [5] {};

    //     //step 2

    //     double denominator;
    //     for(int i{0} ; i < 5 ;++i){
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
    // }




    // // step 3
    // int main(){

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
        
    //     delete [] numerators;
    //     numerators = nullptr;

    //     delete [] denominators;
    //     denominators = nullptr;

    // }







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






    
    // // step 7


    // class Fraction {

    //     public:
       
    //     double fractionValue(){
    //        return numerator / denominator; 
    //     }

    //     void setDenominator(double den){

    //         if (den == 0){
    //             std::cout << "setting Denominator Faild Denominator cant be 0" << std::endl;
                
    //         }else{
    //         denominator = den;
    //         }
    //     }
    //     double getDenominator(){
    //         return denominator;
    //     }
    //     double numerator = 0;


    //     private:
        
    //     double denominator = 1;
    

    // };



    // //function reading of one fraction number 
    // void readFraction(Fraction& frac);



        

    // int main() {


    //     int arraySize;

    //     std::cout << "Please type your desired array size:" << std::endl;
    //     std::cin >> arraySize;
    //     while (arraySize <=0){

    //         std::cout << "array size must be greater than 0. please enter desired array size" << std::endl;
    //         std::cin >> arraySize;
    //     }


    //     Fraction *fractions { new Fraction  [arraySize] {}};

    //     for(int i{0} ; i < arraySize ;++i){

    //         std::cout << "Fraction " << i + 1 << ":" << std::endl;
    //         readFraction(fractions[i]);           

    //     }

    //     for(int i{0} ; i < arraySize ;++i){

    //         double decimalValue = fractions[i].fractionValue();

    //         std::cout << "decimal value:" << i+1 << "=" << decimalValue << std::endl;

    //     }

        
    //     delete [] fractions;
    //     fractions = nullptr;


       
    // }

    // void readFraction(Fraction& frac){

        
    //     std::cout << "Please type in numerator:" << std::endl;
    //     std::cin >> frac.numerator;

    //     std::cout << "Please type in denominator:" << std::endl;
    //     double denominator;
    //     std::cin >> denominator;

    //     while (denominator==0){

    //         std::cout << "denominator cant be 0" <<std::endl;

    //         std::cout << "Please type in denominator:" << std::endl;

    //         std::cin >> denominator;
    //     }
    //     frac.setDenominator(denominator);

    // }

 
























































//     // stap 7a - class Fraction met constructors
// #include <iostream>

// class Fraction {

//     public:

//     // default constructor: nodig voor new Fraction[arraySize]
//     Fraction() {}

//     // constructor met teller en noemer; de noemer gaat via de setter (0-check)
//     Fraction(double num, double den) {
//         numerator = num;
//         setDenominator(den);
//     }

//     double fractionValue() {
//         return numerator / denominator;
//     }

//     void setDenominator(double den) {
//         if (den == 0) {
//             std::cout << "setting denominator failed, denominator can't be 0" << std::endl;
//         } else {
//             denominator = den;
//         }
//     }

//     double getDenominator() {
//         return denominator;
//     }

//     double numerator = 0;

//     private:

//     double denominator = 1;
// };


// // function reading of one fraction number
// void readFraction(Fraction& frac);


// int main() {

//     int arraySize;

//     std::cout << "Please type your desired array size:" << std::endl;
//     std::cin >> arraySize;
//     while (arraySize <= 0) {
//         std::cout << "array size must be greater than 0. please enter desired array size" << std::endl;
//         std::cin >> arraySize;
//     }

//     Fraction *fractions { new Fraction [arraySize] {} };

//     for (int i{0}; i < arraySize; ++i) {
//         std::cout << "Fraction " << i + 1 << ":" << std::endl;
//         readFraction(fractions[i]);
//     }

//     for (int i{0}; i < arraySize; ++i) {
//         double decimalValue = fractions[i].fractionValue();
//         std::cout << "decimal value " << i + 1 << ": " << decimalValue << std::endl;
//     }

//     delete [] fractions;
//     fractions = nullptr;

//     return 0;
// }

// void readFraction(Fraction& frac) {

//     double numerator;
//     double denominator;

//     std::cout << "Please type in numerator:" << std::endl;
//     std::cin >> numerator;

//     std::cout << "Please type in denominator:" << std::endl;
//     std::cin >> denominator;

//     while (denominator == 0) {
//         std::cout << "denominator can't be 0" << std::endl;
//         std::cout << "Please type in denominator:" << std::endl;
//         std::cin >> denominator;
//     }

//     // nieuw object maken met de constructor
//     frac = Fraction(numerator, denominator);
// }




























// stap 8 - operator>> en operator<< overloaden
#include <iostream>

class Fraction {

    public:

    Fraction() {}

    Fraction(double num, double den) {
        numerator = num;
        setDenominator(den);
    }

    // const: verandert het object niet (nodig omdat operator<< een const& krijgt)
    double fractionValue() const {
        return numerator / denominator;
    }

    void setDenominator(double den) {
        if (den == 0) {
            std::cout << "setting denominator failed, denominator can't be 0" << std::endl;
        } else {
            denominator = den;
        }
    }

    double getDenominator() const {
        return denominator;
    }

    double numerator = 0;

    private:

    double denominator = 1;
};


// operator voor inlezen: vervangt readFraction (object by reference, want het wordt gevuld)
std::istream& operator>>(std::istream& in, Fraction& frac);

// operator voor schrijven: object als const reference, want het wordt alleen gelezen
std::ostream& operator<<(std::ostream& out, const Fraction& frac);


int main() {

    int arraySize;

    std::cout << "Please type your desired array size:" << std::endl;
    std::cin >> arraySize;
    while (arraySize <= 0) {
        std::cout << "array size must be greater than 0. please enter desired array size" << std::endl;
        std::cin >> arraySize;
    }

    Fraction *fractions { new Fraction [arraySize] {} };

    for (int i{0}; i < arraySize; ++i) {
        std::cout << "Fraction " << i + 1 << ":" << std::endl;
        std::cin >> fractions[i];
    }

    for (int i{0}; i < arraySize; ++i) {
        std::cout << "Fraction " << i + 1 << ": " << fractions[i] << std::endl;
    }

    delete [] fractions;
    fractions = nullptr;

    return 0;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {

    double numerator;
    double denominator;

    std::cout << "Please type in numerator:" << std::endl;
    in >> numerator;

    std::cout << "Please type in denominator:" << std::endl;
    in >> denominator;

    while (denominator == 0) {
        std::cout << "denominator can't be 0" << std::endl;
        std::cout << "Please type in denominator:" << std::endl;
        in >> denominator;
    }

    frac = Fraction(numerator, denominator);

    return in;   // stream teruggeven voor chaining
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {

    // denominator is private, dus via de getter
    out << frac.numerator << "/" << frac.getDenominator() << " = " << frac.fractionValue();

    return out;  // stream teruggeven voor chaining
}

































// // stap 9 - container van array naar std::list
// #include <iostream>
// #include <list>

// class Fraction {

//     public:

//     Fraction() {}

//     Fraction(double num, double den) {
//         numerator = num;
//         setDenominator(den);
//     }

//     double fractionValue() const {
//         return numerator / denominator;
//     }

//     void setDenominator(double den) {
//         if (den == 0) {
//             std::cout << "setting denominator failed, denominator can't be 0" << std::endl;
//         } else {
//             denominator = den;
//         }
//     }

//     double getDenominator() const {
//         return denominator;
//     }

//     double numerator = 0;

//     private:

//     double denominator = 1;
// };


// std::istream& operator>>(std::istream& in, Fraction& frac);
// std::ostream& operator<<(std::ostream& out, const Fraction& frac);


// int main() {

//     int arraySize;

//     std::cout << "Please type your desired number of fractions:" << std::endl;
//     std::cin >> arraySize;
//     while (arraySize <= 0) {
//         std::cout << "number must be greater than 0. please enter desired number of fractions" << std::endl;
//         std::cin >> arraySize;
//     }

//     // list in plaats van new[]: groeit zelf, geen delete[] nodig
//     std::list<Fraction> fractions;

//     for (int i{0}; i < arraySize; ++i) {
//         std::cout << "Fraction " << i + 1 << ":" << std::endl;
//         Fraction frac;
//         std::cin >> frac;
//         fractions.push_back(frac);   // achteraan toevoegen
//     }

//     // een list heeft geen [i], dus doorlopen met een range-based for
//     int i{0};
//     for (const Fraction& frac : fractions) {
//         std::cout << "Fraction " << i + 1 << ": " << frac << std::endl;
//         ++i;
//     }

//     return 0;
// }

// std::istream& operator>>(std::istream& in, Fraction& frac) {

//     double numerator;
//     double denominator;

//     std::cout << "Please type in numerator:" << std::endl;
//     in >> numerator;

//     std::cout << "Please type in denominator:" << std::endl;
//     in >> denominator;

//     while (denominator == 0) {
//         std::cout << "denominator can't be 0" << std::endl;
//         std::cout << "Please type in denominator:" << std::endl;
//         in >> denominator;
//     }

//     frac = Fraction(numerator, denominator);

//     return in;
// }

// std::ostream& operator<<(std::ostream& out, const Fraction& frac) {

//     out << frac.numerator << "/" << frac.getDenominator() << " = " << frac.fractionValue();

//     return out;
// }


























// // stap 10 - afgeleide class met onder- en bovengrens van de decimale waarde
// #include <iostream>
// #include <list>

// class Fraction {

//     public:

//     Fraction() {}

//     Fraction(double num, double den) {
//         numerator = num;
//         setDenominator(den);
//     }

//     double fractionValue() const {
//         return numerator / denominator;
//     }

//     void setDenominator(double den) {
//         if (den == 0) {
//             std::cout << "setting denominator failed, denominator can't be 0" << std::endl;
//         } else {
//             denominator = den;
//         }
//     }

//     double getDenominator() const {
//         return denominator;
//     }

//     double numerator = 0;

//     private:

//     double denominator = 1;
// };


// // LimitedFraction IS een Fraction (public inheritance), met extra onder- en bovengrens
// class LimitedFraction : public Fraction {

//     public:

//     LimitedFraction(double lower, double upper) {
//         lowerLimit = lower;
//         upperLimit = upper;
//     }

//     // ligt de decimale waarde tussen de grenzen?
//     bool isInLimits() const {
//         return fractionValue() >= lowerLimit && fractionValue() <= upperLimit;
//     }

//     private:

//     double lowerLimit = 0;
//     double upperLimit = 0;
// };


// std::istream& operator>>(std::istream& in, Fraction& frac);
// std::ostream& operator<<(std::ostream& out, const Fraction& frac);


// int main() {

//     int arraySize;

//     std::cout << "Please type your desired number of fractions:" << std::endl;
//     std::cin >> arraySize;
//     while (arraySize <= 0) {
//         std::cout << "number must be greater than 0. please enter desired number of fractions" << std::endl;
//         std::cin >> arraySize;
//     }

//     double lower;
//     double upper;
//     std::cout << "Please type in lower limit:" << std::endl;
//     std::cin >> lower;
//     std::cout << "Please type in upper limit:" << std::endl;
//     std::cin >> upper;
//     while (upper < lower) {
//         std::cout << "upper limit can't be smaller than lower limit. Please type in upper limit:" << std::endl;
//         std::cin >> upper;
//     }

//     std::list<LimitedFraction> fractions;

//     for (int i{0}; i < arraySize; ++i) {
//         std::cout << "Fraction " << i + 1 << ":" << std::endl;
//         LimitedFraction frac(lower, upper);
//         std::cin >> frac;               // werkt: een LimitedFraction is ook een Fraction
//         fractions.push_back(frac);
//     }

//     int i{0};
//     for (const LimitedFraction& frac : fractions) {
//         std::cout << "Fraction " << i + 1 << ": " << frac;
//         if (frac.isInLimits()) {
//             std::cout << " (within limits)" << std::endl;
//         } else {
//             std::cout << " (outside limits)" << std::endl;
//         }
//         ++i;
//     }

//     return 0;
// }

// std::istream& operator>>(std::istream& in, Fraction& frac) {

//     double numerator;
//     double denominator;

//     std::cout << "Please type in numerator:" << std::endl;
//     in >> numerator;

//     std::cout << "Please type in denominator:" << std::endl;
//     in >> denominator;

//     while (denominator == 0) {
//         std::cout << "denominator can't be 0" << std::endl;
//         std::cout << "Please type in denominator:" << std::endl;
//         in >> denominator;
//     }

//     // niet frac = Fraction(...): dat zou bij een LimitedFraction de grenzen niet zetten
//     frac.numerator = numerator;
//     frac.setDenominator(denominator);

//     return in;
// }

// std::ostream& operator<<(std::ostream& out, const Fraction& frac) {

//     out << frac.numerator << "/" << frac.getDenominator() << " = " << frac.fractionValue();

//     return out;
// }


































// // stap 11 - function template Square
// #include <iostream>
// #include <list>

// class Fraction {

//     public:

//     Fraction() {}

//     Fraction(double num, double den) {
//         numerator = num;
//         setDenominator(den);
//     }

//     double fractionValue() const {
//         return numerator / denominator;
//     }

//     void setDenominator(double den) {
//         if (den == 0) {
//             std::cout << "setting denominator failed, denominator can't be 0" << std::endl;
//         } else {
//             denominator = den;
//         }
//     }

//     double getDenominator() const {
//         return denominator;
//     }

//     double numerator = 0;

//     private:

//     double denominator = 1;
// };


// // LimitedFraction IS een Fraction (public inheritance), met extra onder- en bovengrens
// class LimitedFraction : public Fraction {

//     public:

//     LimitedFraction(double lower, double upper) {
//         lowerLimit = lower;
//         upperLimit = upper;
//     }

//     // ligt de decimale waarde tussen de grenzen?
//     bool isInLimits() const {
//         return fractionValue() >= lowerLimit && fractionValue() <= upperLimit;
//     }

//     private:

//     double lowerLimit = 0;
//     double upperLimit = 0;
// };


// std::istream& operator>>(std::istream& in, Fraction& frac);
// std::ostream& operator<<(std::ostream& out, const Fraction& frac);


// // template: werkt voor elk type T dat * ondersteunt (int, double, ...)
// template <typename T>
// T Square(T value) {
//     return value * value;
// }


// int main() {

//     int arraySize;

//     std::cout << "Please type your desired number of fractions:" << std::endl;
//     std::cin >> arraySize;
//     while (arraySize <= 0) {
//         std::cout << "number must be greater than 0. please enter desired number of fractions" << std::endl;
//         std::cin >> arraySize;
//     }

//     double lower;
//     double upper;
//     std::cout << "Please type in lower limit:" << std::endl;
//     std::cin >> lower;
//     std::cout << "Please type in upper limit:" << std::endl;
//     std::cin >> upper;
//     while (upper < lower) {
//         std::cout << "upper limit can't be smaller than lower limit. Please type in upper limit:" << std::endl;
//         std::cin >> upper;
//     }

//     std::list<LimitedFraction> fractions;

//     for (int i{0}; i < arraySize; ++i) {
//         std::cout << "Fraction " << i + 1 << ":" << std::endl;
//         LimitedFraction frac(lower, upper);
//         std::cin >> frac;               // werkt: een LimitedFraction is ook een Fraction
//         fractions.push_back(frac);
//     }

//     int i{0};
//     for (const LimitedFraction& frac : fractions) {
//         std::cout << "Fraction " << i + 1 << ": " << frac;
//         if (frac.isInLimits()) {
//             std::cout << " (within limits)" << std::endl;
//         } else {
//             std::cout << " (outside limits)" << std::endl;
//         }
//         std::cout << "   square of decimal value: " << Square(frac.fractionValue()) << std::endl;   // T = double
//         ++i;
//     }

//     std::cout << "square of number of fractions: " << Square(arraySize) << std::endl;   // T = int

//     return 0;
// }

// std::istream& operator>>(std::istream& in, Fraction& frac) {

//     double numerator;
//     double denominator;

//     std::cout << "Please type in numerator:" << std::endl;
//     in >> numerator;

//     std::cout << "Please type in denominator:" << std::endl;
//     in >> denominator;

//     while (denominator == 0) {
//         std::cout << "denominator can't be 0" << std::endl;
//         std::cout << "Please type in denominator:" << std::endl;
//         in >> denominator;
//     }

//     // niet frac = Fraction(...): dat zou bij een LimitedFraction de grenzen niet zetten
//     frac.numerator = numerator;
//     frac.setDenominator(denominator);

//     return in;
// }

// std::ostream& operator<<(std::ostream& out, const Fraction& frac) {

//     out << frac.numerator << "/" << frac.getDenominator() << " = " << frac.fractionValue();

//     return out;
// }
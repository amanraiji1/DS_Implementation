/*------------------------------------------------------Fraction Class-----------------------------------------------------------*/
class Fraction {
	int numerator;
	int denominator;
	
	public : 
	
	//Default Constructor
	Fraction(){
		
	}
	
	//Constructor
	Fraction(int num,int den){
		numerator = num;
		denominator = den;
	}
	
	//Simplify the fraction
	void simplify(){
		int gcd = 1;
		int j = min(abs(this->numerator),abs(this->denominator)); //abs for negative fraction simplification
		for(int i=2;i<=j;i++){
			if(this->numerator % i == 0 && this->denominator % i == 0)
			    gcd = i;
		}
		
		this->numerator = this->numerator / gcd;
		this->denominator = this->denominator / gcd;
	}
	
	/* ----------------------------------------------Binary Operators--------------------------------------*/
	
	//Add
	Fraction operator+(Fraction const &f2) const {
		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;
		
		int num = x * numerator + (y * f2.numerator);
		Fraction fNew(num,lcm);
		fNew.simplify();
		return fNew;
	}
	
	//Subtraction
	Fraction operator-(Fraction const &f2) const{
		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;
		
		int num = x * numerator - (y * f2.numerator);
		Fraction fNew(num,lcm);
		fNew.simplify();
		return fNew;
	}
	
	//Multiplication
	Fraction operator*(Fraction const &f2) const{
		int num = numerator * f2.numerator;
		int den = denominator * f2.denominator;
		
		Fraction fNew(num,den);
		fNew.simplify();
		return fNew;
	}
	
	//Division
	Fraction operator/(Fraction const &f2) const{
		int num = numerator * f2.denominator;
		int den = denominator * f2.numerator;
		
		Fraction fNew(num,den);
		fNew.simplify();
		return fNew;
	}
	
	//Comparison operator
	bool operator==(Fraction const &f2) const{
		return (numerator == f2.numerator && denominator == f2.denominator);
	}
	
	//Add then assign
	Fraction& operator+=(Fraction const &f2){
		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;
		
		int num = x * numerator + (y * f2.numerator);
		
		this->numerator = num;
		this->denominator = lcm;
		simplify();
		return *this;   //for nesting purpose
	}
	
	//Subtract then Assign
	Fraction& operator-=(Fraction const &f2){
		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;
		
		int num = x * numerator - (y * f2.numerator);
		this->numerator = num;
		this->denominator = lcm;
		
		simplify();
		return *this;   //for nesting purpose
	}
	
	//Multiply then assign
	Fraction& operator*=(Fraction const &f2){
		numerator = numerator * f2.numerator;
		denominator = denominator * f2.denominator;
		
		simplify();
		
		return *this;   //for nesting purpose
	}
	
	//Divide then assign
	Fraction& operator/=(Fraction const &f2){
		numerator = numerator * f2.denominator;
		denominator = denominator * f2.numerator;
		
		simplify();
		
		return *this;
	}
	
	/*-------------------------------------------------------Unary Operators-----------------------------------------------*/
	
	//Pre-Increment
	Fraction& operator++(){
		numerator = numerator + denominator;
		simplify();
		return *this;
	}
	
	//Post - Increment
	Fraction operator++(int){
		Fraction fNew(numerator,denominator);
		numerator = numerator + denominator;
		
		simplify();
		fNew.simplify();
		return fNew;    //No nesting possible in post increment
	}
	
	//Pre-Decrement
	Fraction& operator--(){
		numerator = numerator - denominator;
		simplify();
		return *this;
	}
	
	//Post - Decrement
	Fraction operator--(int){
		Fraction fNew(numerator,denominator);
		numerator = numerator - denominator;
		
		simplify();
		fNew.simplify();
		return fNew;    //No nesting possible in post increment
	}
	
	//User Input using cin
	friend istream &operator>>( istream  &input,Fraction &f ) { 
	     cout << "Enter Numerator : "; 
	     input >>  f.numerator;
	     cout << "Enter Denominator : ";
	     input >> f.denominator;
         return input;            
      }
      
    //Print using cout
	friend ostream &operator<<( ostream  &output,const Fraction &f ) { 
	     output << f.numerator <<"/"<< f.denominator;
         return output;            
      }
   
};

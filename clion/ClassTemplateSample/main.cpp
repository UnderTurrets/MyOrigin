
#include<iostream>
#include<cstring>
#include<iomanip>


using namespace std;


template<class T>
class vector{
public:
   vector(int size):i(size){
   	  m_elements = new T[i];
   }
   vector():i(0){
   }

   ~vector(){
   	  delete[] (T*)m_elements;
   	  delete &i;
   }

   vector(const vector&that){
   	   if(this!=&that){
   	   	  delete[] this->m_elements;
   	   	  this->i=that.i;
   	   	  this->m_elements = new T[that.i];
   	   	  memcpy(this->m_elements,that.m_elements,sizeof(T[that.i]));
		  }
   }

   vector& operator= (const vector&that){
   	   if(this!=&that){
   	   	  delete[] this->m_elements;
   	   	  this->i=that.i;
   	   	  this->m_elements = new T[that.i];
   	   	  memcpy(this->m_elements,that.m_elements,sizeof(T[that.i]));
   	   	  return *this;
		  }
   }

   T& operator[] (int index){
   	    if(index<i && index>=0){
   	   	    return m_elements[index];
		}
   }

   void  print (){
   	   cout<<i<<endl;
   	   cout<<sizeof(m_elements)*i<<endl;
   }

private:
	T* m_elements;
	int i;
};




//    class A{
//    public:
//
//       string str;
//       A(string ar):str(ar){
//	   }
//
//	   A& operator= (const A & that){
//	   	   if(this!=&that){
//	   	   //	delete str;
//	   	   //	str=new string[strlen(that.str)];
//	   	   	memcpy(str,that.str,sizeof(string));
//
//	   	   	     //str = that.str;
//			  }
//			  return *this;
//
//	   }
//
//	   const void print() const {
//	        cout<<str<<endl;
//	   }
//
//
//
//    };
//     	virtual void print(father &p){
//     		p.print();
//		 }


//		virtual void print(){
//     		cout<<"father"<<endl;
//		}







//     class date{
//     	private:
//     		A temp1;
//     		B temp2;
//     	public:
//
//     	   date(int x1,int x2):temp1(x1,x2),temp2(x2,x1){
//			}
//
//		   void print(){temp1.print();
//		                temp2.print();
//		   }
//
//};



int main(int argc, char** argv) {
	vector<char> v1(100);
	v1.print();
	vector<char> v2(50);
	v2.print();
	v1=v2;
	v1.print();
	float a=2.2;
	printf("%09.3f\n",a);
	int b=2,c=3;
cout << "255(..进制): " <<std::setbase(16) << 110 << std::endl;
	cout <<setw( 6 )  <<setfill('x') << a << std::endl;
















//	A x(2,2);
//	B y;
////	date dis(5,8);
//	dis.print();

//    father A;son a;
//    father &n = a;
//    A.print(A);
//    A.print(a);
      //n.print(a);//向上造型



//    A m("a1");
//    m.print();
//    A n("askjcn");
//    n=m;
//    m.print();
}



















